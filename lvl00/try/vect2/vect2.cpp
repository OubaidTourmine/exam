#include "vect2.hpp"

vect2::vect2()
{
    this->x = 0;
    this->y = 0;
}

vect2::vect2(int x, int y)
{
    this->x = x;
    this->y = y;
}   

vect2::vect2(const vect2 &oth)
{
    (*this) = oth;
}
vect2 &vect2::operator=(const vect2 &oth)
{
    if(this != &oth)
    {
        this->x = oth.x;
        this->y = oth.y;
    }
    return (*this);
}
vect2::~vect2() {}

int vect2::operator[](int index) const
{
    if(index == 0)
        return this->x;
    return this->y;
}   
int &vect2::operator[](int index)
{
    if(index == 0)
        return this->x;
    return this->y;
}

vect2 vect2::operator-() const
{
    vect2 temp = (*this);
    temp[0] = - temp[0]; 
    temp[1] = - temp[1]; 
    return temp;
}

vect2 vect2::operator*(int num) const
{
    vect2 temp;
    temp.x = this->x * num;
    temp.y = this->y * num;
    return temp;
}

vect2 &vect2::operator*=(int num)
{
    this->x = this->x * num;
    this->y = this->y * num;
    return (*this);
}



std::ostream &operator<<(std::ostream &os, const vect2 &obj)
{
	std::cout << "{" << obj[0] << ", " << obj[1] << "}";
    return os;
}
vect2 operator*(int num, const vect2 &oth)
{
    vect2 temp(oth);
    temp *= num;
    return temp;
}