#pragma  once
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>
#include <iostream>
#include <memory>
#include <vector>

struct Catalog
{
    int library_code;
    std::string title;
    int author_id;
    std::string publisher;
    int publisher_year;
    std::string publication_type;
    int page_count;
    std::string topic;
    double price;
};

class Catalog_DAO {
public:
    virtual ~Catalog_DAO() = default;
    virtual void Add_book(Catalog book) = 0;
    virtual std::vector<Catalog> findByTitle(const std::string& title) = 0;
    virtual std::vector<Catalog> findByAuthor_id(const int& author_id) = 0;
    virtual std::vector<Catalog> findByPublisher(const std::string& publisher) = 0;
    virtual std::vector<Catalog> findByPublication_type(const std::string& publication_type) = 0;
    virtual Catalog findByLibrary_code(const int& libarary_code) = 0;
    virtual bool UpdateBook(const Catalog& book) = 0;
    virtual bool DeleteBook(const Catalog& book) = 0;
};

class Catalog_mySQL : public Catalog_DAO {
private:
    std::unique_ptr<sql::mysql::MySQL_Driver> driver;
    std::unique_ptr<sql::Connection> con;
public:
    Catalog_mySQL(const std::string& srever, const std::string& user, const std::string& password,
        const std::string& db_name);
    ~Catalog_mySQL() override;
    void Add_book(Catalog book) override;
    std::vector<Catalog> findByTitle(const std::string& title) override;
    std::vector<Catalog> findByAuthor_id(const int& author_id) override; 
    std::vector<Catalog> findByPublisher(const std::string& publisher) override;
    std::vector<Catalog> findByPublication_type(const std::string& publication_type) override;
    Catalog findByLibrary_code(const int& libarary_code) override;
    bool UpdateBook(const Catalog& book) override;
    bool DeleteBook(const Catalog& book) override;
};



