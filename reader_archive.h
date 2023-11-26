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


struct reader_archive{
	int reader_card_number;
	std::string first_name;
	std::string last_name;
	std::string address;
	std::string phone;
	std::string activity_type;
};

class reader_archive_DAO {
public:
	virtual ~reader_archive_DAO() = default;
	virtual void Add_Reader(reader_archive reader) = 0;
	virtual std::vector<reader_archive> findBy_first_name(const std::string& first_name) = 0;
	virtual std::vector<reader_archive> findBy_last_name(const std::string& last_name) = 0;
	virtual reader_archive findBy_last_reader_card_number(const int& reader_card_number) = 0;
	virtual bool UpdateReader(const reader_archive& reader) = 0;
	virtual bool DeleteReader(const reader_archive& reader) = 0;
};

class reader_archive_mySQL : public reader_archive_DAO
{
private:
	std::unique_ptr<sql::mysql::MySQL_Driver> driver;
	std::unique_ptr<sql::Connection> con;
public:
	reader_archive_mySQL(const std::string& srever, const std::string& user, const std::string& password,
		const std::string& db_name);
	~reader_archive_mySQL() override;
	void Add_Reader(reader_archive reader) override;
	std::vector<reader_archive> findBy_first_name(const std::string& first_name) override;
	std::vector<reader_archive> findBy_last_name(const std::string& last_name) override;
	reader_archive findBy_last_reader_card_number(const int& reader_card_number) override;
	bool UpdateReader(const reader_archive& reader) override;
	bool DeleteReader(const reader_archive& reader) override;
};



