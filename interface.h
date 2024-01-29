#include <iostream>
#include <SFML/Graphics.hpp>



int interface_cal()
{
    setlocale(LC_ALL, "RU");
    int a = 0;
    sf::RenderWindow window(sf::VideoMode(1100, 900), "Calculator");
    window.setFramerateLimit(60);

    sf::Font font;


    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Failed to load font!" << std::endl;
        return -1;
    }

    sf::Text text("", font, 30);
    text.setFillColor(sf::Color::Black);
    text.setPosition(20.f, 20.f);

    sf::RectangleShape buttonShapes[22];
    sf::Text buttonTexts[22];
    bool buttonPressed[22] = { false };

    for (int i = 0; i < 22; i++)
    {
        if (i == 1 || i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
        {
            buttonShapes[i].setSize(sf::Vector2f(70.f, 65.f));
        }
        else if (i == 14 || i == 15 || i == 16 || i == 17)
        {
            buttonShapes[i].setSize(sf::Vector2f(128.f, 65.f));
        }
        else
        {
            buttonShapes[i].setSize(sf::Vector2f(75.f, 65.f));
        }


        int x_k = 0, y_k = 0;

        
        if (i == 1 || i == 2 || i == 3)
            y_k = 680 + 75;
        else if (i == 4 || i == 5 || i == 6)
            y_k = 610 + 50;
        else if (i == 7 || i == 8 || i == 9)
            y_k = 540 + 25;
        else if (i == 0)
            y_k = 750 + 100;


        if (i == 1 || i == 4 || i == 7)
            x_k = 50 + 25 - 10;
        else if (i == 2 || i == 5 || i == 8)
            x_k = 120 + 50 - 10;
        else if (i == 9 || i == 6 || i == 3)
            x_k = 190 + 75 - 10;
        else if (i == 0)
            x_k = 120 + 50 - 10;




        
        if (i == 10 || i == 11 || i == 12)
            y_k = 610 + 75 + 20 + 86;
        else if (i == 13 || i == 14 || i == 15)
            y_k = 540 + 50 + 40 + 86;
        else if (i == 16 || i == 17 || i == 18)
            y_k = 470 + 25 + 60 + 86;
        else if (i == 19 || i == 20 || i == 21)
            y_k = 400 + 25+ 80 - 25 + 86;
        

        if (i == 10 || i == 13 || i == 16 || i == 19)
            x_k = 50 + 25 - 10 + 200 + 200 + 25 + 5 + 5 - 100;
        else if (i == 11 || i == 14 || i == 17 || i == 20)
            x_k = 120 + 50 - 10 + 200 + 200 + 50 + 10 + 10 - 100;
        else if (i == 12 || i == 15 || i == 18 || i == 21)
            x_k = 190 + 75 - 10 + 200 + 200 + 75 + 15 + 15 - 100;
        

       

        buttonShapes[i].setPosition(x_k, y_k - 150.f);
        buttonShapes[i].setFillColor(sf::Color::Green);

        buttonTexts[i].setFont(font);
        buttonTexts[i].setCharacterSize(40);
        buttonTexts[i].setFillColor(sf::Color::White);
        buttonTexts[i].setPosition(buttonShapes[i].getPosition() + sf::Vector2f(10.f, 0.f));
        buttonTexts[i].setString(std::to_string(i));
        if (i == 10)
            buttonTexts[i].setString("cos");
        else if (i == 11)
            buttonTexts[i].setString("sin");
        else if (i == 12)
            buttonTexts[i].setString("tg");
        else if (i == 13)
            buttonTexts[i].setString("ctg");
        else if (i == 14)
            buttonTexts[i].setString("arccos");
        else if (i == 15)
            buttonTexts[i].setString("arcsin");
        else if (i == 16)
            buttonTexts[i].setString("arctg");
        else if (i == 17)
            buttonTexts[i].setString("arcctg");
        else if (i == 18)
            buttonTexts[i].setString("+");
        else if (i == 19)
            buttonTexts[i].setString("(");
        else if (i == 20)
            buttonTexts[i].setString(")");
        else if (i == 21)
            buttonTexts[i].setString("-");
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        for (int i = 0; i < 22; i++)
        {
            if (buttonShapes[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    buttonPressed[i] = true;
                    buttonShapes[i].setFillColor(sf::Color::Red);
                }
                else
                {
                    if (buttonPressed[i])
                    {
                        buttonPressed[i] = false;
                        buttonShapes[i].setFillColor(sf::Color::Green);

                        // Обработка значения нажатой кнопки
                        if (i == 1 || i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
                            text.setString(text.getString() + std::to_string(i));
                        else if (i == 10)
                            text.setString(text.getString() + "cos");
                        else if (i == 11)
                            text.setString(text.getString() + "sin");
                        else if (i == 12)
                            text.setString(text.getString() + "tg");
                        else if (i == 13)
                            text.setString(text.getString() + "ctg");
                        else if (i == 14)
                            text.setString(text.getString() + "arccos");
                        else if (i == 15)
                            text.setString(text.getString() + "arcsin");
                        else if (i == 16)
                            text.setString(text.getString() + "arctg");
                        else if (i == 17)
                            text.setString(text.getString() + "arcctg");
                        else if (i == 18)
                            text.setString(text.getString() + "+");
                        else if (i == 19)
                            text.setString(text.getString() + "(");
                        else if (i == 20)
                            text.setString(text.getString() + ")");
                        else if (i == 21)
                            text.setString(text.getString() + "-"); 
                        // Добавить ещё 20 кнопок, написать красиво их расположение, не забыть сделать норм вывод символов на экран 
                        // и прописать ретёрны от кнопок хз куда, наверное в мейн???(Вопрос для Саши Федоряко)
                    }
                }
            }
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < 22; i++)
        {
            window.draw(buttonShapes[i]);
            window.draw(buttonTexts[i]);
        }

        window.draw(text);

        window.display();
    }


}