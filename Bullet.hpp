//
//  Bullet.hpp
//  Game
//
//  Created by Alexandr Kuznetsov on 03.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include "GameObject.hpp"

class Bullet: public GameObject
{
public:
    int movementSpeed = 7;
    int attackDamage = 2;
    int timeLife = 5;
    //int direction = 0; // 1 - up 2 - right 3 - down 4 - left
    
    //Bullet(); // The first Concstructor
    
    Bullet(double x, double y, sf::Sprite spr, sf::RectangleShape rect); // The second Concstructor
    
    int updateBullet();
    
    int drawBullet(sf::RenderWindow* window);
    
};
#endif /* Bullet_hpp */
