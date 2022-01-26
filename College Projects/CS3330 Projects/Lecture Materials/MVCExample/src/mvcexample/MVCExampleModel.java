/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvcexample;

import java.util.ArrayList;

/**
 *
 * @author Professor Wergeles
 */
public class MVCExampleModel {
    
    private ArrayList<String> people; 
    
    public MVCExampleModel(){
        people = new ArrayList<String>(); 
    }
    
    public boolean addPerson(String person){
        return people.add(person); 
    }
    
    public ArrayList<String> getEveryone(){
        return people; 
    }
    
    public boolean deleteEveryone(){
        people.clear();
        
        return people.isEmpty(); 
    }   
}