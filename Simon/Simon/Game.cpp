/// <summary>
/// @Richard Buturla
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit

{
	setupButtons();
	setupFontAndText(); // load font 
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_redButton);
	m_window.draw(m_blueButton);
	m_window.draw(m_greenButton);
	m_window.draw(m_yellowButton);
	m_window.draw(m_title);

	m_window.display();
}

/// <summary>
/// setup button rectangles
/// </summary>
void Game::setupButtons()
{
	m_redButton.setFillColor(RED);
	m_redButton.setPosition(sf::Vector2f(570.0f, 30.0f));
	m_redButton.setSize(sf::Vector2f{ 200.0f, 200.0f });

	m_blueButton.setFillColor(BLUE);
	m_blueButton.setPosition(sf::Vector2f(350.0f, 250.0f));
	m_blueButton.setSize(sf::Vector2f{ 200.0f,200.0f });

	m_greenButton.setFillColor(GREEN);
	m_greenButton.setPosition(sf::Vector2f{ 570.0f, 250.0f });
	m_greenButton.setSize(sf::Vector2f{ 200.0f, 200.0f });

	m_yellowButton.setFillColor(YELLOW);
	m_yellowButton.setPosition(sf::Vector2f{ 350.0f, 30.0f });
	m_yellowButton.setSize(sf::Vector2f{ 200.0f, 200.0f });
	
}


/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_title.setFont(m_ArialBlackfont);
	m_title.setString("Simon ");
	m_title.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_title.setPosition(40.0f, 40.0f);
	m_title.setCharacterSize(80U);
	m_title.setOutlineColor(sf::Color::Red);
	m_title.setFillColor(sf::Color::White);
	m_title.setOutlineThickness(3.0f);

}


