#include "Book_Lending_Journal.h"


book_lending_journal_mySQL::book_lending_journal_mySQL(const std::string& srever, const std::string& user, const std::string& password,
	const std::string& db_name)
{
	try {
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

book_lending_journal_mySQL::~book_lending_journal_mySQL(){}

void book_lending_journal_mySQL::add_book_lending_journal(const book_lending_journal& Book_Lending_Journal)
{
	try
	{
		std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("INSERT INTO book_lending_journal (inventory_number, reader_card_number, lending_date, planned_return_date) VALUES (?, ?, ?, ?)"));
		pstmt->setInt(1, Book_Lending_Journal.inventory_number);
		pstmt->setInt(2, Book_Lending_Journal.reader_card_number);
		pstmt->setDateTime(3, Book_Lending_Journal.lending_date);  // Assuming setDateTime is a valid method to set date and time
		pstmt->setDateTime(4, Book_Lending_Journal.planned_return_date);

		pstmt->execute();
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}




std::vector<book_lending_journal> book_lending_journal_mySQL::findBy_inventory_number(const int& inventory_number)
{
	std::vector<book_lending_journal> result;
	try
	{
		std::unique_ptr<sql::Statement> stmt(con->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM book_lending_journal WHERE inventory_number  = '" + std::to_string(inventory_number) + "'"));

		while (res->next())
		{
			book_lending_journal book_lending_journal;
			book_lending_journal.lending_id = res->getInt("lending_id");
			book_lending_journal.inventory_number = res->getInt("inventory_number");
			book_lending_journal.reader_card_number = res->getInt("reader_card_number");
			book_lending_journal.lending_date = res->getString("lending_date");
			book_lending_journal.planned_return_date = res->getString("planned_return_date");
			
			result.push_back(book_lending_journal);
		}
		return result;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}

std::vector<book_lending_journal> book_lending_journal_mySQL::findBy_reader_card_number(const int& reader_card_number)
{
	std::vector<book_lending_journal> result;
	try {
		std::unique_ptr<sql::Statement> stmt(con->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM book_lending_journal WHERE reader_card_number  = '" + std::to_string(reader_card_number) + "'"));
		while (res->next())
		{
			 book_lending_journal _book_lending_journal;
			_book_lending_journal.lending_id = res->getInt("lending_id");
			_book_lending_journal.inventory_number = res->getInt("inventory_number");
			_book_lending_journal.reader_card_number = res->getInt("reader_card_number");
			_book_lending_journal.lending_date = res->getString("lending_date");
			_book_lending_journal.planned_return_date = res->getString("planned_return_date");
			result.push_back(_book_lending_journal);
		}
		return result;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}

book_lending_journal book_lending_journal_mySQL::findBy_lending_id(const int& lending_id)
{
	book_lending_journal result;
	try {
		std::unique_ptr<sql::Statement> stmt(con->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM book_lending_journal WHERE lending_id  = '" + std::to_string(lending_id) + "'"));
		while (res->next())
		{
			result.lending_id = res->getInt("lending_id");
			result.inventory_number = res->getInt("inventory_number");
			result.reader_card_number = res->getInt("reader_card_number");
			result.lending_date = res->getString("lending_date");
			result.planned_return_date = res->getString("planned_return_date");
		}
		return result;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}

bool book_lending_journal_mySQL::Updatebook_lending_journal(const book_lending_journal& _book_lending_journal)
{
	try
	{
		if (!con->isValid())
		{
			std::cout << "Bad connection" << std::endl;
			return false;
		}
		std::unique_ptr<sql::Statement> check_stmt(con->createStatement());
		std::unique_ptr<sql::ResultSet> check_res(check_stmt->executeQuery("SELECT * FROM book_lending_journal WHERE lending_id = " + std::to_string(_book_lending_journal.lending_id)));

		if (!check_res->next())
		{
			std::cout << "book_lending_journal doesnt exist" << std::endl;
			return false;
		}

		std::unique_ptr<sql::Statement> update_stmt(con->createStatement());
		int updateRow = update_stmt->executeUpdate("UPDATE book_lending_journal SET inventory_number   = '" + std::to_string(_book_lending_journal.inventory_number) + "', reader_card_number  = '" + std::to_string(_book_lending_journal.reader_card_number) + "', lending_date = '" + _book_lending_journal.lending_date + "', planned_return_date = '" + _book_lending_journal.planned_return_date + "' WHERE lending_id  = " + std::to_string(_book_lending_journal.lending_id));
		return updateRow > 0;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}

bool book_lending_journal_mySQL::Deletebook_lending_journal(const book_lending_journal& _book_lending_journal)
{
	try
	{
		if (!con->isValid())
		{
			std::cout << "Bad connection" << std::endl;
			return false;
		}
		std::unique_ptr<sql::Statement> check_stmt(con->createStatement());
		std::unique_ptr<sql::ResultSet> check_res(check_stmt->executeQuery("SELECT * FROM book_lending_journal WHERE lending_id  = " + std::to_string(_book_lending_journal.lending_id)));

		if (!check_res->next())
		{
			std::cout << "book_lending_journal doesnt exist" << std::endl;
			return false;
		}

		std::unique_ptr<sql::Statement> update_stmt(con->createStatement());
		int updateRow = update_stmt->executeUpdate("DELETE FROM book_lending_journal WHERE lending_id = " + std::to_string(_book_lending_journal.lending_id));
		return updateRow > 0;
	}
	catch (sql::SQLException& e)
	{
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
}