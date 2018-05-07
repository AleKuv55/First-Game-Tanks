//
//  Tank.cpp
//  Game
//
//  Created by Alexandr Kuznetsov on 03.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#include "Tank.hpp"
//#include "GameObject.hpp"


Tank::Tank(double x, double y, sf::Sprite spr, sf::RectangleShape rect):
    GameObject(x, y, spr, rect)
{
    direction_  = 1;
    objectType_ = 2;
    objectAlive = true;
}

int Tank::updateTank()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (canMoveUp == true)
        {
            canMoveUp    = true;
            canMoveRight = true;
            canMoveDown  = true;
            canMoveLeft  = true;
            direction_ = 1;
            spr_.setPosition(position_.x_, position_.y_);
            rect_.setPosition(position_.x_, position_.y_);
            position_.y_ -= movementSpeed;
            //                printf("y = %f", tank1.position_.y_);
            //tank1.rect_.move(0,1);
            
            spr_.setTextureRect(sf::IntRect(0 * 100, 0, 100, 100));
            
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (canMoveRight == true)
        {
            canMoveUp    = true;
            canMoveRight = true;
            canMoveDown  = true;
            canMoveLeft  = true;
            direction_ = 2;

            spr_.setPosition(position_.x_, position_.y_);
            rect_.setPosition(position_.x_, position_.y_);

            position_.x_ += movementSpeed;
            //                printf("y = %f", tank1.position_.y_);
            //tank1.rect_.move(0,1);
            
            spr_.setTextureRect(sf::IntRect(1 * 100, 0, 100, 100));
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (canMoveDown == true)
        {
            canMoveUp    = true;
            canMoveRight = true;
            canMoveDown  = true;
            canMoveLeft  = true;
            direction_ = 3;
            
            spr_.setPosition(position_.x_, position_.y_);
            rect_.setPosition(position_.x_, position_.y_);

            position_.y_ += movementSpeed;
            //                printf("y = %f", tank1.position_.y_);
            //tank1.rect_.move(0,1);
            
            spr_.setTextureRect(sf::IntRect(2 * 100, 0, 100, 100));
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (canMoveLeft == true)
        {
            canMoveUp    = true;
            canMoveRight = true;
            canMoveDown  = true;
            canMoveLeft  = true;
            direction_ = 4;
            spr_.setPosition(position_.x_, position_.y_);
            rect_.setPosition(position_.x_, position_.y_);

            position_.x_ -= movementSpeed;
    
            spr_.setTextureRect(sf::IntRect(3 * 100, 0, 100, 100));
        }
    }
    else
    {
        // Tank not moving
    }
    return 0;
}

int Tank:: drawTank(sf::RenderWindow *window)
{
    window -> draw(spr_);
}

// trying Virtual Functions
int Tank:: draw(sf::RenderWindow *window)
{
    window -> draw(spr_);
}

int Tank::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (canMoveUp == true)
        {
            canMoveUp    = true;
            canMoveRight = true;
            canMoveDown  = true;
            canMoveLeft  = true;
            direction_ = 1;
            
            position_.y_ -= movementSpeed;
            //                printf("y = %f", tank1.position_.y_);
            //tank1.rect_.move(0,1);
            spr_.setPosition(position_.x_, position_.y_);
            rect_.setPosition(position_.x_, position_.y_);
            
            spr_.setTextureRect(sf::IntRect(0 * 100, 0, 100, 100));
            
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (canMoveRight == true)
        {
            canMoveUp    = true;
            canMoveRight = true;
            canMoveDown  = true;
            canMoveLeft  = true;
            direction_ = 2;
            
           
            
            position_.x_ += movementSpeed;
            //                printf("y = %f", tank1.position_.y_);
            //tank1.rect_.move(0,1);
            
            spr_.setPosition(position_.x_, position_.y_);
            rect_.setPosition(position_.x_, position_.y_);
            
            spr_.setTextureRect(sf::IntRect(1 * 100, 0, 100, 100));
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (canMoveDown == true)
        {
            canMoveUp    = true;
            canMoveRight = true;
            canMoveDown  = true;
            canMoveLeft  = true;
            direction_ = 3;
            
        
            
            position_.y_ += movementSpeed;
            //                printf("y = %f", tank1.position_.y_);
            //tank1.rect_.move(0,1);
            spr_.setPosition(position_.x_, position_.y_);
            rect_.setPosition(position_.x_, position_.y_);
            
            spr_.setTextureRect(sf::IntRect(2 * 100, 0, 100, 100));
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (canMoveLeft == true)
        {
            canMoveUp    = true;
            canMoveRight = true;
            canMoveDown  = true;
            canMoveLeft  = true;
            direction_ = 4;
           
            
            position_.x_ -= movementSpeed;
            
            spr_.setPosition(position_.x_, position_.y_);
            rect_.setPosition(position_.x_, position_.y_);
            
            spr_.setTextureRect(sf::IntRect(3 * 100, 0, 100, 100));
        }
    }
    else
    {
        // Tank not moving
    }
    return 0;
}

int Tank::collision()
{
    
}
