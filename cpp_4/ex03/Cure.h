
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.h"

class Cure : public AMateria {

	public:
		Cure(void);
		Cure(const Cure &cpy);
        Cure &operator=(const Cure &cpy);
        ~Cure(void);

		Cure* clone() const;
		void use(ICharacter& target);

};

#endif