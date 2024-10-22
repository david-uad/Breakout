#include <sstream>

#include "UI.h"
#include "GameManager.h"
#include <iomanip>

UI::UI(sf::RenderWindow* window, int lives, GameManager* gameManager) 
	: _window(window), _gameManager(gameManager)
{
	for (int i = lives; i > 0; --i)
	{
		sf::CircleShape newLife;
		newLife.setFillColor(sf::Color::Red);	
		newLife.setOutlineColor(sf::Color::Cyan);
		newLife.setOutlineThickness(4.0f);
		newLife.setRadius(LIFE_RADIUS);
		newLife.setPosition((LIFE_RADIUS*2 + LIFE_PADDING) * i, LIFE_PADDING);
		_lives.push_back(newLife);
	}
	_powerupText.setCharacterSize(30);
	_powerupText.setPosition(800, 10);
	_powerupText.setFillColor(sf::Color::Cyan);

	_powerupBar.setPosition(800, 60);
	_powerupBar.setFillColor(sf::Color::Cyan);
	_powerupBar.setSize(sf::Vector2f(POWERUP_BAR_WIDTH, POWERUP_BAR_HEIGHT));

	_font.loadFromFile("font/montS.ttf");
	_powerupText.setFont(_font);
}

UI::~UI()
{
}


void UI::updatePowerupText(std::pair<POWERUPS, float> powerup)
{
	std::ostringstream oss;

	switch (powerup.first)
	{
	case bigPaddle:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("big " + oss.str());
		_powerupText.setFillColor(paddleEffectsColour);
		break;
	case smallPaddle:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("small " + oss.str());
		_powerupText.setFillColor(paddleEffectsColour);
		break;
	case slowBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("slow " + oss.str());
		_powerupText.setFillColor(ballEffectsColour);
		break;
	case fastBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("fast " + oss.str());
		_powerupText.setFillColor(ballEffectsColour);
		break;
	case fireBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("fire " + oss.str());
		_powerupText.setFillColor(extraBallEffectsColour);
		break;
	case none:
		_powerupText.setString("");
		
		break;
	}
}

void UI::updatePowerupUI(std::pair<POWERUPS, float> powerup)
{
	float percent = powerup.second / 5.0f;
	float width = POWERUP_BAR_WIDTH * percent;
	_powerupBar.setSize(sf::Vector2f(width, POWERUP_BAR_HEIGHT));

	switch (powerup.first)
	{
	case bigPaddle:
		_powerupText.setString("big ");
		_powerupText.setFillColor(paddleEffectsColour);
		_powerupBar.setFillColor(paddleEffectsColour);
		break;
	case smallPaddle:
		_powerupText.setString("small ");
		_powerupText.setFillColor(paddleEffectsColour);
		_powerupBar.setFillColor(paddleEffectsColour);
		break;
	case slowBall:
		_powerupText.setString("slow ");
		_powerupText.setFillColor(ballEffectsColour);
		_powerupBar.setFillColor(ballEffectsColour);

		break;
	case fastBall:
		_powerupText.setString("fast ");
		_powerupText.setFillColor(ballEffectsColour);
		_powerupBar.setFillColor(ballEffectsColour);
		break;
	case fireBall:
		_powerupText.setString("fire ");
		_powerupText.setFillColor(extraBallEffectsColour);
		_powerupBar.setFillColor(extraBallEffectsColour);
		break;
	case none:
		_powerupText.setString("");
		_powerupBar.setFillColor(sf::Color::Transparent);

		break;
	}
}

void UI::lifeLost(int lives)
{
	_lives[_lives.size() - 1 - lives].setFillColor(sf::Color::Transparent);
}

void UI::render()
{
	_window->draw(_powerupText);
	for (sf::CircleShape life : _lives)
	{
		_window->draw(life);
	}

	_window->draw(_powerupBar);
}

void UI::reset()
{
	for (auto& life : _lives)
	{
		life.setFillColor(sf::Color::Red);
	}
}