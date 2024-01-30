#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

int interface_cal()
{
    setlocale(LC_ALL, "RU");
    int a = 0;
    sf::RenderWindow window(sf::VideoMode(1600, 870), "Calculator");
    window.setFramerateLimit(60);

    sf::Font font;

   //char exp0[100][8] = {0};

    //int top_left = 0;

    /*sf::RenderWindow windows(sf::VideoMode(1000, 900), "test");
    windows.display();*/


    std::vector<std::string> exp0{  };
    //std::vector<std::string> exp1{  };
    //std::vector<std::string> exp2{  };
    //std::vector<std::string> exp3{  };
    //std::vector<std::string> exp4{  };
    //std::vector<std::string> exp5{  };
    //std::vector<std::string> exp6{  };
 

    //string** gigachad = new string *[7];


    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Failed to load font!" << std::endl;
        return -1;
    }

    sf::Text text0("", font, 30);
    text0.setFillColor(sf::Color::Black);
    text0.setPosition(20.f, 20.f);
    text0.setColor(sf::Color::Green);

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
 

    sf::RectangleShape buttonShapes[42];
    sf::Text buttonTexts[42];
    bool buttonPressed[42] = { false };

    for (int i = 0; i < 42; i++)
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
        else
        {
            buttonShapes[i].setSize(sf::Vector2f(90.f, 65.f));
        }


        int x_k = 0, y_k = 0;

        // 0-9 точка
        if (i == 1 || i == 2 || i == 3)
            y_k = 805;
        else if (i == 4 || i == 5 || i == 6)
            y_k = 710;
        else if (i == 7 || i == 8 || i == 9)
            y_k = 615;
        else if (i == 0 || i == 28)
            y_k = 900;

        // 0-9 точка
        if (i == 1 || i == 4 || i == 7)
            x_k = 30;
        else if (i == 2 || i == 5 || i == 8)
            x_k = 125;
        else if (i == 9 || i == 6 || i == 3 || i == 28)
            x_k = 220;
        else if (i == 0)
            x_k = 125;


        // тригонометрия + - ( )
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
        // добавил * ^ / i pi e
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

        // !29 точка28 sqrt30 x31 y32 z33
       
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


        buttonShapes[i].setPosition(x_k, y_k - 150.f);
        buttonShapes[i].setFillColor(sf::Color::Green);
        if (i == 38) // надо всё разукрасить
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
            buttonTexts[i].setString(" e");// !29 точка28 sqrt30 x31 y32 z33
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

        for (int i = 0; i < 42; i++)
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
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        if (count > 0) { count--; }

                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        if (count < 6) { count++; }
                    }
                    if (buttonPressed[i])
                    {
                        buttonPressed[i] = false;
                        buttonShapes[i].setFillColor(sf::Color::Green);
                        
                        // Обработка значения нажатой кнопки
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
                                text0.setString(" ");
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
                            


                        // Добавить ещё 20 кнопок, написать красиво их расположение, не забыть сделать норм вывод символов на экран 
                        // и прописать ретёрны от кнопок хз куда, наверное в мейн???(Вопрос для Саши Федоряко)
                        // !29 точка28 sqrt30 x31 y32 z33
                    }
                }
            }
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < 42; i++)
        {
            window.draw(buttonShapes[i]);
            window.draw(buttonTexts[i]);
        }

        window.draw(text0);

        window.display();
    }


}