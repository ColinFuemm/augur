/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sensus;

/**
 *
 * @author Colin
 */
public enum Element {
    FIRE, WATER, EARTH, AIR, SHOCK, ICE;
    //Fire beats ice & air, loses to earth & water
    //Water beats earth & fire, loses to shock & air
    //Earth beats fire & shock, loses to air & water
    //Air beats earth & water, loses to fire & ice
    //Shock beats water, loses to earth
    //Ice beats air, loses to fire
}
