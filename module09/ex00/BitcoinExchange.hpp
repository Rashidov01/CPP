#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdio.h>

class BitcoinExchange
{
private:
  std::map<std::string, double> _btcdata;
  bool isLeapYear(int year);
  bool isValidDate(std::string &dateStr);
  bool isValidDateStr(std::string &dateStr);
  double lowerBound(std::string& dataStr);

public:
  BitcoinExchange();
  BitcoinExchange(const std::string &path);
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &object);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);
  void infileRead(const std::string &infile);
  bool readData(const std::string &path);

};

#endif

