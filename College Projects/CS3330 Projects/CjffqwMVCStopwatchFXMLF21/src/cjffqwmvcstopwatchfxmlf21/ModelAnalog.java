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
import javafx.scene.control.Alert;
import javafx.util.Duration;

/**
 *
 * @author Colin
 */
public class ModelAnalog extends Model {   
    private double angleDeltaPerSecond;
    private double rotation;
    
    public ModelAnalog() {
        angleDeltaPerSecond = 6.0;
        rotation = 0.0;
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
        updateAnalog(); 
    }
    public void updateAnalog(){                                                 //updateAnalog referenced from MvcCpuMonitorFxml
        double oldRotation = rotation;
        rotation = secondsElapsed * angleDeltaPerSecond;           
        firePropertyChange("Analog", oldRotation, rotation); 
    }
    public void reset() {
        secondsElapsed = -0.001;
        update();
        timeline.stop();
    }
}
