/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwcpumonitorf21;

import java.lang.management.ManagementFactory;
import java.lang.management.OperatingSystemMXBean;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.chart.AreaChart;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;
import javafx.util.Duration;

/**
 *
 * @author Colin
 */
public class FXMLDocumentController implements Initializable {
    @FXML
    private Pane pane;
    @FXML
    private Pane pane2;
    @FXML
    double cpu = 0;
    @FXML
    TextArea textArea;
    @FXML
    Text meanText;
    @FXML
    Text peakText;
    private String peakString = "0.00";
    private double count = 0;
    private double sum = 0;
    private double max = 0;
    private double secondsElapsed = 0.0;
    private XYChart.Series<Number, Number> series;
    private XYChart.Series<Number, Number> series2;
    @FXML
    public ImageView dialImageView;
    @FXML
    public ImageView handImageView;
    @FXML
    int recordCount = 0;
    @FXML
    Timeline timeline = new Timeline(new KeyFrame(Duration.millis(1000), (ActionEvent) -> {
        update();      
    }));
    
    private double angleDeltaPerCPU = 300;
    @FXML
    double initialRotation = -165;
        
        //Button and Usage Text Setup
    @FXML
    Button play = new Button("Start");
    @FXML
    Button record = new Button("Record");
       
    //Action Area
    @FXML
    public void playAction(ActionEvent event){
        if (isRunning()) {
            stop();
            play.setText("Start");
            record.setText("Reset");
        }
        else {
            start();
            play.setText("Stop");
            record.setText("Record");
        }
    }
    @FXML    
    public void recordAction(ActionEvent event) {
        if (isRunning()) {
            record();
        }
        else {
            reset();
        }
    }
          
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        textArea.setText("Usage: %0.00");
        meanText.setText("Hello: %0.00");
        peakText.setText("Peak Usage: %0.00");       
        loadData();
        timeline.setCycleCount(Animation.INDEFINITE);
    }
    
    private void loadData() {
        pane.getChildren().clear();
        pane2.getChildren().clear();
        NumberAxis xAxis = new NumberAxis();
        xAxis.setLabel("Record Number");
        NumberAxis xxAxis = new NumberAxis();
        xxAxis.setLabel("Seconds Elapsed");
        NumberAxis yAxis = new NumberAxis();
        yAxis.setLabel("Usage");
        NumberAxis yyAxis = new NumberAxis();
        yyAxis.setLabel("Usage");
        xAxis.setAutoRanging(false);
        xxAxis.setAutoRanging(false);
        xAxis.setLowerBound(0);
        xxAxis.setLowerBound(0);
        xAxis.setUpperBound(20);
        xxAxis.setUpperBound(60);                                              //chart creation referenced from https://docs.oracle.com/javafx/2/charts/area-chart.htm
        xAxis.setAnimated(false); // axis animations are removed
        xxAxis.setAnimated(false);
        yAxis.setAutoRanging(false);
        yAxis.setLowerBound(0);
        yAxis.setUpperBound(100);
        yAxis.setAnimated(false); // axis animations are removed
        yyAxis.setAutoRanging(false);
        yyAxis.setLowerBound(0);
        yyAxis.setUpperBound(100);
        yyAxis.setAnimated(false);

        LineChart<Number, Number> lineChart = new LineChart<>(xAxis, yAxis);
        lineChart.setTitle("Record Chart");
        AreaChart<Number, Number> areaChart = new AreaChart<>(xxAxis, yyAxis);
        areaChart.setTitle("Usage Chart");
        
        series = new XYChart.Series<>();
        series.setName("Records");
        series2 = new XYChart.Series<>();
        series2.setName("Seconds Elapsed");
        lineChart.getData().add(series);
        areaChart.getData().add(series2);
        pane.getChildren().add(lineChart);
        pane2.getChildren().add(areaChart);
    }

    //Secondary Functions    
    public void update() {
        secondsElapsed++;
        cpu = this.getCPUUsage();
        String cpuString = (String.format("%.2f", cpu*100));
        count++;
        sum += cpu;
        String meanString = (String.format("%.2f", sum/count*100));
        if(cpu > max) {
            max = cpu;
            peakString = (String.format("%.2f", max*100));
        }
        textArea.setText("Usage: %" + cpuString);
        meanText.setText("  Mean Usage: %" + meanString);
        peakText.setText("  Peak Usage: %" + peakString);
        double rotation = initialRotation + (cpu * angleDeltaPerCPU);
        handImageView.setRotate(rotation);
        series2.getData().add(new XYChart.Data<>(secondsElapsed, cpu*100));
        
    }
    
    public void start() {
        timeline.play();
    }
    public void stop() {
        timeline.pause();
    }
    public void reset() {
        count = 0;
        sum = 0;
        secondsElapsed = 0.0;
        max = 0;
        textArea.setText("Usage: %0.00");
        meanText.setText("  Mean Usage: %0.00");
        peakText.setText("  Peak Usage: %0.00");
        handImageView.setRotate(initialRotation);
        series.getData().clear();
        series2.getData().clear();
        timeline.stop();
    }
    public void record() {
        recordCount++;
        series.getData().add(new XYChart.Data<>(recordCount, cpu*100));
    }
    public boolean isRunning() {
        if(timeline != null) {
            if(timeline.getStatus() == Animation.Status.RUNNING) {
                return true;
            }
        }
        return false;   
    }
    
    public double getCPUUsage() {
        OperatingSystemMXBean operatingSystemMXBean = ManagementFactory.getOperatingSystemMXBean();
        double value = 0;
        
        for(Method method : operatingSystemMXBean.getClass().getDeclaredMethods()) {
            method.setAccessible(true);
            
            if (method.getName().startsWith("getSystemCpuLoad") && Modifier.isPublic(method.getModifiers())) {
                try {
                    value = (double) method.invoke(operatingSystemMXBean);
                } catch (Exception e) {
                    value = 0;
                }
                return value;
            }
        }
        return value;
    }
    
}
