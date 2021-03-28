#include "KICV_ELLD_1_2.hh"
#include "KICV_ELLD_3.hh"
#include "KICV_ELLD_4_5.hh"
#include "KICV_ELLD_6.hh"

#include <iostream>

int main() {
/* justAnInt, some ints with nothing special */
///*
	justAnInt anInt(19);
	anInt = 195;
//*/
/* intModulo, some ints with a modulo, unsigned */
///*
	intModulo anIntWithAModulo(193);
	intModulo :: changeModulo(17);
	anIntWithAModulo.normalize();
//*/
/* polynomeOfInts, Basically polynomes with justAnInts inside */
///*
	polynomeOfInts aVector{12, 19, 45};
	std :: cout << aVector << std :: endl;
//*/
/* polynomeModulo, polynomes that work with a polynome as their modulo, and a uint32_t as a modulo for each member */
///*
	polynomeModulo :: changeModulo({4, 18, 2, 7, 10});		// It uses intModulo, same modulo as them
	polynomeModulo aVectorWithAModulo{12, 14, 98, 200, 14, 29};
	std :: cout << aVectorWithAModulo << std :: endl;
//*/

	/* Everytime, every single operator is overloaded. Feel free to use however you want to */
}