//Written by: Danny Phongsouthy
//Purpose is to create Stock reports written into a .txt file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

struct stock_data 
{
	string stock;
	float entry;
	float exit;
	float tot_shares;
	float profit;
	float roi;
	float p_capital_used;
	float capital_used;
};

//void Intro(); //Prompt User
//void InputStockData(float& balance, vector<float>& ucap, vector<float>& capu, vector<float>& profit, vector<stock_data>& stocks); //Function to input stock information
//void PrintToFile(float& balance, string& filename, vector<stock_data>& stocks); //Function to Print to file


int main() 
{
	int i, j, x, trades;
	double tcapital_used, tnet_income, fbalance;
	string stock_, entry_, exit_, capital_used_;
	float balance;
	string filename; 
	vector<stock_data> stocks; //Data Structure
	vector<float> capu; //Vector for capital used
	vector<float> profit; //Vector for profit
	stock_data a; //Initialize struct

	/*Intro();
	InputStockData(balance, ucap, capu, profit, stocks);
	PrintToFile(balance, filename, stocks);*/

	cout << "Please Input the stock report file name that you would like to create " << endl;
	getline(cin, filename);
	//cout << "This is the filename " << filename << endl;

	cout << "Please Input the Initial Balance before any trades occured " << endl;
	cin >> balance;
	//cout << "This is the balance $" << balance << endl;
	cout << endl;

	cout << "How many trades will you be inputting? " << endl;
	cin >> trades;
	//cout << "Amount of Trades " << trades << endl;
	cout << endl;

	for (i = 0; i < trades; i++)
	{
		cout << "Please input ticker name: " << endl;
		stocks.push_back(stock_data());
		cin >> stock_; //Collect the cin 
		a.stock = stock_;
		stocks[i].stock = a.stock; //Sets the value of stock in the struct = to the cin
		//cout << "This is the ticker " << stocks[i].stock << endl;

		cout << "How much money was traded? " << endl;
		cin.get();
		getline(cin, capital_used_); //Collect the cin
		a.capital_used = stof(capital_used_);
		stocks[i].capital_used = a.capital_used; //Converts to float and sets = to value of capital_used in the vector
		capu.push_back(stocks[i].capital_used); //Stores used capital in capu vector
		//cout << "Amount traded " << stocks[i].capital_used << " Then from the capu vector " << capu[i] << endl;

		
		stocks[i].p_capital_used = (stocks[i].capital_used / balance) * 100; //Calculates the % of capital used
		//cout << " Percent of Capital Used " << stocks[i].p_capital_used  << "%" << endl;

		cout << "What was your Entry? " << endl;
		getline(cin, entry_); //Collect the cin
		a.entry = stof(entry_);
		stocks[i].entry = stof(entry_); //Converts to float and sets = to value of entry in the vector

		stocks[i].tot_shares = stocks[i].capital_used / stocks[i].entry; //Calculates the total shares that were bought

		cout << "Entry price $" << stocks[i].entry << " Total Shares bought " << stocks[i].tot_shares << endl;

		cout << "What was your Exit? " << endl;	
		getline(cin, exit_); //Collect the cin
		a.exit = stof(exit_);
		stocks[i].exit = stof(exit_); //Converts to float and sets = to value of exit in the vector

		stocks[i].profit = (stocks[i].exit * stocks[i].tot_shares) - stocks[i].capital_used; //Calculates the profit +/- in the trade
		stocks[i].roi = (stocks[i].profit / stocks[i].capital_used) * 100; //Calculates the ROI (Return on Investment)
		profit.push_back(stocks[i].profit); //Stores profit into the profit vector
	}

	tcapital_used = accumulate(capu.begin(), capu.end(), 0); //Calculates total capital used
	tnet_income = accumulate(profit.begin(), profit.end(), 0); //Calculates total net income
	fbalance = balance + tnet_income; //Calculate final balance

	cout << "Total Capital Used $" << tcapital_used << endl;
	cout << "Total Net Income $" << tnet_income << endl;
	cout << "Final Balance $" << fbalance << endl;

	ofstream outfile(filename + ".txt"); //Create/Open the .txt file

	outfile << "---------------------------------------------------------------------------------------" << endl;
	outfile << "Balance : $" << balance << "\n\n";

	for (x = 0; x < trades; x++) //Reiterates until it has gone through all trades made
	{
		outfile << stocks[x].stock << "\n\n";
		outfile << stocks[x].p_capital_used << "% : ($" << stocks[x].capital_used << " || " << stocks[x].tot_shares << " Shares) --> Profit $" << stocks[x].profit << " : " << stocks[x].roi << "% ROI" << "\n\n";
		outfile << "        - Entry at $" << stocks[x].entry << "\n";
		outfile << "        - Exit at $" << stocks[x].exit << "\n";
	}
	outfile << endl;
	outfile << "Initial Balance : $" << balance << "\n";
	outfile << "Cash Used : $" << tcapital_used << "\n";
	outfile << "Total Net Income : $" << tnet_income << "\n";
	outfile << "Final Balance : $" << fbalance << "\n\n";
	outfile << "---------------------------------------------------------------------------------------" << endl;
	outfile.close(); //Closes file

	return 0;
}

