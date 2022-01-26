/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package petstore;

/**
 *
 * @author Colin
 */
public class Cat extends Pet {
    
    public Cat(int age, String name, Gender gender) {
        //this. age = age <-- unecessary
        super("Cat", age, name, gender);
        
    } 
    //Method Overloading
    public void meow(int num) {
        for(int i = 0; i < num; i++) {
            System.out.println("meow.");
        }
    }
    
    public void meow(){
        meow(1);
    }
    
    public String meow(String noise){
        System.out.println(noise);
        return noise;
    }
    
    //method overriding
    @Override
    public int getAge(){
        return age * 7;
    }
    
}



