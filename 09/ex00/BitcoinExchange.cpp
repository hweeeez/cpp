#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		*this = other;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::PopulatePrices()
{
	std::string line;
	std::ifstream inputFile;

	inputFile.open("data.csv");
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{		
		std::size_t delim = line.find(",");
		std::string timestr = (line.substr(0, delim));
		
		std::string value = line.substr(delim, line.size());
		std::cout << value << '\n';
		std::stringstream ss(value);
		double v;
		if (ss >> v)
		{
			dateToPrice.insert(std::pair<std::string, double>(timestr, v));
		}
	}
}

double BitcoinExchange::GetExchangeRate(std::string date, double value)
{
	if (dateToPrice.find(date) != dateToPrice.end())
	{
		return (dateToPrice[date] * value);
	}
	else
	{
		std::map<std::string, double>::iterator it = lower_bound(dateToPrice.begin(), dateToPrice.end(), date);
		//if (it.first > )
	}
}
