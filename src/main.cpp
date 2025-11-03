#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        sf::CircleShape shape(100.f);
        shape.setPosition({400-100,300-100});
        shape.setFillColor(sf::Color(100, 250, 50));

        shape.setOutlineThickness(5.f);
        shape.setOutlineColor(sf::Color(255, 255, 255));

        window.draw(shape);

        sf::CircleShape square(100, 4);
        square.setPosition({400-100,300-100});
        square.setFillColor(sf::Color(100, 50, 50));

        window.draw(square);

        // end the current frame
        window.display();
    }
}
