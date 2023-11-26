#include "author.h"


Author_info_MySq::Author_info_MySq(const std::string& srever, const std::string& user, const std::string& password,
    const std::string& db_name)
{
    try {
        driver = std::make_unique<sql::mysql::MySQL_Driver>();
        con = std::unique_ptr<sql::Connection>(driver->connect(srever, user, password));

        con->setSchema(db_name);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

Author_info_MySq::~Author_info_MySq() {}

void Author_info_MySq::Add_Author(Author_info author) {
    try {
        sql::Statement* stmt = con->createStatement();
        stmt->execute("INSERT INTO author_info (author_name, author_surname) VALUES ('" + author.author_name + "', '" + author.author_surname + "')");

        delete stmt;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

std::vector<Author_info> Author_info_MySq::findBySurname(const std::string& surname)
{
    std::vector<Author_info> resArr;
    try
    {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM author_info WHERE author_surname = '" + surname + "'"));

        while (res->next())
        {
            Author_info author;
            author.author_id = res->getInt("author_id");
            author.author_name = res->getString("author_name");
            author.author_surname = res->getString("author_surname");
            resArr.push_back(author);
        }

        return resArr;
    }
    catch (sql::SQLException& e)
    {
        std::cout << "# ERR: " << e.what();
        std::cout << ", SQLState: " << e.getSQLState() << std::endl;
    }
}

std::vector<Author_info> Author_info_MySq::findByName(const std::string& name)
{
    std::vector<Author_info> resArr;
    try
    {
        std::unique_ptr <sql::Statement> stmt(con->createStatement());
        std::unique_ptr <sql::ResultSet> res(stmt->executeQuery("SELECT * FROM author_info WHERE author_name = '" + name + "'"));

        while (res->next())
        {
            Author_info author;
            author.author_id = res->getInt("author_id");
            author.author_name = res->getString("author_name");
            author.author_surname = res->getString("author_surname");
            resArr.push_back(author);
        }

        return resArr;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQLExeption: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}



Author_info Author_info_MySq::findByID(int author_ID)
{
    Author_info result;
    try
    {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM author_info WHERE author_id = " + std::to_string(author_ID)));

        if (res->next())
        {
            result.author_id = res->getInt("author_id");
            result.author_name = res->getString("author_name");
            result.author_surname = res->getString("author_surname");

        }
        else {
            std::cerr << "Author with ID " << author_ID << " not found." << std::endl;
        }
        return result;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQLExeption: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

bool Author_info_MySq::UpdateAuthor(Author_info author)
{
    try
    {
        if (!con->isValid())
        {
            std::cout << "Bad Connect!" << std::endl;
            return false;
        }
        std::unique_ptr <sql::Statement> check_stmt(con->createStatement());
        std::unique_ptr <sql::ResultSet> check_res(check_stmt->executeQuery("SELECT * FROM author_info WHERE author_id=" + std::to_string(author.author_id)));

        if (!check_res->next())
        {
            std::cout << "Author does not exist";
            return false;
        }

        std::unique_ptr<sql::Statement> update_stmt(con->createStatement());
        int updatetedRows = update_stmt->executeUpdate("UPDATE author_info SET author_name='" + author.author_name + "', author_surname='" + author.author_surname + "' WHERE author_id=" + std::to_string(author.author_id));
        return updatetedRows > 0;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQLExeption: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

bool Author_info_MySq::DeleteAuthor(Author_info author)
{
    try
    {
        std::unique_ptr<sql::Statement> check_stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> check_res(check_stmt->executeQuery("SELECT * FROM author_info WHERE author_id = " + std::to_string(author.author_id)));

        if (!check_res->next())
        {
            std::cout << "Author does not exist" << std::endl;
            return false;
        }

        std::unique_ptr<sql::Statement> delete_stmt(con->createStatement());
        int deleteRow = delete_stmt->executeUpdate("DELETE FROM author_info WHERE author_id = " + std::to_string(author.author_id));
        return deleteRow > 0;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "SQLExeption: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}




