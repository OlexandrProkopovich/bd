#pragma once
#include "Catalog.h"  
#include "author.h"
#include "bookinventory.h"
#include "Book_Lending_Journal.h"
#include "reader_archive.h"
#include "func.h"
#include "windows.hpp"
#include "button.hpp" 
#include "Interface.h"


void Catalog_func() {
    sf::RenderWindow Catalog_win(sf::VideoMode(800, 600), "Table Interaction", sf::Style::Close);

    Catalog_mySQL catalog_info("localhost:3306", "root", "qwerty", "norm1");

    button AddBooks(150, 50, 20, 20, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "Add Book", 20);
    button findByTitle(150, 50, 20, 80, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findByTitle", 20);
    button findByAuthor_id(150, 50, 20, 140, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findByAuthor_id", 20);
    button findByPublisher(150, 50, 20, 200, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findByPublisher", 20);
    button findByPublication_type(150, 50, 20, 260, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findByPublication_type", 20);
    button findByLibrary_code(150, 50, 20, 320, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findByLibrary_code", 20);
    button UpdateBooks(150, 50, 20, 380, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "UpdateBook", 20);
    button DeleteBooks(150, 50, 20, 440, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "DeleteBook", 20);

    Catalog book;

    while (Catalog_win.isOpen()) {
        sf::Event event;
        while (Catalog_win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Catalog_win.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) { Catalog_win.close(); }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = Catalog_win.mapPixelToCoords(sf::Mouse::getPosition(Catalog_win));


                if (AddBooks._button.getGlobalBounds().contains(mousePos)) {
                    AddBook(catalog_info, book, "rex", 1, "sdagfds", 2005, "sdgsda", 205, "1254sd", 45.99);
                    std::cout << "AddBooks Button Pressed" << std::endl;
                }

                if (findByTitle._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findByTitle_catalog("412", catalog_info);
                    std::cout << "findByTitle Button Pressed" << std::endl;
                }

                if (findByAuthor_id._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findByAuthor_id_catalog(1, catalog_info);
                    std::cout << "findByAuthor_id Button Pressed" << std::endl;
                }

                if (findByPublisher._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findByPublisher_catalog("12412", catalog_info);
                    std::cout << "findByPublisher Button Pressed" << std::endl;
                }

                if (findByPublication_type._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findByPublication_type_catalog("sdgsda", catalog_info);
                    std::cout << "findByPublication_type Button Pressed" << std::endl;
                }

                if (findByLibrary_code._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findByLibrary_code_catalog(6, catalog_info);
                    std::cout << "findByLibrary_code Button Pressed" << std::endl;
                }

                if (UpdateBooks._button.getGlobalBounds().contains(mousePos)) {
                    UpdateBook(catalog_info, book, 3, "title", 2, "publisher", 1991, "type", 123, "topic", 499.99);
                    std::cout << "UpdateBooks Button Pressed" << std::endl;
                }

                if (DeleteBooks._button.getGlobalBounds().contains(mousePos)) {
                    DeleteBook(catalog_info, book, 3);
                    std::cout << "DeleteBooks Button Pressed" << std::endl;
                }
            }


        }

        Catalog_win.clear();
        Catalog_win.draw(AddBooks._button);
        Catalog_win.draw(AddBooks.text);

        Catalog_win.draw(findByTitle._button);
        Catalog_win.draw(findByTitle.text);


        Catalog_win.draw(findByAuthor_id._button);
        Catalog_win.draw(findByAuthor_id.text);


        Catalog_win.draw(findByPublisher._button);
        Catalog_win.draw(findByPublisher.text);


        Catalog_win.draw(findByPublication_type._button);
        Catalog_win.draw(findByPublication_type.text);


        Catalog_win.draw(findByLibrary_code._button);
        Catalog_win.draw(findByLibrary_code.text);


        Catalog_win.draw(UpdateBooks._button);
        Catalog_win.draw(UpdateBooks.text);


        Catalog_win.draw(DeleteBooks._button);
        Catalog_win.draw(DeleteBooks.text);
        Catalog_win.display();
    }
}

void bookinventory_func() {
    sf::RenderWindow bookinventory_win(sf::VideoMode(800, 600), "Table Interaction", sf::Style::Close);

    bookinventory_mySQL bookinventory_info("localhost:3306", "root", "qwerty", "norm1");

    button Add_bookInventory(150, 50, 20, 20, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "Add_bookInventory", 20);
    button findBy_library_code(150, 50, 20, 80, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findBy_library_code", 20);
    button findBy_issuance_mark(150, 50, 20, 140, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findBy_issuance_mark", 20);
    button findBy_inventory_number(150, 50, 20, 200, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findBy_inventory_number", 20);
    button UpdateBooks(150, 50, 20, 260, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "UpdateBooks", 20);
    button DeleteBooks(150, 50, 20, 320, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "DeleteBooks", 20);

    bookinventory inventory;

    while (bookinventory_win.isOpen()) {
        sf::Event event;
        while (bookinventory_win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                bookinventory_win.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) { bookinventory_win.close(); }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = bookinventory_win.mapPixelToCoords(sf::Mouse::getPosition(bookinventory_win));


                if (Add_bookInventory._button.getGlobalBounds().contains(mousePos)) {
                    Add_BookInvetnory(bookinventory_info, inventory, 3, 1);
                    std::cout << "Add_bookInventory Button Pressed" << std::endl;
                }

                if (findBy_library_code._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findByLibrary_code_bookinventory(4, bookinventory_info);
                    std::cout << "findBy_library_code Button Pressed" << std::endl;
                }

                if (findBy_issuance_mark._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findIssuance_mark_bookinventory(1, bookinventory_info);
                    std::cout << "findBy_issuance_mark Button Pressed" << std::endl;
                }

                if (findBy_inventory_number._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_find_inventory_number_bookinventory(6, bookinventory_info);
                    std::cout << "findBy_inventory_number Button Pressed" << std::endl;
                }

                if (UpdateBooks._button.getGlobalBounds().contains(mousePos)) {
                    UpdateBook_bookinventory(bookinventory_info, inventory, 6, 4, 0);
                    std::cout << "UpdateBooks Button Pressed" << std::endl;
                }

                if (DeleteBooks._button.getGlobalBounds().contains(mousePos)) {
                    DeleteBook_book_inventory(bookinventory_info, inventory, 6);
                    std::cout << "DeleteBooks Button Pressed" << std::endl;
                }

            }

            bookinventory_win.clear();

            bookinventory_win.draw(Add_bookInventory._button);
            bookinventory_win.draw(Add_bookInventory.text);

            bookinventory_win.draw(findBy_library_code._button);
            bookinventory_win.draw(findBy_library_code.text);


            bookinventory_win.draw(findBy_issuance_mark._button);
            bookinventory_win.draw(findBy_issuance_mark.text);


            bookinventory_win.draw(findBy_inventory_number._button);
            bookinventory_win.draw(findBy_inventory_number.text);


            bookinventory_win.draw(UpdateBooks._button);
            bookinventory_win.draw(UpdateBooks.text);


            bookinventory_win.draw(DeleteBooks._button);
            bookinventory_win.draw(DeleteBooks.text);

            bookinventory_win.display();
        }
    }
}

void author_info_func() {
    sf::RenderWindow author_info_win(sf::VideoMode(800, 600), "Table Interaction", sf::Style::Close);

    Author_info_MySq author_info("localhost:3306", "root", "qwerty", "norm1");

    button AddAuthors(150, 50, 20, 20, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "AddAuthor", 20);
    button findBySurname(150, 50, 20, 80, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findBy_library_code", 20);
    button findByName(150, 50, 20, 140, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findByName", 20);
    button findByID(150, 50, 20, 200, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findByID", 20);
    button UpdateAuthors(150, 50, 20, 260, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "UpdateAuthors", 20);
    button DeleteAuthors(150, 50, 20, 320, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "DeleteAuthors", 20);

    Author_info author;

    while (author_info_win.isOpen()) {
        sf::Event event;
        while (author_info_win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                author_info_win.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) { author_info_win.close(); }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = author_info_win.mapPixelToCoords(sf::Mouse::getPosition(author_info_win));


                if (AddAuthors._button.getGlobalBounds().contains(mousePos)) {
                    AddAuthor(author_info, author, "sanek", "sasha");
                    std::cout << "AddAuthors Button Pressed" << std::endl;
                }

                if (findBySurname._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_findBySurname_author("3", author_info);
                    std::cout << "findBySurname Button Pressed" << std::endl;
                }

                if (findByName._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_findByName_author("dota", author_info);
                    std::cout << "findByName Button Pressed" << std::endl;
                }

                if (findByID._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_findByID_author(1, author_info);
                    std::cout << "findByID Button Pressed" << std::endl;
                }

                if (UpdateAuthors._button.getGlobalBounds().contains(mousePos)) {
                    UpdateAuthor_author(author_info, author, 1, "dota", "4");
                    std::cout << "AddAuthors Button Pressed" << std::endl;
                }

                if (DeleteAuthors._button.getGlobalBounds().contains(mousePos)) {
                    DeleteAuthor_author(author_info, author, 13);
                    std::cout << "AddAuthors Button Pressed" << std::endl;
                }

            }
        }

        author_info_win.clear();
        author_info_win.draw(AddAuthors._button);
        author_info_win.draw(AddAuthors.text);

        author_info_win.draw(findBySurname._button);
        author_info_win.draw(findBySurname.text);


        author_info_win.draw(findByName._button);
        author_info_win.draw(findByName.text);


        author_info_win.draw(findByID._button);
        author_info_win.draw(findByID.text);


        author_info_win.draw(UpdateAuthors._button);
        author_info_win.draw(UpdateAuthors.text);


        author_info_win.draw(DeleteAuthors._button);
        author_info_win.draw(DeleteAuthors.text);

        author_info_win.display();
    }
}

void Book_Lending_Journal_func() {
    sf::RenderWindow Book_Lending_Journal_win(sf::VideoMode(800, 600), "Table Interaction", sf::Style::Close);

    book_lending_journal_mySQL Book_Lending_Journal_info("localhost:3306", "root", "qwerty", "norm1");

    button add_book_lending_journal(150, 50, 20, 20, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "add_book_lending_journal", 20);
    button findBy_inventory_number(150, 50, 20, 80, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findBy_inventory_number", 20);
    button findBy_reader_card_number(150, 50, 20, 140, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findBy_reader_card_number", 20);
    button findBy_lending_id(150, 50, 20, 200, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findBy_lending_id", 20);
    button Updatebook_lending_journal(150, 50, 20, 260, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "Updatebook_lending_journal", 20);
    button Deletebook_lending_journal(150, 50, 20, 320, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "Deletebook_lending_journal", 20);

    book_lending_journal journal;

    while (Book_Lending_Journal_win.isOpen()) {
        sf::Event event;
        while (Book_Lending_Journal_win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Book_Lending_Journal_win.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) { Book_Lending_Journal_win.close(); }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = Book_Lending_Journal_win.mapPixelToCoords(sf::Mouse::getPosition(Book_Lending_Journal_win));


                if (add_book_lending_journal._button.getGlobalBounds().contains(mousePos)) {
                    Add_book_lending_journal(Book_Lending_Journal_info, journal, 7, 3, "2021-12-12", "2023-12-21");
                    std::cout << "add_book_lending_journal Button Pressed" << std::endl;
                }


                if (findBy_inventory_number._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findBy_inventory_number_lending(6, Book_Lending_Journal_info);
                    std::cout << "findBy_inventory_number Button Pressed" << std::endl;
                }


                if (findBy_reader_card_number._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findBy_reader_card_number_lending(2, Book_Lending_Journal_info);
                    std::cout << "findBy_reader_card_number Button Pressed" << std::endl;
                }


                if (findBy_lending_id._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findBy_findBy_lending_id_lending(5, Book_Lending_Journal_info);
                    std::cout << "findBy_lending_id Button Pressed" << std::endl;
                }


                if (Updatebook_lending_journal._button.getGlobalBounds().contains(mousePos)) {
                    Update_book_lending_journal(Book_Lending_Journal_info, journal, 5, 6, 3, "2024-12-21", "2025-12-28");
                    std::cout << "Updatebook_lending_journal Button Pressed" << std::endl;
                }


                if (Deletebook_lending_journal._button.getGlobalBounds().contains(mousePos)) {
                    Delete_book_lending_journal(Book_Lending_Journal_info, journal, 5);
                    std::cout << "Deletebook_lending_journal Button Pressed" << std::endl;
                }

            }
        }

        Book_Lending_Journal_win.clear();
        Book_Lending_Journal_win.draw(add_book_lending_journal._button);
        Book_Lending_Journal_win.draw(add_book_lending_journal.text);

        Book_Lending_Journal_win.draw(findBy_inventory_number._button);
        Book_Lending_Journal_win.draw(findBy_inventory_number.text);


        Book_Lending_Journal_win.draw(findBy_reader_card_number._button);
        Book_Lending_Journal_win.draw(findBy_reader_card_number.text);


        Book_Lending_Journal_win.draw(findBy_lending_id._button);
        Book_Lending_Journal_win.draw(findBy_lending_id.text);


        Book_Lending_Journal_win.draw(Updatebook_lending_journal._button);
        Book_Lending_Journal_win.draw(Updatebook_lending_journal.text);


        Book_Lending_Journal_win.draw(Deletebook_lending_journal._button);
        Book_Lending_Journal_win.draw(Deletebook_lending_journal.text);

        Book_Lending_Journal_win.display();
    }
}

void reader_archive_func() {
    sf::RenderWindow reader_archive_win(sf::VideoMode(800, 600), "Table Interaction", sf::Style::Close);

    reader_archive_mySQL reader_archive_info("localhost:3306", "root", "qwerty", "norm1");

    button Add_Reader(150, 50, 20, 20, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "Add_Reader", 20);
    button findBy_first_name(150, 50, 20, 80, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findBy_first_name", 20);
    button findBy_last_name(150, 50, 20, 140, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findBy_last_name", 20);
    button findBy_last_reader_card_number(150, 50, 20, 200, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "findBy_last_reader_card_number", 20);
    button UpdateReader(150, 50, 20, 260, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "UpdateReader", 20);
    button DeleteReaders(150, 50, 20, 320, sf::Color::Red, sf::Color::White, "C:/Users/sasha/source/repos/Game1/font/Maestroc.otf", "DeleteReader", 20);

    reader_archive reader;

    while (reader_archive_win.isOpen()) {
        sf::Event event;
        while (reader_archive_win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                reader_archive_win.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) { reader_archive_win.close(); }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = reader_archive_win.mapPixelToCoords(sf::Mouse::getPosition(reader_archive_win));


                if (Add_Reader._button.getGlobalBounds().contains(mousePos)) {
                    AddReader(reader_archive_info, reader, "vadim", "sasha", "franka", "1254215", "student");
                    std::cout << "Add_Reader Button Pressed" << std::endl;
                }

                if (findBy_first_name._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findBy_first_name_reader_archive("sanek", reader_archive_info);
                    std::cout << "findBy_first_name Button Pressed" << std::endl;
                }

                if (findBy_last_name._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findBy_last_name_reader_archive("sanel", reader_archive_info);
                    std::cout << "findBy_last_name Button Pressed" << std::endl;
                }

                if (findBy_last_reader_card_number._button.getGlobalBounds().contains(mousePos)) {
                    displayResult_vector_findBy_reader_card_number_reader_archive(2, reader_archive_info);
                    std::cout << "findBy_last_reader_card_number Button Pressed" << std::endl;
                }

                if (UpdateReader._button.getGlobalBounds().contains(mousePos)) {
                    UpdateBook_Reader(reader_archive_info, reader, 3, "vadim", "yat", "kyiv", "0567812", "operator");
                    std::cout << "UpdateReader Button Pressed" << std::endl;
                }

                if (DeleteReaders._button.getGlobalBounds().contains(mousePos)) {
                    DeleteReader(reader_archive_info, reader, 2);
                    std::cout << "DeleteReader Button Pressed" << std::endl;
                }
            }
        }

        reader_archive_win.clear();
        reader_archive_win.draw(Add_Reader._button);
        reader_archive_win.draw(Add_Reader.text);

        reader_archive_win.draw(findBy_first_name._button);
        reader_archive_win.draw(findBy_first_name.text);


        reader_archive_win.draw(findBy_last_name._button);
        reader_archive_win.draw(findBy_last_name.text);


        reader_archive_win.draw(findBy_last_reader_card_number._button);
        reader_archive_win.draw(findBy_last_reader_card_number.text);


        reader_archive_win.draw(UpdateReader._button);
        reader_archive_win.draw(UpdateReader.text);


        reader_archive_win.draw(DeleteReaders._button);
        reader_archive_win.draw(DeleteReaders.text);

        reader_archive_win.display();
    }
}
;