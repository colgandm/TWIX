#include "player.h"
#include "graphics.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
}

Player::Player() {}

Player::Player(Graphics& graphics, float x, float y) :
	AnimatedSprite(graphics, "Sprites/MyChar.png", 0, 0, 16, 16, x, y, 100) {
	graphics.loadImage("Sprites/MyChar.png");

	this->setupAnimations();
	this->playAnimation("RunRight");
}

void Player::setupAnimations() {
	this->addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
	this->addAnimation(1, 0, 32, "Shoot", 16, 16, Vector2(0, 0));
}

void Player::animationDone(std::string currentAnimation) {}

void Player::moveLeft() {
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;
}

void Player::moveRight() {
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void Player::stopMoving() {
	this->_dx = 0.0f;
	this->_dy = 0.0f;
	this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::moveUp() {
	this->_dy = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;
}

void Player::moveDown() {
	this->_dy = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void Player::action() {
	this->playAnimation("Shoot");
}

void Player::update(float elapsedTime) {
	//Move by dx
	this->_x += this->_dx * elapsedTime;
	this->_y += this->_dy * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics& graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}