#include "MutantStack.hpp"
#include <vector>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << '\n';
    std::vector<int> s;
    s.push_back(5);
    s.push_back(17);

    std::cout << s.back() << std::endl;

    s.pop_back();

    std::cout << s.size() << std::endl;

    s.push_back(3);
    s.push_back(5);
    s.push_back(737);

    s.push_back(0);

    std::vector<int>::iterator sit = s.begin();
    std::vector<int>::iterator site = s.end();

    ++sit;
    --sit;
    while (sit != site)
    {
        std::cout << *sit << std::endl;
        ++sit;
    }
    std::cout << '\n';

    MutantStack<std::string> mstack2;
    mstack2.push("this ");
    mstack2.push("is ");
    mstack2.push("mstack2\n");


    MutantStack<std::string>::iterator it2 = mstack2.begin();
    MutantStack<std::string>::iterator ite2 = mstack2.end();

    while (it2 != ite2)
    {
        std::cout << *it2;
        ++it2;
    }

    MutantStack<int> mstack3(mstack);
    //mstack3 = mstack;
    MutantStack<int>::iterator it3 = mstack3.begin();
    MutantStack<int>::iterator ite3 = mstack3.end();

    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    return 0;

}