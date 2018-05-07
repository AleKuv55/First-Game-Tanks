//
//  TankFriend.hpp
//  Game
//
//  Created by Alexandr Kuznetsov on 07.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#ifndef TankFriend_hpp
#define TankFriend_hpp

#include "GameObject.hpp"

class TankFriend: public GameObject
{
public:
    int movementSpeed = 4;
    int attack = 2;
    double attackSpeed = 0.3;
    //int offset = 3;
    
    bool canMoveUp = true;
    bool canMoveRight = true;
    bool canMoveDown = true;
    bool canMoveLeft = true;
    
    TankFriend();
    TankFriend(double x, double y, sf::Sprite spr, sf::RectangleShape rect);
    
    int updateTankFriend();
    
    int drawTankFriend(sf::RenderWindow* window);
    
    
    // For objectManager
    virtual int draw(sf::RenderWindow* window) override;
    virtual int update() override;
    virtual int collision() override;
};
#endif /* TankFriend_hpp */
