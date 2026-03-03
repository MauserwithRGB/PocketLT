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

class Budget // for multiple budgets
{
	private:
		std::string name;
		double limit;
//		double daily;  // a daily spending limit calculated using limit and budget duration, exceeding this will cause it  to be recalculated
//		int duration  // to-do
		std::vector <Transactions*> transactionVctr;  // a vector to store the list of pointers to transactions
		
	public:
		Budget(std::string name, double limit) : name(name), limit(limit) {}
		
		void addTransaction(Transactions* t)
		{
			transactionVctr.push_back(t);
		}
};

/* the singleton
excerpt from Refactoring Guru:
All implementations of the Singleton have these two steps in common:

    1. Make the default constructor private, to prevent other objects from using the new operator with the Singleton class.
    2. Create a static creation method that acts as a constructor. Under the hood, this method calls the private constructor to create an object and saves it in a static field. All following calls to this method return the cached object.

If your code has access to the Singleton class, then it’s able to call the Singleton’s static method. So whenever that method is called, the same object is always returned. */

class BudgetManager
{
	private:
		BudgetManager();
		static BudgetManager& getInstance()
		{
			BudgetManager instance;
			return instance;
		}
		std::vector <Budget*> budgetVctr;
		
	public:
};

int main()
{
	std::cout << "\n-------- FinaLT --------\n";
	
	BudgetManager manager;
	
}
