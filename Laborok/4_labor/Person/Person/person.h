#pragma once

class Person {
	char* name; // dinamikus tagv�ltoz� (karakter t�mb)
	unsigned int age;
public:
	Person();
	Person(const char*, unsigned int);
	Person(const Person&);
	~Person();
	const char* getName();
	void setName(const char*);
	unsigned int getAge();
	void setAge(unsigned int);
};