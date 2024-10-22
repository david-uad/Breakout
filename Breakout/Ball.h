#pragma once
#include <SFML/Graphics.hpp>
#include <list>


class GameManager;  // forward declaration



class Ball {
public:
    Ball(sf::RenderWindow* window, float velocity, GameManager* gameManager);
    ~Ball();
    void update(float dt);
    void render();
    void setVelocity(float coeff, float duration);
    void setFireBall(float duration);
    void reset() { _trailSprites.clear(); _timeWithPowerupEffect = 0.f; }

private:
    sf::CircleShape _sprite;
    std::list<sf::CircleShape> _trailSprites;
    sf::Vector2f _direction;
    sf::RenderWindow* _window;
    float _velocity;
    bool _isAlive;
    bool _isFireBall;
    float _timeWithPowerupEffect;
    

    GameManager* _gameManager;  // Reference to the GameManager

    static constexpr int _trailLength = 480;
    static constexpr float RADIUS = 10.0f;      
    static constexpr float VELOCITY = 350.0f;   // for reference.
};

