#ifndef __String_H__
#define _String_H__

class String{


private:

	unsigned int size;
	char* str;

	void alloc(unsigned int requiredMemory);

public:

	String();

	String(const char *format, ...);

	String(const String& s);

	~String();

	bool operator== (const String& s) const;

	bool operator== (const char* s) const;

	bool operator!= (const String& s) const;

	bool operator!= (const char* s)const;

	const String& operator= (const String& s);

	const String& operator= (const char* s);

	const String& operator+= (const String& s);

	const String& operator+= (const char* s);

	const unsigned int len() const;

	void clear();

	const unsigned int capacity();

	const char* getString()const;

};
#endif