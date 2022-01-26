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
public class Dog extends Pet {
    //instance field (no static keyword)
    private int id;
    
    //class field (static keyword)
    private static int numOfDogs = 0;
    
    //constant field
    private static final String GENUS = "Canis";
    
    //instance field
    private String position = "standing";
    
    public Dog(int age, String name, Gender gender){
        super("Dog", age, name, gender); 
        
        id = ++numOfDogs; //pre increment so that first dog is ID 1, second is ID 2, etc.
    }
    
    //instance method accessing an instance field
    public int getID(){
        return this.id;
       
    }
    
    //class method (static method) accessing a static field
    public static int getNumOfDogs(){
//      return this.numOfDogs; this is not allowed
        return numOfDogs;
    }
    
    //class methods cannot access instance fields
//    public static int getID2(){
//        return id;
//    }
    
    //class method accessing a constant
    public static String getGenus() {
        return GENUS;
    }
    
    //instance methods (non-static) can access class fields (static fields)
    public String getGenus2(){
        return GENUS; //several memory locations can point to one,
    }                 //but one single function can't return multiple instance variable
    
//    @Override
//    public void birthday(){
//        age += 7; 
//    }
    
    
    // polymorphism ... getAge() from Pet will return age directly
    // getAge() from Dog will return age * 7 
    // two getAge() methods both of them are doing different things
    // method overriding 
    @Override
    public int getAge(){
        return age * 7; 
    }
    
    // method overloading 
    // two methods with the same name, printing (or doing) different things     
    public void bark(int num){
        for(int i = 0; i < num; i++){
            System.out.println("Bark!");
        }
    }
    
    public void bark(){
        bark(1); 
    }
    
//    public void bark(){
//        
//    }
    
    // signature is the name and parameter list 
}
