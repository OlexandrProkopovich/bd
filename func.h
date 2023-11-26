#pragma once
#include "author.h"
#include "Catalog.h"
#include "bookinventory.h"
#include "reader_archive.h"
#include "Book_Lending_Journal.h"

void displayResult_findByName_author(std::string Name, Author_info_MySq& author_info)
{
    std::vector<Author_info> authors = author_info.findByName(Name);
    for (const auto& author : authors)
    {
        std::cout << "Author_ID: " << author.author_id << ", Author_NAME: " << author.author_name <<
            ", Author_SURNAME: " << author.author_surname << std::endl;
    }
}

void displayResult_findBySurname_author(std::string surname, Author_info_MySq& author_info)
{
    std::vector<Author_info> authors = author_info.findBySurname(surname);
    for (const auto& author : authors)
    {
        std::cout << "Author_ID: " << author.author_id << ", Author_NAME: " << author.author_name <<
            ", Author_SURNAME: " << author.author_surname << std::endl;
    }
}

void displayResult_findByID_author(int author_id, Author_info_MySq& author_info)
{
    Author_info founded_author = author_info.findByID(author_id);
    std::cout << "Author ID: " << founded_author.author_id << std::endl;
    std::cout << "Author Name: " << founded_author.author_name << std::endl;
    std::cout << "Author Surname: " << founded_author.author_surname << std::endl;
}

void UpdateAuthor_author(Author_info_MySq& author_info, Author_info& authorToUpdate, int id, std::string name, std::string surname)
{
    authorToUpdate.author_id = id;
    authorToUpdate.author_name = name;
    authorToUpdate.author_surname = surname;

    bool updateResult = author_info.UpdateAuthor(authorToUpdate);

    if (updateResult) {
        std::cout << "Author updated successfully." << std::endl;
    }
    else {
        std::cerr << "Failed to update author." << std::endl;
    }
}

void DeleteAuthor_author(Author_info_MySq& author_info, Author_info AuthorToWantDelete, int id)
{
    AuthorToWantDelete.author_id = id;

    bool deleteResult = author_info.DeleteAuthor(AuthorToWantDelete);

    if (deleteResult)
    {
        std::cout << "DELETED" << std::endl;
    }
    else
    {
        std::cout << "NOT DELETED" << std::endl;
    }

}

void AddAuthor(Author_info_MySq& author_info, Author_info& authoe_Who_Want_Add, std::string name, std::string surname)
{
    authoe_Who_Want_Add.author_name = name;
    authoe_Who_Want_Add.author_surname = surname;

    author_info.Add_Author(authoe_Who_Want_Add);
}

void AddBook(Catalog_mySQL& catalog_info, Catalog& book, std::string title, int author_id, std::string publisher, int publisher_year,
    std::string publication_type, int page_count, std::string topic, double price)
{
    book.title = title;
    book.author_id = author_id;
    book.publisher = publisher;
    book.publisher_year = publisher_year;
    book.publication_type = publication_type;
    book.page_count = page_count;
    book.topic = topic;
    book.price = price;
    catalog_info.Add_book(book);
}

void displayResult_vector_findByTitle_catalog(std::string title, Catalog_mySQL& catalog_info)
{
    std::vector<Catalog> resultVEctor = catalog_info.findByTitle(title);
    for (const auto& book : resultVEctor)
    {
        std::cout << "library_code: " << book.library_code << ", title: " << book.title << ", author_id: " << book.author_id << ", publisher: " << book.publisher << ", publisher_year: " <<
            book.publisher_year << ", publication_type: " << book.publication_type << ", page_count: " << book.page_count << ", topic: " << book.topic << ", price: " << book.price << std::endl;
    }
}

void displayResult_vector_findByAuthor_id_catalog(int author_id, Catalog_mySQL& catalog_info)
{
    std::vector<Catalog> resultVEctor = catalog_info.findByAuthor_id(author_id);
    for (const auto& book : resultVEctor)
    {
        std::cout << "library_code: " << book.library_code << ", title: " << book.title << ", author_id: " << book.author_id << ", publisher: " << book.publisher << ", publisher_year: " <<
            book.publisher_year << ", publication_type: " << book.publication_type << ", page_count: " << book.page_count << ", topic: " << book.topic << ", price: " << book.price << std::endl;
    }
}

