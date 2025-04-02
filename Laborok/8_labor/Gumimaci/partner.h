#pragma once
#include <string>
#include <iostream>


class Partner {
	static long nextID;
protected:
	long id;
	char privateKey[2001];
public:
	Partner();
	Partner(const Partner&);

	void generatePrivateKey();

	long getId() const;
	std::string getPrivateKey() const;
};

std::ostream& operator<<(std::ostream&, const Partner&);