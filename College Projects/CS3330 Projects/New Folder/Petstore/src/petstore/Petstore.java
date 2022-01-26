/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package petstore;

import static petstore.Gender.FEMALE;
import static petstore.Gender.MALE;

/**
 *
 * @author Professor Wergeles <Professor Wergeles at cs3330@missouri.edu>
 */

// This is the main class, it's the main class because it has the same name as the project 
// also it has the main method in it 
public class Petstore {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Pet pet = new Pet(); 
     
        pet.age = 3;
        pet.setName("Maggie");
        pet.gender = Gender.FEMALE;
        pet.type = "Dog"; 
        
        // Pet pet2 -> Declaration (Type and Variable Name)
        // = new -> Initialization (Creates a memory location and returns reference (pointer) to that memory location)
        // Pet() -> Instantiation (Sets the memory location states (fields, variables) to a initial value) 
        Pet pet2 = new Pet("Cat", 2, "Kitty", FEMALE); 
        
        String petName = pet.getName(); 
        
        System.out.println("Pet 1 Name: " + petName); 
        
        System.out.println("Pet 2 Name: " + pet2.getName());
        
        // main method from lecture 03 
        
        Dog dog = new Dog(3, "Fido", Gender.MALE);
        
        System.out.println(dog.getName() + " is " + dog.getAge() + " years old");
        
        dog.birthday();
        
        System.out.println(dog.getName() + " is " + dog.getAge() + " years old");
        
        Dog dog2 = new Dog(11, "Halo", MALE); 
        
        System.out.println(dog2.getName() + " is " + dog2.getAge() + " years old");
        
        //9/3/21 notes
        
        Cat c1 = new Cat(2, "Susan", FEMALE);
        
        //implicit casting -> compiler knows all cats are pets via extends keyword
        //this is a key definition of polymorphism
        Pet pet3 = c1; //brings cat up into pet subclass
        //in this moment, cat-specific traits cannot be accessed, they are hidden
        
        //Cat c2 = pet3; <----- pet cannot move down into subclass
        
        if (pet3 instanceof Cat) {
            Cat c2 = (Cat)pet3;
        }
        //doable with explicit casting IF pet was originally a cat
        //cat-specific traits are once again accessible
        
        Pet test = new Pet("Cat", 2, "No", FEMALE);
        
        if(test instanceof Cat){
            Cat test2 = (Cat) test;
        }
        
        //9-8-21 notes
        
        Pet pet4 = new Dog(2, "Poly", FEMALE);
        Pet pet5 = new Cat(2, "Poly", MALE);
        //pet4.~~~ & pet5.~~~ cannot access dog and cat members at this point
        
        //9-19-21 notes
        
        System.out.println("Number of Dogs Created: " + Dog.getNumOfDogs());
        
        Dog dog3 = new Dog(21, "Test", FEMALE);
        
        System.out.println("Number of Dogs Created: " + Dog.getNumOfDogs());
       
        System.out.println("Test Dog's id: " + dog3.getID());
        
    }
    
}
