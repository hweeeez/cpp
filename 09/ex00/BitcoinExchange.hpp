#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

class BitcoinExchange
{
	private:
	std::map<std::string, double> dateToPrice;
	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange& operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	double GetExchangeRate(std::string date, double value);
	void PopulatePrices();
};


#endif 