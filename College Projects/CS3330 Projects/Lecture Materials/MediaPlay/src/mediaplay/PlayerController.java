/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mediaplay;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaView;
import javafx.scene.text.Text;

/**
 *
 * @author Professor Wergeles
 * 
 * http://stackoverflow.com/questions/20787450/javafx-mediaplayer-stops-before-end-of-video-without-throwing-an-event-when-comp
 * 
 * 
 * Comment about the use of Runnable instead of EventHandlers in Media:
 * http://stackoverflow.com/questions/11598486/status-listener-on-mediaplayer-object-in-javafx-2
 */
public class PlayerController implements Initializable {
    
    @FXML
    MediaView mediaView; 
    
    MediaPlayer mediaPlayer; 
    
    @FXML
    Text status; 
    
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
//        Media media = new Media("http://dalemusser.net/media/sl.mp4"); 

//        Media media = new Media(this.getClass().getResource("Slightly Stoopid - Closer to the Sun.mp3")
//                .toExternalForm());
        
        Media media = new Media(this.getClass().getResource("tomandjerry.mp4")
                .toExternalForm());
        
        mediaPlayer = new MediaPlayer(media); 
        
        mediaView.setMediaPlayer(mediaPlayer);
        
        mediaPlayer.setOnPaused(() -> {
            status.setText("paused at " + mediaPlayer.getCurrentTime().toString());
        });
        
        mediaPlayer.setOnStopped(new Runnable() {
            @Override
            public void run(){
                status.setText("stopped"); 
            }
        });
        
        mediaPlayer.setOnReady(() -> { 
           status.setText("ready");
        });
        
        mediaPlayer.setOnPlaying(() -> { 
            status.setText("playing");
        });
        
        mediaPlayer.setOnStalled(() -> { 
            status.setText("stalled");
        });
        
    } 
    
    @FXML
    private void handlePlay(ActionEvent event){
        mediaPlayer.play();
    }
    
    @FXML
    private void handlePause(ActionEvent event){
        mediaPlayer.pause();
    }
    @FXML
    private void handleStop(ActionEvent event){
        mediaPlayer.stop(); 
    }
    
}
