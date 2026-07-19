#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <sstream>
#include <algorithm>

class bigint
{
    private :
        std::string str;
    public :
        bigint();
        bigint(unsigned int n);
        bigint(std::string str);
        bigint(const bigint &oth);
        bigint &operator=(const bigint &oth);
        ~bigint();
        std::string get_str() const;


        bigint &operator+=(const bigint &oth);

        bigint operator++(int);
        bigint &operator++();

        bigint operator<<(unsigned int num) const;
        bigint operator>>(unsigned int num) const;
        bigint &operator<<=(unsigned int num);
        bigint &operator>>=(unsigned int num);

        bigint operator<<(const bigint &oth) const;
        bigint operator>>(const bigint &oth) const;
        bigint &operator<<=(const bigint &oth);
        bigint &operator>>=(const bigint &oth);

        bool operator==(const bigint &oth);
        bool operator!=(const bigint &oth);
        bool operator>(const bigint &oth);
        bool operator<(const bigint &oth);
        bool operator>=(const bigint &oth);
        bool operator<=(const bigint &oth);

};

bigint operator+(const bigint &a, const bigint &b);
std::ostream &operator<<(std::ostream &os, const bigint &obj);


#endif