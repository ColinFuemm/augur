/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwmvcstopwatchfxmlf21;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Alert;
import javafx.util.Duration;

/**
 *
 * @author Colin
 */
public class ModelDigital extends Model {
    private double startTime;
    private String timer;
    private String countdown;
    private String lap;
    private String oldLap;
    private String average;
    private String oldAvg;
    private int recordCount;
    private double lastTime;
    
    public ModelDigital() {
        startTime = 60.0;
        timer = "01:00.00";
        oldLap = "00:00.00";
        lap = "00:00.00";
        average = "00:00.00";
        oldAvg = "00:00.00";
        recordCount = 0;
        lastTime = secondsElapsed;
    }
    public void setupMonitor() {
        keyFrame = new KeyFrame(Duration.millis(tickTimeInSeconds * 1000), (ActionEvent event) -> {
                update(); 
        });
        timeline = new Timeline(keyFrame);
        timeline.setCycleCount(Animation.INDEFINITE);
    }
    public void update() {
        secondsElapsed += tickTimeInSeconds;
        if(startTime > 0) startTime -= tickTimeInSeconds;
        updateDigital(); 
    }
    public void updateDigital(){                                                //updateDigital referenced from MvcCpuMonitorFxml
        String oldTimer = timer;
        String oldCount = countdown;
        timer = Timer(secondsElapsed);
        countdown = Timer(startTime);
        firePropertyChange("Digital", oldTimer, timer);
        firePropertyChange("Timer", oldCount, countdown);
    }
    public XYChart.Series<Number, Number> updateSeriesOne(XYChart.Series<Number, Number> series) {
        series.getData().add(new XYChart.Data<>(recordCount, secondsElapsed - lastTime));
        return series;
    }
    public XYChart.Series<Number, Number> updateSeriesTwo(XYChart.Series<Number, Number> series) {
        series.getData().add(new XYChart.Data<>(recordCount, secondsElapsed/recordCount));
        return series;
    }
    public void reset() {
        secondsElapsed = -0.001;
        recordCount = 0;
        startTime = 60.001;
        firePropertyChange("Lap", lap, "00:00.00");
        firePropertyChange("Record", average, "00:00.00");
        update();
        timeline.stop();
    }
    public void record() {
        if(startTime > 0) { 
            recordCount++;
            oldLap = lap;
            oldAvg = average;
            lap = Timer(secondsElapsed - lastTime);
            average = Timer(secondsElapsed/recordCount);
            firePropertyChange("Lap", oldLap, lap);
            firePropertyChange("Record", oldAvg, average);
            firePropertyChange("Line", "hi", timer);
            firePropertyChange("Area", ";)", countdown);
            lastTime = secondsElapsed;
        }
        else {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);                     //all alert commands are referenced from https://code.makery.ch/blog/javafx-dialogs-official/
            alert.setTitle("Out of Time!");
            alert.setHeaderText(null);
            alert.setContentText("Time is up... No more records");
            alert.showAndWait();
        }
    }
    public String Timer(double secondsElapsed) {
        int minutes = (int)(secondsElapsed /60);
        int seconds = (int)(secondsElapsed %60);
        int millis = (int) ((secondsElapsed*1000)%1000);
        //number formatting found on https://stackoverflow.com/questions/12421444/how-to-format-a-number-0-9-to-display-with-2-digits-its-not-a-date
        String timeString = (String.format("%02d", minutes) + ":" + String.format("%02d", seconds) + "." + String.format("%03d", millis));
        return timeString;
    }
}
