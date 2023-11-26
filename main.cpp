#include <SFML/Graphics.hpp>
#include <iostream>
#include "windows.hpp"
#include "Interface.h"
#include "GameMenu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "TestSFML");

    Interface background("C:/Users/sasha/Desktop/project/images/background.png", 1024, 1024);

    sf::Text Titul;
    background.WorkText("C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", Titul, 160, 50, L"Choose table", 200, sf::Color(237, 147, 0), 0, sf::Color::Black);

    std::vector<sf::String> name_button = { L"author_info", L"Catalog", L"bookinventory", L"Book_Lending_Journal", L"reader_archive", L"Exit" };

    game::GameMenu mymenu(window, 500, 400, 60, 90, name_button);
    mymenu.setColorTextMenu(sf::Color(237, 147, 0), sf::Color::Red, sf::Color::Black);
    mymenu.AlignMenu(2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
            if (event.type == sf::Event::KeyReleased)
            {

                if (event.key.code == sf::Keyboard::Up) { mymenu.MoveUp(); }
                if (event.key.code == sf::Keyboard::Down) { mymenu.MoveDown(); }
                if (event.key.code == sf::Keyboard::Return)
                {
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0: author_info_func(); break;
                    case 1: Catalog_func(); break;
                    case 2: bookinventory_func(); break;
                    case 3: Book_Lending_Journal_func(); break;
                    case 4: reader_archive_func(); break;
                    case 5: window.close(); break;
                    }
                }
            }
        }
        window.clear();
        window.draw(background.background);
        window.draw(Titul);
        mymenu.draw();
        window.display();
    }
}
