#include <SFML\Graphics.hpp>

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::Texture texture;
	texture.loadFromFile("Auto.png");
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	window.setFramerateLimit(60);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			sprite.move(10, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			sprite.move(-10, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			sprite.move(0, 10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			sprite.move(0, -10);

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			//Para que se cierre con la cruz o apretando la tecla ESC
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		window.draw(sprite);

		// end the current frame
		window.display();
	}

	return 0;
}