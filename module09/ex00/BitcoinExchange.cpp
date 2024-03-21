#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const std::string& path) {
  std::ifstream file(path.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: could not open database file!" << std::endl;
    std::exit(1);
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line == "date,exchange_rate")
      continue;
    size_t delimiterPos = line.find(',');
    if (delimiterPos != std::string::npos) {
      std::string date = line.substr(0, delimiterPos);
      std::string price_str = line.substr(delimiterPos + 1);
      try
      {
        if (!isValidDate(date))
        {
          std::cerr << "Error: invalid date in database " << date << std::endl;
          continue;
        }
        double price = std::strtod(price_str.c_str(), NULL);
        _btcdata[date] = price;
      }
      catch (...)
      {
        std::cerr << "Error: invalid date!" << std::endl;
      }
    }
  }
  file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &object)
{
  *this = object;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
  if (this != &rhs)
  {
  }
  return (*this);
}

bool BitcoinExchange::isLeapYear(int year)
{
  return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool BitcoinExchange::isValidDate(std::string &dateStr) {
  std::istringstream ss(dateStr);
  int year, month, day;
  char dash1, dash2;

  ss >> year >> dash1 >> month >> dash2 >> day;
  if (ss.fail() || dash1 != '-' || dash2 != '-')
    return false;
  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  if (month == 4 || month == 6 || month == 9 || month == 11)
    return day <= 30; // April, June, September, November have 30 days

  if (month == 2)
    return isLeapYear(year) ? day <= 29 : day <= 28;
  return true;
}

double BitcoinExchange::lowerBound(std::string& dataStr)
{
  std::map<std::string, double>::iterator it = _btcdata.lower_bound(dataStr);
  if (it->first >= dataStr && it != _btcdata.begin())
    it--;
  return (it->second);
}

void BitcoinExchange::infileRead(const std::string& infile) {
  std::ifstream input_file(infile.c_str());
  if (!input_file.is_open())
  {
    std::cerr << "Error: could not open input file." << std::endl;
    std::exit(1);
  }

  std::string line;
  while (std::getline(input_file, line))
  {
    if (line == "date | value") {
        continue;
    }
    size_t delimiterPos = line.find('|');
    if (delimiterPos != std::string::npos)
    {
      std::string date_str = line.substr(0, delimiterPos);
      std::string value_str = line.substr(delimiterPos + 1);

      try {
        if (!isValidDate(date_str))
        {
          std::cerr << "Error: invalid date " << "=> " << date_str << std::endl;
          continue;
        }
        double value = std::strtod(value_str.c_str(), NULL);
        if (value < 0) {
          std::cerr << "Error: not a positive number!" << std::endl;
          continue;
        }
        if (value >= 1000)
        {
          std::cerr << "Error: too large a number!" << std::endl;
          continue;
        }
        double exchange_rate = lowerBound(date_str);
        double calculated_value = value * exchange_rate;
        std::cout << date_str << " => " << value << " = " << calculated_value << std::endl;
      }
      catch (...)
      {
        std::cerr << "Error: invalid number!" << std::endl;
      }
    }
    else
    {
      std::cerr << "Error: Invalid delimeter " << line << std::endl;
    }
  }
  input_file.close();
}