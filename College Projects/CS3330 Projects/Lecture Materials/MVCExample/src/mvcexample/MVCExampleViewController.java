/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvcexample;

import java.net.URL;
import java.util.Optional;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.VBox;

/**
 * FXML Controller class
 *
 * @author Professor Wergeles
 */
public class MVCExampleViewController implements Initializable {

    @FXML
    private VBox root;
    @FXML
    private MenuItem addPerson;
    @FXML
    private MenuItem getEveryone;
    @FXML
    private MenuItem deleteEveryone;
    @FXML
    private TextArea textArea;
   @FXML
   private TextField textField;
    
    MVCExampleModel model = new MVCExampleModel();
    TextInputDialog dialog; 

    @FXML
    public void addPersonButton(ActionEvent event){
        dialog = new TextInputDialog(); 
        dialog.setContentText("Please enter person's name:"); 
        
        Optional<String> result = dialog.showAndWait(); 
        
        System.out.println("Result: " + result.toString()); 
        System.out.println("Result2: " + result.get());
        
        if(result.isPresent()){
            if( model.addPerson( result.get() ) ){
                textArea.setText("Person: " + result.get() + " was added succesfully!");
            }
            else {
                textArea.setText("Count not add person: " + result.get() );
            }
        }
    }
    
    @FXML
    public void getEveryoneButton(ActionEvent event){
        textArea.setText(model.getEveryone().toString()); 
    }
    
    @FXML
    public void deleteEveryoneButton(ActionEvent event){
        if(model.deleteEveryone()){
            textArea.setText("Everyone was deleted succesfully!"); 
        }
        else {
            textArea.setText("Could not delete everyone");
        }
    }
   
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
