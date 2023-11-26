#include "bookinventory.h"

bookinventory_mySQL::bookinventory_mySQL(const std::string &server, const std::string &user,
                                         const std::string &password, const std::string &db_name)
{
    try
    {
        driver = std::make_unique<sql::mysql::MySQL_Driver>();
        con = std::unique_ptr<sql::Connection>(driver->connect(server, user, password));

        con->setSchema(db_name);
    }catch (sql::SQLException& e)
    {
        std::cerr<< "SQLException: "<< e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

bookinventory_mySQL::~bookinventory_mySQL(){}


void bookinventory_mySQL::Add_bookInventory(bookinventory book_inventory) {
    try
    {
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("INSERT INTO bookinventory(library_code, issuance_mark) VALUES (?, ?)"));
    
        pstmt->setInt(1, book_inventory.library_code);
        pstmt->setBoolean(2, book_inventory.issuance_mark);
        pstmt->execute();
    }
    catch (sql::SQLException& e)
    {
        std::cerr<< "SQLException: "<< e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

std::vector<bookinventory> bookinventory_mySQL::findBy_library_code(const int& library_code)
{
    std::vector<bookinventory> result;
    try
    {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM bookinventory WHERE library_code = " + std::to_string(library_code)));
        while (res->next())
        {
            bookinventory _bookinventory;
            _bookinventory.inventory_number = res->getInt("inventory_number");
            _bookinventory.library_code = res->getInt("library_code");
            _bookinventory.issuance_mark = res->getBoolean("issuance_mark");
            result.push_back(_bookinventory);
        }
        return result;
    } catch(sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }

}

std::vector<bookinventory> bookinventory_mySQL::findBy_issuance_mark(const int& issuance_mark)
{
    std::vector<bookinventory> result;
    try
    {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr <sql::ResultSet> res(stmt->executeQuery("SELECT * FROM bookinventory WHERE issuance_mark = " + std::to_string(issuance_mark)));
        while (res->next())
        {
            bookinventory _bookinventory;
            _bookinventory.inventory_number = res->getInt("inventory_number");
            _bookinventory.library_code = res->getInt("library_code");
            _bookinventory.issuance_mark = res->getBoolean("issuance_mark");
            result.push_back(_bookinventory);
        }
        return result;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
    
}

bool bookinventory_mySQL::UpdateBook(const bookinventory& book)
{
    bookinventory result;
    try
    {
        if (!con->isValid()) {
            std::cout << "Bad con" << std::endl;
            return false;
        }
        std::unique_ptr<sql::Statement> check_stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> check_res(check_stmt->executeQuery("SELECT * FROM bookinventory WHERE inventory_number = " + std::to_string(book.inventory_number)));
        if (!check_res->next())
        {
            std::cout << "Bad request" << std::endl;
            return false;
        }

        std::unique_ptr<sql::Statement> update_stmt(con->createStatement());
        int updaterow = update_stmt->executeUpdate("UPDATE bookinventory SET library_code = '" + std::to_string(book.library_code) + "', issuance_mark = '" + std::to_string(book.issuance_mark) + "' WHERE inventory_number = " + std::to_string(book.inventory_number));
        return updaterow > 0;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}


bool bookinventory_mySQL::DeleteBook(const bookinventory& book)
{
    bookinventory result;
    try
    {
        if (!con->isValid()) {
            std::cout << "Bad con" << std::endl;
            return false;
        }
        std::unique_ptr<sql::Statement> check_stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> check_res(check_stmt->executeQuery("SELECT * FROM bookinventory WHERE inventory_number = " + std::to_string(book.inventory_number)));
        if (!check_res->next())
        {
            std::cout << "Bad request" << std::endl;
            return false;
        }

        std::unique_ptr<sql::Statement> update_stmt(con->createStatement());
        int Delete_row = update_stmt->executeUpdate("DELETE FROM bookinventory WHERE inventory_number = " + std::to_string(book.inventory_number));
        return Delete_row > 0;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}


bookinventory bookinventory_mySQL::findBy_inventory_number(const int& inventory_number)
{
    bookinventory result;
    try
    {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM bookinventory WHERE inventory_number = " + std::to_string(inventory_number)));
        
        if (res->next())
        {
            result.inventory_number = res->getInt("inventory_number");
            result.library_code = res->getInt("library_code");
            result.issuance_mark = res->getInt("issuance_mark");

        }
        else {
            std::cerr << "Author with ID " << inventory_number << " not found." << std::endl;
        }
        return result;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}