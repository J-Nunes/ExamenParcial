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
		unsigned int need_size = s.len() + len() + 1;

		if (need_size > size)
		{
			char* tmp = str;
			alloc(need_size);
			strcpy_s(str, size, tmp);
			delete[] tmp;
		}

		strcat_s(str, size, s.str);

		return(*this);
	}

	const String& String::operator+= (const char* s)
	{
		if (s != NULL)
		{
			unsigned int need_size = strlen(s) + len() + 1;

			if (need_size > size)
			{
				char* tmp = str;
				alloc(need_size);
				strcpy_s(str, size, tmp);
				delete[] tmp;
			}

			strcat_s(str, size, s);
		}

		return(*this);
	}

	const unsigned int String::len() const
	{
		return strlen(str);
	}


	void String::clear()
	{
		delete[] str;
		str = new char[1];
		str[0] = '\0';
	}

	void String::trim()
	{
		unsigned int i = 0;

		if (str[0] == ' ')
		{
			while (str[i] == ' ')
				i++;

			for (unsigned int j = 0, i; str[i] != ' ' && str[i + 1] != ' '; j++, i++)
				{
					if (i < size)
						str[j] = str[i];
					else
						break;
				}

			if (str[i] == ' ')
			{
				str[i] = '/0';
			}
		}

		else
		{
			while (str[i] != ' ' && str[i + 1] != ' ')
			{
				if (i < size)
					i++;
				else
					break;
			}

			if (str[i] == ' ')
			{
				str[i] = '/0';
			}
		}
	}

	const unsigned int String::getCapacity()const
	{
		return(size + 1);
	}

	const char* String::getString()const
	{
		return str;
	}