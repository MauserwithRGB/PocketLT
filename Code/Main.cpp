#include <iostream>
#include <string>
#include <vector>

class Category; // forward decalaration, because 'Category' is used before it is defined in 'Transactions'

class Transactions
{
	private:
		double amount;
		// date and time
		std::string name;
		std::string details;
		Category* category;
		
	public:
		Transactions(double amount, std::string name, std::string details, Category *category/* , date and time*/) : amount(amount), name(name), details(details), category(category) {}
		
		double getAmount()  // in order to update the budget
		{
			return amount;
		}
};

class Category
{
	private:
		std::string name;
	
	public:
		Category(std::string name) : name(name){
		}
		
};

class BudgetManager
{
	private:
		double limit;  // total budget
//		double daily;  // a daily spending limit calculated using limit and budget duration, exceeding this will cause it  to be recalculated
		std::vector <Transactions*> transactionVctr;  // a vector to store the list of pointers to transactions
		
	public:
		void addTransaction(Transactions* t)
		{
			transactionVctr.push_back(t);
		}
};
