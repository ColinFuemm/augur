/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwmoviesf21;

/**
 *
 * @author Colin
 */
import java.util.Calendar;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.text.NumberFormat;

public class Movie {
    
    private String name;
    private String director;
    private String summary;
    private String rating;
    private double revenue;
    private Genre genre;
    private Calendar releaseDate = Calendar.getInstance();
    private String runtime;
    private int version;
    public static int numOfMovies;
    public int movieID;
    
    public Movie() {                                                            //these four constructors are modeled 
        this.version = 0;                                                       //after the petstore constructors discussed in
        this.name = "";                                                         //lecture on 9/8/21
        this.director = "";
        this.releaseDate.set(1988, 10, 14);                                     //setter method found in java docs https://docs.oracle.com/javase/7/docs/api/java/util/Calendar.html#set(int,%20int,%20int)
        this.movieID = ++numOfMovies;                                           //movie id correlating with num of movies is an idea derived from lecture
    }
    
    public Movie(String name, String director, String runtime) {
        this();
        this.name = name;
        this.director = director;
        this.runtime = runtime;
    }
    
    public Movie(String name, String director, String summary, Genre genre, Calendar releaseDate, String runtime) {
        this(name, director, runtime);
        this.summary = summary;
        this.genre = genre;
        this.releaseDate = releaseDate;
        this.version = 1;
    }
    
    public Movie(String name, String director, String summary, String rating, double revenue, Genre genre, Calendar releaseDate, String runtime) {
        this(name, director, summary, genre, releaseDate, runtime);
        this.rating = rating;
        this.revenue = revenue;
    }                                                                           //end reference
    
    public void setName(String name) {
        this.name = name;
        this.version += 1;
    }
    public void setDirector(String director) {
        this.director = director;
        this.version += 1;
    }   
    public void setRating(String rating) {
        this.rating = rating;
        this.version += 1;
    }    
    public void setRevenue(double revenue) {
        this.revenue = revenue;
    }    
    public void setReleaseDate(Calendar releaseDate) {
        this.releaseDate = releaseDate;
        this.version += 1;
    }
    public void setReleaseDate(int month, int day, int year) {                  //utilizing method overloading, I created a function
        Calendar date = Calendar.getInstance();                                 //that can set the release date using corresponding
        date.set(year, month, day);                                             //intger values, therby eliminating the need to use
        this.releaseDate = date;                                                //Calendars in the main function.
        this.version += 1;
    }
    public void setGenre(Genre genre) {
        this.genre = genre;
        this.version += 1;
    }    
    public void setSummary(String summary) {
        this.summary = summary;
        this.version += 1;
    }    
    public void setRuntime(String runtime) {
        this.runtime = runtime;
    }
    
    public String getName() {
        return this.name;
    }
    public String getDirector() {
        return this.director;
    }
    public String getRating() {
        return this.rating;
    }
    public double getRevenue() {
        return this.revenue;
    }
    public Calendar getReleaseDate() {
        return this.releaseDate;
    }
    public Genre getGenre() {
        return this.genre;
    }                
    public String getSummary() {
        return this.summary;
    }
    public int getVersion() {
        return this.version;
    }
    public String getRuntime() {
        return this.runtime;
    }
    public static int getNumOfMovies() {
        return numOfMovies;                                                     //static getter derived from 9-10 lecture
    }
    
    public void printMovie() {
        System.out.println("MOVIE " + this.movieID + ":");                     //movie number is automatically tracked and printed accordingly
        System.out.println("Name: " + this.name);
        System.out.println("Director: " + this.director);
        System.out.println("Summary: " + this.summary);
        System.out.println("Genre: " + this.genre);
        System.out.println("Rating: " + this.rating);
        NumberFormat formatter = NumberFormat.getCurrencyInstance();
        System.out.println("Revenue: " + formatter.format(this.revenue));
        Date date = this.releaseDate.getTime();             
        SimpleDateFormat format1 = new SimpleDateFormat("MMM d, yyyy");          //release date format referenced from
        String inActiveDate = null;                                             //https://intellipaat.com/community/31920/convert-calendar-date-to-yyyy-mm-dd-format-in-java
        inActiveDate = format1.format(date);
        System.out.println("Release Date: " + inActiveDate );
        System.out.println("Runtime: " + this.runtime);
        System.out.println("Version: " + this.version);
        playMovie();
        System.out.println("");
    }
    
    public void playMovie() {
        Calendar timer = Calendar.getInstance();
        Date date = timer.getTime();
        SimpleDateFormat format2 = new SimpleDateFormat("MM-dd-yyyy h:mm a");
        String current = format2.format(date);
        System.out.println("The runtime of " + this.getName() + " is " + this.getRuntime());
        System.out.println("The current time is " + current);
        String string = this.getRuntime();
        int hours = Integer.parseInt(string.substring(0, string.indexOf("h")));  //referenced from https://stackoverflow.com/questions/14974033/extract-digits-from-string-stringutils-java
        int minutes = Integer.parseInt(string.substring(string.indexOf("h") + 1, string.indexOf("m"))); // and https://codingbat.com/doc/java-string-indexof-parsing.html
        minutes = minutes += (60 * hours);
        timer.add( Calendar.MINUTE, minutes );                                  //add function and minute member found on https://docs.oracle.com/javase/7/docs/api/java/util/Calendar.html#
        date = timer.getTime();
        String future = format2.format(date);
        System.out.println(this.getName() + " will end at " + future);
        
    }
}
