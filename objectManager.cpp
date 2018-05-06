//
//  objectManager.cpp
//  Game
//
//  Created by Alexandr Kuznetsov on 04.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#include "objectManager.hpp"
//#include "Tank.hpp"
//#include "Bullet.hpp"

objectManager::objectManager() :
    topObject_(0),
    objectArray_(new GameObject*[500])
{
   /*for (int i = 0; i < 100; i++)
    {
//        objectArray_[i] = &GameObject();
    }*/
};

int objectManager::run(sf::RenderWindow* window)
{
    for (int i = 0; i < topObject_; i++)
    {
        if (objectArray_[i] -> objectAlive == true)
        {
            if      (objectArray_[i] -> objectType_ == 0) // Bullet
            {
                // Bullet Draw and Move
                ((Bullet*)objectArray_[i]) -> updateBullet();
                ((Bullet*)objectArray_[i]) -> drawBullet(window);
                
                //Bullet Collision with wall
                for (int j = 0; j < topObject_; j++) // instead of topObj make define
                {
                    if ( (objectArray_[j] -> objectAlive == true) && (objectArray_[j] -> objectType_ == 3) )
                    {
                        if ( ((Bullet*)(objectArray_[i])) -> rect_.getGlobalBounds().intersects( ((wall*)(objectArray_[j])) -> rect_.getGlobalBounds()) )
                        {
                            // Hit Wall
                            ((Bullet*)(objectArray_[i])) -> objectAlive = false;
                        }
                    }
                }
               
            }
            else if (objectArray_[i] -> objectType_ == 3) // Wall
            {
                // Check for Collisions
                ((wall*)objectArray_[i]) -> draWall(window);
            }
            else if (objectArray_[i] -> objectType_ == 1) // Enemy
            {
                // Enemy Tank Draw and Move
                ((enemyTank*)objectArray_[i]) -> updatenemyTank();
                ((enemyTank*)objectArray_[i]) -> drawenemyTank(window);
                
            }
            else if (objectArray_[i] -> objectType_ == 2) // Tank
            {
                // Tank Draw and Move
                ((Tank*)objectArray_[i]) -> updateTank();
                ((Tank*)objectArray_[i]) -> drawTank(window);
                
                // Collision Tank with Wall
                for (int j = 0; j < topObject_; j++) // don't like it may be radius
                {
                    if ( (objectArray_[j] -> objectAlive == true) && (objectArray_[j] -> objectType_ == 3) )
                    {
                        if ( ((Tank*)(objectArray_[i])) -> rect_.getGlobalBounds().intersects( ((wall*)(objectArray_[j])) -> rect_.getGlobalBounds()) )
                        {
                            // Hit Wall
                            if (objectArray_[i] -> direction_ == 1) // Up
                            {
                                ((Tank*)objectArray_[i]) -> canMoveUp = false;
                                objectArray_[i] -> position_.y_ += 2;
                                //                    Player1.rect.move(0,1);
                            }
                            else if (objectArray_[i] -> direction_ == 2) // Right
                            {
                                ((Tank*)objectArray_[i]) -> canMoveRight = false;
                                objectArray_[i] -> position_.x_ -= 2;
                                
                                //                    Player1.rect.move(0,-1);
                            }
                            else if (objectArray_[i] -> direction_ == 3) // Down
                            {
                                ((Tank*)objectArray_[i]) -> canMoveDown = false;
                                objectArray_[i] -> position_.y_ -= 2;
                                //                    Player1.rect.move(1,0);
                            }
                            else if (objectArray_[i] ->direction_ == 4) // Left
                            {
                                ((Tank*)objectArray_[i]) -> canMoveLeft = false;
                                objectArray_[i] -> position_.x_ += 2;
                                
                                //                    Player1.rect.move(-1,0);
                            }
                            else
                            {}
                        }
                    }
                }
            }
            
        }
    }
}
int objectManager::objectAdd(GameObject* gameObject)
{
    objectArray_[topObject_] = gameObject;
    topObject_++;
//    objectArray_[topObject_] = GameObject();
}
