#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


class ScalarConverter {
    private:
        enum numType {
            TYPE_CHAR,
            TYPE_INT,
            TYPE_FLOAT,
            TYPE_DOUBLE,
            TYPE_PSEUDO_FLOAT,
            TYPE_PSEUDO_DOUBLE,
            TYPE_UNKNOWN
        };
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter &operator=(const ScalarConverter &cpy);

        //functions
        static numType detect_type(const std::string &input);



    public:
        ~ScalarConverter(void);

        static void convert(const char *input);
        static void printChar(const int i);
        static void convertFromChar(const char *input);
        static void convertFromInt(const char *input);
        static void convertFromFloat(const char *input);

    	class NotPrintableException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

    	class ImpossibleException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

#endif