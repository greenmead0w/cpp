
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.h"

class Ice : public AMateria {

	public:
		Ice(void);
		Ice(const Ice &cpy);
        Ice &operator=(const Ice &cpy);
        ~Ice(void);

		Ice* clone() const;
		void use(ICharacter& target);

};

#endif