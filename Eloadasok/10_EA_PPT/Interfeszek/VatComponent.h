#pragma once
#include <stdio.h>
#include <iostream>


class IAccountable {
public:
	virtual int getVAT() const = 0;
};

void AccountingDoSomethingWithVAT(const IAccountable& acc);

