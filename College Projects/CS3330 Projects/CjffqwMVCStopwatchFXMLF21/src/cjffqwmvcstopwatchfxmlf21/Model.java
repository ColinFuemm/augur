/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwmvcstopwatchfxmlf21;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;

/**
 *
 * @author Colin
 */
public class Model extends AbstractModel {
    double secondsElapsed;   
    double tickTimeInSeconds; 
    Timeline timeline;
    KeyFrame keyFrame;
    
    public Model() {
        tickTimeInSeconds = 0.001; 
        secondsElapsed = 0.0;
    }
    
    public void start() {
        timeline.play();
    }
    public void stop() {
        timeline.pause();
    }
    public Timeline getTimeLine(){
        return timeline; 
    }
    public void setTimeLine(Timeline timeline){
        this.timeline = timeline; 
    }
    public KeyFrame getKeyFrame(){
        return keyFrame; 
    }
    public void setKeyFrame(KeyFrame keyFrame){
        this.keyFrame = keyFrame; 
    }
    public double getTickTimeInSeconds(){
        return tickTimeInSeconds; 
    }
    public boolean isRunning() {
        if(timeline != null) {
            if(timeline.getStatus() == Animation.Status.RUNNING) {
                return true;
            }
        }
        return false;   
    }
}
