
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) : _exchangeRates(cpy._exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy) {
    if (this != &cpy)
        this->_exchangeRates = cpy._exchangeRates;
    return *this;
}

BitcoinExchange::BitcoinExchange(const std::string &dbFile) {
    //create input file stream object
    std::ifstream file(dbFile.c_str()); //from string to const char *
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        std::stringstream ss(line); //create a "file stream" from a string
        std::string date, rateStr;
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            date.erase(date.find_last_not_of(" \t\r\n") + 1);
            rateStr.erase(0, rateStr.find_first_not_of(" \t\r\n"));
            _exchangeRates[date] = std::atof(rateStr.c_str());
        }
    }
}

//if false then program throws error. invalid if date is before bitcoin creation
// valid if for example someone inputs the year 212903
bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
        return false;
    return (y >= 2009 && m >= 1 && m <= 12 && d >= 1 && d <= 31);
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value) const {
    char* end;
    value = std::strtof(valueStr.c_str(), &end);
    if (*end != '\0' || value < 0)
        return false;
    return value <= INT_MAX;
}

std::string BitcoinExchange::getClosestDate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    if (it != _exchangeRates.end() && it->first == date)
        return date;
    if (it == _exchangeRates.begin()) //it would mean date before entry number 1 in db.
        return "";
    --it;
    return it->first;
}

void BitcoinExchange::processInput(const std::string &inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        //throw std::runtime_error("Error: could not open file.");
        return;
    }

    std::string line;
    std::getline(file, line); // skipping header too
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date.erase(date.find_last_not_of(" \t\r\n") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));

        float value;
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
        } else if (!isValidValue(valueStr, value)) {
            if (value > INT_MAX)
                std::cerr << "Error: too large a number." << std::endl;
            else
                std::cerr << "Error: not a positive number." << std::endl;
        } else {
            std::string closest = getClosestDate(date);
            if (closest.empty()) {
                std::cerr << "Error: no valid earlier date found." << std::endl;
                continue;
            }
            float rate = _exchangeRates.find(closest)->second;
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
    }
}