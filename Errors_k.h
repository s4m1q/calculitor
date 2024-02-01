#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <conio.h> 
#include <windows.h> 


void call_error()
{
    sf::RenderWindow error(sf::VideoMode(600, 400), "Wrong input Data");
    error.setFramerateLimit(13);
    sf::Font font;

    
    sf::Text _error_("", font, 40);
    _error_.setFillColor(sf::Color::Red);
    _error_.setPosition(10.f, 160.f);

    while (error.isOpen())
    {
        sf::Event event;

        while (error.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                error.close();
            }
        }

        _error_.setString("ERROR, CHANGE INPUT DATA");
        error.clear(sf::Color::Black);

        error.draw(_error_);
        error.display();
    }
}