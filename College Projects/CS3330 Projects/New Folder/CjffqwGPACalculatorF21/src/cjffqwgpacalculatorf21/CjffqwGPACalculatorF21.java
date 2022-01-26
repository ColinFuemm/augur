/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwgpacalculatorf21;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;

/**
 *
 * @author Colin cjffqw
 */
public class CjffqwGPACalculatorF21 extends Application {
    
    private String title = "GPA Calculator";
    private int width = 500;
    private int height = 425;
    
    private String font = "Verdana"; //cjffqw
    
    @Override
    public void start(Stage primaryStage) {
        
        GridPane root = new GridPane();                                         //Gridpane setup and adding labels referenced from
        root.setVgap(10);
        root.setHgap(10);
        root.setAlignment(Pos.BASELINE_CENTER);                                 //LoginForm script from 9-13 lecture
        root.setPadding(new Insets(15,15,15,15));
        
        Label course1 = new Label("Course 1: ");
        course1.setFont(Font.font(font, FontWeight.NORMAL, 13));
        root.add(course1, 0, 0);
        
        TextField score1 = new TextField();
        score1.setPrefWidth(350);                                               //setPrefWidth found on https://stackoverflow.com/questions/19843469/set-textfield-width-in-javafx
        root.add(score1, 1, 0);
        
        Label course2 = new Label("Course 2: ");
        course2.setFont(Font.font(font, FontWeight.NORMAL, 13));
        root.add(course2, 0, 1);
        
        TextField score2 = new TextField();
        score2.setPrefWidth(350);
        root.add(score2, 1, 1);
        
        Label course3 = new Label("Course 3: ");
        course3.setFont(Font.font(font, FontWeight.NORMAL, 13));
        root.add(course3, 0, 2);
        
        TextField score3 = new TextField();
        score3.setPrefWidth(350);
        root.add(score3, 1, 2);
        
        Label course4 = new Label("Course 4: ");
        course4.setFont(Font.font(font, FontWeight.NORMAL, 13));
        root.add(course4, 0, 3);
        
        TextField score4 = new TextField();
        score4.setPrefWidth(350);
        root.add(score4, 1, 3);                                                 //end LoginForm reference
                                                                                //cjffqw
        Label label = new Label("Information: ");
        label.setFont(Font.font(font, FontWeight.NORMAL, 13));
        root.add(label, 0, 4, 2, 1);
        
        TextArea infoArea = new TextArea();
        infoArea.setFont(Font.font(font, FontWeight.NORMAL, 14));
        infoArea.setPrefRowCount(3);
        infoArea.setWrapText(true);
        infoArea.setEditable(false);
        root.add(infoArea, 0, 5, 2, 1);
        
        Button button1 = new Button("Calculate GPA Score");
        button1.setMaxWidth(Double.MAX_VALUE);
        Button button2 = new Button("Show Statistics");
        button2.setMaxWidth(Double.MAX_VALUE);
        Button button3 = new Button("Alert");
        button3.setMaxWidth(Double.MAX_VALUE);
        Button button4 = new Button("Clear All");
        button4.setMaxWidth(Double.MAX_VALUE);
        
        button1.setOnAction((ActionEvent e) -> {
            //Retrieve textfield info cjffqw
            String field1 = score1.getText();
            String field2 = score2.getText();
            String field3 = score3.getText();
            String field4 = score4.getText();
            Double data1, data2, data3, data4, average;
            char grade = 'F';
            
            Alert alert = new Alert(AlertType.INFORMATION);                     //all alert commands are referenced from https://code.makery.ch/blog/javafx-dialogs-official/
            alert.setTitle("Error");
            alert.setHeaderText(null);
            
            if(field1.length() < 1 || field2.length() < 1 || field3.length() < 1 || field4.length() < 1) { //referenced from LoginForm
                alert.setContentText("Error: Please Enter Values in All Four Fields");
                alert.showAndWait();
                return;
            }
            if(field1.matches("^[0-9]+$")) {
                data1 = Double.valueOf(field1);
                if (data1 < 0 || data1 > 100) {
                    alert.setContentText("Error: Please Enter Values Between 0 and 100");
                    alert.showAndWait();
                    return;
                }
            }
            else {
                alert.setContentText("Error: Please Enter Only Numerical Values");
                alert.showAndWait();
                return;
            }
            if(field2.matches("^[0-9]+$")) { //cjffqw
                data2 = Double.valueOf(field2);
                if (data2 < 0 || data2 > 100) {
                    alert.setContentText("Error: Please Enter Values Between 0 and 100");
                    alert.showAndWait();
                    return;
                }
            }
            else {
                alert.setContentText("Error: Please Enter Only Numerical Values");
                alert.showAndWait();
                return;
            }
            if(field3.matches("^[0-9]+$")) {
                data3 = Double.valueOf(field3);
                if (data3 < 0 || data3 > 100) {
                    alert.setContentText("Error: Please Enter Values Between 0 and 100");
                    alert.showAndWait();
                    return;
                }
            }
            else {
                alert.setContentText("Error: Please Enter Only Numerical Values");
                alert.showAndWait();
                return;
            }
            if(field4.matches("^[0-9]+$")) {
                data4 = Double.valueOf(field4);
                if (data4 < 0 || data4 > 100) {
                    alert.setContentText("Error: Please Enter Values Between 0 and 100");
                    alert.showAndWait();
                    return;
                }
            }
            else {
                alert.setContentText("Error: Please Enter Only Numerical Values");
                alert.showAndWait();
                return;
            }
            //calculate GPA cjffqw
            average = (data1 + data2 + data3 + data4)/4;
            if (average >= 60) grade = 'D';
            if (average >= 67) grade = 'C';
            if (average >= 77) grade = 'B';
            if (average >= 87) grade = 'A';
            infoArea.setText("Your average score is: " + average + "\nYour GPA is: " + grade);
        });
        
        button2.setOnAction((ActionEvent e) -> {
            
            String field1 = score1.getText();
            String field2 = score2.getText();
            String field3 = score3.getText();
            String field4 = score4.getText();
            Double data1, data2, data3, data4;
            
            Alert alert = new Alert(AlertType.INFORMATION);
            alert.setTitle("Error");
            alert.setHeaderText(null);
            
            if(field1.length() < 1 || field2.length() < 1 || field3.length() < 1 || field4.length() < 1) {
                alert.setContentText("Error: Please Enter Values in All Four Fields");
                alert.showAndWait();
                return;
            }
            if(field1.matches("^[0-9]+$")) {
                data1 = Double.valueOf(field1);
                if (data1 < 0 || data1 > 100) {
                    alert.setContentText("Error: Please Enter Values Between 0 and 100");
                    alert.showAndWait();
                    return;
                }
            } //cjffqw
            else {
                alert.setContentText("Error: Please Enter Only Numerical Values");
                alert.showAndWait();
                return;
            }
            if(field2.matches("^[0-9]+$")) {
                data2 = Double.valueOf(field2);
                if (data2 < 0 || data2 > 100) {
                    alert.setContentText("Error: Please Enter Values Between 0 and 100");
                    alert.showAndWait();
                    return;
                }
            }
            else {
                alert.setContentText("Error: Please Enter Only Numerical Values");
                alert.showAndWait();
                return;
            }
            if(field3.matches("^[0-9]+$")) { //cjffq    w
                data3 = Double.valueOf(field3);
                if (data3 < 0 || data3 > 100) {
                    alert.setContentText("Error: Please Enter Values Between 0 and 100");
                    alert.showAndWait();
                    return;
                }
            }
            else {
                alert.setContentText("Error: Please Enter Only Numerical Values");
                alert.showAndWait();
                return;
            }
            if(field4.matches("^[0-9]+$")) {
                data4 = Double.valueOf(field4);
                if (data4 < 0 || data4 > 100) {
                    alert.setContentText("Error: Please Enter Values Between 0 and 100");
                    alert.showAndWait();
                    return;
                }
            }
            else {
                alert.setContentText("Error: Please Enter Only Numerical Values");
                alert.showAndWait();
                return;
            }
            double greatest = 0;
            double least = 0;
            if(data1 >= data2 && data1 >= data3 && data1 >= data4) {
                greatest = data1;
            }
            if(data2 >= data1 && data2 >= data3 && data2 >= data4) {
                greatest = data2;
            }
            if(data3 >= data2 && data3 >= data1 && data3 >= data4) {
                greatest = data3;
            }
            if(data4 >= data1 && data4 >= data3 && data4 >= data2) {
                greatest = data4;
            }
            if(data1 <= data2 && data1 <= data3 && data1 <= data4) {
                least = data1;
            }
            if(data2 <= data1 && data2 <= data3 && data2 <= data4) {
                least = data2;
            }
            if(data3 <= data2 && data3 <= data1 && data3 <= data4) {
                least = data3;
            }
            if(data4 <= data1 && data4 <= data3 && data4 <= data2) {
                least = data4;
            }
            infoArea.setText("Your highest score is: " + greatest +
                    "\nYour lowest score is: " + least);
        });
        
        button3.setOnAction((ActionEvent e) -> { //cjffqw
            Alert alert = new Alert(AlertType.INFORMATION);
            alert.setTitle("Info Box Contents");
            alert.setHeaderText(null);
            if(infoArea.getText().length() < 1) {
                alert.setContentText("There is nothing to display");
            }
            else {
                String string = infoArea.getText();
                alert.setContentText(string);
            }
            alert.showAndWait();
        });
        
        button4.setOnAction((ActionEvent e) -> { //cjffqw
            infoArea.setText("");
            score1.setText("");
            score2.setText("");
            score3.setText("");
            score4.setText("");
        });
       
                
        VBox vbox = new VBox(10);
        vbox.setAlignment(Pos.CENTER);                                          //VBox documentation found at https://docs.oracle.com/javase/8/javafx/api/javafx/scene/layout/VBox.html
        vbox.getChildren().addAll(button1, button2, button3, button4);
        root.add(vbox, 0, 6, 2, 1);
        
        
        //debugging tool
        root.setGridLinesVisible(true);
        
        Scene scene = new Scene(root, width, height);
        
        primaryStage.setScene(scene);
        
        primaryStage.setTitle(title);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) { //cjffqw
        launch(args);
    }
    
}

