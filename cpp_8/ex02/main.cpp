
#include "MutantStack.hpp"
#include <list> //for main 2

// int main()
// {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);

//     std::cout << mstack.top() << std::endl;

//     mstack.pop();

//     std::cout << mstack.size() << std::endl;

//     mstack.push(3); 
//     mstack.push(5); 
//     mstack.push(737); 
//     //[...] 
//     mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin(); 
//     MutantStack<int>::iterator ite = mstack.end();

//     ++it;
//     --it;

//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     std::stack<int> s(mstack); 

//     return 0;
// }


// int main() {
//     std::cout << "Testing std::list:\n";
//     std::list<int> lst;
//     lst.push_back(5);
//     lst.push_back(17);
//     std::cout << lst.back() << std::endl;
//     lst.pop_back();
//     std::cout << lst.size() << std::endl;
//     lst.push_back(3);
//     lst.push_back(5);
//     lst.push_back(737);
//     lst.push_back(0);

//     std::list<int>::iterator lit = lst.begin();
//     std::list<int>::iterator lite = lst.end();
//     while (lit != lite) {
//         std::cout << *lit << std::endl;
//         ++lit;
//     }

//     return 0;
// }

int main() 
{
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);
    mstack.push(50);

    std::cout << "Regular iterator:\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Reverse iterator:\n";
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    for (; rit != rite; ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;


    //check copy constructor
    std::cout << "checking copy constructor" <<std::endl;
    MutantStack<int> copy_stack(mstack);
    MutantStack<int>::iterator copy_it = copy_stack.begin();
    MutantStack<int>::iterator copy_ite = copy_stack.end();
    for (; copy_it != copy_ite; ++copy_it)
        std::cout << *copy_it << " ";
    std::cout << std::endl;


    //check assignment operator
    std::cout << "checking assignment operator" <<std::endl;
    MutantStack<int> mstack2;
    mstack2.push(-99);
    mstack2.push(-97);
    mstack2.push(96);
    mstack2.push(95);
    copy_stack = mstack2;
    MutantStack<int>::iterator copy_it2 = copy_stack.begin();
    MutantStack<int>::iterator copy_ite2 = copy_stack.end();
    for (; copy_it2 != copy_ite2; ++copy_it2)
        std::cout << *copy_it2 << " ";
    std::cout << std::endl;

    return 0;


}
