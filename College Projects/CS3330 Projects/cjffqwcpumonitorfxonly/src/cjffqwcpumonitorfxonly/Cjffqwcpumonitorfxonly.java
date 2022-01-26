/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwcpumonitorfxonly;

import java.lang.management.ManagementFactory;
import java.lang.management.OperatingSystemMXBean;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.chart.AreaChart;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.RowConstraints;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Duration;

/**
 *
 * @author Colin
 */
public class Cjffqwcpumonitorfxonly extends Application {
    
     private double cpu = 0;
    
    private GridPane root;
    private VBox digital;
    private HBox buttons;
    private TextArea textArea;
    private Text meanText;
    private Text peakText;
    private String peakString = "0.00";
    private double count = 0;
    private double sum = 0;
    private double max = 0;
    private StackPane stack;
    private double secondsElapsed = 0.0;
    
    private String font = "Comic Sans MS";
    
    private ImageView dialImageView;
    private Image dial;
    private ImageView handImageView;
    private Image hand;
    
    private int recordCount = 0;
    
    private Timeline timeline;
    
    private double angleDeltaPerCPU = 300;
    private double initialRotation = -165;
    
    private XYChart.Series<Number, Number> series;
    private XYChart.Series<Number, Number> series2;
    
    @Override
    public void start(Stage primaryStage) {
        
        //initial pane setup
        root = new GridPane();
        root.setPadding(new Insets(25, 25, 25, 25));
        root.setVgap(10);
        root.setHgap(10);
        root.getColumnConstraints().add(new ColumnConstraints(300));
        root.getRowConstraints().add(new RowConstraints(300));
        
        //Analog Display Setup
        stack = new StackPane();
        dialImageView = new ImageView();
        handImageView = new ImageView();

        dial = new Image(getClass().getResourceAsStream("mygauge.png"));
        hand = new Image(getClass().getResourceAsStream("hand.png"));
        
        dialImageView.setImage(dial);
        dialImageView.setFitWidth(300);
        dialImageView.setFitHeight(300);
        handImageView.setImage(hand);
        handImageView.setRotate(initialRotation);
        handImageView.setFitWidth(300);
        handImageView.setFitHeight(300);
        
        stack.getChildren().addAll(dialImageView, handImageView);
        root.add(stack, 0, 0);
        
        //Button and Usage Text Setup
        digital = new VBox();
        buttons = new HBox();
        Button play = new Button("Start");
        Button record = new Button("Record");
        play.setMaxWidth(Double.MAX_VALUE);
        record.setMaxWidth(Double.MAX_VALUE);
        play.setMaxHeight(Double.MAX_VALUE);
        record.setMaxHeight(Double.MAX_VALUE);
        digital.setAlignment(Pos.BOTTOM_LEFT);
        digital.setSpacing(30);
        textArea = new TextArea("Usage: %0.00"); 
        textArea.setFont(Font.font(font, FontWeight.BOLD, 18.0));
        textArea.setPrefRowCount(1);
        meanText = new Text("  Mean Usage: %0.00"); 
        meanText.setFont(Font.font(font, FontWeight.BOLD, 16.0));
        peakText = new Text("  Peak Usage: %0.00");
        peakText.setFont(Font.font(font, FontWeight.BOLD, 16.0));
        buttons.getChildren().addAll(play, record);
        digital.getChildren().addAll(buttons, textArea, meanText, peakText);
        root.add(digital, 0, 1);
        
        //Chart Setup
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis xxAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        final NumberAxis yyAxis = new NumberAxis();
        xAxis.setLabel("Record Number");
        xxAxis.setLabel("Seconds Elapsed");
        xAxis.setAutoRanging(false);
        xxAxis.setAutoRanging(false);
        xAxis.setLowerBound(0);
        xxAxis.setLowerBound(0);
        xAxis.setUpperBound(20);
        xxAxis.setUpperBound(60);                                              //chart creation referenced from https://docs.oracle.com/javafx/2/charts/area-chart.htm
        xAxis.setAnimated(false); // axis animations are removed
        xxAxis.setAnimated(false);
        yAxis.setLabel("Usage");
        yAxis.setAutoRanging(false);
        yAxis.setLowerBound(0);
        yAxis.setUpperBound(100);
        yAxis.setAnimated(false); // axis animations are removed
        yyAxis.setLabel("Usage");
        yyAxis.setAutoRanging(false);
        yyAxis.setLowerBound(0);
        yyAxis.setUpperBound(100);
        yyAxis.setAnimated(false);

        //creating the line chart with two axis created above
        final LineChart<Number, Number> lineChart = new LineChart<>(xAxis, yAxis);
        lineChart.setTitle("Record Chart");
        lineChart.setAnimated(false); // disable animations
        
        final AreaChart<Number, Number> areaChart = new AreaChart<>(xxAxis, yyAxis);
        areaChart.setTitle("Usage Chart");
        areaChart.setAnimated(false);
        
        series = new XYChart.Series<>();
        series.setName("Data Series");
        lineChart.getData().add(series);
        series2 = new XYChart.Series<>();
        series2.setName("Second Intervals");
        areaChart.getData().add(series2);
        
        root.add(lineChart, 1, 0);
        root.add(areaChart, 1, 1);
        
        //Action Area
        play.setOnAction((ActionEvent event) -> {
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
        });
        
        record.setOnAction((ActionEvent event) -> {
            if (isRunning()) {
                record();
            }
            else {
               reset();
            }
        });

        timeline = new Timeline(new KeyFrame(Duration.millis(1000), (ActionEvent) -> {
            update();      
        }));
        
        timeline.setCycleCount(Animation.INDEFINITE);
        
        Scene scene = new Scene(root, 750, 675); 
        
        primaryStage.setTitle("CPU Monitor Starter Code"); 
        primaryStage.setScene(scene); 
        primaryStage.show(); 
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
    }                                                                                                           //end starter code reference

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
