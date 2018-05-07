//
//  enemyTank.hpp
//  Game
//
//  Created by Alexandr Kuznetsov on 05.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#ifndef enemyTank_hpp
#define enemyTank_hpp

#include "GameObject.hpp"
class enemyTank: public GameObject
{
public:
    int movementSpeed = 5;
    int attack = 2;
    double attackSpeed = 0.3;
    //int direction = 0; // 1 - up 2 - right 3 - down 4 - left
    
    enemyTank();
    enemyTank(double x, double y, sf::Sprite spr, sf::RectangleShape rect);
    
    int updatenemyTank();
    
    int drawenemyTank(sf::RenderWindow* window);

    
    // For objectManager
        virtual int draw(sf::RenderWindow* window) override;
        virtual int update() override;
        virtual int collision() override;

};
#endif /* enemyTank_hpp */

