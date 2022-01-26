/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pet;

/**
 *
 * @author Colin
 */
public class pet {

    public static void main(String[] args) {
        Pet pet = new Pet();

        pet.age = 3;
        pet.setName("Maggie");
        pet.gender = Gender.FEMALE;
        pet.type = "Dog";
        
        //Pet pet2 -> Declaration(type and variable name)
        //= new -> Initialization(Creates memory location and returns it
        // Pet() -> Instantiation(sets memore states to initial value
        Pet pet2 = new Pet("Cat", 2, "Kitty", FEMALE);
    }
}
