#pragma once
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>
#include <memory>
#include <vector>

struct Author_info
{
    int author_id;
    std::string author_name;
    std::string author_surname;
};

class Author_info_DAO {
public:
    virtual ~Author_info_DAO() = default;
    virtual void Add_Author(Author_info author) = 0;
    virtual std::vector<Author_info> findBySurname(const std::string& surname) = 0;
    virtual std::vector<Author_info> findByName(const std::string& name) = 0;
    virtual Author_info findByID(int author_ID) = 0;
    virtual bool UpdateAuthor(Author_info author) = 0;
    virtual bool DeleteAuthor(Author_info author) = 0;
};

class Author_info_MySq : public Author_info_DAO {
private:
    std::unique_ptr<sql::mysql::MySQL_Driver> driver;
    std::unique_ptr<sql::Connection> con;

public:
    Author_info_MySq(const std::string& srever, const std::string& user, const std::string& password,
                     const std::string& db_name);
    ~Author_info_MySq() override;
    void Add_Author(Author_info author) override;
    std::vector<Author_info> findBySurname(const std::string& surname) override;
    std::vector<Author_info> findByName(const std::string& name) override;
    Author_info findByID(int author_ID) override;
    bool UpdateAuthor(Author_info author) override;
    bool DeleteAuthor(Author_info author) override;
};

