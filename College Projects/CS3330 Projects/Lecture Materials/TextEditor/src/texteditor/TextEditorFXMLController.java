/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package texteditor;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author Professor Wergeles
 */
public class TextEditorFXMLController implements Initializable {
    
    @FXML
    private TextArea textArea; 
    
    @FXML
    private VBox root; 
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }
    
    @FXML
    public void handleOpen(ActionEvent event){
        FileChooser fileChooser = new FileChooser(); 
        
        Stage stage = (Stage) root.getScene().getWindow(); 
        
        fileChooser.getExtensionFilters().add(
            new ExtensionFilter("Text files", "*.txt", "*.html", "*.c")); 
        
        File file = fileChooser.showOpenDialog(stage);
        
        if(file != null){
            
            BufferedReader bufferedReader = null; 
            
            String document = ""; 
            String line = ""; 
            
            try { 
                bufferedReader = new BufferedReader(new FileReader(file));
                
                
                while( (line = bufferedReader.readLine()) != null){
                    document += line + "\n"; 
                }
                
                textArea.setText(document); 
                
                
            } catch (FileNotFoundException fnfex) {
                displayExceptionAlert(fnfex); 
            } catch (IOException ioex) {
                displayExceptionAlert(ioex);
            } finally {
                if(bufferedReader != null){
                    
                    try { 

                        bufferedReader.close();
                    
                    } catch (IOException ioex) {
                        displayExceptionAlert(ioex); 
                 
                    }
                    
                }
            }   
        }
    }
    
    @FXML
    public void handleSave(ActionEvent event){
        FileChooser fileChooser = new FileChooser(); 
        Stage stage = (Stage) root.getScene().getWindow(); 
        
        fileChooser.getExtensionFilters().add(new ExtensionFilter("Text Files", "*.txt")); 
        
        File file = fileChooser.showSaveDialog(stage); 
        
        FileWriter writer = null; 
        
        if(file != null){
            
            try { 
                
                writer = new FileWriter(file);
                
                writer.write(textArea.getText());
                
                
            } catch (IOException ioex) {
                
                displayExceptionAlert(ioex); 
                
            } catch (Exception ex){
                
                displayExceptionAlert(ex); 
                
            } finally {
                
                if(writer != null){
                    
                    try {
                        writer.close();
                    } catch (IOException ioex) {
                        
                        displayExceptionAlert(ioex); 
                    
                    } catch (Exception ex){
                       
                        displayExceptionAlert(ex); 
                    }
                }   
            }   
        }
    }
    
    private void displayExceptionAlert(Exception ex){
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Exception Dialog");
        alert.setHeaderText(ex.getClass().getCanonicalName());
        alert.setContentText(ex.getMessage());
        
        // Create expandable Exception.
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        ex.printStackTrace(pw);
        String exceptionText = sw.toString();

        Label label = new Label("The exception stacktrace was:");

        TextArea textArea = new TextArea(exceptionText);
        textArea.setEditable(false);
        textArea.setWrapText(true);

        textArea.setMaxWidth(Double.MAX_VALUE);
        textArea.setMaxHeight(Double.MAX_VALUE);
        GridPane.setVgrow(textArea, Priority.ALWAYS);
        GridPane.setHgrow(textArea, Priority.ALWAYS);

        GridPane expContent = new GridPane();
        expContent.setMaxWidth(Double.MAX_VALUE);
        expContent.add(label, 0, 0);
        expContent.add(textArea, 0, 1);

        // Set expandable Exception into the dialog pane.
        alert.getDialogPane().setExpandableContent(expContent);

        alert.showAndWait(); 
    }
    
}
