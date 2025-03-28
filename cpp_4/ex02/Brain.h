
#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain(void);
        Brain(const Brain &cpy);
        ~Brain(void);
        Brain &operator=(const Brain &cpy);

        std::string getIdea(int index) const;
        void setIdea(int index, const std::string &idea);

};

#endif