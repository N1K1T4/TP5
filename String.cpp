#include "String.h"

size_t String::_max_size = 100;

String::String()
{
	_capacity = 0;
	_size = 0;
	_str = nullptr;
}

String::String(size_t capacity)
{
	_capacity = capacity;
	_size = 0;
	_str = new char[_capacity+1];
}

String::String(const char* s)
{
	_size = sizeof(s)/sizeof(char)-1;
	_capacity = _size;
	_str = new char[_capacity+1];
	//TODO remplir _str (Ambre)
}

String::~String()
{
	delete[] _str;
	_str = nullptr;
}

bool String::empty()
{
	return _size == 0;
}

void String::reserve(size_t length)
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

void String::resize(size_t n)
{
	//TODO définir resize (Ambre)
}
