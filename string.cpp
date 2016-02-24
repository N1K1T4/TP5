#include "string.h"

size_t string::_max_size = 100;

string::string()
{
	_capacity = 0;
	_size = 0;
	_str = new char[_capacity+1];
	_str[_size]='\0';
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

string::string(const string& s)
{
	_capacity = s.capacity();
	_size = s.size();
	_str = new char[_capacity+1];
	for (int i=0; i<(int)_size; i++)
	{
		_str[i] = s(i);
	}
	_str[_size] = '\0';
}

string::string(const char* s)
{
	_capacity = sizeof(s)/sizeof(char)-1;
	_size = _capacity;
	_str = new char[_capacity+1];
	//TODO remplir _str @Ambre
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

char* string::c_str()
{
	char* str = new char[_size+1];
	for (int i=0; i<(int)_size+1; i++)
	{
		str[i]=_str[i];
	}
	return str;
}

void string::clear()
{
	delete[] _str;
	_str = new char[_capacity+1];
	_size = 0;
	_str[_size] = '\0';
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

void string::resize(size_t length)
{
	//TODO définir resize @Ambre
}

char string::operator () (int i) const
{
	return _str[i%(_capacity+1)];
}

char& string::operator [] (int i)
{
	return _str[i%(_capacity+1)];
}

const string& string::operator = (const char c)
{
	//TODO définir =(char) @Ambre
}

const string& string::operator = (const char* s)
{
  int length = sizeof(s)/sizeof(char);
  _capacity = length;
  delete[] _str;
  _str = new char[_capacity+1];
  for (int i=0; i<length; i++){
    _str[i] = s[i];
    _size++;
  }
  return *this;
}

const string& string::operator = (const string& s)
{
	if (&s != this)
	{
		_capacity = s.capacity();
		_size = s.size();
		delete[] _str;
		_str = new char[_capacity+1];
		for (int i=0; i<(int)_size+1; i++)
		{
			_str[i] = s(i);
		}
	}
	return *this;
}

void string::operator + (const char c)
{
	if (_size == _capacity)
	{
		_capacity++;
		char* str = new char[_capacity+1];
		for (int i=0; i<(int)_size; i++)
		{
			str[i] = _str[i];
		}
		delete[] _str;
		_str = str;
	}
	_str[_size] = c;
	_size++;
	_str[_size] = '\0';
}

void string::operator + (const char* s)
{
	//TODO définir +(char*) @Ambre
}

string operator + (const string& lhs, const string& rhs)
{
  size_t capacity = lhs.capacity() + rhs.capacity();
  size_t size = lhs.size() + rhs.size();
  string s = string(capacity);
  s.resize(size);
  for (int i=0; i<int(lhs.size()); i++){
    s[i] = lhs[i];
  }
  for (int i=int(lhs.size()); i<int(capacity); i++)
  {
    s[i] = rhs[i];
  }
  return s;
}
