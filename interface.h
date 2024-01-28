#include <iostream>
#include <SFML/Graphics.hpp>



int interface_cal()
{
    setlocale(LC_ALL, "RU");
    int a = 0;
    sf::RenderWindow window(sf::VideoMode(801, 601), "Type of calculator");

    sf::RectangleShape rectangle(sf::Vector2f(8000, 6000));
    rectangle.setPosition(0, 0);
    rectangle.setFillColor(sf::Color::White);
    
    sf::Font font;

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Eror" << std::endl;
        return -1;
    }

    
    
    sf::Text option1;
    option1.setFont(font);
    option1.setString("               Rational calculator without functions");
    option1.setCharacterSize(25);
    option1.setPosition(sf::Vector2f(100, 100));
    option1.setFillColor(sf::Color::Black);

    sf::Text option2;
    option2.setFont(font);
    option2.setString("   Imaganary and rational calculator without functions");
    option2.setCharacterSize(25);
    option2.setPosition(sf::Vector2f(100, 200));
    option2.setFillColor(sf::Color::Black);

    sf::Text option3;
    option3.setFont(font);
    option3.setString("                 Rational calculator with functions");
    option3.setCharacterSize(25);
    option3.setPosition(sf::Vector2f(100, 300));
    option3.setFillColor(sf::Color::Black);

    sf::Text option4;
    option4.setFont(font);
    option4.setString("     Imaganary and rational calculator with functions");
    option4.setCharacterSize(25);
    option4.setPosition(sf::Vector2f(100, 400));
    option4.setFillColor(sf::Color::Black);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (option1.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        return a = 1;
                    }
                    else if (option2.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        return a = 2;
                    }
                    else if (option3.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        return a = 3;
                    }
                    else if (option4.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        return a = 4;
                    }
                }
            }
        }

        window.clear();
        window.draw(rectangle);
        window.draw(option1);
        window.draw(option2);
        window.draw(option3);
        window.draw(option4);
        window.display();
    }
}