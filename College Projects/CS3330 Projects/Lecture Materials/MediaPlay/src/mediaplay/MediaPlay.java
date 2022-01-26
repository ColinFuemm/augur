/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mediaplay;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 *
 * @author Professor Wergeles
 * 
 * 
 * http://stackoverflow.com/questions/13509331/javafx-playing-video-with-mediaplayer-and-mediaview
 * http://docs.oracle.com/javafx/2/media/simpleplayer.htm
 * http://what-when-how.com/javafx-2/playing-audio-using-the-media-classes-javafx-2-part-1/
 */
public class MediaPlay extends Application {
    
    @Override
    public void start(Stage stage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("Player.fxml"));
        
        Scene scene = new Scene(root);
        
        stage.setScene(scene);
        stage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
