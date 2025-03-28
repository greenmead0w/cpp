
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.h"


class AMateria {

	protected:
		std::string type;

	public:
		AMateria(void);
		AMateria(const AMateria &cpy);
		AMateria(std::string const & type);
        AMateria &operator=(const AMateria &cpy);
        virtual ~AMateria(void);


		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);


};

#endif