void displayResult_vector_findByPublisher_catalog(std::string publisher, Catalog_mySQL& catalog_info)
{
    std::vector<Catalog> resultVEctor = catalog_info.findByPublisher(publisher);
    for (const auto& book : resultVEctor)
    {
        std::cout << "library_code: " << book.library_code << ", title: " << book.title << ", author_id: " << book.author_id << ", publisher: " << book.publisher << ", publisher_year: " <<
            book.publisher_year << ", publication_type: " << book.publication_type << ", page_count: " << book.page_count << ", topic: " << book.topic << ", price: " << book.price << std::endl;
    }
}

void displayResult_vector_findByPublication_type_catalog(std::string publication_type, Catalog_mySQL& catalog_info)
{
    std::vector<Catalog> resultVEctor = catalog_info.findByPublication_type(publication_type);
    for (const auto& book : resultVEctor)
    {
        std::cout << "library_code: " << book.library_code << ", title: " << book.title << ", author_id: " << book.author_id << ", publisher: " << book.publisher << ", publisher_year: " <<
            book.publisher_year << ", publication_type: " << book.publication_type << ", page_count: " << book.page_count << ", topic: " << book.topic << ", price: " << book.price << std::endl;
    }
}


void displayResult_vector_findByLibrary_code_catalog(int library_code, Catalog_mySQL& catalog_info)
{
    Catalog foundedBook;
    foundedBook = catalog_info.findByLibrary_code(library_code);
    std::cout << "library_code: " << foundedBook.library_code << ", title: " << foundedBook.title << ", author_id: " << foundedBook.author_id << ", publisher: " << foundedBook.publisher << ", publisher_year: " <<
        foundedBook.publisher_year << ", publication_type: " << foundedBook.publication_type << ", page_count: " << foundedBook.page_count << ", topic: " << foundedBook.topic << ", price: " << foundedBook.price << std::endl;
}

void UpdateBook(Catalog_mySQL& catalog_info, Catalog& BookToUpdate, int library_code, std::string title, int author_id, std::string publisher, int publisher_year, std::string publication_type, int pahe_count,
    std::string topic, int price)
{
    BookToUpdate.library_code = library_code;
    BookToUpdate.title = title;
    BookToUpdate.author_id = author_id;
    BookToUpdate.publisher = publisher;
    BookToUpdate.publisher_year = publisher_year;
    BookToUpdate.publication_type = publication_type;
    BookToUpdate.page_count = pahe_count;
    BookToUpdate.topic = topic;
    BookToUpdate.price = price;
    bool resulted = catalog_info.UpdateBook(BookToUpdate);

    if (resulted)
    {
        std::cout << "updated succsesful" << std::endl;
    }
    else {
        std::cout << "updated not succsesful" << std::endl;
    }
}


void DeleteBook(Catalog_mySQL& catalog_info, Catalog& BookToUpdate, int library_code)
{
    BookToUpdate.library_code = library_code;
   
    bool resulted = catalog_info.DeleteBook(BookToUpdate);

    if (resulted)
    {
        std::cout << "deleted succsesful" << std::endl;
    }
    else {
        std::cout << "deleted not succsesful" << std::endl;
    }
}

void Add_BookInvetnory(bookinventory_mySQL& bookinventory_info, bookinventory& new_bookInventory, int library_code, bool issuance_mark)
{
    new_bookInventory.library_code = library_code;
    new_bookInventory.issuance_mark = issuance_mark;
    bookinventory_info.Add_bookInventory(new_bookInventory);
}

void displayResult_vector_findByLibrary_code_bookinventory(int library_code, bookinventory_mySQL& book_info)
{
    std::vector<bookinventory> foundedBook = book_info.findBy_library_code(library_code);;
    for (const auto& book : foundedBook)
    {
        std::cout << "inventory_number: " << book.inventory_number << ", library_code: " << book.library_code << ", issuance_mark: " << book.issuance_mark << std::endl;
    }
}

void displayResult_vector_findIssuance_mark_bookinventory(int issuance_mark, bookinventory_mySQL& book_info)
{
    std::vector<bookinventory> foundedBook = book_info.findBy_issuance_mark(issuance_mark);;
    for (const auto& book : foundedBook)
    {
        std::cout << "inventory_number: " << book.inventory_number << ", library_code: " << book.library_code << ", issuance_mark: " << book.issuance_mark << std::endl;
    }
}

