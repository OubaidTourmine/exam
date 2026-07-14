#include "bigint.hpp"

bigint::bigint() : str("0") {}

bigint::bigint(unsigned int n)
{
    std::stringstream ss;
    ss << n;
    this->str = ss.str();
}

bigint::bigint(std::string str)
{
    this->str = str;
}

bigint::bigint(const bigint &obj)
{
    (*this) = obj;
}

bigint &bigint::operator=(const bigint &obj)
{
    if(this == &obj)
        return (*this);
    this->str = obj.str;
    return (*this);
}

bigint::~bigint() {}

std::string bigint::get_str() const
{
    return (this->str);
}

bigint operator+(const bigint &a, const bigint &b)
{
    const std::string &A = a.get_str();
    const std::string &B = b.get_str();

    int carry = 0;
    std::string res;

    int i = (int)A.size() - 1;
    int j = (int)B.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digitA = 0;
        if(i >= 0)
            digitA = A[i] - '0';

        int digitB = 0;
        if(j >= 0)
            digitB = B[j] - '0';
        int sum = digitA + digitB + carry;
        int out = sum % 10;
        carry = sum / 10;
        res.push_back(char('0' + out));
        i--;
        j--;
    }
    std::reverse(res.begin(), res.end());
    return(bigint(res));
}

bigint &bigint::operator+=(const bigint &obj)
{
    (*this) = (*this) + obj;
    return *this;
}

bigint &bigint::operator++()
{
    (*this) = (*this) + bigint(1);
    return (*this);
}

bigint bigint::operator++(int)
{
    bigint temp = (*this);
    (*this) = (*this) + bigint(1);
    return (temp);
}

bigint bigint::operator<<(unsigned  int n) const
{
    bigint temp = (*this);
    temp.str.insert(temp.str.end(), n, '0');
    return temp;
} 

bigint bigint::operator>>(unsigned int n) const
{
    bigint temp = (*this);
    size_t len = temp.str.length();
    if(n >= len)
        temp.str = "0";
    else
        temp.str.erase(temp.str.length() - n, n);
    return temp;
}

bigint &bigint::operator>>=(unsigned int n)
{
    (*this) = (*this) >> n;
    return (*this);
}

bigint &bigint::operator<<=(unsigned int n)
{
    (*this) = (*this) << n;
    return (*this);
}

unsigned int str_to_int(std::string str)
{
    std::stringstream ss(str);
    unsigned int num;
    ss >> num;
    return num;
}

bigint bigint::operator>>(const bigint &oth) const
{
    bigint temp = (*this);
    temp = (*this) >> str_to_int(oth.str);
    return temp;
}

bigint bigint::operator<<(const bigint &oth) const
{
    bigint temp = (*this);
    temp = (*this) << str_to_int(oth.str);
    return temp;
}

bigint &bigint::operator>>=(const bigint &oth)
{
    (*this) = (*this) >> str_to_int(oth.str);
    return (*this);
}

bigint &bigint::operator<<=(const bigint &oth)
{
    (*this) = (*this) << str_to_int(oth.str);
    return (*this);

}

bool bigint::operator==(const bigint &oth)
{
    if(this->str == oth.get_str())
        return true;
    return false;
}

bool bigint::operator!=(const bigint &oth)
{
    return(!((*this) == oth));
}

bool bigint::operator>(const bigint &oth)
{
    std::string str1 = this->str;
    std::string str2 = oth.get_str();

    size_t len1 = str1.length();
    size_t len2 = str2.length();

    if(len1 > len2)
        return (len1 > len2);
    return (str1 > str2);
}

bool bigint::operator<(const bigint &oth)
{
    return(!((*this) > oth));
}

bool bigint::operator>=(const bigint &oth)
{
    return(((*this) > oth) || ((*this) == oth));
}

bool bigint::operator<=(const bigint &oth)
{
    return(((*this) < oth) || ((*this) == oth));
}

std::ostream &operator<<(std::ostream &os, const bigint &obj)
{
    os << obj.get_str();
    return os;
}