//void Intro() 
//{
//	string filename; //Initialize filename for function
//	float balance; //Initialize balance for function
//	cout << "Please Input the stock report file name that you would like to create " << endl;
//	getline(cin, filename);
//	cout << "Please Input the Initial Balance before any trades occured " << endl;
//	cin >> balance;
//		cout << endl;
//}
//
//void InputStockData(float& balance, vector<float>& ucap, vector<float>& capu, vector<float>& profit, vector<stock_data>& stocks)
//{
//	int i, j, trades;
//	float tcapital_used, tunused_capital, tnet_income, fbalance;
//	string stock_, entry_, exit_, capital_used_;
//	stock_data a;
//
//	cout << "How many trades will you be inputting? " << endl;
//	cin >> trades;
//	cout << endl;
//
//	for (i = 0; i < trades; i++)
//	{
//		cout << "Please input ticker name: " << endl;
//		getline(cin, stock_); //Collect the cin 
//		a.stock = stock_;
//		stocks[i].stock = stock_; //Sets the value of stock in the struct = to the cin
//		stocks.push_back(stock_data());
//
//		cout << "How much money was traded? " << "\n";
//		getline(cin, capital_used_); //Collect the cin
//		a.capital_used = stof(capital_used_);
//		stocks[i].capital_used = stof(capital_used_); //Converts to float and sets = to value of capital_used in the vector
//		capu.push_back(stocks[i].capital_used); //Stores used capital in capu vector
//
//		a.unused_capital = balance - stocks[i].capital_used; //Calculates the unused capital
//		stocks[i].unused_capital = a.unused_capital;
//		ucap.push_back(stocks[i].unused_capital); //Stores unused capital in ucap vector
//		stocks[i].p_capital_used = (balance / stocks[i].capital_used) * 100; //Calculates the % of capital used
//
//		cout << "What was your Entry? " << "\n";
//		getline(cin, entry_); //Collect the cin
//		a.entry = stof(entry_);
//		stocks[i].entry = stof(entry_); //Converts to float and sets = to value of entry in the vector
//
//		stocks[i].tot_shares = stocks[i].capital_used / stocks[i].entry; //Calculates the total shares that were bought
//
//		cout << "What was your Exit? " << "\n";
//		getline(cin, exit_); //Collect the cin
//		a.exit = stof(exit_);
//		stocks[i].exit = stof(exit_); //Converts to float and sets = to value of exit in the vector
//
//		stocks[i].profit = (stocks[i].exit * stocks[i].tot_shares) - stocks[i].capital_used; //Calculates the profit +/- in the trade
//		stocks[i].roi = (stocks[i].profit / stocks[i].capital_used) * 100; //Calculates the ROI (Return on Investment)
//		profit.push_back(stocks[i].profit); //Stores profit into the profit vector
//	}
//
//	tcapital_used = accumulate(capu.begin(), capu.end(), 0); //Calculates total capital used
//	tunused_capital = accumulate(ucap.begin(), ucap.end(), 0); //Calculates total unused capital
//	tnet_income = accumulate(profit.begin(), profit.end(), 0); //Calculates total net income
//	fbalance = balance + tnet_income; //Calculate final balance
//}
//
//void PrintToFile(float& balance, string& filename, vector<stock_data>& stocks)
//{
//	int i, trades{};
//	float fbalance{}, tcapital_used{}, tunused_capital{}, tnet_income{};
//	ofstream outfile(filename + ".txt"); //Create/Open the .txt file
//
//	for (i = 0; i < trades; i++) //Reiterates until it has gone through all trades made
//	{
//		outfile << "---------------------------------------------------------------------------------------" << endl;
//		outfile << "Balance : $" << balance << "\n\n";
//		outfile << stocks[i].stock << "\n";
//		outfile << stocks[i].p_capital_used << "% : ($" << stocks[i].capital_used << " || " << stocks[i].tot_shares << " Shares) --> Profit $" << stocks[i].profit << " : " << stocks[i].roi << "% ROI" << "\n\n";
//		outfile << "        - Entry at $" << stocks[i].entry << "\n";
//		outfile << "        - Exit at $" << stocks[i].exit << "\n";
//	}
//	outfile << endl;
//	outfile << "Initial Balance : $" << balance << "\n";
//	outfile << "Cash Used : $" << tcapital_used << "--> $ " << tunused_capital << " unused" << "\n";
//	outfile << "Total Net Income : $" << tnet_income << "\n";
//	outfile << "Final Balance : $" << fbalance << "\n";
//
//	outfile.close(); //Closes file
//}