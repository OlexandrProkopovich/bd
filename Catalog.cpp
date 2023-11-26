#include "Catalog.h"


Catalog_mySQL::Catalog_mySQL(const std::string& srever, const std::string& user, const std::string& password,
    const std::string& db_name){
    try
    {
        driver = std::make_unique<sql::mysql::MySQL_Driver>() ;
        con = std::unique_ptr<sql::Connection>(driver->connect(srever, user, password));

        con->setSchema(db_name);
    } catch (sql::SQLException& e){
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

Catalog_mySQL::~Catalog_mySQL(){}

void Catalog_mySQL::Add_book(Catalog book) {
    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(
            con->prepareStatement("INSERT INTO catalog (title, author_id, publisher, publisher_year, "
                "publication_type, page_count, topic, price) VALUES (?, ?, ?, ?, ?, ?, ?, ?)"));

        pstmt->setString(1, book.title);
        pstmt->setInt(2, book.author_id);
        pstmt->setString(3, book.publisher);
        pstmt->setInt(4, book.publisher_year);
        pstmt->setString(5, book.publication_type);
        pstmt->setInt(6, book.page_count);
        pstmt->setString(7, book.topic);
        pstmt->setDouble(8, book.price);

        pstmt->execute();

    }
    catch (sql::SQLException& e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

std::vector<Catalog> Catalog_mySQL::findByTitle(const std::string& title)
{
    std::vector<Catalog> result;
    try
    {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM catalog WHERE title = '" + title + "'"));

        while (res->next())
        {
            Catalog Foundedcatalog;
            Foundedcatalog.library_code = res->getInt("library_code");
            Foundedcatalog.title = res->getString("title");
            Foundedcatalog.author_id = res->getInt("author_id");
            Foundedcatalog.publisher = res->getString("publisher");
            Foundedcatalog.publisher_year = res->getInt("publisher_year");
            Foundedcatalog.publication_type = res->getString("publication_type");
            Foundedcatalog.page_count = res->getInt("page_count");
            Foundedcatalog.topic = res->getString("topic");
            Foundedcatalog.price = res->getDouble("price");
            result.push_back(Foundedcatalog);
        }
        return result;
    }
    catch (const sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "getSQLState: " << e.getSQLState() << std::endl;
    }
}


std::vector<Catalog> Catalog_mySQL::findByAuthor_id(const int& author_id)
{
    std::vector<Catalog> result;
    try
    {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM catalog WHERE author_id = '" + std::to_string(author_id) + "'"));

        while (res->next())
        {
            Catalog Foundedcatalog;
            Foundedcatalog.library_code = res->getInt("library_code");
            Foundedcatalog.title = res->getString("title");
            Foundedcatalog.author_id = res->getInt("author_id");
            Foundedcatalog.publisher = res->getString("publisher");
            Foundedcatalog.publisher_year = res->getInt("publisher_year");
            Foundedcatalog.publication_type = res->getString("publication_type");
            Foundedcatalog.page_count = res->getInt("page_count");
            Foundedcatalog.topic = res->getString("topic");
            Foundedcatalog.price = res->getDouble("price");
            result.push_back(Foundedcatalog);
        }
        return result;
    }
    catch (const sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "getSQLState: " << e.getSQLState() << std::endl;
    }
}


std::vector<Catalog> Catalog_mySQL::findByPublisher(const std::string& publisher)
{
    std::vector<Catalog> result;
    try
    {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM catalog WHERE publisher = '" + publisher + "'"));

        while (res->next())
        {
            Catalog Foundedcatalog;
            Foundedcatalog.library_code = res->getInt("library_code");
            Foundedcatalog.title = res->getString("title");
            Foundedcatalog.author_id = res->getInt("author_id");
            Foundedcatalog.publisher = res->getString("publisher");
            Foundedcatalog.publisher_year = res->getInt("publisher_year");
            Foundedcatalog.publication_type = res->getString("publication_type");
            Foundedcatalog.page_count = res->getInt("page_count");
            Foundedcatalog.topic = res->getString("topic");
            Foundedcatalog.price = res->getDouble("price");
            result.push_back(Foundedcatalog);
        }
        return result;
    }
    catch (const sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "getSQLState: " << e.getSQLState() << std::endl;
    }
}

std::vector<Catalog> Catalog_mySQL::findByPublication_type(const std::string& publication_type)
{
    std::vector<Catalog> result;
    try
    {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM catalog WHERE publication_type = '" + publication_type + "'"));

        while (res->next())
        {
            Catalog Foundedcatalog;
            Foundedcatalog.library_code = res->getInt("library_code");
            Foundedcatalog.title = res->getString("title");
            Foundedcatalog.author_id = res->getInt("author_id");
            Foundedcatalog.publisher = res->getString("publisher");
            Foundedcatalog.publisher_year = res->getInt("publisher_year");
            Foundedcatalog.publication_type = res->getString("publication_type");
            Foundedcatalog.page_count = res->getInt("page_count");
            Foundedcatalog.topic = res->getString("topic");
            Foundedcatalog.price = res->getDouble("price");
            result.push_back(Foundedcatalog);
        }
        return result;
    }
    catch (const sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "getSQLState: " << e.getSQLState() << std::endl;
    }
}

Catalog Catalog_mySQL::findByLibrary_code(const int& library_code)
{
    Catalog foundedCatalog;
    try
    {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM catalog WHERE library_code = '" + std::to_string(library_code) + "'"));
       
        while (res->next())
        {
            foundedCatalog.library_code = res->getInt("library_code");
            foundedCatalog.title = res->getString("title");
            foundedCatalog.author_id = res->getInt("author_id");
            foundedCatalog.publisher = res->getString("publisher");
            foundedCatalog.publisher_year = res->getInt("publisher_year");
            foundedCatalog.publication_type = res->getString("publication_type");
            foundedCatalog.page_count = res->getInt("page_count");
            foundedCatalog.topic = res->getString("topic");
            foundedCatalog.price = res->getDouble("price");
        }
        return foundedCatalog;
    } catch(sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "getSQLState: " << e.getSQLState() << std::endl;
    }
}

bool Catalog_mySQL::UpdateBook(const Catalog& book)
{
    try
    {
        if (!con || !con->isValid())
        {
            std::cout << "Bad Connect!" << std::endl;
            return false;
        }

        // Використовуйте параметризований запит для перевірки наявності книги.
        std::unique_ptr<sql::PreparedStatement> checkStmt(con->prepareStatement("SELECT * FROM catalog WHERE library_code = ?"));
        checkStmt->setInt(1, book.library_code);

        std::unique_ptr<sql::ResultSet> checkRes(checkStmt->executeQuery());

        if (!checkRes->next())
        {
            std::cout << "Book with this library code not found" << std::endl;
            return false;
        }

        // Використовуйте параметризований запит для оновлення книги.
        std::unique_ptr<sql::PreparedStatement> updateStmt(con->prepareStatement(
            "UPDATE catalog SET title=?, author_id=?, publisher=?, publisher_year=?, "
            "publication_type=?, page_count=?, topic=?, price=? WHERE library_code=?"));

        updateStmt->setString(1, book.title);
        updateStmt->setInt(2, book.author_id);
        updateStmt->setString(3, book.publisher);
        updateStmt->setInt(4, book.publisher_year);
        updateStmt->setString(5, book.publication_type);
        updateStmt->setInt(6, book.page_count);
        updateStmt->setString(7, book.topic);
        updateStmt->setDouble(8, book.price);
        updateStmt->setInt(9, book.library_code);

        int updatedRows = updateStmt->executeUpdate();

        return updatedRows > 0;
    }
    catch (const sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "getSQLState: " << e.getSQLState() << std::endl;
    }

    return false;
}


bool Catalog_mySQL::DeleteBook(const Catalog& book)
{
    try
    {
        if (!con || !con->isValid())
        {
            std::cerr << "Bad Connect!" << std::endl;
            return false;
        }

        // Використовуйте параметризований запит для перевірки наявності книги.
        std::unique_ptr<sql::PreparedStatement> checkStmt(con->prepareStatement("SELECT * FROM catalog WHERE library_code = ?"));
        checkStmt->setInt(1, book.library_code);

        std::unique_ptr<sql::ResultSet> checkRes(checkStmt->executeQuery());

        if (!checkRes->next())
        {
            std::cerr << "Book with this library code not found" << std::endl;
            return false;
        }

        // Використовуйте параметризований запит для оновлення книги.
        std::unique_ptr<sql::PreparedStatement> updateStmt(con->prepareStatement(
            "DELETE FROM catalog WHERE library_code = ?"));

        updateStmt->setInt(1, book.library_code);
        
        int DeleteRows = updateStmt->executeUpdate();

        return DeleteRows > 0;
    }
    catch (const sql::SQLException& e)
    {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "getSQLState: " << e.getSQLState() << std::endl;
    }

    return false;
}