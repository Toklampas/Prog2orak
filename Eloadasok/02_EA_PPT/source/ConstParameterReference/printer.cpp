#include "printer.h"
#include <stdio.h>
#include <iostream>

void printCV(person subject) {
	printf("A nyomtato nyomtatja %s oneletrajzat.\n", subject.name);
	if(strcmp(subject.name, "Sanyi")==0)
		subject.salary=2000000;
}