#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string> //getline
#include <fstream> //read files: ifstream
#include <iostream>
#include <sstream> //parsing strings: stringstream
#include <cstdlib> //atoi, atof, strtof, etc.
#include <cstdio> //for sscanf
#include <exception> //throw errors
#include <climits> // for int_max

class BitcoinExchange {
private:
    std::map<std::string, float> _exchangeRates;
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &valueStr, float &value) const;
    std::string getClosestDate(const std::string &date) const;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &cpy);
    BitcoinExchange(const std::string &dbFile);
    BitcoinExchange &operator=(const BitcoinExchange &cpy);
    void processInput(const std::string &inputFile) const;
};

#endif
