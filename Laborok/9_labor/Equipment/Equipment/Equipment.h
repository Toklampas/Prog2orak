#pragma once
class Equipment
{
protected:	
	unsigned serialNumber;
	unsigned price;
public:
	Equipment(unsigned pSerialNumber, unsigned pPrice);
	void setPrice(unsigned pPrice);
	void setSerialNumber(unsigned pSerialNumber);

	unsigned getPrice() const;
	unsigned getSerialNumber() const;

	virtual void print() const;
};

