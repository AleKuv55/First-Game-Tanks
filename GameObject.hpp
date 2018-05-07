//
//  GameObject.hpp
//  Game
//
//  Created by Alexandr Kuznetsov on 03.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp


#include "Vector.hpp"

class GameObject
{
public:
    Vector position_;
    //    Vector v_;
    //    Vector a_;
    //    double m_;
    sf::Sprite spr_;
    sf::RectangleShape rect_;
    int objectType_ = 0;// 2 Tank 1 Enemy 0 Bullet
    int direction_  = 0;
    bool objectAlive = false;
    
    GameObject();
    GameObject(double x, double y, sf::Sprite spr, sf::RectangleShape rect);
    
    
    
    virtual int draw(sf::RenderWindow* window) = 0;
    virtual int update() = 0;
    virtual int collision() = 0;
    
private:
protected:
};



#endif /* GameObject_hpp */
