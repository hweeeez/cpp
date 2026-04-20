#include "BitcoinExchange.hpp"
#include <iostream>

int main()//int argc, char** argv
{
    //BitcoinExchange* btc = new BitcoinExchange();

	// if (argc != 2)
	// 	return 0;
	std::string line;
	std::ifstream inputFile;

	inputFile.open("input.txt");
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		//std::cout << line << '\n';
		std::size_t delim = line.find(" | ");
		if (delim == std::string::npos){
			std::cout << "Error: String not formatted correctly" << std::endl;
			continue;
		}
		std::string timestr = (line.substr(0, delim));
		struct tm tmStruct;
		if (strptime(timestr.c_str(), "%Y-%m-%d", &tmStruct) == NULL)
		{
			std::cout << "Error: Date not formatted correctly" << std::endl;
			continue;
		}
		std::cout<< timestr;
		std::cout << delim;
		std::string value = line.substr(delim, line.size());
		std::cout << value << '\n';
		std::stringstream ss(value);
		double v;
		if (!(ss >> v))
		{
			std::cout << "Error: Invalid number" << std::endl;
			continue;
		}
		if (v < 1)
		{
			std::cout << "Error: Not a positive number" << std::endl;
			continue;
		}
		if (v > 999)
		{
			std::cout << "Error: Number is too large" << std::endl;
			continue;
		}
	}
	inputFile.close();
    return 0;
}

//generate file

// std::ofstream file("input.txt");
//     if (!file.is_open())
//     {
//         std::cerr << "Error: could not open file" << std::endl;
//         return 1;
//     }

//     std::srand(std::time(0));

//     int year = 2009;
//     int month = 1;
//     int day = 1;

//     file << "date | value" << std::endl;
// 	for (int j = 0; j < 12; j++)
//     {
// 		year++;
// 		for (int i = 0; i < 12; i++)
// 		{
// 			// Advance date crudely
// 			day += rand() % 15 + 1;
// 			if (day > 28) { day = 1; month++; }
// 			if (month > 12) { month = 1; year++; }

// 			// Alternate between int and float
// 			float value;
// 			if (rand() % 2 == 0)
// 				value = (float)(rand() % 1001);         // 0 to 1000 int
// 			else
// 				value = (float)(rand() % 100000) / 100; // 0.00 to 999.99 float

// 			// Format: YYYY-MM-DD
// 			file << year << "-";
// 			if (month < 10) file << "0";
// 			file << month << "-";
// 			if (day < 10) file << "0";
// 			file << day;

// 			file << " | " << value << std::endl;
// 		}
// 	}
//     file.close();