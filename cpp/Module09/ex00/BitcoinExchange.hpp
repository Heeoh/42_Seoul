#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange {
private:
    std::map<std::string, double> data;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange & obj);
    BitcoinExchange& operator=(const BitcoinExchange & obj);
    ~BitcoinExchange();

    void execute(std::string inputFile);

private:
    void parseData();
    std::string getDate(std::string input);
    double getExchangeRate(std::string input);
	double getValue(std::string input);


    bool isValidDate(const std::string dateStr);
	
};

#endif