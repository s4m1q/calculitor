#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>



void interface_cal()
{
   
        sf::RenderWindow window(sf::VideoMode(800, 600), "Window Title");
        sf::Font font;
        font.loadFromFile("arial.ttf");

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(24);

        std::string input;
        std::string output;
        std::cout << "Добро пожаловать в калькулятор!";
        std::cin >> input;

        text.setString(input);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(text);
            window.display();
        }

    
}