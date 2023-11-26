#include "reader_archive.h"


reader_archive_mySQL::reader_archive_mySQL(const std::string& srever, const std::string& user, const std::string& password,
	const std::string& db_name)
{
	try{
	driver = std::make_unique<sql::mysql::MySQL_Driver>();
	con = std::unique_ptr<sql::Connection>(driver->connect(srever, user, password));
	con->setSchema(db_name);
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}

reader_archive_mySQL::~reader_archive_mySQL(){}

void reader_archive_mySQL::Add_Reader(reader_archive reader) 
{
	try
	{
		std::unique_ptr<sql::Statement> stmt (con->createStatement());
		stmt->execute("INSERT INTO reader_archive (first_name, last_name, address, phone, activity_type) VALUES ('" + reader.first_name + "', '" + reader.last_name + "' , '" + reader.address + "', '" + reader.phone + "', '" + reader.activity_type + "')");
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}

std::vector<reader_archive> reader_archive_mySQL::findBy_first_name(const std::string& first_name)
{
	std::vector<reader_archive> result;
	try
	{
		std::unique_ptr<sql::Statement> stmt(con->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM reader_archive WHERE first_name = '" + first_name + "'"));

		while (res->next())
		{
			reader_archive reader;
			reader.reader_card_number = res->getInt("reader_card_number");
			reader.first_name = res->getString("first_name");
			reader.last_name = res->getString("last_name");
			reader.address = res->getString("address");
			reader.phone = res->getString("phone");
			reader.activity_type = res->getString("activity_type");
			result.push_back(reader);
		}
		return result;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}

std::vector<reader_archive> reader_archive_mySQL::findBy_last_name(const std::string& last_name)
{
	std::vector<reader_archive> result;
	try
	{
		std::unique_ptr<sql::Statement> stmt(con->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM reader_archive WHERE last_name = '" + last_name + "'"));

		while (res->next())
		{
			reader_archive reader;
			reader.reader_card_number = res->getInt("reader_card_number");
			reader.first_name = res->getString("first_name");
			reader.last_name = res->getString("last_name");
			reader.address = res->getString("address");
			reader.phone = res->getString("phone");
			reader.activity_type = res->getString("activity_type");
			result.push_back(reader);
		}
		return result;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}


reader_archive reader_archive_mySQL::findBy_last_reader_card_number(const int& reader_card_number)
{
	reader_archive result;
	try {
		std::unique_ptr<sql::Statement> stmt(con->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM reader_archive WHERE reader_card_number  = '" + std::to_string(reader_card_number) + "'"));
		while (res->next())
		{
			result.reader_card_number = res->getInt("reader_card_number");
			result.first_name = res->getString("first_name");
			result.last_name = res->getString("last_name");
			result.address = res->getString("address");
			result.phone = res->getString("phone");
			result.activity_type = res->getString("activity_type"); 
		}
		return result;
	}
	catch (sql::SQLException& e) 
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}

bool reader_archive_mySQL::UpdateReader(const reader_archive& reader)
{
	try
	{
		if (!con->isValid())
		{
			std::cout << "Bad connection" << std::endl;
			return false;
		}
		std::unique_ptr<sql::Statement> check_stmt(con->createStatement());
		std::unique_ptr<sql::ResultSet> check_res(check_stmt->executeQuery("SELECT * FROM reader_archive WHERE reader_card_number = " + std::to_string(reader.reader_card_number)));

		if (!check_res->next())
		{
			std::cout << "reader doesnt exist" << std::endl;
			return false;
		}

		std::unique_ptr<sql::Statement> update_stmt(con->createStatement());
		int updateRow = update_stmt->executeUpdate("UPDATE reader_archive SET first_name = '" + reader.first_name + "', last_name = '" + reader.last_name + "', address = '" + reader.address + "', phone = '" + reader.phone + "', activity_type = '" + reader.activity_type + "' WHERE reader_card_number  = " + std::to_string(reader.reader_card_number));
		return updateRow > 0;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}

bool reader_archive_mySQL::DeleteReader(const reader_archive& reader)
{
	try
	{
		if (!con->isValid())
		{
			std::cout << "Bad connection" << std::endl;
			return false;
		}
		std::unique_ptr<sql::Statement> check_stmt(con->createStatement());
		std::unique_ptr<sql::ResultSet> check_res(check_stmt->executeQuery("SELECT * FROM reader_archive WHERE reader_card_number = " + std::to_string(reader.reader_card_number)));

		if (!check_res->next())
		{
			std::cout << "reader doesnt exist" << std::endl;
			return false;
		}

		std::unique_ptr<sql::Statement> update_stmt(con->createStatement());
		int updateRow = update_stmt->executeUpdate("DELETE FROM reader_archive WHERE reader_card_number = " + std::to_string(reader.reader_card_number));
		return updateRow > 0;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}