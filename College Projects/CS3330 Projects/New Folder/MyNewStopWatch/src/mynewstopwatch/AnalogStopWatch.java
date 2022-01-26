/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mynewstopwatch;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Parent;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.TextInputDialog;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.RowConstraints;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.util.Duration;

/**
 *
 * @author Colin Fuemmeler
 */

public class AnalogStopWatch {  //the outlining of this document and its functions were modeled after in class lecture
    
    private KeyFrame keyFrame;
    private Timeline timeline;  
    
    private double secondsElapsed = 0.0;
    private double startTime = 600.0;
    private double tickTimeInSeconds = 0.001;   
    private double angleDeltaPerSecond = 6.0;  
    
    private double width = 600;
    private double height = 450;
    
    private ImageView dialImageView;    
    private ImageView handImageView;    
    private Image dial;    
    private Image hand;
    private String dialName = "clockface.png";
    private String handName = "clockhand.png";
    
    private StackPane root;
    private GridPane rootContainer;
    
    private Text timer;
    private String font = "Comic Sans MS";
    
    private String timeString = "00:00.000";
    private String counter;
    private Text countDown; 
    private Text label1;
    private Text label2;
    private Text label3;
    private Text champ;
    
    private double prevTime = 0.0;
    
    private TextInputDialog dialog;
    
    private int recordCount = 0;
    
    public AnalogStopWatch(){
        setupUI();
        setupTimer();
        setupDigital();
    }
    
    public void setupUI(){
        rootContainer = new GridPane();
        rootContainer.setAlignment(Pos.CENTER);
        rootContainer.getColumnConstraints().add(new ColumnConstraints(150));
        rootContainer.getRowConstraints().add(new RowConstraints(150));
        //rootContainer.setGridLinesVisible(true);
        root = new StackPane();
    
        dialImageView = new ImageView();
        handImageView = new ImageView();

        dial = new Image(getClass().getResourceAsStream("clockface.png"));
        hand = new Image(getClass().getResourceAsStream("hand.png"));
        
        dialImageView.setImage(dial);
        handImageView.setImage(hand);
        
        root.getChildren().addAll(dialImageView, handImageView);
        rootContainer.add(root, 0, 0, 2, 3);
        
        dialog = new TextInputDialog();
        dialog.getDialogPane().lookupButton(ButtonType.CANCEL).setDisable(true);
        dialog.setTitle("Timer Setup");
        dialog.setHeaderText("Set Up Start Time: ");
        dialog.setContentText("Please enter the start time as an integer:");    
        dialog.showAndWait();
        if (dialog.getEditor().getText().length() < 1) {
            dialog.setHeaderText("Please Enter a Value or 10 Will be Used.");
            dialog.showAndWait();
        }
        if(dialog.getEditor().getText().matches("^[0-9]+$") == false) {
            dialog.setHeaderText("Error: Enter Only Numerical Characters or 10 Will be Used.");
            dialog.showAndWait();
        }
        if(dialog.getEditor().getText().matches("^[0-9]+$")) {
            double test = ((Double.valueOf(dialog.getEditor().getText())));
            if (test < 0 || test > 100) {
                dialog.setHeaderText("Error: Enter Values From 0-100 or 10 Will Be Used.");
                dialog.showAndWait();
                test = ((Double.valueOf(dialog.getEditor().getText())));
                if(test >= 0 && test <= 100) startTime = test*60;
            }
            else {
                startTime = test*60;
            }
        }       
        counter = Timer(startTime);   
        
        timer = new Text("Time: \n" + timeString);
        timer.setFont(Font.font(font, FontWeight.BOLD, 18.0));
        timer.setTextAlignment(TextAlignment.LEFT);
        rootContainer.add(timer, 1, 3);
        countDown = new Text("Countdown: \n" + counter);
        countDown.setFont(Font.font(font, FontWeight.BOLD, 18.0));
        countDown.setTextAlignment(TextAlignment.LEFT);
        rootContainer.add(countDown, 1, 4);
 
    }
    
