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
    int offset = 0;
    for (int i = 0; i < topObject_; i++)
    {
        if (objectArray_[i] -> objectAlive == true)
        {
            
            objectArray_[i] -> update();
            objectArray_[i] -> draw(window);
            offset = 1;
            //objectArray_[i] -> collision();
            // ObjectType 3 - Wall 2 - Tank 1 - Enemy 0 - Bullet
            // ObjectOwner 3 - Tank 2 - FriendTank 1 - Enemy Tank
                //Bullet Collision with wall
            if (objectArray_[i] -> objectType_ == 0) // Bullet
                {
                for (int j = 0; j < topObject_; j++) // instead of topObj make define
                {
                    //Bullet Collision with wall
                    if ( (objectArray_[j] -> objectAlive == true) && (objectArray_[j] -> objectType_ == 3) )
                    {
                        if ( (objectArray_[i]) -> rect_.getGlobalBounds().intersects( ((objectArray_[j])) -> rect_.getGlobalBounds()) )
                        {
                            // Hit Wall
                            ((objectArray_[i])) -> objectAlive = false; // Kill Bullet
                            ((wall*)objectArray_[j]) -> hp --;
                            if ( ((wall*)objectArray_[j]) -> hp <= 0 )
                            {
                                objectArray_[j] -> objectAlive = false;
                            }
                            
                        }
                    }
                    //Bullet Collision with Tank and Friend Tank
                    if ( (objectArray_[j] -> objectAlive == true) && (objectArray_[j] -> objectType_ == 2) && (((Bullet*)objectArray_[i]) -> objectOwner == 3) )
                    {
                        if ( ((Bullet*)objectArray_[i]) -> objectOwner == 2 )
                        {
                            if ( (objectArray_[i]) -> rect_.getGlobalBounds().intersects( ((objectArray_[j])) -> rect_.getGlobalBounds()) )
                            {
//                                ((objectArray_[i])) -> objectAlive = false; // Kill Bullet
                                // If tank - enemy hp --
                            }
                        }
                        
                    }
                     //Bullet Collision with Enemy Tank
                    if( (objectArray_[j] -> objectAlive == true) && (objectArray_[j] -> objectType_ == 1) )
                    {
                        
                    }

                }
                }
//            Collision Tank with Walls
            else if (objectArray_[i] -> objectType_ == 2) // Tank
            {
                for (int j = 0; j < topObject_; j++) // don't like it may be radius
                {
                    if ( (objectArray_[j] -> objectAlive == true) && (objectArray_[j] -> objectType_ == 3) )
                    {
                        if ( (objectArray_[i]) -> rect_.getGlobalBounds().intersects( objectArray_[j] -> rect_.getGlobalBounds() ) )
                        {
                            if (objectArray_[i] -> direction_ == 1) // Up
                            {
                                ((Tank*)objectArray_[i]) -> canMoveUp = false;
                                objectArray_[i] -> position_.y_ += offset;
                                offset = 0;
                                
                                //                    Player1.rect.move(0,1);
                            }
                            else if (objectArray_[i] -> direction_ == 2) // Right
                            {
                                ((Tank*)objectArray_[i]) -> canMoveRight = false;
                                objectArray_[i] -> position_.x_ -= offset;
                                offset = 0;
                                
                                //                    Player1.rect.move(0,-1);
                            }
                            else if (objectArray_[i] -> direction_ == 3) // Down
                            {
                                ((Tank*)objectArray_[i]) -> canMoveDown = false;
                                objectArray_[i] -> position_.y_ -= offset;
                                offset = 0;
                                //                    Player1.rect.move(1,0);
                            }
                            else if (objectArray_[i] ->direction_ == 4) // Left
                            {
                                ((Tank*)objectArray_[i]) -> canMoveLeft = false;
                                objectArray_[i] -> position_.x_ += offset;
                                offset = 0;
                                
                                //                    Player1.rect.move(-1,0);
                            }
                            else
                            {}
                        }
                    }
                }
            }
               
//            }
//            else if (objectArray_[i] -> objectType_ == 3) // Wall
//            {
                // Check for Collisions
                //((wall*)objectArray_[i]) -> draWall(window);
//            }
//            else if (objectArray_[i] -> objectType_ == 1) // Enemy
//            {
                // Enemy Tank Draw and Move
//                ((enemyTank*)objectArray_[i]) -> updatenemyTank();
//                ((enemyTank*)objectArray_[i]) -> drawenemyTank(window);
            
//            }
//            else if (objectArray_[i] -> objectType_ == 2) // Tank
//            {
                // Tank Draw and Move
//                ((Tank*)objectArray_[i]) -> updateTank();
//                ((Tank*)objectArray_[i]) -> drawTank(window);
            
                // Collision Tank with Wall
                /*for (int j = 0; j < topObject_; j++) // don't like it may be radius
                {
                    if ( (objectArray_[j] -> objectAlive == true) && (objectArray_[j] -> objectType_ == 3) )
                    {
                        if ( ((Tank*)(objectArray_[i])) -> rect_.getGlobalBounds().intersects( ((wall*)(objectArray_[j])) -> rect_.getGlobalBounds()) )
                        {
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
                    }*/
            
            
            
        }
    }
}
int objectManager::objectAdd(GameObject* gameObject)
{
    objectArray_[topObject_] = gameObject;
    topObject_++;
//    objectArray_[topObject_] = GameObject();
}
