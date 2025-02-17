
#include <string>

class Zombie {
    private:
        std::string name;
    public:
        void announce(void);
        void setName(std::string name);
        ~Zombie(void);
};

Zombie*    zombieHorde( int N, std::string name );
