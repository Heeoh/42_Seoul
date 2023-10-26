#include "BitcoinExchange.hpp"

#include <iostream>
#include <exception>
#include <fstream>
#include <ctime>
#include <cctype> // isdigit()
#include <algorithm> // lower_bound

BitcoinExchange::BitcoinExchange() {
    this->parseData();

	// for (std::map<std::string, double>::iterator it = this->data.begin(); it != this->data.end(); it++)
	// 	std::cout << "(" << it->first << ", " << it->second << ")\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & obj) {
	*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange & obj) {
	if (this == &obj)
		return *this;
	
	this->data = obj.data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::execute(std::string filename) {
	// input file open
	std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("could not open input file");

	try {
		// read first line and get format
		std::string buf = "";
		if (!std::getline(inputFile, buf))
			throw std::invalid_argument("empty input file");  
		if (buf != "date | value")
			throw std::invalid_argument("invalid input format"); 
		std::string sep = " | ";

		// read the other lines and execute
		while (std::getline(inputFile, buf)) {
			try {
				size_t sepPos = buf.find(sep);
				if (sepPos == std::string::npos)
					throw std::invalid_argument("invalid input format");
			
				std::string date = buf.substr(0, sepPos);
				if (!isValidDate(date))
					throw std::invalid_argument("bad input => " + date);
				double value = this->getValue(buf.substr(sepPos + 3));
				
				std::map<std::string, double>::iterator it = data.lower_bound(date);
				if (it == data.end())
					throw std::runtime_error("no valid data");
				std::cout << date << " => " << value << " = " << it->second * value << std::endl;
			} catch (std::exception & e) {
				std::cout << "Error: " << e.what() << "." << std::endl;
			}
		
		}
	} catch (std::exception & e) {
		if (inputFile.is_open())
			inputFile.close();
		throw std::invalid_argument(e.what());
	}
	
}


void BitcoinExchange::parseData() {
    std::string filename = "data.csv";

	// data file open
    std::ifstream dataFile(filename.c_str());
    if (!dataFile.is_open())
        throw std::runtime_error("could not open data file");

	
	try {
		// read first line and get format
		std::string buf = "";
		if (!std::getline(dataFile, buf))
			throw std::invalid_argument("empty data file");  

		size_t datePos = buf.find("date");
		size_t exchangeRatePos = buf.find("exchange_rate");
		if (datePos == std::string::npos || exchangeRatePos == std::string::npos)
			throw std::invalid_argument("invalid data format");

		std::string sep = buf.substr(datePos + 4, exchangeRatePos - (datePos + 4));
		size_t sepLen = sep.length();

		// read the other lines and set data map
		while (std::getline(dataFile, buf)) {
			size_t sepPos = buf.find(sep);
			if (sepPos == std::string::npos)
				throw std::invalid_argument("invalid data format");

			std::string date = this->getDate(buf.substr(0, sepPos));
			double rate = this->getExchangeRate(buf.substr(sepPos + sepLen));
			if (date == "")
				throw std::invalid_argument("invalid date format");
			if (rate < 0)
				throw std::invalid_argument("invalid exchange rate");
			data.insert(std::make_pair(date, rate));
		}
	} catch (std::exception & e) {
		if (dataFile.is_open())
			dataFile.close();
		throw std::invalid_argument(e.what());
	}

	dataFile.close();
}

std::string BitcoinExchange::getDate(std::string input) {
    if (!this->isValidDate(input)) 
        return "";
	return input;
}

double BitcoinExchange::getExchangeRate(std::string input) {
	if (input.empty() || !std::isdigit(input[0]))
		return -1;

	double val = 0.0;
	char *endPtr = NULL;
	val = std::strtod(input.c_str(), &endPtr);

	if (!endPtr || *endPtr != '\0')
		return -1;
	if (std::isnan(val) || std::isinf(val) || val < 0)
		return -1;

	return val;
}

double BitcoinExchange::getValue(std::string input) {
	if (input.empty() || input[0] == ' ')
		throw std::invalid_argument("invalid input format");
	
	double val = 0.0;
	char *endPtr = NULL;
	val = std::strtod(input.c_str(), &endPtr);

	if (!endPtr)
		throw std::invalid_argument("bad input");
	if (*endPtr != '\0')
		throw std::invalid_argument("bad input => " + input);
	else if (std::isnan(val) || std::isinf(val) || val > 1000)
		throw std::invalid_argument("too large a number");
	else if (val < 0)
		throw std::invalid_argument("not a positive number");
		
	return val;
}

bool BitcoinExchange::isValidDate(const std::string dateStr) {
    struct std::tm timeStruct;
    if (strptime(dateStr.c_str(), "%Y-%m-%d", &timeStruct) == NULL)
        return false;

    if (timeStruct.tm_mon < 0 || timeStruct.tm_mon > 11)
        return false;
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (timeStruct.tm_mday < 1 || timeStruct.tm_mday > daysInMonth[timeStruct.tm_mon]) {
        if (timeStruct.tm_mon == 1 && timeStruct.tm_mday == 29) { // 02-29
            int year = timeStruct.tm_year + 1900;
            if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
                return false;
        } else {
            return false;   
        }
    }
    
	std::time_t currentTime = std::time(NULL); 
    std::time_t yesterdayTime = currentTime - (60 * 60 * 24);
	timeStruct.tm_hour = 0;
    timeStruct.tm_min = 0;
    timeStruct.tm_sec = 0;
	std::time_t inputTime = std::mktime(&timeStruct);
    if (inputTime > yesterdayTime)
        return false;   

    return true;
}