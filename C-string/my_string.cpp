// my_string.cpp
#include <iostream>
#include "my_string.h"
#include "my_sstream.h"
using namespace std;

// TODO(student): define all necessary my_string methods
// NOTE: some methods suggested here may not be required for you.
//       if you don't need a method, then you are not required to implement it
// NOTE: some methods not suggested here may be required for you.
//       if you need a method, then you are required to implement it (or re-engineer your solution to no longer need the method).

// my_string methods

// constructors
//   default (done for you.  you're welcome.)
my_string::my_string() : _data(new char[1]{0}), _capacity(1), _size(0) {}


my_string::my_string(const my_string& other): _data(new char[other._size]{}), _capacity(other._capacity), _size(other._size)         
{
    // allocate new memory                              //my_string copy constructor
    // copy values
    for (size_t i=0; i<_size; ++i) 
    {
        _data[i] = other._data[i];
    }
} 

my_string& my_string::operator=(const my_string& rhs)       //copy assignment
{
    if (this != &rhs) { // check for self assignment
    delete [] _data; // delete old memory
    _size = rhs._size; // copy
    _capacity = rhs._capacity; // copy
    _data = new char[_capacity]; // allocate new memory
    // copy data
    for (size_t i=0; i<_size; ++i) {
      _data[i] = rhs._data[i];
    }
  }
  return *this;
}

my_string::~my_string()                                 //destructor
{
  delete [] _data ;
  _data = nullptr;
  _size = 0;
  _capacity = 0;
}

my_string::my_string(const char* other): _data(), _capacity(), _size()          // c-string copy constructor
{                                                    
    size_t i =0;
    while(other[i] != '\n')
    {
        ++i;
    }

    size_t spaces;
    spaces = i+1;

    _data = new char[spaces];

    for(size_t j =0; j<1; ++j)
    {
        _data[j] = other[j];
    }
    _capacity = spaces;
    _size =i;

}

size_t my_string:: size() const
{
    size_t nums =0;
    for(size_t i=0; i<_size; ++i)
    {
        nums+=1;
    }
    return nums;
}

bool my_string:: empty() const
{
    if(_size<1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


my_string my_string::substr(size_t start,size_t end)
{  
    my_string point;
    for(size_t i=start-1; i<end; ++i)
    {
        point+=this->_data[i];
    }
    return point;
}



my_string my_string::insert(size_t start, my_string point)
{
    my_string temp;
    temp._capacity = this->_capacity+1;
    temp._size = this->_size+1;
    temp._data = new char[temp._capacity];
    for(size_t i=0; i<start; ++i)
    {
        temp._data[i] = this->_data[i];
    }
    char po = point[0];
    temp._data[start] = po;

    for(size_t j = start+1; j<temp._capacity; ++j)
    {
        temp._data[j] = this->_data[j-1];
    }

    return temp;
}

/*
void my_string:: reverse()
{
    my_string temp;
    temp._capacity = this->_capacity;
    temp._size = this -> _size;
    temp._data = new char[temp._capacity];

    size_t count =0;
    for(size_t i = _size-1; i>=0; --i)
    {
        point[count] = _data[i];
        count+=1;
    }
    delete[] _data;
    _data = point;


    create temp and set its data equal to this data
    for i in range length of data
    this at i = temp at length-i
    return this

}*/



/*
void my_string::push_back(char rhs)                                 
{
 if (_size == _capacity) 
 {
    increaseCapacity();
 }
  
  _data[_size] = //new array ;
  _size++;
  _data[_size-1] = //array;
}*/

/*
const char& my_string::at(size_type index)          //element access at, front, []
{
    return _data[index];
}                       

char& my_string::at(size_t index)
{
    return _data[index];
}

const char& my_string::front() const
{
    return _data[0];
}

char& my_string::front()
{
    return _data[0];
}

const char& my_string::operator[](size_type index) const
{
    if(index > _size)
    {
        cout<<"Error: Out of bounds"<<endl;
        return _data[0];
    }
    return _data[index];
}

char& my_string:: operator[](size_type index)
{
    if(index > _size)
    {
        cout<<"Error: Out of bounds"<<endl;
        return _data[0];
    }
    return _data[index];
}

bool my_string::empty() const
{
    if(_size>1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool my_string::size() const
{
    size_type count =0;
    for(size_type i =0; i<_size; ++i)
    {
        count+=1;
    }
    return count;
}


char& my_string::front()
{
    return _data[0];
}

*/



/*

void my_string::increaseCapacity() 
{
  // increase capacity
  if (_capacity == 0) 
  {
    _capacity = 1;
  }
  else 
  {
    _capacity += 2; // capacity = capacity * 2;
  }
}

*/

/*


void my_string::length(int value)
{
    if (_size == _capacity) 
    {
    increaseCapacity();
    }

    _data[_size] = ;  //new array ;

    for(int i=0; i<_size; ++i)
    {
        value+=1;
    }   
    return value;
}*/





//   rule of "3"
//     my_string copy constructor       DONE
//     my_string copy assignment        DONE
//     destructor                       DONE
//   c-string copy constructor          NEED TO DO

// element access                       DONE
//   at                                 DONE
//   front                              DONE
//   operator[]

// capacity                             DONE
//   empty                              DONE
//   size                               DONE

// operations
//   concatenation
//     my_string + my_string (non-member, friend)
//     my_string + c-string (non-member, friend)
//     my_string + char (non-member, friend)
//     c-string + my_string (non-member, friend)
//     char + my_string (non-member, friend)
//     my_string += my_string
//     my_string += c-string
//     my_string += char

// search
//   find

// non-member functions
//   relational operators
//     my_string == my_string
//     my_string == c-string
//   stream operators
//     ostream instertion operator
//     istream extraction operator
//     getline
//   numeric conversions
//     to_string


// my_istringstream methods
/*
my_istringstream::my_istringstream(const my_string& str) : _str(str), idx(0), state_fail(false), state_eof(str.empty()) {}

void my_istringstream::eat_whitespaces() {
    while (idx < _str.size() && isspace(_str[idx])) {
        idx++;
    }
}

my_istringstream& my_istringstream::operator>>(my_string& str) {
    eat_whitespaces();
    if (eof()) {
        state_fail = true;
    }
    if (fail()) {
        return *this;
    }
    my_string s;
    while (idx < _str.size() && !isspace(_str[idx])) {
        s += _str[idx++];
    }
    if (idx == _str.size()) {
        state_eof = true;
    }
    str = s;
    return *this;
}

my_istringstream& my_istringstream::operator>>(char& c) {
    eat_whitespaces();
    if (eof()) {
        state_fail = true;
    }
    if (fail()) {
        return *this;
    }
    if (idx < _str.size()) {
        c = _str[idx++];
    }
    if (idx == _str.size()) {
        state_eof = true;
    }
    return *this;
}

bool my_istringstream::good() const { return !(state_fail || state_eof); }
bool my_istringstream::fail() const { return state_fail; }
bool my_istringstream::eof() const { return state_eof; }
*/
// TODO(student): define other my_istringstream methods, if any
