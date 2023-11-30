#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	moving = false;
}

void Player::initTexture()
{
	if (!textureSheet.loadFromFile("Texture/Idle.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the player texture" << '\n';
	}
}

void Player::initSprite()
{
	sprite.setTexture(textureSheet);
	currentFrame = sf::IntRect(0, 0, 128, 128);


	sprite.setTextureRect(currentFrame);
	sprite.setScale(7.f, 7.f);
}

void Player::initAnimations()
{
	animationTimer.restart();
}

//Con/Des
Player::Player()
{	
	initVariables();
	initTexture();
	initSprite();
}

Player::~Player()
{

}



void Player::updateMovement()
{
	//Move player
	moving = false;
	// Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		sprite.move(-5.f, 0.f);
		moving = true;
	}
	//Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		sprite.move(5.f, 0.f);
		moving = true;
	}
	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		sprite.move(0.f, -5.f);
		moving = true;
	}
	//Buttom
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		sprite.move(0.f, 5.f);
		moving = true;
	}
}

void Player::updateAnimations()
{	

	if (animationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (moving == false)
		{
			currentFrame.left += 128.f;
			if (currentFrame.left >= 512.f)
			{
				currentFrame.left = 0;
			}
		}
		animationTimer.restart();
		sprite.setTextureRect(currentFrame);
	}
}

//Functions 
void Player::update()
{
	updateMovement();
	updateAnimations();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
