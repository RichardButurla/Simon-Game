/// <summary>
/// Richard Buturla
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>


const sf::Color RED{ 180,0,0,255 };
const sf::Color BLUE{ 0,0,180,255 };
const sf::Color GREEN{ 0,180,0,255 };
const sf::Color YELLOW{ 180,180,0,255 };

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void setupButtons();
	void setupFontAndText();
	



	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_title; //Title text
	sf::Text m_instructions;
	sf::Text m_menuButtonText;
	//our squares
	sf::RectangleShape m_redButton; 
	sf::RectangleShape m_blueButton;
	sf::RectangleShape m_greenButton;
	sf::RectangleShape m_yellowButton;



	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

