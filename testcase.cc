// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"	/* Thanks Mrs Braunstein */
#include "KICV_ELLD_1_2.hh"
#include "KICV_ELLD_3.hh"
#include "KICV_ELLD_4_5.hh"

#include <iostream>

TEST_CASE("1: Regular ints")
{
	justAnInt firstInt(200);
	REQUIRE(firstInt.giveValue() == 200); 					/* Testing constructor */
	firstInt *= 192;
	REQUIRE(firstInt.giveValue() == 200 * 192);				/* Testing *= */
	firstInt /= 84;
	REQUIRE(firstInt.giveValue() == (200 * 192) / 84);		/* Testing /= */
	justAnInt secondInt(-84);
	REQUIRE(secondInt.giveValue() == -84);					/* Testing constructor (< 0) */
	firstInt = 19;
	REQUIRE(firstInt.giveValue() == 19);					/* Testing = */
	REQUIRE((firstInt + secondInt).giveValue() == 19 - 84);	/* Testing + */
	REQUIRE((secondInt - firstInt).giveValue() == -(19 + 84));	/* Testing - */
	REQUIRE(firstInt > secondInt);							/* Testing > */
	REQUIRE(secondInt < firstInt);							/* Testing < */
	REQUIRE(firstInt == 19);								/* Testing == */
	REQUIRE(justAnInt :: extendedEuclidean(4, 5, NULL, NULL, true) == 1);					/* Euclidean */
	REQUIRE(justAnInt :: extendedEuclidean(4, 226, NULL, NULL, true) == 2);				/* Euclidean */
}

TEST_CASE("2: Int Modulo")
{
	intModulo firstInt(700);
	REQUIRE(firstInt == 700);								/* Constructor, == */
	intModulo :: changeModulo(7);
	REQUIRE(intModulo :: giveModulo() == 7);				/* Changing modulo */
	firstInt.normalize();
	REQUIRE(firstInt == 0);									/* Normalize */
	firstInt = 9;
	REQUIRE(firstInt == 2);									/* = */
	REQUIRE(firstInt.modInv() == 4);						/* Modular Inversion */
	REQUIRE((firstInt += 3) == 5);							/* += */
	REQUIRE((firstInt /= 2) == 6);							/* /= */
	REQUIRE(firstInt * 2 == 5);								/* * */
	REQUIRE(firstInt > 5);									/* > */
	REQUIRE(intModulo :: extendedEuclidean(firstInt, 5, NULL, NULL) == 1);	/* ExtendedEuclidean */	
}

