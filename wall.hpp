//
//  wall.hpp
//  Game
//
//  Created by Alexandr Kuznetsov on 05.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#ifndef wall_hpp
#define wall_hpp
#include "GameObject.hpp"

class wall: public GameObject
{
public:
    bool destructable = false;
    int hp = 10;
    bool destroy = false;
    
    wall();
    wall(double x, double y, sf::Sprite spr, sf::RectangleShape rect);
    int updateWall();
    
    int draWall(sf::RenderWindow* window);
    
    virtual int draw(sf::RenderWindow* window) override;
    virtual int update() override;
    virtual int collision() override;

};

#endif /* wall_hpp */
