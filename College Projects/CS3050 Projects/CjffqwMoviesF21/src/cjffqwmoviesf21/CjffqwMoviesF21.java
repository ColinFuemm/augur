/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cjffqwmoviesf21;

import java.text.NumberFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

/**
 *
 * @author Colin Fuemmeler cjffqw
 */
        
public class CjffqwMoviesF21 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Movie movie1 = new Movie("BLACK WIDOW", "Cate Shortland", "2h13m");
        movie1.setGenre( Genre.ACTION );
        movie1.setSummary("Natasha Romanoff, aka Black Widow, confronts the darker parts"
                + " of her ledger when a dangerous conspiracy with ties to her past arises."
                + "Pursued by a force that will stop at nothing to bring her down, "
                + "Natasha must deal with her history as a spy, and the broken relationships "
                + "left in her wake long before she became an Avenger.");
        movie1.setRating("PG-13");
        movie1.setRevenue(181500000);
        movie1.setReleaseDate(6, 9, 2021);
        
        
        Calendar movie2RD = Calendar.getInstance();                             //these two lines referenced from
        movie2RD.set(2020, 10, 25);                                             //https://docs.oracle.com/javase/7/docs/api/java/util/Calendar.html#set(int,%20int,%20int)
        Movie movie2 = new Movie("TOYS OF TERROR", "Nicholas Verso", "Evil toys magically come to life to terrorize a couple and their children inside a secluded mansion.", "R", 0, Genre.HORROR, movie2RD, "1h29m");
        
        Calendar movie3RD = Calendar.getInstance();                             
        movie3RD.set(2019, 8, 27);
        Movie movie3 = new Movie("THE LION KING", "Jon Favreau", "After the murder of his father, a young lion prince flees his kingdom only to learn the true meaning of responsibility and bravery.", Genre.KIDS, movie3RD, "1h58m");
        movie3.setRating("PG");
        movie3.setRevenue(543600000);
        
        Movie movie4 = new Movie();
        movie4.setName("KILLER JOE");
        movie4.setDirector("William Friedkin");
        movie4.setSummary("A cop (Matthew McConaughey) who moonlights as a hit man agrees to kill the hated mother of a desperate drug dealer (Emile Hirsch) in exchange for a tumble with the young man's virginal sister (Juno Temple)");
        movie4.setGenre( Genre.DRAMA );
        movie4.setRating("TVMA");
        movie4.setRevenue(2000000);
        movie4.setReleaseDate(12, 21, 2012);
        movie4.setRuntime("1h41m");
        
        //info on my favorite movie from https://www.imdb.com/title/tt0347149/
        Movie myFavMovie = new Movie("HOWL'S MOVING CASTLE", "Hayao Miyazaki", "1h59m");
        myFavMovie.setGenre( Genre.ANIMATION );
        myFavMovie.setSummary("When an unconfident young woman is cursed with an old body by a spiteful witch, her only chance of breaking the spell lies with a self-indulgent yet insecure young wizard and his companions in his legged, walking castle.");
        myFavMovie.setRating("PG");
        myFavMovie.setRevenue(5576743);
        myFavMovie.setReleaseDate(6, 17, 2005);
        
        //info on movie5 (the sixth movie) from https://www.imdb.com/title/tt1843866/?ref_=fn_tt_tt_9
        Movie movie5 = new Movie("CAPTAIN AMERICA: THE WINTER SOLDIER", "The Russo Brothers", "2h16m");
        movie5.setGenre( Genre.ACTION );
        movie5.setSummary("As Steve Rogers struggles to embrace his role in the modern world, he teams up with a fellow Avenger and S.H.I.E.L.D agent, Black Widow, to battle a new threat from history: an assassin known as the Winter Soldier.");
        movie5.setRating("PG-13");
        movie5.setRevenue(259766572);
        movie5.setReleaseDate(4, 4, 2014);
        
        //info on worstMovie (the seventh movie) from https://www.imdb.com/title/tt1700841/?ref_=nv_sr_srsg_0
        Movie worstMovie = new Movie("SAUSAGE PARTY", "Greg Tiernan", "1h29m");
        worstMovie.setGenre( Genre.COMEDY );
        worstMovie.setSummary("A sausage strives to discover the truth about his existence.");
        worstMovie.setRating("R");
        worstMovie.setRevenue(97685686);
        worstMovie.setReleaseDate(8, 14, 2016);
        
        System.out.println("MOVIE " + movie1.movieID + ":");                     //movie number is automatically tracked and printed accordingly
        System.out.println("Name: " + movie1.getName());
        System.out.println("Director: " + movie1.getDirector());
        System.out.println("Summary: " + movie1.getSummary());
        System.out.println("Genre: " + movie1.getGenre());
        System.out.println("Rating: " + movie1.getRating());
        NumberFormat formatter = NumberFormat.getCurrencyInstance();
        System.out.println("Revenue: " + formatter.format(movie1.getRevenue()));
        Date date = movie1.getReleaseDate().getTime();             
        SimpleDateFormat format1 = new SimpleDateFormat("MMM d, yyyy");          //release date format referenced from
        String inActiveDate = null;                                             //https://intellipaat.com/community/31920/convert-calendar-date-to-yyyy-mm-dd-format-in-java
        inActiveDate = format1.format(date);
        System.out.println("Release Date: " + inActiveDate );
        System.out.println("Runtime: " + movie1.getRuntime());
        System.out.println("Version: " + movie1.getVersion());
        movie1.playMovie();
        System.out.println("");
        
        System.out.println("MOVIE " + movie2.movieID + ":");                     //movie number is automatically tracked and printed accordingly
        System.out.println("Name: " + movie2.getName());
        System.out.println("Director: " + movie2.getDirector());
        System.out.println("Summary: " + movie2.getSummary());
        System.out.println("Genre: " + movie2.getGenre());
        System.out.println("Rating: " + movie2.getRating());
        NumberFormat formatter2 = NumberFormat.getCurrencyInstance();
        System.out.println("Revenue: " + formatter.format(movie2.getRevenue()));
        Date date2 = movie2.getReleaseDate().getTime();                          //release date format referenced from
        String inActiveDate2 = null;                                             //https://intellipaat.com/community/31920/convert-calendar-date-to-yyyy-mm-dd-format-in-java
        inActiveDate2 = format1.format(date);
        System.out.println("Release Date: " + inActiveDate );
        System.out.println("Runtime: " + movie2.getRuntime());
        System.out.println("Version: " + movie2.getVersion());
        movie2.playMovie();
        System.out.println("");
               
        movie3.printMovie();
        movie4.printMovie();
        myFavMovie.printMovie();
        movie5.printMovie();
        worstMovie.printMovie();
        
        System.out.println("Number of Movies: " + Movie.getNumOfMovies());
    }
    
}
