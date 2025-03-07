
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"


class FragTrap : public ClapTrap{
	public:
		FragTrap(void);
		FragTrap(const FragTrap &cpy);
		FragTrap(const std::string &name);
		~FragTrap(void);
		FragTrap &operator=(const FragTrap &cpy);

		void highFivesGuys(void);


};

#endif