/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package audiovisual;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.image.ImageView;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.text.Text;
import javafx.util.Duration;

/**
 *
 * @author Professor Wergeles
 */
public class PlayerController implements Initializable {
    
    private static final Duration TRANSLATE_DURATION = Duration.seconds(0.25);
    
    @FXML
    private Text magText1;
    
    @FXML
    private Text magText2;
    
    @FXML
    private Text magText3;
    
    @FXML
    private Text magText4;
    
    @FXML
    private Text phaseText1;
    
    @FXML
    private Text phaseText2;
    
    @FXML
    private Text phaseText3;
    
    @FXML
    private Text phaseText4;
    
    @FXML
    private Ellipse ellipse1;
    
    @FXML
    private Ellipse ellipse2;
    
    @FXML
    private Ellipse ellipse3;
    
    @FXML
    private Ellipse ellipse4;
    
    @FXML
    private ImageView c; 
    
    @FXML
    private ImageView o1;
    
    @FXML
    private ImageView o2;
    
    @FXML
    private ImageView l;
    

    
    String[] songs = {"Slightly Stoopid - Closer to the Sun.mp3",
                        "James Hersey - Miss You.mp3",
                        "Are You In.mp3",
                        "Flake - Jack Johnson.mp3", 
                        "bensound-scifi.mp3"
    };
    
    private int x = 0; 
    
    private Media media; 
    private MediaPlayer mediaPlayer; 
    
    private Double phaseMultipler = 360.0; 
    private Double magnitudeOffset = 70.0; 
    

    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        setupUI(songs[x]); 
    } 
    
    @FXML
    private void handlePlay() {
        mediaPlayer.play();
    }
    
    @FXML
    private void handlePause() {
        mediaPlayer.pause(); 
    }
    
    @FXML
    private void handleStop() {
        mediaPlayer.stop(); 
    }
    
    @FXML
    private void handleNext(){
        if(isRunning()){
            mediaPlayer.stop(); 
        }
        
        if(x++ == songs.length - 1){
            x = 0; 
        }
        
        setupUI(songs[x]); 
        mediaPlayer.play();
    }
    
    private void setupUI(String song){
        media = new Media(this.getClass().getResource(song).toExternalForm()); 
        
        mediaPlayer = new MediaPlayer(media); 
        
        mediaPlayer.setAudioSpectrumNumBands(4); 
        mediaPlayer.setAudioSpectrumInterval(0.01); 
        
        mediaPlayer.setAudioSpectrumListener((double timestamp, double duration, float[] magnitudes, float[] phases) -> { 
            if(magnitudes.length >= 4 && phases.length >=4){
                System.out.println("timestamp: " + timestamp); 
                System.out.println("duration: " + duration); 
                System.out.println("magnitudes: " + magnitudes[0] + ", " + magnitudes[1] + ", " + magnitudes[2] +
                        ", " + magnitudes[3]); 
                
                System.out.println("phases: " + phases[0] + ", " + phases[1] + ", " + phases[2] + ", " + phases[3]);
                
                magText1.setText(Float.toString(magnitudes[0]));
                magText2.setText(Float.toString(magnitudes[1]));
                magText3.setText(Float.toString(magnitudes[2]));
                magText4.setText(Float.toString(magnitudes[3]));
                
                phaseText1.setText(Float.toString(phases[0]));
                phaseText2.setText(Float.toString(phases[1]));
                phaseText3.setText(Float.toString(phases[2]));
                phaseText4.setText(Float.toString(phases[3]));
                
                ellipse1.setRadiusX(magnitudeOffset + magnitudes[0]); 
                ellipse1.setRadiusY(magnitudeOffset + magnitudes[0]); 
                
                ellipse2.setRadiusX(magnitudeOffset + magnitudes[1]); 
                ellipse2.setRadiusY(magnitudeOffset + magnitudes[1]);
                
                ellipse3.setRadiusX(magnitudeOffset + magnitudes[2]); 
                ellipse3.setRadiusY(magnitudeOffset + magnitudes[2]); 
               
                ellipse4.setRadiusX(magnitudeOffset + magnitudes[3]); 
                ellipse4.setRadiusY(magnitudeOffset + magnitudes[3]);
                
                
                ellipse1.setTranslateY( (Math.abs(magnitudes[0]) * 5) - 300);
                ellipse2.setTranslateY( (Math.abs(magnitudes[1]) * 5) - 300);
                ellipse3.setTranslateY( (Math.abs(magnitudes[2]) * 5) - 300);
                ellipse4.setTranslateY( (Math.abs(magnitudes[3]) * 5) - 300);
                
                ellipse1.setFill(Color.hsb(magnitudes[0] * -6.0, 1.0, 1.0, 1.0));
                ellipse2.setFill(Color.hsb(magnitudes[1] * -6.0, 1.0, 1.0, 1.0));
                ellipse3.setFill(Color.hsb(magnitudes[2] * -6.0, 1.0, 1.0, 1.0));
                ellipse4.setFill(Color.hsb(magnitudes[3] * -6.0, 1.0, 1.0, 1.0));
                
                c.setRotate(phases[0] * phaseMultipler); 
                o1.setRotate(phases[1] * phaseMultipler);
                o2.setRotate(phases[2] * phaseMultipler); 
                l.setRotate(phases[3] * phaseMultipler);
                
            }
        });
        
    }
    
    private boolean isRunning(){
        if(mediaPlayer.getAudioSpectrumListener() != null){
            if(mediaPlayer.getStatus() == MediaPlayer.Status.PLAYING){
                return true; 
            }
        }
        return false; 
    }
}