//
//  objectManager.hpp
//  Game
//
//  Created by Alexandr Kuznetsov on 04.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#ifndef objectManager_hpp
#define objectManager_hpp

#include "GameObject.hpp"
#include "Bullet.hpp"
#include "enemyTank.hpp"
#include "Tank.hpp"
#include "wall.hpp"

class objectManager
{
public:
    GameObject** objectArray_;
    int topObject_;
    
    
    objectManager() ;
    
    int run(sf::RenderWindow* window);
    
    int objectAdd(GameObject* gameObject);
};
#endif /* objectManager_hpp */
