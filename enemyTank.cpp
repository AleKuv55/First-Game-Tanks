//
//  enemyTank.cpp
//  Game
//
//  Created by Alexandr Kuznetsov on 05.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#include "enemyTank.hpp"
enemyTank::enemyTank(double x, double y, sf::Sprite spr, sf::RectangleShape rect):
GameObject(x, y, spr, rect)
{
//    rect_.setFillColor(sf::Color::Green);
    objectType_ = 1;
    objectAlive = true;
}

int enemyTank::updatenemyTank()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (1)
        {
            direction_ = 1;
            spr_.setPosition(position_.x_, position_.y_);
            
            position_.y_ -= movementSpeed;
            //                printf("y = %f", tank1.position_.y_);
            //tank1.rect_.move(0,1);
            
            spr_.setTextureRect(sf::IntRect(0 * 200, 0, 195, 300));
            
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (1)
        {
            direction_ = 2;
            
            spr_.setPosition(position_.x_, position_.y_);
            
            position_.x_ += movementSpeed;
            //                printf("y = %f", tank1.position_.y_);
            //tank1.rect_.move(0,1);
            
            spr_.setTextureRect(sf::IntRect(1 * 200, 0, 200, 300));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (1)
        {
            direction_ = 3;
            
            spr_.setPosition(position_.x_, position_.y_);
            
            position_.y_ += movementSpeed;
            //                printf("y = %f", tank1.position_.y_);
            //tank1.rect_.move(0,1);
            
            spr_.setTextureRect(sf::IntRect(2 * 204, 0, 200, 300));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (1)
        {
            direction_ = 4;
            
            spr_.setPosition(position_.x_, position_.y_);
            
            position_.x_ -= movementSpeed;
            //                printf("y = %f", tank1.position_.y_);
            //tank1.rect_.move(0,1);
            
            spr_.setTextureRect(sf::IntRect(3 * 200, 0, 200, 300));
        }
    }
    return 0;
}


int enemyTank::drawenemyTank(sf::RenderWindow* window)
{
    window -> draw(spr_);
}
