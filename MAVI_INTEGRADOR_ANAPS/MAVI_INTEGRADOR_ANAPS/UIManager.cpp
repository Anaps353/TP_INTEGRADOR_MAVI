#include "UIManager.h"

UIManager::UIManager()
{
	_font.loadFromFile(Data::AssetsPath[FontEnum]);

	_pointsText.setFont(_font);
	_pointsText.setCharacterSize(50.0f);
	_pointsText.setFillColor(Color::Green);

	_livesText.setFont(_font);
	_livesText.setCharacterSize(50.0f);
	_livesText.setFillColor(Color::Green);

	_loseText.setFont(_font);
	_loseText.setCharacterSize(80.0f);
	_loseText.setFillColor(Color::Red);
	_loseText.setOutlineColor(Color::White);
	_loseText.setOutlineThickness(5.0f);
}

UIManager::~UIManager()
{
}

void UIManager::Draw(RenderWindow* window, int points, int lives, bool gameOver)
{
	const sf::Vector2u windowSize = window->getSize();

	_pointsText.setString("Puntos: " + to_string(points));
	_pointsText.setPosition(windowSize.x / 8, windowSize.y / 8 * 6.5);
	window->draw(_pointsText);

	_livesText.setString("Vidas: " + to_string(lives));
	_livesText.setPosition(windowSize.x / 8 * 5, windowSize.y / 8 * 6.5);
	window->draw(_livesText);

	if (gameOver) {
		_loseText.setString("Game Over\nPuntaje: " + to_string(points));
		const sf::FloatRect bounds(_loseText.getLocalBounds());
		_loseText.setOrigin((bounds.width - windowSize.x) / 2 + bounds.left, (bounds.height - windowSize.y) / 2 + bounds.top);
		window->draw(_loseText);
	}
}
