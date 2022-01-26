/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package loginform;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 *
 * @author Colin
 */
public class LoginForm extends Application {
    
    private String title = "My JavaFX Login";
    private int width = 600;
    private int height = 400;
    
    private String sceneTitleText = "Welcome Please Login";
    private String font = "Comic Sans MS";
    
    @Override
    public void start(Stage primaryStage) {
        
        GridPane root = new GridPane();
        root.setAlignment(Pos.CENTER);
        root.setVgap(20);
        root.setHgap(20);
        root.setPadding(new Insets(25,25,25,25));
        
        Text sceneTitle = new Text(sceneTitleText);
        sceneTitle.setFont(Font.font(font, FontWeight.BOLD, 26.0));
        //root.add(sceneTitle, 0, 0);
        root.add(sceneTitle, 0, 0, 2, 1);
        
        Label username = new Label("Username: ");
        username.setFont(Font.font(font, FontWeight.NORMAL, 18));
        root.add(username, 0, 1);
        
        TextField usernameTextField = new TextField();
        root.add(usernameTextField, 1, 1);
        
        Label password = new Label("Password: ");
        password.setFont(Font.font(font, FontWeight.NORMAL, 18));
        root.add(password, 0, 2);
        
        PasswordField passwordInput = new PasswordField();
        root.add(passwordInput, 1, 2);
        
        //debugging tool
        //root.setGridLinesVisible(true);
        
        Button button = new Button("Sign In");
        HBox hboxForButton = new HBox(10);
        hboxForButton.setAlignment(Pos.BOTTOM_RIGHT);
        hboxForButton.getChildren().add(button);
        root.add(hboxForButton, 1, 4);
        
        Text actionTarget = new Text();
        GridPane.setColumnIndex(actionTarget, 1);
        GridPane.setRowIndex(actionTarget, 4);
        root.getChildren().add(actionTarget);
        
        button.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent e) {
                System.out.println("Sign in pressed.");
                actionTarget.setFill(Color.FIREBRICK);
                actionTarget.setText("Sign in pressed");
                
                if(usernameTextField.getText().length() < 1) {
                    actionTarget.setText("WHERE IS THE USERNAME");
                }
                else {
                    //continue
                }
                
                
            }
        });
        
        Scene scene = new Scene(root, width, height);
        
        primaryStage.setScene(scene);
        
        primaryStage.setTitle(title);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