void displayResult_vector_find_inventory_number_bookinventory(int inventory_number, bookinventory_mySQL& book_info)
{
    bookinventory foundedInventory = book_info.findBy_inventory_number(inventory_number);;
    std::cout << "inventory_number: " << foundedInventory.inventory_number << ", library_code: " << foundedInventory.library_code << ", issuance_mark: " << foundedInventory.issuance_mark << std::endl;
    
}

void UpdateBook_bookinventory(bookinventory_mySQL& bookinventory_info, bookinventory& BookToUpdate, int inventory_number, int library_code, int issuance_mark)
{
    BookToUpdate.inventory_number = inventory_number;
    BookToUpdate.library_code = library_code;
    BookToUpdate.issuance_mark = issuance_mark;
  
    bool resulted = bookinventory_info.UpdateBook(BookToUpdate);

    if (resulted)
    {
        std::cout << "updated succsesful" << std::endl;
    }
    else {
        std::cout << "updated not succsesful" << std::endl;
    }
}

void DeleteBook_book_inventory(bookinventory_mySQL& bookinventory_info, bookinventory& BookToDelete, int inventory_number)
{
    BookToDelete.inventory_number = inventory_number;

    bool resulted = bookinventory_info.DeleteBook(BookToDelete);

    if (resulted)
    {
        std::cout << "deleted succsesful" << std::endl;
    }
    else {
        std::cout << "deleted not succsesful" << std::endl;
    }
}


void AddReader(reader_archive_mySQL& reader_info, reader_archive& new_reader, std::string first_name, std::string last_name, std::string address, std::string phone, std::string activity_type)
{
    new_reader.first_name = first_name;
    new_reader.last_name = last_name;
    new_reader.address = address;
    new_reader.phone = phone;
    new_reader.activity_type = activity_type;
    reader_info.Add_Reader(new_reader);
}

void displayResult_vector_findBy_first_name_reader_archive(std::string first_name, reader_archive_mySQL& reader_info)
{
    std::vector<reader_archive> readers = reader_info.findBy_first_name(first_name);
    for (const auto& reader : readers)
    {
        std::cout << "reader_card_number: " << reader.reader_card_number << ", first_name: " << reader.first_name << ", last_name: " << reader.last_name <<
            ", last_name: " << reader.last_name << ", address: " << reader.address << ", phone: " << reader.address << ", activity_type: " << reader.activity_type << std::endl;
    }
}

void displayResult_vector_findBy_last_name_reader_archive(std::string last_name, reader_archive_mySQL& reader_info)
{
    std::vector<reader_archive> readers = reader_info.findBy_last_name(last_name);
    for (const auto& reader : readers)
    {
        std::cout << "reader_card_number: " << reader.reader_card_number << ", first_name: " << reader.first_name << ", last_name: " << reader.last_name <<
            ", last_name: " << reader.last_name << ", address: " << reader.address << ", phone: " << reader.address << ", activity_type: " << reader.activity_type << std::endl;
    }
}

void displayResult_vector_findBy_reader_card_number_reader_archive(int reader_card_number, reader_archive_mySQL& reader_info)
{
    reader_archive readers = reader_info.findBy_last_reader_card_number(reader_card_number);
    std::cout << "reader_card_number: " << readers.reader_card_number << ", first_name: " << readers.first_name << ", last_name: " << readers.last_name <<
        ", last_name: " << readers.last_name << ", address: " << readers.address << ", phone: " << readers.address << ", activity_type: " << readers.activity_type << std::endl;

}

void UpdateBook_Reader(reader_archive_mySQL& reader_info, reader_archive& ReaderToUpdate, int reader_card_number, std::string first_name, std::string last_name, std::string address, std::string phone, std::string activity_type)
{
    ReaderToUpdate.reader_card_number = reader_card_number;
    ReaderToUpdate.first_name = first_name;
    ReaderToUpdate.last_name = last_name;
    ReaderToUpdate.address = address;
    ReaderToUpdate.phone = phone;
    ReaderToUpdate.address = activity_type;
   

    bool resulted = reader_info.UpdateReader(ReaderToUpdate);

    if (resulted)
    {
        std::cout << "updated succsesful" << std::endl;
    }
    else {
        std::cout << "updated not succsesful" << std::endl;
    }
}

