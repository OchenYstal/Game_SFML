#include <SFML/Graphics.hpp>

#include "Math.hpp"
#include "Bullet.hpp"



void Bullet::Initialize(const sf::Vector2f& position, sf::Vector2f& target, float speed)
{
    this->speed = speed;
rectangleshape.setSize(sf::Vector2f(50, 25));
rectangleshape.setPosition(position);
direction = Math::Normolize(target - position);

}
void Bullet::Load()
{

}
void Bullet::Update(float DeltaTime)
{
     rectangleshape.setPosition(rectangleshape.getPosition() + direction * speed * DeltaTime);

}
void Bullet::Draw(sf::RenderWindow& window)
{
    window.draw(rectangleshape);
}