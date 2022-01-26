/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwhelloworldf21;

import java.text.Format;
import java.text.SimpleDateFormat;
import java.util.Date;
    

/**
 *
 * @author Colin Fuemmeler cjffqw
 */
public class CjffqwHelloWorldF21 {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        String name = "Colin";
        String myCourseNum = "CS3330";
        
        print(name, myCourseNum);
    }
    
    public static void print(String name, String myCourseNum) {
        System.out.println("Hello World! My name is " + name);
        System.out.println("My course number is " + myCourseNum);
        Format day = new SimpleDateFormat("EEEE");                                  //This code is based on an example found on
        String str = day.format(new Date());                                        //https://www.tutorialspoint.com/java-program-to-get-full-day-name
        System.out.println("Today is " + str);                                      //while the last two lines are from
        System.out.println("Today's date is " + (java.time.LocalDate.now()));       //https://www.javatpoint.com/java-get-current-date
        System.out.println("The current time is " + (java.time.LocalTime.now()));   //end reference
    }
    
}
