



#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Vector.hpp"
#include "GameObject.hpp"
// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Tank.hpp"
#include "Bullet.hpp"
#include "objectManager.hpp"
#include "enemyTank.hpp"
#include "wall.hpp"
#include "TankFriend.hpp"

// tiled
// ogmo editor

int main(int, char const**)
{
    //Time
    srand(time(NULL));
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Clock clock3;
    
    int counterWalking = 0;
    // Create the main window
    sf::RenderWindow window (sf::VideoMode (1600, 860), __FILE__, sf::Style::Default & ~sf::Style::Resize);
    window.setVerticalSyncEnabled (true);
    window.setFramerateLimit (25);

    // Jury Dud Just For FUN
    sf::Texture textureDud;
    if (!textureDud.loadFromFile(resourcePath() + "Dud.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteDud(textureDud);
    sf::RectangleShape rect;
    rect.setPosition(600, 800);
    spriteDud.setPosition(800, 600);
//    class GameObject Dud(800, 600, spriteDud, rect);
//    Dud.spr_.setPosition(Dud.position_.x_, Dud.position_.y_);
    
    
   
    
    // The first Bullet
    sf::Texture textureBullet;
    if (!textureBullet.loadFromFile(resourcePath() + "bullet.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteBullet(textureBullet);
    sf::RectangleShape rectBullet;
    
    //class Bullet bullet1(tank1.position_.x_, tank1.position_.y_, spriteBullet, rectBullet);
    //bullet1.direction_ = 1;
    
    // The enemyTank
    sf::Texture texturEnemyTank;
    if (!texturEnemyTank.loadFromFile(resourcePath() + "enemytank.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spritEnemyTank(texturEnemyTank);
    sf::RectangleShape rectEnemyTank;
    
    class enemyTank enemyTank1(window.getSize().x/2 - 80, window.getSize().y/2 - 191, spritEnemyTank, rectEnemyTank);
    enemyTank1.spr_.setScale(0.4f, 0.4f);
    enemyTank1.spr_.setPosition(enemyTank1.position_.x_, enemyTank1.position_.y_);
//    enemyTank1.spr_.setPosition(0, 0);

    enemyTank1.spr_.setTextureRect(sf::IntRect(0, 0, 200, 300));
    enemyTank1.rect_.setSize(sf::Vector2f(200, 300));

    

    // The first Tank
    sf::Texture textureTanki;
    if (!textureTanki.loadFromFile(resourcePath() + "tanchiki2.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteTanki1(textureTanki);
    sf::RectangleShape rectTank1;
    
    class Tank tank1(window.getSize().x/2 + 100 , window.getSize().y/2 + 100, spriteTanki1, rectTank1);
    //tank1.spr_.setScale(0.5f, 0.5f);
    tank1.spr_.setPosition(tank1.position_.x_, tank1.position_.y_);
    tank1.spr_.setTextureRect(sf::IntRect(0, 0, 100, 100));
    tank1.rect_.setSize(sf::Vector2f((100), (100)));
    
    /*sf::Sprite spriteTanki2(textureTanki);
    sf::RectangleShape rectTank2;
    
    class Tank tank2(window.getSize().x/2 - 100 , window.getSize().y/2 - 100, spriteTanki2, rectTank2);
    //tank1.spr_.setScale(0.5f, 0.5f);
    tank2.spr_.setPosition(tank2.position_.x_, tank2.position_.y_);
    tank2.spr_.setTextureRect(sf::IntRect(0, 0, 100, 100));
    tank2.rect_.setSize(sf::Vector2f((100), (100)));*/
    // The Friend Tank
    sf::Texture textureFriendTank;
    if (!textureFriendTank.loadFromFile(resourcePath() + "tanchiki2.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteTanki2(textureFriendTank);
    sf::RectangleShape rectTank2;
    
    class TankFriend tank2(window.getSize().x/2 - 100 , window.getSize().y/2 , spriteTanki2, rectTank2);
    //tank1.spr_.setScale(0.5f, 0.5f);
    tank2.spr_.setPosition(tank2.position_.x_, tank2.position_.y_);
    tank2.spr_.setTextureRect(sf::IntRect(0, 0, 100, 100));
    tank2.rect_.setSize(sf::Vector2f((100), (100)));
    
    // The object Array
    class objectManager ObjectManager;
    ObjectManager.objectAdd(&tank1);
    ObjectManager.objectAdd(&tank2);
    ObjectManager.objectAdd(&enemyTank1);
    
    // The Wall Array
    sf::Texture textureWall;
    if (!textureWall.loadFromFile(resourcePath() + "box1.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteWall(textureWall);
    sf::RectangleShape rectWall;
    class wall wall1;
    wall1.position_.x_ = 600;
    wall1.position_.y_ = 600;
    wall1.rect_.setPosition(wall1.position_.x_, wall1.position_.y_);
    for (int k = 0; k < 3; k++)
        for ( int i = 0; i < 8; i++) // It is considered to make another array for wall
            for ( int j = 0; j < 5; j++)
        {
            wall* wall = new class wall(0, 0, spriteWall, rectWall);
//            wall -> spr_.setTexture(textureWall);
            wall -> spr_.setTextureRect(sf::IntRect (0, 10, 102, 102));
            if ( i > j )
            {
            wall -> position_.x_ = 0;
            wall -> position_.y_ = i * 120 * k ;
            }
            if ( j > i )
            {
                wall -> position_.x_ = j * 120 * 3;
                wall -> position_.y_ =     120 * k;
            }
            wall -> rect_.setPosition(wall -> position_.x_, wall -> position_.y_);
            ObjectManager.objectAdd(wall);
        }
    // The Rectangle
  /*  sf:: RectangleShape rect_;
    sf:: Sprite spr_;
    rect_.setSize(sf::Vector2f(70, 70));
    rect_.setPosition(window.getSize().x/2, window.getSize().y/2 - 100);
    rect_.setFillColor(sf::Color::Green);*/
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        // Clock
        sf::Time elapsed1 = clock1.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();
        
        // Press Space and R to Make Bullet
        int coolDown = 0;
        if (elapsed1.asSeconds() >= tank1.attackSpeed)
        {
            clock1.restart();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) // Create new bullet, put pointer in objectManager
            {
                Bullet* bullet = new Bullet(tank1.position_.x_ + 38 , tank1.position_.y_ + 40, spriteBullet, rectBullet);
                bullet -> direction_ = tank1.direction_;
                bullet -> objectOwner = 3;
                ObjectManager.objectAdd(bullet);
            }
        }
        
        if (elapsed2.asSeconds() >= tank2.attackSpeed)
        {
            clock2.restart();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) // Create new bullet, put pointer in objectManager
            {
                Bullet* bullet = new Bullet(tank2.position_.x_ + 38 , tank2.position_.y_ + 40, spriteBullet, rectBullet);
                bullet -> direction_ = tank2.direction_;
                bullet -> objectOwner = 2;
                ObjectManager.objectAdd(bullet);
            }
        }
        
        ObjectManager.run(&window);

        /*for(int i = 0; i < ObjectManager.topObject_; i++)
        {
            if (ObjectManager.objectArray_[i] -> objectType_ == 0)
            {
                if (((Bullet*)(ObjectManager.objectArray_[i])) -> rect_.getGlobalBounds().intersects(wall1.rect_.getGlobalBounds()))
                {
            // Hit Wall
            ((Bullet*)(ObjectManager.objectArray_[i])) -> objectAlive = false;
                }
            }
        }*/
        
//        window.draw(((Bullet*)objectArray_[i]) -> spr_);
        
        // Tank Collides with Wall
//        int counter = 0;
        //for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
//        {
        
        
//        printf("m %d %d", sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        //printf("tx %f ty %f wx %f wy %f ", tank1.position_.x_, tank1.position_.y_, wall1.position_.x_, wall1.position_.y_);
//        printf("%f %f %f %f ", tank1.position_.x_, tank1.position_.y_, wall1.rect_.getSize().x, wall1.rect_.getSize().y);

           /* if ( ((tank1.position_.x_  >= wall1.position_.x_)                           &&
                 ( tank1.position_.x_  <= wall1.rect_.getSize().x + wall1.position_.x_) &&
                 ( tank1.position_.y_  >= wall1.position_.y_)                           &&
                 ( tank1.position_.y_  <= wall1.rect_.getSize().y + wall1.position_.y_))
                 ||
                 ((tank1.position_.x_  >= wall1.position_.x_)                           &&
                 ( tank1.position_.x_  <= wall1.rect_.getSize().x + wall1.position_.x_) &&
                 ( tank1.position_.y_  >= wall1.position_.y_)                           &&
                 ( tank1.position_.y_  <= wall1.rect_.getSize().y + wall1.position_.y_)))
          if(//(( tank1.position_.y_ + tank1.movementSpeed >= wall1.position_.y_ ) && (tank1.direction_ = 1))                            ||
           //(( tank1.position_.x_ + tank1.movementSpeed <= wall1.position_.x_ ) && (tank1.direction_ = 2))                            ||
           (( tank1.position_.y_ - tank1.movementSpeed <= wall1.position_.y_ ) &&  (tank1.direction_ = 1))  ||
           (( tank1.position_.x_ - tank1.movementSpeed <= wall1.position_.x_ ) &&  (tank1.direction_ = 4)))*/
      /*   if (tank1.rect_.getGlobalBounds().intersects(wall1.rect_.getGlobalBounds()))
            {
                // Hit Wall
                if (tank1.direction_ == 1) // Up
                {
                    tank1.canMoveUp = false;
                    tank1.position_.y_ += 2;
//                    Player1.rect.move(0,1);
                }
                else if (tank1.direction_ == 2) // Right
                {
                    tank1.canMoveRight = false;
                    tank1.position_.x_ -= 2;

//                    Player1.rect.move(0,-1);
                }
                else if (tank1.direction_ == 3) // Down
                {
                    tank1.canMoveDown = false;
                    tank1.position_.y_ -= 2;
//                    Player1.rect.move(1,0);
                }
                else if (tank1.direction_ == 4) // Left
                {
                    tank1.canMoveLeft = false;
                    tank1.position_.x_ += 2;

//                    Player1.rect.move(-1,0);
                }
                else
                {}
            }
            
//            counter++;
//        }*/
        


        // Draw the sprite
        window.draw(spriteDud);
        window.draw(tank1.spr_);
        window.draw(tank2.spr_);

//        window.draw(tank2.spr_);
       // window.draw(wall1.rect_);
        //window.draw(rect_);
//        window.draw(spriteBullet);
        


        // Update the window
         window.display();
    }

    return EXIT_SUCCESS;
}
//        Player View
//        window.setView(view1);
//        view1.setCenter(Player1.rect.getPosition());
