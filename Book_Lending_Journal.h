#pragma once
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>
#include <iostream>
#include <memory>
#include <vector>

struct book_lending_journal
{
	int lending_id;
	int inventory_number;
	int reader_card_number;
	std::string lending_date;
	std::string planned_return_date;
};



class book_lending_journal_DAO {
public:
	virtual ~book_lending_journal_DAO() = default;
	virtual void add_book_lending_journal(const book_lending_journal& Book_Lending_Journal) = 0;
	virtual std::vector<book_lending_journal> findBy_inventory_number(const int& inventory_number) = 0;
	virtual std::vector<book_lending_journal> findBy_reader_card_number (const int& reader_card_number) = 0;
	virtual book_lending_journal findBy_lending_id (const int& lending_id) = 0;
	virtual bool Updatebook_lending_journal(const book_lending_journal& _book_lending_journal) = 0;
	virtual bool Deletebook_lending_journal(const book_lending_journal& _book_lending_journal) = 0;
};


class book_lending_journal_mySQL : public book_lending_journal_DAO {
private:
	std::unique_ptr<sql::mysql::MySQL_Driver> driver;
	std::unique_ptr<sql::Connection> con;
public:
	book_lending_journal_mySQL(const std::string& srever, const std::string& user, const std::string& password,
		const std::string& db_name);
	~book_lending_journal_mySQL() override;
	void add_book_lending_journal(const book_lending_journal& Book_Lending_Journal) override;
	std::vector<book_lending_journal> findBy_inventory_number(const int& inventory_number) override;
	std::vector<book_lending_journal> findBy_reader_card_number(const int& reader_card_number) override;
	book_lending_journal findBy_lending_id(const int& lending_id) override;
	bool Updatebook_lending_journal(const book_lending_journal& _book_lending_journal) override;
	bool Deletebook_lending_journal(const book_lending_journal& _book_lending_journal) override;
};






