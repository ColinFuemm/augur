/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sensus;

import javafx.scene.image.Image;

/**
 *
 * @author Colin
 */
public abstract class Entity {
    public MapNode position;
    
    public Image identity; //character representation on screen
    
    public Entity() {
        
    }
    
    public Entity(int x, int y, Image image) {
        identity = image;
        Move(MapNode.getNode(x, y));
    }
    
    void Move(MapNode node) {
        if(node.entity != null) {
            position = node;
        }
    }
    
}

