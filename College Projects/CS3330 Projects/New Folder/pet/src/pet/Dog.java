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
public class Dog extends PetInfo {
    
    public Dog(int age, String name, Gender gender) {
        super("Dog", age, name, gender);
    }
    
    public void birthday(){
        age += 7;
    }
}
