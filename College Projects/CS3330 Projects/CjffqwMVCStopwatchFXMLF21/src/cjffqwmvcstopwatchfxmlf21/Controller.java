/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwmvcstopwatchfxmlf21;

import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.chart.AreaChart;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
import javafx.scene.image.ImageView;
import javafx.scene.text.Text;

/**
 *
 * @author Colin
 */
public class Controller implements Initializable, PropertyChangeListener {
   
    @FXML
    private ImageView handImageView;
    @FXML
    private Button play;
    @FXML
    private Button record;
    @FXML
    private Text timerLabel;
    @FXML
    private Text lapLabel;
    @FXML
    private Text lapAvg;
    @FXML
    private Text counter;
    @FXML
    private LineChart lineChart;
    @FXML 
    private AreaChart areaChart;
    private XYChart.Series<Number, Number> series;
    private XYChart.Series<Number, Number> series2;
    private ModelAnalog analog;
    private ModelDigital digital;
     
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        analog = new ModelAnalog();
        digital = new ModelDigital();
        analog.setupMonitor();
        digital.setupMonitor();
        handImageView.setRotate(0);
        setupCharts();
        timerLabel.setText("00:00.00");
        lapLabel.setText("Lap: 00:00.00");
        counter.setText("Timer: 00:00.00");
        lapAvg.setText("Average Lap: 00:00.00");

        analog.addPropertyChangeListener(this);
        digital.addPropertyChangeListener(this);
    }  
    
    @FXML
    private void playAction(ActionEvent event) {
            if (digital.isRunning()) {
                digital.stop();
                analog.stop();
                play.setText("Start");
                record.setText("Reset");
            }
            else {
                digital.start();
                analog.start();
                play.setText("Stop");
                record.setText("Record");
            }
    }
    @FXML    
    private void recordAction(ActionEvent event) {
            if (digital.isRunning()) {
                digital.record();
            }
            else {
               digital.reset();
               analog.reset();
               series.getData().clear();
               series2.getData().clear();
            }
    }   
    private void setupCharts() {
        series = new XYChart.Series<>();
        series.setName("Record Mark");
        series2 = new XYChart.Series<>();
        series2.setName("Record Mark");
        lineChart.getData().add(series);
        areaChart.getData().add(series2);
    }
    @Override
    public void propertyChange(PropertyChangeEvent evt) {
        
        // propertyChange layout referenced from lecture
       
        if(evt.getPropertyName().equals("Analog")){                                      
            handImageView.setRotate(Double.parseDouble(evt.getNewValue().toString()));
        }
        else if(evt.getPropertyName().equals("Digital")){
            timerLabel.setText(evt.getNewValue().toString());
        }
        else if(evt.getPropertyName().equals("Lap")){
            lapLabel.setText("Lap: " + evt.getNewValue().toString());   
        }
        else if(evt.getPropertyName().equals("Record")){
            lapAvg.setText("Average Lap: " + evt.getNewValue().toString());
        }
        else if(evt.getPropertyName().equals("Timer")){
            counter.setText("Timer: " + evt.getNewValue().toString());
        }
        else if(evt.getPropertyName().equals("Line")){
            series = digital.updateSeriesOne(series);
        }
        else if(evt.getPropertyName().equals("Area")){
            series2 = digital.updateSeriesTwo(series2);
        }
   
    }
}