    public void setupDigital() {
        VBox controlButtons = new VBox();        
        Button play = new Button("Start");
        Button record = new Button("Record");
        play.setMaxWidth(Double.MAX_VALUE);
        record.setMaxWidth(Double.MAX_VALUE);
        controlButtons.setAlignment(Pos.BOTTOM_CENTER);
        controlButtons.setSpacing(10);
        controlButtons.setPadding(new Insets(25, 25, 25, 25));
        controlButtons.getChildren().addAll(play, record);
        rootContainer.add(controlButtons, 0, 3, 1, 2);
        label1 = new Text("Record 1:\n" + Timer(secondsElapsed));
        label2 = new Text("Record 2:\n" + Timer(secondsElapsed));
        label3 = new Text("Record 3:\n" + Timer(secondsElapsed));
        champ = new Text("Champion:\n" + Timer(secondsElapsed));
        label1.setFont(Font.font(font, FontWeight.BOLD, 18.0));
        label1.setTextAlignment(TextAlignment.LEFT);
        label2.setFont(Font.font(font, FontWeight.BOLD, 18.0));
        label2.setTextAlignment(TextAlignment.LEFT);
        label3.setFont(Font.font(font, FontWeight.BOLD, 18.0));
        label3.setTextAlignment(TextAlignment.LEFT);
        champ.setFont(Font.font(font, FontWeight.BOLD, 18.0));
        champ.setTextAlignment(TextAlignment.LEFT);
        rootContainer.add(label1, 3, 0);
        rootContainer.add(label2, 3, 1);
        rootContainer.add(label3, 3, 2);
        rootContainer.add(champ, 3, 4);
        
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
    }

    public void setupTimer() {
        keyFrame = new KeyFrame(Duration.millis(1), (ActionEvent actionEvent) -> {
            update();
        });
        timeline = new Timeline(keyFrame);
        timeline.setCycleCount(Animation.INDEFINITE);
    }
    
    private void update() {
        secondsElapsed += tickTimeInSeconds;
        startTime -= tickTimeInSeconds;
        double rotation = secondsElapsed * angleDeltaPerSecond;
        handImageView.setRotate(rotation);  
     
       timeString = ( Timer(secondsElapsed) );
       timer.setText("Time: \n" + timeString);   
       
       if (startTime >= 0) {
           counter = ( Timer(startTime));
           countDown.setText("Countdown: \n" + counter);
       }
       else {
           countDown.setText("Countdown: \nTime's Up!");
       }
        
    }
    
    public void start() {
        timeline.play();
    }
    public void stop() {
        timeline.pause();
    }
    public void reset() {
        secondsElapsed = -0.001;
        label1.setText("Record 1:\n00:00.000");
        label2.setText("Record 2:\n00:00.000");
        label3.setText("Record 3:\n00:00.000");
        startTime = ((Double.valueOf(dialog.getEditor().getText()))*60 + 0.001);
        update();
        timeline.stop();
    }
    public void record() {
        if(startTime > 0) { 
            recordCount++;
            if(recordCount == 1) {
                champ.setText("Champion:\n" + Timer(secondsElapsed));
                label1.setText("Record " + recordCount + ":\n" + Timer(secondsElapsed));
            }
            if(recordCount % 3 == 1) {
                label1.setText("Record " + recordCount + ":\n" + Timer(secondsElapsed-prevTime));
            }
            if(recordCount % 3 == 2) {
                label2.setText("Record " + recordCount + ":\n" + Timer(secondsElapsed-prevTime));
            }
            if(recordCount % 3 == 0) {
                label3.setText("Record " + recordCount + ":\n" + Timer(secondsElapsed-prevTime));
            }
            prevTime = secondsElapsed;
        }
        else {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);                     //all alert commands are referenced from https://code.makery.ch/blog/javafx-dialogs-official/
            alert.setTitle("Out of Time!");
            alert.setHeaderText(null);
            alert.setContentText("Time is up... No more records");
            alert.showAndWait();
        }
    }
    public boolean isRunning() {
        if(timeline != null) {
            if(timeline.getStatus() == Animation.Status.RUNNING) {
                return true;
            }
        }
        return false;   
    }
    /*
        Return type is Parent so that any type of JavaFX Container can be returned
        StackPane, GridPane, AnchorPane, VBox, etc. inherit from parent class
    */
    
    public Parent getRootContainer(){
        return rootContainer;
    }
    
    public Double getWidth(){
        return width;
    }
    
    public Double getHeight(){
        return height;
    }
    
    public void setTickTimeInSeconds(double tickTimeInSeconds) {
        this.tickTimeInSeconds = tickTimeInSeconds;
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




