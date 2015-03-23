#include <stdio.h>
#include <stdarg.h>
#include <wtypes.h>
#include <string.h>

#include "String.h"	


	void String::alloc(unsigned int requiredMemory)
	{
		size = requiredMemory;
		str = new char[size];
	}

	String::String()
	{
		size = 1;
		str = new char[size];
		str[0] = '\0';
	}

	String::String(const char *format, ...)
	{
		size = 0;
		if (format != NULL)
		{
			static char tmp[4096];
			static va_list af;

			va_start(af, format);
			int res = vsprintf_s(tmp, 4096, format, af);
			va_end(af);
			if (res > 0)
			{
				alloc(res + 1);
				strcpy_s(str, size, tmp);
			}
		}
		if (size == 0)
		{
			alloc(1);
			clear();
		}
	}



	String::String(const String& s)
	{
		if (s != NULL)
		{
			alloc(s.len() + 1);
			strcpy_s(str, size, s.getString());
		}
		else
		{
			alloc(1);
			clear();
		}
	}

	String::~String()
	{ 
		delete[]str; 
	}

	bool String::operator== (const String& s) const
	{
		return strcmp(s.str, str) == 0;
	}

	bool String::operator== (const char* s) const
	{
		if (s != NULL)
			return strcmp(s, str) == 0;
		return false;
	}

	bool String::operator!= (const String& s) const
	{
		return strcmp(s.str, str) != 0;
	}

	bool String::operator!= (const char* s) const
	{
		if (s != NULL)
			return strcmp(s, str) != 0;
		return true;
	}

	const String& String::operator= (const String& s)
	{
		if (s.len() + 1 > size)
		{
			delete[] str;
			alloc(s.len() + 1);
		}
		else
			clear();

		strcpy_s(str, size, s.str);

		return(*this);
	}

	const String& String::operator= (const char* s)
	{
		if (s != NULL)
		{
			if (strlen(s) + 1 > size)
			{
				delete[] str;
				alloc(strlen(s) + 1);
			}
			else
				clear();

			strcpy_s(str, size, s);
		}
		return(*this);
	}

	const String& String::operator+= (const String& s)
	{
		String tmp0;
		String& tmp = tmp0;

		tmp.alloc(strlen(str) + 1);
		strcpy_s(tmp.str, strlen(str) + 1, str);

		alloc(strlen(s.str) + size + 1);



		strcpy_s(str, strlen(tmp.str) + 1, tmp.str);

		strcat_s(str, strlen(s.str) + size + 1, s.str);

		printf("%s", str);

		return (*this);


	}

	const String& String::operator+= (const char* s)
	{

		if (s != NULL)
		{
			strcat_s(str, strlen(s), s);
			return (*this);
		}
		return (*this);
	}

	const int String::len() const
	{
		return strlen(str);
	}


	void String::clear()
	{
		delete[] str;
		str = new char[1];
		str[0] = '\0';
	}

	const int String::capacity()
	{
		return(size + 1);
	}

	const char* String::getString()const
	{
		return str;
	}