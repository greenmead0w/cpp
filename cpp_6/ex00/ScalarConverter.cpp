
#include "ScalarConverter.h"
#include <cctype> //isdigit, isprint
#include <cstring> //strlen
#include <cstdlib> //strtol, strtod, strtof
#include <climits> //CHAR_MIN, CHAR_MAX, INT_MIN, INT_MAX


static ScalarConverter::numType ScalarConverter::detect_type(const char *input)
{
	std::string str = input;
	char *endptr;

	//PSEUDO_LITERALS
	if (str == "nanf" || str == "+inff" || str == "-inff")
    	return TYPE_PSEUDO_FLOAT;
	if (str == "nan" || str == "+inf" || str == "-inf")
    	return TYPE_PSEUDO_DOUBLE;

	//CHAR [strlen("\n") would also return 1]
	if (std::strlen(input) == 1 && !std::isdigit(input[0]))
		return TYPE_CHAR;

	//handles chars like '1'
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return TYPE_CHAR;

	//INT
    std::strtol(input, &endptr, 10);
    if (*endptr == '\0')
        return TYPE_INT;

    //FLOAT
    std::strtof(input, &endptr);
    if (*endptr == 'f' && *(endptr + 1) == '\0')
        return TYPE_FLOAT;

    //DOUBLE
    std::strtod(input, &endptr);
    if (*endptr == '\0')
        return TYPE_DOUBLE;

    return TYPE_UNKNOWN;

}

static void ScalarConverter::printChar(const double i)
{
	std::cout << "char: ";
    if (i < CHAR_MIN || i > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(i)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

}

static void ScalarConverter::convertFromChar(const char *input)
{
	char c;
	if (std::strlen((input)) == 1)
		c = input[0]; //when input comes like this: x
	else
		c = input[1]; //when input comes like this: 'x'
	if (!std::isprint(c))
		throw ScalarConverter::NotPrintableException();

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void ScalarConverter::convertFromInt(const char *input)
{
	long l;
	char *endptr;
	int i;
    
    l = std::strtol(input, &endptr, 10);
    
    //check if overflows int
    if (l < INT_MIN || l > INT_MAX)
        throw ScalarConverter::ImpossibleException();
    
    i = static_cast<int>(l);

	printChar(i);
    
    std::cout << "int: " << i << std::endl;
    
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;

}

static void ScalarConverter::convertFromFloat(const char *input)
{
	float f;
    char *endptr;
    
    f = std::strtof(input, &endptr);

	printChar(f);
    
    //Print int
    std::cout << "int: ";
    if (f < INT_MIN || f > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;
    
    //Print float
    std::cout << "float: ";
    if (f == static_cast<int>(f)) //check if whole number
        std::cout << f << ".0f" << std::endl;
    else
        std::cout << f << "f" << std::endl;
    
    //Print double
    std::cout << "double: ";
    if (static_cast<double>(f) == static_cast<int>(f))
        std::cout << static_cast<double>(f) << ".0" << std::endl;
    else
        std::cout << static_cast<double>(f) << std::endl;
}


static void ScalarConverter::convertFromDouble(const char *input)
{
	double d;
    char *endptr;
    
    d = std::strtod(input, &endptr);

	printChar(d);
    
    //Print int
    std::cout << "int: ";
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
    
    //Print float
    std::cout << "float: ";
	if (d < -FLT_MAX || d > FLT_MAX)
		std::cout << "impossible";
    else if (d == static_cast<int>(d)) //check if whole number
        std::cout << d << ".0f" << std::endl;
    else
        std::cout << d << "f" << std::endl;
    
    //Print double
    std::cout << "double: ";
    if (static_cast<double>(d) == static_cast<int>(d))
        std::cout << static_cast<double>(d) << ".0" << std::endl;
    else
        std::cout << static_cast<double>(d) << std::endl;

}

static void ScalarConverter::convertFromPseudoFloat(const char *input) {
    std::string pseudoFloat = input;
    
    // Handle the special pseudo-literals for float
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    // Print float with proper format
    std::cout << "float: " << pseudoFloat << std::endl;
    
    // Print double equivalent
    std::cout << "double: ";
    if (pseudoFloat == "nanf")
        std::cout << "nan" << std::endl;
    else if (pseudoFloat == "+inff")
        std::cout << "+inf" << std::endl;
    else if (pseudoFloat == "-inff")
        std::cout << "-inf" << std::endl;
}

static void ScalarConverter::convertFromPseudoDouble(const char *input) {
    std::string pseudoDouble = input;
    
    // Handle the special pseudo-literals for double
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    // Print float equivalent
    std::cout << "float: ";
    if (pseudoDouble == "nan")
        std::cout << "nanf" << std::endl;
    else if (pseudoDouble == "+inf")
        std::cout << "+inff" << std::endl;
    else if (pseudoDouble == "-inf")
        std::cout << "-inff" << std::endl;
    
    // Print double
    std::cout << "double: " << pseudoDouble << std::endl;
}

static void ScalarConverter::convert(const char *input)
{
	numType _type = detect_type(input);

	switch(_type) 
	{
		case TYPE_CHAR:
			convertFromChar(input);
			break;

		case TYPE_INT:
			convertFromInt(input);
			break;

		case TYPE_FLOAT:
			convertFromFloat(input);
			break;

		case TYPE_DOUBLE:
			convertFromDouble(input);
			break;

		case TYPE_PSEUDO_DOUBLE:
			convertFromPseudo(input):
			break;

		case TYPE_PSEUDO_FLOAT:
			convertFromPseudo(input):
			break;

		case TYPE_UNKNOWN:
			throw ScalarConverter::ImpossibleException();
			break;
	}
}

const char *ScalarConverter::NotPrintableException::what() const throw() {
	return ("Non displayable char");
}

const char *ScalarConverter::ImpossibleException::what() const throw() {
	return ("Impossible");
}