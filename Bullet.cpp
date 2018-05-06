//
//  Bullet.cpp
//  Game
//
//  Created by Alexandr Kuznetsov on 03.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#include "Bullet.hpp"
#include "GameObject.hpp"

/*Bullet::Bullet() // The First Constructor
{
}*/

Bullet::Bullet(double x, double y, sf::Sprite spr, sf::RectangleShape rect): // The Second Constructor
GameObject(x, y, spr, rect)
{
    //spr_.setScale(0.3f, 0.3f);
    spr_.setPosition(position_.x_, position_.y_);
    spr_.setTextureRect(sf::IntRect(0, 0, 30, 30));
    rect_.setSize(sf::Vector2f(30, 30));
    objectType_ = 0;
    objectAlive = true;
}


int Bullet:: updateBullet()
{
    if (objectAlive == true)
    {
        if (direction_ == 1) // up
        {
            position_.y_ -=  movementSpeed;
        }
        if (direction_ == 2) // right
        {
            position_.x_ +=  movementSpeed;
        }
        if (direction_ == 3) // down
        {
            position_.y_ +=  movementSpeed;
        }
        if (direction_ == 4) // left
        {
            position_.x_ -=  movementSpeed;
        }
        rect_.setPosition(position_.x_, position_.y_);
        spr_.setPosition(position_.x_, position_.y_);
    }
    return 0;
}

int Bullet:: drawBullet(sf::RenderWindow* window)
{
    window -> draw(spr_);
}
