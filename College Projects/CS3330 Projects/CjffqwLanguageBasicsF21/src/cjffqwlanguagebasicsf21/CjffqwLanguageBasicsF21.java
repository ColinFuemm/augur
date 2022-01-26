/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwlanguagebasicsf21;

/**
 *
 * @author Colin
 */
import java.time.LocalTime;
import java.util.Random;

public class CjffqwLanguageBasicsF21 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        char c1 = 'J';
        char c2 = 74;
        short qualityScore = 98;
        float miles = 175.0f;
        float milesPerGallon = 18.5f;
        float gasPrice = 2.85f;
        boolean summer = true;
        boolean sunny = false; 
        LocalTime time = LocalTime.now();                                       //this line and the one after is referenced from
        int hour = time.getHour();                                              //https://zetcode.com/java/localtime/
        double min = 0.0;
        double max = 4.0;
        Random r = new Random();                                                //this line and the one before is referenced from
        double randomValue = min + (max - min) * r.nextDouble();                //https://stackoverflow.com/questions/3680637/generate-a-random-double-in-a-range
        String greeting = "Hi";
        String pawprint = "cjffqw";
    
        Compare(c1, c2);
        QualityAssurance(qualityScore);
        GasCalculator(miles, milesPerGallon, gasPrice);
        WeatherAdvice(summer, sunny);
        CheckTime(hour);
        CheckGrade(randomValue);
        CountFor();
        Greeting(greeting, pawprint);
        
    }
    
    public static void Compare( char a, char b) {
        if (a == b) {
            System.out.println( a + " and " + b + " are the same.");
        }
        if (a != b) {
            System.out.println( a + " and " + b + " are not the same.");
        }
    }
    
    public static void QualityAssurance(short qualityScore) {
        if (qualityScore >= 0 && qualityScore <= 60) {
            System.out.println("The quality is bad");
        }
        if (qualityScore > 60 && qualityScore <= 95) {
            System.out.println("Good Quality.");
        }
        else { System.out.println("Perfect."); }
    }
    
    public static void GasCalculator(float miles, float milesPerGallon, float gasPrice) {
        float gasUsed = miles/milesPerGallon;
        float gasFee = gasUsed*gasPrice;
        
        System.out.println("Total gas used = " + gasUsed + " gallons");
        System.out.println("Total gas fee = $" + gasFee);
    }
    
    public static void WeatherAdvice(boolean summer, boolean sunny) {
        if (sunny == true && summer == true) {
            System.out.println("Go swimming.");
            return;
        }
        if (sunny == true && summer == false) {
            System.out.println("Go hiking.");
            return;
        }
        if (sunny == false && summer == true) {
            System.out.println("Playing Games.");
            return;
        }
        System.out.println("Stay home.");
    }
    
    public static void CheckTime(int hour) {
        switch (hour) {
            case 0: 
                System.out.println("The current time is " + hour + " in the NIGHT");    //switch case syntax found on
                break;                                                                  //https://docs.oracle.com/javase/tutorial/java/nutsandbolts/switch.html
            case 1: 
                System.out.println("The current time is " + hour + " in the NIGHT");
                break;
            case 2: 
                System.out.println("The current time is " + hour + " in the NIGHT");
                break;
            case 3: 
                System.out.println("The current time is " + hour + " in the NIGHT");
                break;
            case 4: 
                System.out.println("The current time is " + hour + " in the NIGHT");
                break;
            case 5: 
                System.out.println("The current time is " + hour + " in the MORNING");
                break;
            case 6: 
                System.out.println("The current time is " + hour + " in the MORNING");
                break;
            case 7: 
                System.out.println("The current time is " + hour + " in the MORNING");
                break;
            case 8: 
                System.out.println("The current time is " + hour + " in the MORNING");
                break;
            case 9: 
                System.out.println("The current time is " + hour + " in the MORNING");
                break; 
            case 10: 
                System.out.println("The current time is " + hour + " in the MORNING");
                break;
            case 11: 
                System.out.println("The current time is " + hour + " in the AFTERNOON");
                break;
            case 12: 
                System.out.println("The current time is " + hour + " in the AFTERNOON");
                break;
            case 13: 
                System.out.println("The current time is " + hour + " in the AFTERNOON");
                break;
            case 14: 
                System.out.println("The current time is " + hour + " in the AFTERNOON");
                break;
            case 15: 
                System.out.println("The current time is " + hour + " in the AFTERNOON");
                break;
            case 16: 
                System.out.println("The current time is " + hour + " in the AFTERNOON");
                break;
            case 17: 
                System.out.println("The current time is " + hour + " in the EVENING");
                break;
            case 18: 
                System.out.println("The current time is " + hour + " in the EVENING");
                break;
            case 19: 
                System.out.println("The current time is " + hour + " in the EVENING");
                break;
            case 20: 
                System.out.println("The current time is " + hour + " in the EVENING");
                break;
            case 21: 
                System.out.println("The current time is " + hour + " in the EVENING");
                break;
            case 22: 
                System.out.println("The current time is " + hour + " in the EVENING");
                break;
            case 23: 
                System.out.println("The current time is " + hour + " in the NIGHT");
                break;
            default: 
                System.out.println("You have the wrong time.");
                break;
        }
    }
    
    public static void CheckGrade(double randomValue) {
        if (randomValue >= 0.00 && randomValue < 0.70) { System.out.println("The student's GPA is an F in the class."); }
        if (randomValue >= 0.70 && randomValue < 1.70) { System.out.println("The student's GPA is a D- to D+ in the class."); }
        if (randomValue >= 1.70 && randomValue < 2.70) { System.out.println("The student's GPA is a C- to C+ in the class."); }
        if (randomValue >= 2.70 && randomValue < 3.70) { System.out.println("The student's GPA is a B- to B+ in the class."); }
        if (randomValue >= 3.70) { System.out.println("The student's GPA is a A- to A+ in the class."); }
    }
    
    public static void CountFor() {
        for(int i = 1; i < 31; i++) {
            if ((i % 7) == 0 || (i % 9) == 0) {
                System.out.println("Count: " + i);
            }    
        }
        int countDown = 3;
        while(countDown > 0) {
            System.out.println("Count Down: " + countDown);
            countDown--;
        }
        if(countDown == 0) System.out.println("Go!");
    }
    
    public static void Greeting(String greeting, String pawprint) {
        System.out.println( greeting + ", my pawprint is "+ pawprint + " and today's date is " + (java.time.LocalDate.now()) + " " + (java.time.LocalTime.now())); 
        //this code is cut from Challenge 2, and by extension is referenced from https://www.javatpoint.com/java-get-current-date
    }
}
