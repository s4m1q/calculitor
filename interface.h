#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <conio.h> 
#include <windows.h> 
#include "polska_notation.h"



int interface_cal()
{
    setlocale(LC_ALL, "RU");
    int a = 0;
    sf::RenderWindow window(sf::VideoMode(1600, 870), "Calculator");
    window.setFramerateLimit(13);

    sf::Font font;


    /*sf::RenderWindow error(sf::VideoMode(600, 400), "Wrong input Data");
    error.setFramerateLimit(13);


    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Failed to load font!" << std::endl;
        return -1;
    }
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
    }*/
    

    

    std::vector<std::string> exp0{  };
    std::vector<std::string> exp1{  };
    std::vector<std::string> exp2{  };
    std::vector<std::string> exp3{  };
    std::vector<std::string> exp4{  };
    std::vector<std::string> exp5{  };
    std::vector<std::string> exp6{  };



 

    /*sf::RenderWindow windows(sf::VideoMode(1000, 900), "test");
    windows.display();*/


    
 


    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Failed to load font!" << std::endl;
        return -1;
    }

    sf::RectangleShape rectangle(sf::Vector2f(1500.f, 40.f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(20.f, 20.f);

    // Îòðèñîâêà ïðÿìîóãîëüíèêà
    

    sf::Text text0("", font, 30);
    text0.setFillColor(sf::Color::Black);
    text0.setPosition(20.f, 20.f);
    

    sf::Text text1("", font, 30);
    text1.setFillColor(sf::Color::Black);
    text1.setPosition(20.f, 60.f);

    sf::Text text2("", font, 30);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(20.f, 100.f);            // f(x) = x^2
                                              // x = 2       

    sf::Text text3("", font, 30);
    text3.setFillColor(sf::Color::Black);
    text3.setPosition(20.f, 140.f);


    sf::Text text4("", font, 30);
    text4.setFillColor(sf::Color::Black);
    text4.setPosition(20.f, 180.f);

    sf::Text text5("", font, 30);
    text5.setFillColor(sf::Color::Black);
    text5.setPosition(20.f, 220.f);
    
    sf::Text text6("", font, 30);
    text6.setFillColor(sf::Color::Black);
    text6.setPosition(20.f, 260.f);


    int count = 0;
 

    sf::RectangleShape buttonShapes[44];
    sf::Text buttonTexts[44];
    bool buttonPressed[44] = { false };

    for (int i = 0; i < 44; i++)
    {
        if (i == 1 || i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
        {
            buttonShapes[i].setSize(sf::Vector2f(70.f, 65.f));
        }
        else if (i == 22 || i == 23 || i == 24 || i == 25 || i == 26 || i == 27 || i == 18 || i == 21 || i == 19 || i == 20 || i == 28 || i == 29 ||   i == 31 || i == 32 || i == 33)
        {
            buttonShapes[i].setSize(sf::Vector2f(70.f, 65.f));
        }
        else if (i == 34 || i == 35 || i == 36 || i == 37 || i == 39) // 34f( 35g( 36h( 37= 38BkSp 39ln( 40log_
        {
            buttonShapes[i].setSize(sf::Vector2f(70.f, 65.f));
        }
        else if (i == 14 || i == 15 ||  i == 17)
        {
            buttonShapes[i].setSize(sf::Vector2f(145.f, 65.f));
        }
        else if (i == 16)
        {
            buttonShapes[i].setSize(sf::Vector2f(127.f, 65.f));
        }
        else if (i == 38 || i == 41)
        {
            buttonShapes[i].setSize(sf::Vector2f(130.f, 65.f));
        }
        else if (i == 42 || i == 43)
        {
            buttonShapes[i].setSize(sf::Vector2f(115.f, 65.f));
        }
        else
        {
            buttonShapes[i].setSize(sf::Vector2f(90.f, 65.f));
        }


        int x_k = 0, y_k = 0;

        // 0-9 òî÷êà
        if (i == 1 || i == 2 || i == 3)
            y_k = 805;
        else if (i == 4 || i == 5 || i == 6)
            y_k = 710;
        else if (i == 7 || i == 8 || i == 9)
            y_k = 615;
        else if (i == 0 || i == 28)
            y_k = 900;

        // 0-9 òî÷êà
        if (i == 1 || i == 4 || i == 7)
            x_k = 30;
        else if (i == 2 || i == 5 || i == 8)
            x_k = 125;
        else if (i == 9 || i == 6 || i == 3 || i == 28)
            x_k = 220;
        else if (i == 0)
            x_k = 125;


        // òðèãîíîìåòðèÿ + - ( )
        if (i == 10)
        {
            y_k = 935;
            x_k = 340;
        }
        else if (i == 11)
        {
            y_k = 935;
            x_k = 470;
        }
        else if (i == 12)
        {
            y_k = 860;
            x_k = 470;
        }
        else if (i == 13)
        {
            y_k = 816 + 15 + 29;
            x_k = 340;
        }
        else if (i == 14)
        {
            
            y_k = 891 + 15 + 29;
            x_k = 600 + 500;
        }
        else if (i == 15)
        {
            y_k = 816 + 15 + 29;
            x_k = 600 + 500;
        }
        else if (i == 16)
        {
            
            y_k = 741 + 15 + 29;
            x_k = 600 + 500;
        }
        else if (i == 17)
        {
            y_k = 666 + 15 + 29;
            x_k = 600 + 500;
        }
        else if (i == 18)
        {
            y_k = 741 + 15 + 29;
            x_k = 340;
        }
        else if (i == 19)
        {
            y_k = 666 + 15 + 29;
            x_k = 340;
        }
        else if (i == 20)
        {
            y_k = 666 + 15 + 29;
            x_k = 470;
        }
        else if (i == 21)
        {
            
            y_k = 741 + 15 + 29;
            x_k = 470;
        }
        // äîáàâèë * ^ / i pi e
        else if (i == 22)
        {
            y_k = 615;
            x_k = 340;;
        }
        else if (i == 23)
        {

            y_k = 615;
            x_k = 470;;;
        }
        else if (i == 24)
        {

            y_k = 615;
            x_k = 600;
        }
        else if (i == 25)
        {

            y_k = 615;
            x_k = 730;
        }
        else if (i == 26)
        {

            y_k = 615;
            x_k = 860;
        }
        else if (i == 27)
        {

            y_k = 615;
            x_k = 990;
        }

        // !29 òî÷êà28 sqrt30 x31 y32 z33
       
        else if (i == 29)
        {

            y_k = 615;
            x_k = 1100;
        }
        else if (i == 30)
        {

            y_k = 710;
            x_k = 600;
        }
        else if (i == 31)
        {

            y_k = 710;
            x_k = 730;
        }
        else if (i == 32)
        {

            y_k = 710;
            x_k = 860;
        }
        else if (i == 33)
        {

            y_k = 710;
            x_k = 990;
        }
        // 34f( 35g( 36h( 37= 38BkSp 39ln( 40log_

        else if (i == 34)
        {
            y_k = 741 + 15 + 29;
            x_k = 600;
        }
        else if (i == 35)
        {
            y_k = 741 + 15 + 29;
            x_k = 730;
        }
        else if (i == 36)
        {
            y_k = 741 + 15 + 29;
            x_k = 860;
        }
        else if (i == 37)
        {
            y_k = 900;
            x_k = 30;
        }
        else if (i == 38)
        {
            y_k = 615;
            x_k = 1200;
        }
        else if (i == 39)
        {
            y_k = 741 + 15 + 29;
            x_k = 990;
        }
        else if (i == 40)
        {
            y_k = 860;
            x_k = 600;
        }
        else if (i == 41)
        {
            y_k = 615;
            x_k = 1350;
        }
        //  UP/DOWN

        else if (i == 42)
        {
            y_k = 715;
            x_k = 1350;
        }

        else if (i == 43)
        {
            y_k = 815;
            x_k = 1350;
        }

        buttonShapes[i].setPosition(x_k, y_k - 150.f);
        buttonShapes[i].setFillColor(sf::Color::Green);
        if (i == 38) // íàäî âñ¸ ðàçóêðàñèòü
        {
            buttonShapes[i].setFillColor(sf::Color::Black);
        }
        buttonTexts[i].setFont(font);
        buttonTexts[i].setCharacterSize(40);
        buttonTexts[i].setFillColor(sf::Color::White);
        buttonTexts[i].setPosition(buttonShapes[i].getPosition() + sf::Vector2f(10.f, 0.f));
        

        if (i == 0)
            buttonTexts[i].setString(" 0");
        else if (i == 1)
            buttonTexts[i].setString(" 1");
        else if (i == 2)
            buttonTexts[i].setString(" 2");
        else if (i == 3)
            buttonTexts[i].setString(" 3");
        else if (i == 4)
            buttonTexts[i].setString(" 4");
        else if (i == 5)
            buttonTexts[i].setString(" 5");
        else if (i == 6)
            buttonTexts[i].setString(" 6");
        else if (i == 7)
            buttonTexts[i].setString(" 7");
        else if (i == 8)
            buttonTexts[i].setString(" 8");
        else if (i == 9)
            buttonTexts[i].setString(" 9");
        else if (i == 10)
            buttonTexts[i].setString("cos(");
        else if (i == 11)
            buttonTexts[i].setString("sin(");
        else if (i == 12)
            buttonTexts[i].setString("tg(");
        else if (i == 13)
            buttonTexts[i].setString("ctg(");
        else if (i == 14)
            buttonTexts[i].setString("arccos(");
        else if (i == 15)
            buttonTexts[i].setString("arcsin(");
        else if (i == 16)
            buttonTexts[i].setString("arctg(");
        else if (i == 17)
            buttonTexts[i].setString("arcctg(");
        else if (i == 18)
            buttonTexts[i].setString(" (");
        else if (i == 19)
            buttonTexts[i].setString("  +");
        else if (i == 20)
            buttonTexts[i].setString("  -");
        else if (i == 21)
            buttonTexts[i].setString("  )");
        else if (i == 22)
            buttonTexts[i].setString("  *");
        else if (i == 23)
            buttonTexts[i].setString("  /");
        else if (i == 24)
            buttonTexts[i].setString("  ^");
        else if (i == 25)
            buttonTexts[i].setString("  i");
        else if (i == 26)
            buttonTexts[i].setString("pi");
        else if (i == 27)
            buttonTexts[i].setString(" e");// !29 òî÷êà28 sqrt30 x31 y32 z33
        else if (i == 28)
            buttonTexts[i].setString("  .");
        else if (i == 29)
            buttonTexts[i].setString("  !");
        else if (i == 30)
            buttonTexts[i].setString("sqrt(");
        else if (i == 31)
            buttonTexts[i].setString(" x");
        else if (i == 32)
            buttonTexts[i].setString(" y");
        else if (i == 33)
            buttonTexts[i].setString(" z");
        else if (i == 34)
            buttonTexts[i].setString("f(");// 34f( 35g( 36h( 37= 38BkSp 39ln( 40log_
        else if (i == 35)
            buttonTexts[i].setString("g(");
        else if (i == 36)
            buttonTexts[i].setString("h(");
        else if (i == 37)
            buttonTexts[i].setString(" =");
        else if (i == 38)
            buttonTexts[i].setString(" BkSp");
        else if (i == 39)
            buttonTexts[i].setString("ln(");
        else if (i == 40)
            buttonTexts[i].setString("log_");
        else if (i == 41)
            buttonTexts[i].setString(" Enter");
        else if (i == 42)
            buttonTexts[i].setString("  Up");
        else if (i == 43)
            buttonTexts[i].setString("Down");
        
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


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { if (count > 0) { count--; std::cout << count; rectangle.move(0.f, -40.f); } }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { if (count < 6) { count++; std::cout << count; rectangle.move(0.f, 40.f); } }
       


        if (count == 0)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                text0.setString(text0.getString() + std::to_string(1));
                exp0.push_back(std::to_string(1));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                if (!exp0.empty())
                {
                    text0.setString("");
                    exp0.pop_back();
                    for (int j = 0; j < size(exp0); j++)
                        text0.setString(text0.getString() + exp0[j]);
                };
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                text0.setString(text0.getString() + std::to_string(2));
                exp0.push_back(std::to_string(2));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                text0.setString(text0.getString() + std::to_string(3));
                exp0.push_back(std::to_string(3));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                text0.setString(text0.getString() + std::to_string(4));
                exp0.push_back(std::to_string(4));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
                text0.setString(text0.getString() + std::to_string(5));
                exp0.push_back(std::to_string(5));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            {
                text0.setString(text0.getString() + std::to_string(6));
                exp0.push_back(std::to_string(6));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
            {
                text0.setString(text0.getString() + std::to_string(7));
                exp0.push_back(std::to_string(7));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
            {
                text0.setString(text0.getString() + std::to_string(8));
                exp0.push_back(std::to_string(8));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
            {
                text0.setString(text0.getString() + std::to_string(9));
                exp0.push_back(std::to_string(9));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
            {
                text0.setString(text0.getString() + std::to_string(0));
                exp0.push_back(std::to_string(0));
            }
        }


        else if (count == 1)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                text1.setString(text1.getString() + std::to_string(1));
                exp1.push_back(std::to_string(1));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                text1.setString(text1.getString() + std::to_string(2));
                exp1.push_back(std::to_string(2));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                if (!exp1.empty())
                {
                    text1.setString("");
                    exp1.pop_back();
                    for (int j = 0; j < size(exp1); j++)
                        text1.setString(text1.getString() + exp1[j]);
                };
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                text1.setString(text1.getString() + std::to_string(3));
                exp1.push_back(std::to_string(3));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                text1.setString(text1.getString() + std::to_string(4));
                exp1.push_back(std::to_string(4));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
                text1.setString(text1.getString() + std::to_string(5));
                exp1.push_back(std::to_string(5));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            {
                text1.setString(text1.getString() + std::to_string(6));
                exp1.push_back(std::to_string(6));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
            {
                text1.setString(text1.getString() + std::to_string(7));
                exp1.push_back(std::to_string(7));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
            {
                text1.setString(text1.getString() + std::to_string(8));
                exp1.push_back(std::to_string(8));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
            {
                text1.setString(text1.getString() + std::to_string(9));
                exp1.push_back(std::to_string(9));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
            {
                text1.setString(text1.getString() + std::to_string(0));
                exp1.push_back(std::to_string(0));
            }
        }
        
        else if (count == 2)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                text2.setString(text2.getString() + std::to_string(1));
                exp2.push_back(std::to_string(1));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                if (!exp2.empty())
                {
                    text2.setString("");
                    exp2.pop_back();
                    for (int j = 0; j < size(exp2); j++)
                        text2.setString(text2.getString() + exp2[j]);
                };
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                text2.setString(text2.getString() + std::to_string(2));
                exp2.push_back(std::to_string(2));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                text2.setString(text2.getString() + std::to_string(3));
                exp2.push_back(std::to_string(3));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                text2.setString(text2.getString() + std::to_string(4));
                exp2.push_back(std::to_string(4));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
                text2.setString(text2.getString() + std::to_string(5));
                exp2.push_back(std::to_string(5));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            {
                text2.setString(text2.getString() + std::to_string(6));
                exp2.push_back(std::to_string(6));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
            {
                text2.setString(text2.getString() + std::to_string(7));
                exp2.push_back(std::to_string(7));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
            {
                text2.setString(text2.getString() + std::to_string(8));
                exp2.push_back(std::to_string(8));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
            {
                text2.setString(text2.getString() + std::to_string(9));
                exp2.push_back(std::to_string(9));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
            {
                text2.setString(text2.getString() + std::to_string(0));
                exp2.push_back(std::to_string(0));
            }
        }

        else if (count == 3)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                text3.setString(text3.getString() + std::to_string(1));
                exp3.push_back(std::to_string(1));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                if (!exp3.empty())
                {
                    text3.setString("");
                    exp3.pop_back();
                    for (int j = 0; j < size(exp3); j++)
                        text3.setString(text3.getString() + exp3[j]);
                };
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                text3.setString(text3.getString() + std::to_string(2));
                exp3.push_back(std::to_string(2));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                text3.setString(text3.getString() + std::to_string(3));
                exp3.push_back(std::to_string(3));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                text3.setString(text3.getString() + std::to_string(4));
                exp3.push_back(std::to_string(4));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
                text3.setString(text3.getString() + std::to_string(5));
                exp3.push_back(std::to_string(5));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            {
                text3.setString(text3.getString() + std::to_string(6));
                exp3.push_back(std::to_string(6));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
            {
                text3.setString(text3.getString() + std::to_string(7));
                exp3.push_back(std::to_string(7));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
            {
                text3.setString(text3.getString() + std::to_string(8));
                exp3.push_back(std::to_string(8));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
            {
                text3.setString(text3.getString() + std::to_string(9));
                exp3.push_back(std::to_string(9));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
            {
                text3.setString(text3.getString() + std::to_string(0));
                exp3.push_back(std::to_string(0));
            }
        }

        else if (count == 4)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                text4.setString(text4.getString() + std::to_string(1));
                exp4.push_back(std::to_string(1));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                text4.setString(text4.getString() + std::to_string(2));
                exp4.push_back(std::to_string(2));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                if (!exp4.empty())
                {
                    text4.setString("");
                    exp4.pop_back();
                    for (int j = 0; j < size(exp4); j++)
                        text4.setString(text4.getString() + exp4[j]);
                };
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                text4.setString(text4.getString() + std::to_string(3));
                exp4.push_back(std::to_string(3));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                text4.setString(text4.getString() + std::to_string(4));
                exp4.push_back(std::to_string(4));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
                text4.setString(text4.getString() + std::to_string(5));
                exp4.push_back(std::to_string(5));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            {
                text4.setString(text4.getString() + std::to_string(6));
                exp4.push_back(std::to_string(6));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
            {
                text4.setString(text4.getString() + std::to_string(7));
                exp4.push_back(std::to_string(7));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
            {
                text4.setString(text4.getString() + std::to_string(8));
                exp4.push_back(std::to_string(8));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
            {
                text4.setString(text4.getString() + std::to_string(9));
                exp4.push_back(std::to_string(9));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
            {
                text4.setString(text4.getString() + std::to_string(0));
                exp4.push_back(std::to_string(0));
            }
        }

        else if (count == 5)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                text5.setString(text5.getString() + std::to_string(1));
                exp5.push_back(std::to_string(1));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                text5.setString(text5.getString() + std::to_string(2));
                exp5.push_back(std::to_string(2));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                if (!exp5.empty())
                {
                    text5.setString("");
                    exp5.pop_back();
                    for (int j = 0; j < size(exp5); j++)
                        text5.setString(text5.getString() + exp5[j]);
                };
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                text5.setString(text5.getString() + std::to_string(3));
                exp5.push_back(std::to_string(3));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                text5.setString(text5.getString() + std::to_string(4));
                exp5.push_back(std::to_string(4));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
                text5.setString(text5.getString() + std::to_string(5));
                exp5.push_back(std::to_string(5));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            {
                text5.setString(text5.getString() + std::to_string(6));
                exp5.push_back(std::to_string(6));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
            {
                text5.setString(text5.getString() + std::to_string(7));
                exp5.push_back(std::to_string(7));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
            {
                text5.setString(text5.getString() + std::to_string(8));
                exp5.push_back(std::to_string(8));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
            {
                text5.setString(text5.getString() + std::to_string(9));
                exp5.push_back(std::to_string(9));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
            {
                text5.setString(text5.getString() + std::to_string(0));
                exp5.push_back(std::to_string(0));
            }
        }

        else if (count == 6)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                text6.setString(text6.getString() + std::to_string(1));
                exp6.push_back(std::to_string(1));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                if (!exp6.empty())
                {
                    text6.setString("");
                    exp6.pop_back();
                    for (int j = 0; j < size(exp6); j++)
                        text6.setString(text6.getString() + exp6[j]);
                };
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                text6.setString(text6.getString() + std::to_string(2));
                exp6.push_back(std::to_string(2));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                text6.setString(text6.getString() + std::to_string(3));
                exp6.push_back(std::to_string(3));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                text6.setString(text6.getString() + std::to_string(4));
                exp6.push_back(std::to_string(4));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
                text6.setString(text6.getString() + std::to_string(5));
                exp6.push_back(std::to_string(5));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            {
                text6.setString(text6.getString() + std::to_string(6));
                exp6.push_back(std::to_string(6));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
            {
                text6.setString(text6.getString() + std::to_string(7));
                exp6.push_back(std::to_string(7));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
            {
                text6.setString(text6.getString() + std::to_string(8));
                exp6.push_back(std::to_string(8));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
            {
                text6.setString(text6.getString() + std::to_string(9));
                exp6.push_back(std::to_string(9));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
            {
                text6.setString(text6.getString() + std::to_string(0));
                exp6.push_back(std::to_string(0));
            }
        }


        
        if (count == 0)
        {
            text0.setFillColor(sf::Color::Black);
            for (int i = 0; i < 44; i++)
            {
                if (buttonShapes[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
                {
                    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        if (count > 0) { count--; }

                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        if (count < 6) { count++; }
                    }*/

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

                            // Îáðàáîòêà çíà÷åíèÿ íàæàòîé êíîïêè

                            if (i == 1 || i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
                            {
                                text0.setString(text0.getString() + std::to_string(i));
                                exp0.push_back(std::to_string(i));
                            }
                            
                            else if (i == 10)
                            {
                                text0.setString(text0.getString() + "cos(");
                                exp0.push_back("cos(");
                            }
                            else if (i == 11)
                            {
                                text0.setString(text0.getString() + "sin(");
                                exp0.push_back("sin(");
                            }

                            else if (i == 12)
                            {
                                text0.setString(text0.getString() + "tg(");
                                exp0.push_back("tg(");
                            }
                            else if (i == 13)
                            {
                                text0.setString(text0.getString() + "ctg(");
                                exp0.push_back("ctg(");
                            }
                            else if (i == 14)
                            {
                                text0.setString(text0.getString() + "arccos(");
                                exp0.push_back("arccos(");
                            }
                            else if (i == 15)
                            {
                                text0.setString(text0.getString() + "arcsin(");
                                exp0.push_back("arcsin(");
                            }
                            else if (i == 16)
                            {
                                text0.setString(text0.getString() + "arctg(");
                                exp0.push_back("arctg(");
                            }
                            else if (i == 17)
                            {
                                text0.setString(text0.getString() + "arcctg(");
                                exp0.push_back("arcctg(");
                            }
                            else if (i == 18)
                            {
                                text0.setString(text0.getString() + "(");
                                exp0.push_back("(");
                            }

                            else if (i == 19)
                            {
                                text0.setString(text0.getString() + "+");
                                exp0.push_back("+");
                            }
                            else if (i == 20)
                            {
                                text0.setString(text0.getString() + "-");
                                exp0.push_back("-");
                            }
                            else if (i == 21)
                            {
                                text0.setString(text0.getString() + ")");
                                exp0.push_back(")");
                            }
                            else if (i == 22)
                            {
                                text0.setString(text0.getString() + "*");
                                exp0.push_back("*");
                            }
                            else if (i == 23)
                            {
                                text0.setString(text0.getString() + "/");
                                exp0.push_back("/");
                            }
                            else if (i == 24)
                            {
                                text0.setString(text0.getString() + "^");
                                exp0.push_back("^");
                            }
                            else if (i == 25)
                            {
                                text0.setString(text0.getString() + "i");
                                exp0.push_back("i");
                            }
                            else if (i == 26)
                            {
                                text0.setString(text0.getString() + "pi");
                                exp0.push_back("pi");
                            }
                            else if (i == 27)
                            {
                                text0.setString(text0.getString() + "e");
                                exp0.push_back("e");
                            }

                            else if (i == 28)
                            {
                                text0.setString(text0.getString() + ".");
                                exp0.push_back(".");
                            }
                            else if (i == 29)
                            {
                                text0.setString(text0.getString() + "!");
                                exp0.push_back("!");
                            }
                            else if (i == 30) {
                                text0.setString(text0.getString() + "sqrt(");
                                exp0.push_back("sqrt(");
                            }
                            else if (i == 31) {
                                text0.setString(text0.getString() + "x");
                                exp0.push_back("x");
                            }
                            else if (i == 32) {
                                text0.setString(text0.getString() + "y");
                                exp0.push_back("y");
                            }
                            else if (i == 33) {
                                text0.setString(text0.getString() + "z");
                                exp0.push_back("z");
                            }
                            else if (i == 34) {
                                text0.setString(text0.getString() + "f(");
                                exp0.push_back("f(");
                            }
                            else if (i == 35) {
                                text0.setString(text0.getString() + "g(");
                                exp0.push_back("g(");
                            }
                            else if (i == 36) {
                                text0.setString(text0.getString() + "h(");
                                exp0.push_back("h(");
                            }
                            else if (i == 37) {
                                text0.setString(text0.getString() + "=");      // 34f( 35g( 36h( 37= 38BkSp 39ln( 40log_
                                exp0.push_back("=");
                            }
                            else if (i == 38)//backspace
                            {
                                if (!exp0.empty())
                                {
                                    text0.setString("");
                                    exp0.pop_back();
                                    for (int j = 0; j < size(exp0); j++)
                                        text0.setString(text0.getString() + exp0[j]);
                                }
                            }
                            else if (i == 39)
                            {
                                text0.setString(text0.getString() + "ln(");
                                exp0.push_back("ln(");
                            }

                            else if (i == 40)
                            {
                                text0.setString(text0.getString() + "log_");
                                exp0.push_back("log_(");
                            }

                            else if (i == 41) //enter
                            {
                                ;    
                            }

                            else if (i == 42) 
                            {
                                if (count > 0) { count--; std::cout << count; rectangle.move(0.f, -40.f);  }

                            }
                            else if (i == 43)             //rectangle.move(-40.f, 0.f); rectangle.move(40.f, 0.f);
                            {
                                if (count < 6) { count++; std::cout << count; rectangle.move(0.f, 40.f);  }
                            }

                            // Äîáàâèòü åù¸ 20 êíîïîê, íàïèñàòü êðàñèâî èõ ðàñïîëîæåíèå, íå çàáûòü ñäåëàòü íîðì âûâîä ñèìâîëîâ íà ýêðàí 
                            // è ïðîïèñàòü ðåò¸ðíû îò êíîïîê õç êóäà, íàâåðíîå â ìåéí???(Âîïðîñ äëÿ Ñàøè Ôåäîðÿêî)
                            // !29 òî÷êà28 sqrt30 x31 y32 z33
                        }
                    }
                }
            }
            text0.setFillColor(sf::Color::Black);
        }

        if (count == 1)
        {
            
            text1.setFillColor(sf::Color::Black);
            for (int i = 0; i < 44; i++)
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

                            // Îáðàáîòêà çíà÷åíèÿ íàæàòîé êíîïêè
                            if (i == 1 || i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
                            {
                                text1.setString(text1.getString() + std::to_string(i));
                                exp1.push_back(std::to_string(i));
                            }
                           
                            else if (i == 10)
                            {
                                text1.setString(text1.getString() + "cos(");
                                exp1.push_back("cos(");
                            }
                            else if (i == 11)
                            {
                                text1.setString(text1.getString() + "sin(");
                                exp1.push_back("sin(");
                            }

                            else if (i == 12)
                            {
                                text1.setString(text1.getString() + "tg(");
                                exp1.push_back("tg(");
                            }
                            else if (i == 13)
                            {
                                text1.setString(text1.getString() + "ctg(");
                                exp1.push_back("ctg(");
                            }
                            else if (i == 14)
                            {
                                text1.setString(text1.getString() + "arccos(");
                                exp1.push_back("arccos(");
                            }
                            else if (i == 15)
                            {
                                text1.setString(text1.getString() + "arcsin(");
                                exp1.push_back("arcsin(");
                            }
                            else if (i == 16)
                            {
                                text1.setString(text1.getString() + "arctg(");
                                exp1.push_back("arctg(");
                            }
                            else if (i == 17)
                            {
                                text1.setString(text1.getString() + "arcctg(");
                                exp1.push_back("arcctg(");
                            }
                            else if (i == 18)
                            {
                                text1.setString(text1.getString() + "(");
                                exp1.push_back("(");
                            }

                            else if (i == 19)
                            {
                                text1.setString(text1.getString() + "+");
                                exp1.push_back("+");
                            }
                            else if (i == 20)
                            {
                                text1.setString(text1.getString() + "-");
                                exp1.push_back("-");
                            }
                            else if (i == 21)
                            {
                                text1.setString(text1.getString() + ")");
                                exp1.push_back(")");
                            }
                            else if (i == 22)
                            {
                                text1.setString(text1.getString() + "*");
                                exp1.push_back("*");
                            }
                            else if (i == 23)
                            {
                                text1.setString(text1.getString() + "/");
                                exp1.push_back("/");
                            }
                            else if (i == 24)
                            {
                                text1.setString(text1.getString() + "^");
                                exp1.push_back("^");
                            }
                            else if (i == 25)
                            {
                                text1.setString(text1.getString() + "i");
                                exp1.push_back("i");
                            }
                            else if (i == 26)
                            {
                                text1.setString(text1.getString() + "pi");
                                exp1.push_back("pi");
                            }
                            else if (i == 27)
                            {
                                text1.setString(text1.getString() + "e");
                                exp1.push_back("e");
                            }

                            else if (i == 28)
                            {
                                text1.setString(text1.getString() + ".");
                                exp1.push_back(".");
                            }
                            else if (i == 29)
                            {
                                text1.setString(text1.getString() + "!");
                                exp1.push_back("!");
                            }
                            else if (i == 30) {
                                text1.setString(text1.getString() + "sqrt(");
                                exp1.push_back("sqrt(");
                            }
                            else if (i == 31) {
                                text1.setString(text1.getString() + "x");
                                exp1.push_back("x");
                            }
                            else if (i == 32) {
                                text1.setString(text1.getString() + "y");
                                exp1.push_back("y");
                            }
                            else if (i == 33) {
                                text1.setString(text1.getString() + "z");
                                exp1.push_back("z");
                            }
                            else if (i == 34) {
                                text1.setString(text1.getString() + "f(");
                                exp1.push_back("f(");
                            }
                            else if (i == 35) {
                                text1.setString(text1.getString() + "g(");
                                exp1.push_back("g(");
                            }
                            else if (i == 36) {
                                text1.setString(text1.getString() + "h(");
                                exp1.push_back("h(");
                            }
                            else if (i == 37) {
                                text1.setString(text1.getString() + "=");      // 34f( 35g( 36h( 37= 38BkSp 39ln( 40log_
                                exp1.push_back("=");
                            }
                            else if (i == 38)//backspace
                            {
                                if (!exp1.empty())
                                {
                                    text1.setString("");
                                    exp1.pop_back();
                                    for (int j = 0; j < size(exp1); j++)
                                        text1.setString(text1.getString() + exp1[j]);
                                }
                            }
                            else if (i == 39)
                            {
                                text1.setString(text1.getString() + "ln(");
                                exp1.push_back("ln(");
                            }

                            else if (i == 40)
                            {
                                text1.setString(text1.getString() + "log_");
                                exp1.push_back("log_(");
                            }

                            else if (i == 41) //enter
                            {
                                ;
                            }

                            else if (i == 42)
                            {
                                if (count > 0) { count--; std::cout << count; rectangle.move(0.f, -40.f);  }

                            }//  rectangle.move(-40.f, 0.f); rectangle.move(40.f, 0.f);  
                            else if (i == 43)
                            {
                                if (count < 6) { count++; std::cout << count; rectangle.move(0.f, 40.f);   }
                            }

                            // Äîáàâèòü åù¸ 20 êíîïîê, íàïèñàòü êðàñèâî èõ ðàñïîëîæåíèå, íå çàáûòü ñäåëàòü íîðì âûâîä ñèìâîëîâ íà ýêðàí 
                            // è ïðîïèñàòü ðåò¸ðíû îò êíîïîê õç êóäà, íàâåðíîå â ìåéí???(Âîïðîñ äëÿ Ñàøè Ôåäîðÿêî)
                            // !29 òî÷êà28 sqrt30 x31 y32 z33
                        }
                    }
                }
            }

            text1.setFillColor(sf::Color::Black);
        }

        

        if (count == 2)
        {
            
            text2.setFillColor(sf::Color::Black);
            for (int i = 0; i < 44; i++)
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

                            // Îáðàáîòêà çíà÷åíèÿ íàæàòîé êíîïêè
                            if (i == 1 || i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
                            {
                                text2.setString(text2.getString() + std::to_string(i));
                                exp2.push_back(std::to_string(i));
                            }
                            
                            else if (i == 10)
                            {
                                text2.setString(text2.getString() + "cos(");
                                exp2.push_back("cos(");
                            }
                            else if (i == 11)
                            {
                                text2.setString(text2.getString() + "sin(");
                                exp2.push_back("sin(");
                            }

                            else if (i == 12)
                            {
                                text2.setString(text2.getString() + "tg(");
                                exp2.push_back("tg(");
                            }
                            else if (i == 13)
                            {
                                text2.setString(text2.getString() + "ctg(");
                                exp2.push_back("ctg(");
                            }
                            else if (i == 14)
                            {
                                text2.setString(text2.getString() + "arccos(");
                                exp2.push_back("arccos(");
                            }
                            else if (i == 15)
                            {
                                text2.setString(text2.getString() + "arcsin(");
                                exp2.push_back("arcsin(");
                            }
                            else if (i == 16)
                            {
                                text2.setString(text2.getString() + "arctg(");
                                exp2.push_back("arctg(");
                            }
                            else if (i == 17)
                            {
                                text2.setString(text2.getString() + "arcctg(");
                                exp2.push_back("arcctg(");
                            }
                            else if (i == 18)
                            {
                                text2.setString(text2.getString() + "(");
                                exp2.push_back("(");
                            }

                            else if (i == 19)
                            {
                                text2.setString(text2.getString() + "+");
                                exp2.push_back("+");
                            }
                            else if (i == 20)
                            {
                                text2.setString(text2.getString() + "-");
                                exp2.push_back("-");
                            }
                            else if (i == 21)
                            {
                                text2.setString(text2.getString() + ")");
                                exp2.push_back(")");
                            }
                            else if (i == 22)
                            {
                                text2.setString(text2.getString() + "*");
                                exp2.push_back("*");
                            }
                            else if (i == 23)
                            {
                                text2.setString(text2.getString() + "/");
                                exp2.push_back("/");
                            }
                            else if (i == 24)
                            {
                                text2.setString(text2.getString() + "^");
                                exp2.push_back("^");
                            }
                            else if (i == 25)
                            {
                                text2.setString(text2.getString() + "i");
                                exp2.push_back("i");
                            }
                            else if (i == 26)
                            {
                                text2.setString(text2.getString() + "pi");
                                exp2.push_back("pi");
                            }
                            else if (i == 27)
                            {
                                text2.setString(text2.getString() + "e");
                                exp2.push_back("e");
                            }

                            else if (i == 28)
                            {
                                text2.setString(text2.getString() + ".");
                                exp2.push_back(".");
                            }
                            else if (i == 29)
                            {
                                text2.setString(text2.getString() + "!");
                                exp2.push_back("!");
                            }
                            else if (i == 30) {
                                text2.setString(text2.getString() + "sqrt(");
                                exp2.push_back("sqrt(");
                            }
                            else if (i == 31) {
                                text2.setString(text2.getString() + "x");
                                exp2.push_back("x");
                            }
                            else if (i == 32) {
                                text2.setString(text2.getString() + "y");
                                exp2.push_back("y");
                            }
                            else if (i == 33) {
                                text2.setString(text2.getString() + "z");
                                exp2.push_back("z");
                            }
                            else if (i == 34) {
                                text2.setString(text2.getString() + "f(");
                                exp2.push_back("f(");
                            }
                            else if (i == 35) {
                                text2.setString(text2.getString() + "g(");
                                exp2.push_back("g(");
                            }
                            else if (i == 36) {
                                text2.setString(text2.getString() + "h(");
                                exp2.push_back("h(");
                            }
                            else if (i == 37) {
                                text2.setString(text2.getString() + "=");      // 34f( 35g( 36h( 37= 38BkSp 39ln( 40log_
                                exp2.push_back("=");
                            }
                            else if (i == 38)//backspace
                            {
                                if (!exp2.empty())
                                {
                                    text2.setString("");
                                    exp2.pop_back();
                                    for (int j = 0; j < size(exp2); j++)
                                        text2.setString(text2.getString() + exp2[j]);
                                }
                            }
                            else if (i == 39)
                            {
                                text2.setString(text2.getString() + "ln(");
                                exp2.push_back("ln(");
                            }

                            else if (i == 40)
                            {
                                text2.setString(text2.getString() + "log_");
                                exp2.push_back("log_(");
                            }

                            else if (i == 41) //enter
                            {
                                ;
                            }

                            else if (i == 42)
                            {
                                if (count > 0) { count--; std::cout << count; rectangle.move(0.f, -40.f);
                                }

                            }
                            else if (i == 43)//  rectangle.move(-40.f, 0.f); rectangle.move(40.f, 0.f);  
                            {
                                if (count < 6) { count++; std::cout << count; rectangle.move(0.f, 40.f);
                                }
                            }

                            // Äîáàâèòü åù¸ 20 êíîïîê, íàïèñàòü êðàñèâî èõ ðàñïîëîæåíèå, íå çàáûòü ñäåëàòü íîðì âûâîä ñèìâîëîâ íà ýêðàí 
                            // è ïðîïèñàòü ðåò¸ðíû îò êíîïîê õç êóäà, íàâåðíîå â ìåéí???(Âîïðîñ äëÿ Ñàøè Ôåäîðÿêî)
                            // !29 òî÷êà28 sqrt30 x31 y32 z33
                        }
                    }
                }
            }
            text2.setFillColor(sf::Color::Black);
        }

        if (count == 3)
        {
            
            text3.setFillColor(sf::Color::Black);
            for (int i = 0; i < 44; i++)
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

                            // Îáðàáîòêà çíà÷åíèÿ íàæàòîé êíîïêè
                            if (i == 1 || i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
                            {
                                text3.setString(text3.getString() + std::to_string(i));
                                exp3.push_back(std::to_string(i));
                            }
                            
                            else if (i == 10)
                            {
                                text3.setString(text3.getString() + "cos(");
                                exp3.push_back("cos(");
                            }
                            else if (i == 11)
                            {
                                text3.setString(text3.getString() + "sin(");
                                exp3.push_back("sin(");
                            }

                            else if (i == 12)
                            {
                                text3.setString(text3.getString() + "tg(");
                                exp3.push_back("tg(");
                            }
                            else if (i == 13)
                            {
                                text3.setString(text3.getString() + "ctg(");
                                exp3.push_back("ctg(");
                            }
                            else if (i == 14)
                            {
                                text3.setString(text3.getString() + "arccos(");
                                exp3.push_back("arccos(");
                            }
                            else if (i == 15)
                            {
                                text3.setString(text3.getString() + "arcsin(");
                                exp3.push_back("arcsin(");
                            }
                            else if (i == 16)
                            {
                                text3.setString(text3.getString() + "arctg(");
                                exp3.push_back("arctg(");
                            }
                            else if (i == 17)
                            {
                                text3.setString(text3.getString() + "arcctg(");
                                exp3.push_back("arcctg(");
                            }
                            else if (i == 18)
                            {
                                text3.setString(text3.getString() + "(");
                                exp3.push_back("(");
                            }

                            else if (i == 19)
                            {
                                text3.setString(text3.getString() + "+");
                                exp3.push_back("+");
                            }
                            else if (i == 20)
                            {
                                text3.setString(text3.getString() + "-");
                                exp3.push_back("-");
                            }
                            else if (i == 21)
                            {
                                text3.setString(text3.getString() + ")");
                                exp3.push_back(")");
                            }
                            else if (i == 22)
                            {
                                text3.setString(text3.getString() + "*");
                                exp3.push_back("*");
                            }
                            else if (i == 23)
                            {
                                text3.setString(text3.getString() + "/");
                                exp3.push_back("/");
                            }
                            else if (i == 24)
                            {
                                text3.setString(text3.getString() + "^");
                                exp3.push_back("^");
                            }
                            else if (i == 25)
                            {
                                text3.setString(text3.getString() + "i");
                                exp3.push_back("i");
                            }
                            else if (i == 26)
                            {
                                text3.setString(text3.getString() + "pi");
                                exp3.push_back("pi");
                            }
                            else if (i == 27)
                            {
                                text3.setString(text3.getString() + "e");
                                exp3.push_back("e");
                            }

                            else if (i == 28)
                            {
                                text3.setString(text3.getString() + ".");
                                exp3.push_back(".");
                            }
                            else if (i == 29)
                            {
                                text3.setString(text3.getString() + "!");
                                exp3.push_back("!");
                            }
                            else if (i == 30) {
                                text3.setString(text3.getString() + "sqrt(");
                                exp3.push_back("sqrt(");
                            }
                            else if (i == 31) {
                                text3.setString(text3.getString() + "x");
                                exp3.push_back("x");
                            }
                            else if (i == 32) {
                                text3.setString(text3.getString() + "y");
                                exp3.push_back("y");
                            }
                            else if (i == 33) {
                                text3.setString(text3.getString() + "z");
                                exp3.push_back("z");
                            }
                            else if (i == 34) {
                                text3.setString(text3.getString() + "f(");
                                exp3.push_back("f(");
                            }
                            else if (i == 35) {
                                text3.setString(text3.getString() + "g(");
                                exp3.push_back("g(");
                            }
                            else if (i == 36) {
                                text3.setString(text3.getString() + "h(");
                                exp3.push_back("h(");
                            }
                            else if (i == 37) {
                                text3.setString(text3.getString() + "=");      // 34f( 35g( 36h( 37= 38BkSp 39ln( 40log_
                                exp3.push_back("=");
                            }
                            else if (i == 38)//backspace
                            {
                                if (!exp3.empty())
                                {
                                    text3.setString("");
                                    exp3.pop_back();
                                    for (int j = 0; j < size(exp3); j++)
                                        text3.setString(text3.getString() + exp3[j]);
                                }
                            }
                            else if (i == 39)
                            {
                                text3.setString(text3.getString() + "ln(");
                                exp3.push_back("ln(");
                            }

                            else if (i == 40)
                            {
                                text3.setString(text3.getString() + "log_");
                                exp3.push_back("log_(");
                            }

                            else if (i == 41) //enter
                            {
                                ;
                            }

                            else if (i == 42)//  rectangle.move(-40.f, 0.f); rectangle.move(40.f, 0.f); 
                            {
                                if (count > 0) { count--; std::cout << count; rectangle.move(0.f, -40.f);
                                }

                            }
                            else if (i == 43)
                            {
                                if (count < 6) { count++; std::cout << count; rectangle.move(0.f, 40.f);
                                }
                            }

                            // Äîáàâèòü åù¸ 20 êíîïîê, íàïèñàòü êðàñèâî èõ ðàñïîëîæåíèå, íå çàáûòü ñäåëàòü íîðì âûâîä ñèìâîëîâ íà ýêðàí 
                            // è ïðîïèñàòü ðåò¸ðíû îò êíîïîê õç êóäà, íàâåðíîå â ìåéí???(Âîïðîñ äëÿ Ñàøè Ôåäîðÿêî)
                            // !29 òî÷êà28 sqrt30 x31 y32 z33
                        }
                    }
                }
            }
            text3.setFillColor(sf::Color::Black);
        }

        if (count == 4)
        {
            
            text4.setFillColor(sf::Color::Black);
            for (int i = 0; i < 44; i++)
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

                            // Îáðàáîòêà çíà÷åíèÿ íàæàòîé êíîïêè
                            if (i == 1 || i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
                            {
                                text4.setString(text4.getString() + std::to_string(i));
                                exp4.push_back(std::to_string(i));
                            }
                            
                            else if (i == 10)
                            {
                                text4.setString(text4.getString() + "cos(");
                                exp4.push_back("cos(");
                            }
                            else if (i == 11)
                            {
                                text4.setString(text4.getString() + "sin(");
                                exp4.push_back("sin(");
                            }

                            else if (i == 12)
                            {
                                text4.setString(text4.getString() + "tg(");
                                exp4.push_back("tg(");
                            }
                            else if (i == 13)
                            {
                                text4.setString(text4.getString() + "ctg(");
                                exp4.push_back("ctg(");
                            }
                            else if (i == 14)
                            {
                                text4.setString(text4.getString() + "arccos(");
                                exp4.push_back("arccos(");
                            }
                            else if (i == 15)
                            {
                                text4.setString(text4.getString() + "arcsin(");
                                exp4.push_back("arcsin(");
                            }
                            else if (i == 16)
                            {
                                text4.setString(text4.getString() + "arctg(");
                                exp4.push_back("arctg(");
                            }
                            else if (i == 17)
                            {
                                text4.setString(text4.getString() + "arcctg(");
                                exp4.push_back("arcctg(");
                            }
                            else if (i == 18)
                            {
                                text4.setString(text4.getString() + "(");
                                exp4.push_back("(");
                            }

                            else if (i == 19)
                            {
                                text4.setString(text4.getString() + "+");
                                exp4.push_back("+");
                            }
                            else if (i == 20)
                            {
                                text4.setString(text4.getString() + "-");
                                exp4.push_back("-");
                            }
                            else if (i == 21)
                            {
                                text4.setString(text4.getString() + ")");
                                exp4.push_back(")");
                            }
                            else if (i == 22)
                            {
                                text4.setString(text4.getString() + "*");
                                exp4.push_back("*");
                            }
                            else if (i == 23)
                            {
                                text4.setString(text4.getString() + "/");
                                exp4.push_back("/");
                            }
                            else if (i == 24)
                            {
                                text4.setString(text4.getString() + "^");
                                exp4.push_back("^");
                            }
                            else if (i == 25)
                            {
                                text4.setString(text4.getString() + "i");
                                exp4.push_back("i");
                            }
                            else if (i == 26)
                            {
                                text4.setString(text4.getString() + "pi");
                                exp4.push_back("pi");
                            }
                            else if (i == 27)
                            {
                                text4.setString(text4.getString() + "e");
                                exp4.push_back("e");
                            }

                            else if (i == 28)
                            {
                                text4.setString(text4.getString() + ".");
                                exp4.push_back(".");
                            }
                            else if (i == 29)
                            {
                                text4.setString(text4.getString() + "!");
                                exp4.push_back("!");
                            }
                            else if (i == 30) {
                                text4.setString(text4.getString() + "sqrt(");
                                exp4.push_back("sqrt(");
                            }
                            else if (i == 31) {
                                text4.setString(text4.getString() + "x");
                                exp4.push_back("x");
                            }
                            else if (i == 32) {
                                text4.setString(text4.getString() + "y");
                                exp4.push_back("y");
                            }
                            else if (i == 33) {
                                text4.setString(text4.getString() + "z");
                                exp4.push_back("z");
                            }
                            else if (i == 34) {
                                text4.setString(text4.getString() + "f(");
                                exp4.push_back("f(");
                            }
                            else if (i == 35) {
                                text4.setString(text4.getString() + "g(");
                                exp4.push_back("g(");
                            }
                            else if (i == 36) {
                                text4.setString(text4.getString() + "h(");
                                exp4.push_back("h(");
                            }
                            else if (i == 37) {
                                text4.setString(text4.getString() + "=");      // 34f( 35g( 36h( 37= 38BkSp 39ln( 40log_
                                exp4.push_back("=");
                            }
                            else if (i == 38)//backspace
                            {
                                if (!exp4.empty())
                                {
                                    text4.setString("");
                                    exp4.pop_back();
                                    for (int j = 0; j < size(exp4); j++)
                                        text4.setString(text4.getString() + exp4[j]);
                                }
                            }
                            else if (i == 39)
                            {
                                text4.setString(text4.getString() + "ln(");
                                exp4.push_back("ln(");
                            }

                            else if (i == 40)
                            {
                                text4.setString(text4.getString() + "log_");
                                exp4.push_back("log_(");
                            }

                            else if (i == 41) //enter
                            {
                                ;
                            }

                            else if (i == 42)//  rectangle.move(-40.f, 0.f); rectangle.move(40.f, 0.f);
                            {
                                if (count > 0) { count--; std::cout << count; rectangle.move(0.f, -40.f);
                                }

                            }
                            else if (i == 43)
                            {
                                if (count < 6) { count++; std::cout << count; rectangle.move(0.f, 40.f);
                                }
                            }

                            // Äîáàâèòü åù¸ 20 êíîïîê, íàïèñàòü êðàñèâî èõ ðàñïîëîæåíèå, íå çàáûòü ñäåëàòü íîðì âûâîä ñèìâîëîâ íà ýêðàí 
                            // è ïðîïèñàòü ðåò¸ðíû îò êíîïîê õç êóäà, íàâåðíîå â ìåéí???(Âîïðîñ äëÿ Ñàøè Ôåäîðÿêî)
                            // !29 òî÷êà28 sqrt30 x31 y32 z33
                        }
                    }
                }
            }
            text4.setFillColor(sf::Color::Black);
        }

        if (count == 5)
        {
            
            text5.setFillColor(sf::Color::Black);
            for (int i = 0; i < 44; i++)
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

                            // Îáðàáîòêà çíà÷åíèÿ íàæàòîé êíîïêè
                            if (i == 1 || i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
                            {
                                text5.setString(text5.getString() + std::to_string(i));
                                exp5.push_back(std::to_string(i));
                            }
                            
                            else if (i == 10)
                            {
                                text5.setString(text5.getString() + "cos(");
                                exp5.push_back("cos(");
                            }
                            else if (i == 11)
                            {
                                text5.setString(text5.getString() + "sin(");
                                exp5.push_back("sin(");
                            }

                            else if (i == 12)
                            {
                                text5.setString(text5.getString() + "tg(");
                                exp5.push_back("tg(");
                            }
                            else if (i == 13)
                            {
                                text5.setString(text5.getString() + "ctg(");
                                exp5.push_back("ctg(");
                            }
                            else if (i == 14)
                            {
                                text5.setString(text5.getString() + "arccos(");
                                exp5.push_back("arccos(");
                            }
                            else if (i == 15)
                            {
                                text5.setString(text5.getString() + "arcsin(");
                                exp5.push_back("arcsin(");
                            }
                            else if (i == 16)
                            {
                                text5.setString(text5.getString() + "arctg(");
                                exp5.push_back("arctg(");
                            }
                            else if (i == 17)
                            {
                                text5.setString(text5.getString() + "arcctg(");
                                exp5.push_back("arcctg(");
                            }
                            else if (i == 18)
                            {
                                text5.setString(text5.getString() + "(");
                                exp5.push_back("(");
                            }

                            else if (i == 19)
                            {
                                text5.setString(text5.getString() + "+");
                                exp5.push_back("+");
                            }
                            else if (i == 20)
                            {
                                text5.setString(text5.getString() + "-");
                                exp5.push_back("-");
                            }
                            else if (i == 21)
                            {
                                text5.setString(text5.getString() + ")");
                                exp5.push_back(")");
                            }
                            else if (i == 22)
                            {
                                text5.setString(text5.getString() + "*");
                                exp5.push_back("*");
                            }
                            else if (i == 23)
                            {
                                text5.setString(text5.getString() + "/");
                                exp5.push_back("/");
                            }
                            else if (i == 24)
                            {
                                text5.setString(text5.getString() + "^");
                                exp5.push_back("^");
                            }
                            else if (i == 25)
                            {
                                text5.setString(text5.getString() + "i");
                                exp5.push_back("i");
                            }
                            else if (i == 26)
                            {
                                text5.setString(text5.getString() + "pi");
                                exp5.push_back("pi");
                            }
                            else if (i == 27)
                            {
                                text5.setString(text5.getString() + "e");
                                exp5.push_back("e");
                            }

                            else if (i == 28)
                            {
                                text5.setString(text5.getString() + ".");
                                exp5.push_back(".");
                            }
                            else if (i == 29)
                            {
                                text5.setString(text5.getString() + "!");
                                exp5.push_back("!");
                            }
                            else if (i == 30) {
                                text5.setString(text5.getString() + "sqrt(");
                                exp5.push_back("sqrt(");
                            }
                            else if (i == 31) {
                                text5.setString(text5.getString() + "x");
                                exp5.push_back("x");
                            }
                            else if (i == 32) {
                                text5.setString(text5.getString() + "y");
                                exp5.push_back("y");
                            }
                            else if (i == 33) {
                                text5.setString(text5.getString() + "z");
                                exp5.push_back("z");
                            }
                            else if (i == 34) {
                                text5.setString(text5.getString() + "f(");
                                exp5.push_back("f(");
                            }
                            else if (i == 35) {
                                text5.setString(text5.getString() + "g(");
                                exp5.push_back("g(");
                            }
                            else if (i == 36) {
                                text5.setString(text5.getString() + "h(");
                                exp5.push_back("h(");
                            }
                            else if (i == 37) {
                                text5.setString(text5.getString() + "=");      // 34f( 35g( 36h( 37= 38BkSp 39ln( 40log_
                                exp5.push_back("=");
                            }
                            else if (i == 38)//backspace
                            {
                                if (!exp5.empty())
                                {
                                    text5.setString("");
                                    exp5.pop_back();
                                    for (int j = 0; j < size(exp5); j++)
                                        text5.setString(text5.getString() + exp5[j]);
                                }
                            }
                            else if (i == 39)
                            {
                                text5.setString(text5.getString() + "ln(");
                                exp5.push_back("ln(");
                            }

                            else if (i == 40)
                            {
                                text5.setString(text5.getString() + "log_");
                                exp5.push_back("log_(");
                            }

                            else if (i == 41) //enter
                            {
                                ;
                            }

                            else if (i == 42)  //  rectangle.move(-40.f, 0.f); rectangle.move(40.f, 0.f);
                            {
                                if (count > 0) { count--; std::cout << count; rectangle.move(0.f, -40.f);
                                }

                            }
                            else if (i == 43)
                            {
                                if (count < 6) { count++; std::cout << count; rectangle.move(0.f, 40.f);
                                }
                            }

                            // Äîáàâèòü åù¸ 20 êíîïîê, íàïèñàòü êðàñèâî èõ ðàñïîëîæåíèå, íå çàáûòü ñäåëàòü íîðì âûâîä ñèìâîëîâ íà ýêðàí 
                            // è ïðîïèñàòü ðåò¸ðíû îò êíîïîê õç êóäà, íàâåðíîå â ìåéí???(Âîïðîñ äëÿ Ñàøè Ôåäîðÿêî)
                            // !29 òî÷êà28 sqrt30 x31 y32 z33
                        }
                    }
                }
            }
            text5.setFillColor(sf::Color::Black);
        }

        if (count == 6)
        {
            
            text6.setFillColor(sf::Color::Black);
            for (int i = 0; i < 44; i++)
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

                            // Îáðàáîòêà çíà÷åíèÿ íàæàòîé êíîïêè
                            if (i == 1 || i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
                            {
                                text6.setString(text6.getString() + std::to_string(i));
                                exp6.push_back(std::to_string(i));
                            }
                            
                            else if (i == 10)
                            {
                                text6.setString(text6.getString() + "cos(");
                                exp6.push_back("cos(");
                            }
                            else if (i == 11)
                            {
                                text6.setString(text6.getString() + "sin(");
                                exp6.push_back("sin(");
                            }

                            else if (i == 12)
                            {
                                text6.setString(text6.getString() + "tg(");
                                exp6.push_back("tg(");
                            }
                            else if (i == 13)
                            {
                                text6.setString(text6.getString() + "ctg(");
                                exp6.push_back("ctg(");
                            }
                            else if (i == 14)
                            {
                                text6.setString(text6.getString() + "arccos(");
                                exp6.push_back("arccos(");
                            }
                            else if (i == 15)
                            {
                                text6.setString(text6.getString() + "arcsin(");
                                exp6.push_back("arcsin(");
                            }
                            else if (i == 16)
                            {
                                text6.setString(text6.getString() + "arctg(");
                                exp6.push_back("arctg(");
                            }
                            else if (i == 17)
                            {
                                text6.setString(text6.getString() + "arcctg(");
                                exp6.push_back("arcctg(");
                            }
                            else if (i == 18)
                            {
                                text6.setString(text6.getString() + "(");
                                exp6.push_back("(");
                            }

                            else if (i == 19)
                            {
                                text6.setString(text6.getString() + "+");
                                exp6.push_back("+");
                            }
                            else if (i == 20)
                            {
                                text6.setString(text6.getString() + "-");
                                exp6.push_back("-");
                            }
                            else if (i == 21)
                            {
                                text6.setString(text6.getString() + ")");
                                exp6.push_back(")");
                            }
                            else if (i == 22)
                            {
                                text6.setString(text6.getString() + "*");
                                exp6.push_back("*");
                            }
                            else if (i == 23)
                            {
                                text6.setString(text6.getString() + "/");
                                exp6.push_back("/");
                            }
                            else if (i == 24)
                            {
                                text6.setString(text6.getString() + "^");
                                exp6.push_back("^");
                            }
                            else if (i == 25)
                            {
                                text6.setString(text6.getString() + "i");
                                exp6.push_back("i");
                            }
                            else if (i == 26)
                            {
                                text6.setString(text6.getString() + "pi");
                                exp6.push_back("pi");
                            }
                            else if (i == 27)
                            {
                                text6.setString(text6.getString() + "e");
                                exp6.push_back("e");
                            }

                            else if (i == 28)
                            {
                                text6.setString(text6.getString() + ".");
                                exp6.push_back(".");
                            }
                            else if (i == 29)
                            {
                                text6.setString(text6.getString() + "!");
                                exp6.push_back("!");
                            }
                            else if (i == 30) {
                                text6.setString(text6.getString() + "sqrt(");
                                exp6.push_back("sqrt(");
                            }
                            else if (i == 31) {
                                text6.setString(text6.getString() + "x");
                                exp6.push_back("x");
                            }
                            else if (i == 32) {
                                text6.setString(text6.getString() + "y");
                                exp6.push_back("y");
                            }
                            else if (i == 33) {
                                text6.setString(text6.getString() + "z");
                                exp6.push_back("z");
                            }
                            else if (i == 34) {
                                text6.setString(text6.getString() + "f(");
                                exp6.push_back("f(");
                            }
                            else if (i == 35) {
                                text6.setString(text6.getString() + "g(");
                                exp6.push_back("g(");
                            }
                            else if (i == 36) {
                                text6.setString(text6.getString() + "h(");
                                exp6.push_back("h(");
                            }
                            else if (i == 37) {
                                text6.setString(text6.getString() + "=");      // 34f( 35g( 36h( 37= 38BkSp 39ln( 40log_
                                exp6.push_back("=");
                            }
                            else if (i == 38)//backspace
                            {
                                if (!exp6.empty())
                                {
                                    text6.setString("");
                                    exp6.pop_back();
                                    for (int j = 0; j < size(exp6); j++)
                                        text6.setString(text6.getString() + exp6[j]);
                                }
                            }
                            else if (i == 39)
                            {
                                text6.setString(text6.getString() + "ln(");
                                exp6.push_back("ln(");
                            }

                            else if (i == 40)
                            {
                                text6.setString(text6.getString() + "log_");
                                exp6.push_back("log_(");
                            }

                            else if (i == 41) //enter
                            {
                                ;
                            }

                            else if (i == 42)//  rectangle.move(-40.f, 0.f); rectangle.move(40.f, 0.f);
                            {
                                if (count > 0) { count--; std::cout << count; rectangle.move(0.f, -40.f);
                                }

                            }
                            else if (i == 43)
                            {
                                if (count < 6) { count++; std::cout << count; rectangle.move(0.f, 40.f);
                                }
                            }

                            // Äîáàâèòü åù¸ 20 êíîïîê, íàïèñàòü êðàñèâî èõ ðàñïîëîæåíèå, íå çàáûòü ñäåëàòü íîðì âûâîä ñèìâîëîâ íà ýêðàí 
                            // è ïðîïèñàòü ðåò¸ðíû îò êíîïîê õç êóäà, íàâåðíîå â ìåéí???(Âîïðîñ äëÿ Ñàøè Ôåäîðÿêî)
                            // !29 òî÷êà28 sqrt30 x31 y32 z33
                        }
                    }
                }
            }
            text6.setFillColor(sf::Color::Black);
        }
        window.clear(sf::Color::White);
        for (int i = 0; i < 44; i++)
        {
            window.draw(buttonShapes[i]);
            window.draw(buttonTexts[i]);
        }
        window.draw(rectangle);
        window.draw(text0);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.draw(text6);
        window.display();
    }
}
