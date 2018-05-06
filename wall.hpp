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
    int hp = 50;
    bool destroy = false;
    
    wall();
    
    int updateWall();
    
    int draWall(sf::RenderWindow* window);
    
};

#endif /* wall_hpp */
