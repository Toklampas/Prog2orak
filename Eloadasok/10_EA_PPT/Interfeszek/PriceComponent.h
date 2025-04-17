#pragma once
#include <stdio.h>
#include <iostream>


class IWare {
public:
	virtual int getPrice() const = 0;
};

void PrintPrice(const IWare& ware);
