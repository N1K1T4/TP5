#include "string.h"

size_t string::_max_size = 100;

string::string()
{
	_capacity = 0;
	_size = 0;
	_str = nullptr;
}

string::string(size_t capacity)
{
	_capacity = capacity;
	_size = 0;
	_str = new char[_capacity+1];
	_str[_size] = '\0';
}

string::string(size_t capacity, char c)
{
	_capacity = capacity;
	_size = _capacity;
	_str = new char[_capacity+1];
	for (int i=0; i<(int)_size; i++)
	{
		_str[i] = c;
	}
	_str[_size] = '\0';
}

string::string(const char* s)
{
	_capacity = sizeof(s)/sizeof(char)-1;
	_size = _capacity;
	_str = new char[_capacity+1];
	//TODO remplir _str (Ambre)
}

string::~string()
{
	delete[] _str;
	_str = nullptr;
}

bool string::empty()
{
	return _size == 0;
}

void string::reserve(size_t length)
{
	if (length > _capacity)
	{
		char* newstr = new char[length+1];
		for (int i=0; i<(int)_size; i++)
		{
			newstr[i] = _str[i];
		}
		delete[] _str;
		_str = newstr;
		_capacity = length; 
	}
}

void string::resize(size_t n)
{
	//TODO définir resize (Ambre)
}
