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

struct bookinventory{
    int inventory_number;
    int library_code;
    int issuance_mark;
};


class bookinventory_DAO{
public:
    virtual ~bookinventory_DAO() = default;
    virtual void Add_bookInventory(bookinventory book_inventory) = 0;
    virtual std::vector<bookinventory> findBy_library_code(const int& library_code) = 0;
    virtual std::vector<bookinventory> findBy_issuance_mark(const int& issuance_mark) = 0;
    virtual bookinventory findBy_inventory_number(const int& inventory_number) = 0;
    virtual bool UpdateBook(const bookinventory& book) = 0;
    virtual bool DeleteBook(const bookinventory& book) = 0;
};

class bookinventory_mySQL : public bookinventory_DAO{
private:
    std::unique_ptr<sql::mysql::MySQL_Driver> driver;
    std::unique_ptr<sql::Connection> con;
public:
    bookinventory_mySQL(const std::string& server, const std::string& user, const std::string& password,
                        const std::string& db_name);
    ~bookinventory_mySQL() override;
    void Add_bookInventory(bookinventory book_inventory) override;
    std::vector<bookinventory> findBy_library_code(const int& library_code) override;
    std::vector<bookinventory> findBy_issuance_mark(const int& issuance_mark) override;
    bookinventory findBy_inventory_number(const int& inventory_number) override;
    bool UpdateBook(const bookinventory& book) override;
    bool DeleteBook(const bookinventory& book) override;
};



