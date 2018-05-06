//
//  wall.cpp
//  Game
//
//  Created by Alexandr Kuznetsov on 05.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#include "wall.hpp"
wall::wall():
GameObject()
{
    rect_.setSize(sf::Vector2f(102, 102));
    //rect_.setPosition(0, 0);
    rect_.setFillColor(sf::Color::Blue);
//    spr_.setPosition(rect_.getPosition());
//    spr_.setTextureRect(sf::IntRect(0, 0, 10, 10));
    objectAlive = true;
    objectType_ = 3;
}


int wall::updateWall()
{
   //sprite.setPosition(rect.getPosition());
}

int wall:: draWall(sf::RenderWindow* window)
{
    window -> draw(rect_);
}
