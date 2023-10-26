#include "BitcoinExchange.hpp"

#include <fstream>

BitcoinExchange::BitcoinExchange() {
    this->parseData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & obj) {

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange & obj) {

}

BitcoinExchange::~BitcoinExchange() {

}

void BitcoinExchange::execute(std::string inputFile) {

}

void BitcoinExchange::parseData() {
    std::string filename = "data.csv";

    std::ifstream dataFile(filename.c_str());
    if (!dataFile.is_open())
        throw std::runtime_error("Error: could not open data file.");

    std::string buf = "";
	while (std::getline(dataFile, buf)) {
		size_t sepPos = buf.find(",");
        if (sepPos == std::string::npos)
            throw std::invalid_argument("Error: Invalid Data Format");
        
        std::string dateStr = buf.substr(0, sepPos);
        std::string rateStr = buf.substr(sepPos + 1);


        std::string date = getDate(buf.substr(0, sepPos));
	}
}

std::string& BitcoinExchange::getDate(std::string& input) {
    if (!this->isValidDate(input)) 
        throw std::invalid_argument("Error: Invalid Date Format");
    
}

bool BitcoinExchange::isValidDate(const std::string &dateStr) {
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
    
    std::time_t yesterdayTime = std::time(NULL) - (60 * 60 * 24);
    if  (std::mktime(&timeStruct) > std::time(NULL) - (60 * 60 * 24))
        return false;   

    return true;
}