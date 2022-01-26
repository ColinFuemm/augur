/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwtimerstopwatchf21;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 *
 * @author Colin Fuemmeler
 */

public class MyNewStopWatch extends Application {
    
    private String appName = "New Stopwatch";
    
    @Override
    public void start(Stage primaryStage) {      //overarching stage setup and AnalogStopWatch containment from in lecture
        AnalogStopWatch analog = new AnalogStopWatch();
        
        //Scene scene = new Scene(analog.getRootContainer());
        Scene scene = new Scene(analog.getRootContainer(), analog.getWidth(), analog.getHeight());
        
        primaryStage.setTitle(appName);
        primaryStage.setScene(scene);
        primaryStage.show();
        
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