void DeleteReader(reader_archive_mySQL& reader_info, reader_archive& ReaderToDelete, int reader_card_number)
{
    ReaderToDelete.reader_card_number = reader_card_number;

    bool resulted = reader_info.DeleteReader(ReaderToDelete);

    if (resulted)
    {
        std::cout << "deleted succsesful" << std::endl;
    }
    else {
        std::cout << "deleted not succsesful" << std::endl;
    }
}



void Add_book_lending_journal(book_lending_journal_mySQL& book_lending_journal_info, book_lending_journal& book_lending_journal_Who_Want_Add, int inventory_number, int reader_card_number, std::string lending_date, std::string planned_return_date)
{
    book_lending_journal_Who_Want_Add.inventory_number = inventory_number;
    book_lending_journal_Who_Want_Add.reader_card_number = reader_card_number;
    book_lending_journal_Who_Want_Add.lending_date = lending_date;
    book_lending_journal_Who_Want_Add.planned_return_date = planned_return_date;
    book_lending_journal_info.add_book_lending_journal(book_lending_journal_Who_Want_Add);
}

void displayResult_vector_findBy_inventory_number_lending(int inventory_number, book_lending_journal_mySQL& book_lending_journal_info)
{
    std::vector<book_lending_journal> res = book_lending_journal_info.findBy_inventory_number(inventory_number);
    for (const auto& book_lending_journal : res)
    {
        std::cout << "lending_id : " << book_lending_journal.lending_id << ", inventory_number : " << book_lending_journal.inventory_number << ", reader_card_number : " << book_lending_journal.reader_card_number <<
            ", lending_date: " << book_lending_journal.lending_date << ", planned_return_date: " << book_lending_journal.planned_return_date << std::endl;
    }
}

void displayResult_vector_findBy_reader_card_number_lending(int reader_card_number, book_lending_journal_mySQL& book_lending_journal_info)
{
    std::vector<book_lending_journal> res = book_lending_journal_info.findBy_reader_card_number(reader_card_number);
    for (const auto& book_lending_journal : res)
    {
        std::cout << "lending_id : " << book_lending_journal.lending_id << ", inventory_number : " << book_lending_journal.inventory_number << ", reader_card_number : " << book_lending_journal.reader_card_number <<
            ", lending_date: " << book_lending_journal.lending_date << ", planned_return_date: " << book_lending_journal.planned_return_date << std::endl;
    }
}

void displayResult_vector_findBy_findBy_lending_id_lending(int lending_id, book_lending_journal_mySQL& book_lending_journal_info)
{
    book_lending_journal book_lending_journal = book_lending_journal_info.findBy_lending_id(lending_id);
    std::cout << "lending_id : " << book_lending_journal.lending_id << ", inventory_number : " << book_lending_journal.inventory_number << ", reader_card_number : " << book_lending_journal.reader_card_number <<
        ", lending_date: " << book_lending_journal.lending_date << ", planned_return_date: " << book_lending_journal.planned_return_date << std::endl;
}

void Update_book_lending_journal(book_lending_journal_mySQL& book_lending_journal_info, book_lending_journal& book_lending_journal_Who_Update, int lending_id, int inventory_number, int reader_card_number, std::string lending_date, std::string planned_return_date)
{
    book_lending_journal_Who_Update.lending_id = lending_id;
    book_lending_journal_Who_Update.inventory_number = inventory_number;
    book_lending_journal_Who_Update.reader_card_number = reader_card_number;
    book_lending_journal_Who_Update.lending_date = lending_date;
    book_lending_journal_Who_Update.planned_return_date = planned_return_date;


    bool resulted = book_lending_journal_info.Updatebook_lending_journal(book_lending_journal_Who_Update);

    if (resulted)
    {
        std::cout << "updated succsesful" << std::endl;
    }
    else {
        std::cout << "updated not succsesful" << std::endl;
    }
}

void Delete_book_lending_journal(book_lending_journal_mySQL& book_lending_journal_info, book_lending_journal& book_lending_journal_Who_Delete, int lending_id)
{
    book_lending_journal_Who_Delete.lending_id = lending_id;

    bool resulted = book_lending_journal_info.Deletebook_lending_journal(book_lending_journal_Who_Delete);

    if (resulted)
    {
        std::cout << "deleted succsesful" << std::endl;
    }
    else {
        std::cout << "deleted not succsesful" << std::endl;
    }
}
