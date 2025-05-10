#include <iostream>
#include <string>
#include "Fraction.h"


Fraction reciprocal(const Fraction& f) {
	return Fraction(0, f.getDenominator(), f.getWholePart() * f.getDenominator() + f.getNumerator());
}


int main() {
    try {
        Fraction f1(3, 1, 4);
        Fraction f2(2, 2, 5);


        //1. Keszitsd el a double konverzios operatorodat, es probald ki a kovetkezo sorokkal
        double result = static_cast<double>(f1 + f2);
        std::cout << "Sum as double: " << result << std::endl;

        //2.+3. Keszitsd el a string konverzios operatorodat, valamint az osszeadast, es probald ki a kovetkezo sorokkal
        std::string resultStr = static_cast<std::string>(f1 + f2);
        std::cout << "Sum as string: " << resultStr << std::endl;

        //4. Keszitsd el a konverzios konstruktorodat, es probald ki a kovetkezo sorokkal
        Fraction f3(10.58);
        std::cout << "f3 as string: " << static_cast<std::string>(f3) << std::endl;

        //5. Ennek dobnia kell egy kivetelt: 0-val nem lehet osztani. Kapd el a kivetelt es irasd ki a hibauzenetet
        Fraction f4(2, 2, 0);
        std::cout << "F4 as double: " << static_cast<double>(f4) << std::endl;

        //6. Keszitsd el a reciprocal fuggvenyt, es probald ki a kovetkezo sorokkal
        //A reciprocal fuggvenyen belul tortenik egy kivetel dobasa, amit a main fuggvenyben el kell kapni
        //std::cout << "Reciprocal of 0: " << static_cast<double>(reciprocal(0.0)) << std::endl;



        return 0;
    }
    catch (const FractionException& exception)
    {
        cerr << "FractionException caught: " << exception.what() << endl;
    }
}







