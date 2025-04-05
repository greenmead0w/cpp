#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.h"
// # include <stdint>

class Serializer
{
    private:
        Serializer(void);
		Serializer(const Serializer  &cpy);
        Serializer &operator=(const Serializer &cpy);

	public:
		~Serializer(void);
		static	uintptr_t serialize(Data *ptr); //from ptr to uint
		static	Data	*deserialize(uintptr_t raw); //from uint to ptr


};



#endif