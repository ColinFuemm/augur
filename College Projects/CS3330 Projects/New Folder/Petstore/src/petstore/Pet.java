/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package petstore;

/**
 *
 * @author Professor Wergeles <Professor Wergeles at cs3330@missouri.edu>
 */
public class Pet {
        
    // states 
    public String type; 
    public int age; 
    private String name; 
    public Gender gender; 
    
    private static int numOfPets = 0;
    
    // special method -> constructor 
    // Constructor has the same name as the class 
    // Constructor has no return type
    public Pet(){
        age = 0;
        name = "";
        numOfPets++;
    }
    
    public Pet(String type, String name) {
        this();
        this.type = type;
        //this.name = name + " is a Pet";
        this.name = name;
    }
    
    //these constructors are now linked, and the lowest constructor listed
    //calls the ones above before itself running to initialize the rest of the values
    
    public Pet(String type, int age, String name, Gender gender){
        this(type, name);
        //this.type = type;        
        //this.name = name; 
        this.age = age;
        this.gender = gender; 
    }
    
    // behaviors 
    public void setName(String name){
        this.name = name; 
    }
    
    public String getName(){
        return this.name; 
    }
    
    public void birthday(){
        this.age++;
    }
    public int getAge(){
        return this.age; 
    }
    
    public String getType(){
        return this.type; 
    }
    
}
