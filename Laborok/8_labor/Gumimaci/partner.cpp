#include "partner.h"

using namespace std;

long Partner::nextID = 0;

Partner::Partner() : id(nextID++) {
	generatePrivateKey();
}

Partner::Partner(const Partner & other) : id(nextID++) {
	// az ID és a titkus kulcs egyedi, nem másolhatjuk le
	generatePrivateKey();
}

long Partner::getId() const {
	return id;
}

string Partner::getPrivateKey() const {
	return privateKey;
}

void Partner::generatePrivateKey() {
	const char charSet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int charNum = sizeof(charSet) - 1;
	int size = sizeof(privateKey);
	for (int i = 0; i < size - 1; i++) {
		privateKey[i] = charSet[rand() % charNum];
	}
	privateKey[size - 1] = '\0';
}

ostream& operator<<(ostream& os, const Partner& p) {
	os << "ID: " << p.getId() << endl << "Kulcs: " << p.getPrivateKey() << endl << endl;
	return os;
}