#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <ctype.h>
#include <stdlib.h>

class ScalarConverter
{
  public:
    static void toChar(const std::string& str);
    static void toInt(std::string str);
    static void	toFloat(std::string str);
    static void toDouble(std::string str);


  private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &obj);
    ScalarConverter &operator=(ScalarConverter const &rhs);;
};

#endif