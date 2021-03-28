// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"	/* Thanks Mrs Braunstein */
#include "KICV_ELLD_1_2.hh"
#include "KICV_ELLD_3.hh"
#include "KICV_ELLD_4_5.hh"
#include "KICV_ELLD_6.hh"

#include <iostream>

TEST_CASE("1: Regular ints, operator +") {
/*
	operator+= (const justAnInt &rightHandSide);
	operator+= (const someType &rightHandSide);
	operator+  (const justAnInt &rightHandSide);
	operator+  (const someType &rightHandSide);
*/
	justAnInt firstInt(85);
	justAnInt secondInt(1974);
	justAnInt thirdInt(-964);
	REQUIRE((firstInt += secondInt) == 85 + 1974);
	REQUIRE((firstInt += thirdInt) == 85 + 1974 - 964);
	REQUIRE((thirdInt += 1000) == 36);
	REQUIRE(thirdInt + secondInt == 1974 + 36);
	REQUIRE(thirdInt + 25 == 61);
}

TEST_CASE("2: Regular ints, operator -") {
/*
	operator-= (const justAnInt &rightHandSide);
	operator-= (const someType &rightHandSide);
	operator-  (const justAnInt &rightHandSide);
	operator-  (const someType &rightHandSide);
*/
	justAnInt firstInt(85);
	justAnInt secondInt(1974);
	justAnInt thirdInt(-964);
	REQUIRE((firstInt -= secondInt) == 85 - 1974);
	REQUIRE((firstInt -= thirdInt) == 85 - 1974 + 964);
	REQUIRE((thirdInt -= 1000) == -1964);
	REQUIRE(thirdInt - secondInt == -1974 - 1964);
	REQUIRE(thirdInt - 25 == -1989);
}

TEST_CASE("3: Regular ints, operator *") {
/*
	operator*= (const justAnInt &rightHandSide);
	operator*= (const someType &rightHandSide);
	operator*  (const justAnInt &rightHandSide);
	operator*  (const someType &rightHandSide);
*/
	justAnInt firstInt(85);
	justAnInt secondInt(1974);
	justAnInt thirdInt(-964);
	REQUIRE((firstInt *= secondInt) == 85 * 1974);
	REQUIRE((firstInt *= thirdInt) == -(85 * 1974) * 964);
	REQUIRE((thirdInt *= 1000) == -964000);
	thirdInt = 19;
	REQUIRE(thirdInt * secondInt == 19 * 1974);
	REQUIRE(thirdInt * 25 == 25 * 19);
}

TEST_CASE("4: Regular ints, operator /") {
/*
	operator*= (const justAnInt &rightHandSide);
	operator*= (const someType &rightHandSide);
	operator*  (const justAnInt &rightHandSide);
	operator*  (const someType &rightHandSide);
*/
	justAnInt firstInt(1974);
	justAnInt secondInt(85);
	justAnInt thirdInt(-964);
	REQUIRE((firstInt /= secondInt) == 1974 / 85);
	REQUIRE((thirdInt /= firstInt) == -964 / (1974 / 85));
	REQUIRE((secondInt /= 17) == 85 / 17);
	thirdInt = 197;
	REQUIRE(thirdInt / secondInt == 197 / (85 / 17));
	REQUIRE(thirdInt == 197);
	REQUIRE(thirdInt / 25 == 197 / 25);
}

TEST_CASE("5: intModulo, operator +") {
/*
	operator+= (const intModulo &rightHandSide);
	operator+= (const someType &rightHandSide);
	operator+  (const intModulo &rightHandSide);
	operator+  (const someType &rightHandSide);
*/
	intModulo :: changeModulo(67); /* It is prime, we are working on Z / 67 Z */
	intModulo firstInt(85); /* 18 */
	REQUIRE(firstInt == 18);
	intModulo secondInt(19);
	intModulo thirdInt(-69); /* 65 */
	REQUIRE(thirdInt == 65);
	REQUIRE((firstInt += secondInt) == 18 + 19);
	REQUIRE(firstInt == 18 + 19);
	REQUIRE((firstInt += thirdInt) == 18 + 19 - 2);
	REQUIRE((thirdInt += 1000) == 1065 % 67);
	REQUIRE(thirdInt + secondInt == (1065 + 19) % 67);
	REQUIRE(thirdInt + 25 == (1065 + 25) % 67);
}

TEST_CASE("6: intModulo, operator -") {
/*
	operator-= (const intModulo &rightHandSide);
	operator-= (const someType &rightHandSide);
	operator-  (const intModulo &rightHandSide);
	operator-  (const someType &rightHandSide);
*/
	intModulo :: changeModulo(67); /* It is prime, we are working on Z / 67 Z */
	intModulo firstInt(85); /* 18 */
	intModulo secondInt(19);
	intModulo thirdInt(-69); /* 65 */
	REQUIRE((firstInt -= secondInt) == 66);
	REQUIRE((firstInt -= thirdInt) == 1);
	REQUIRE((thirdInt -= 1000) == ((-1069) % 67) + 67);
	REQUIRE(thirdInt - secondInt == ((-1069 - 19) % 67) + 67);
	REQUIRE(thirdInt - 25 == ((-1069 - 25) % 67) + 67);
}

TEST_CASE("7: intModulo, operator *") {
/*
	operator*= (const intModulo &rightHandSide);
	operator*= (const someType &rightHandSide);
	operator*  (const intModulo &rightHandSide);
	operator*  (const someType &rightHandSide);
*/
	intModulo :: changeModulo(67); /* It is prime, we are working on Z / 67 Z */
	intModulo firstInt(85); /* 18 */
	intModulo secondInt(19);
	intModulo thirdInt(-69); /* 65 */
	REQUIRE((firstInt *= secondInt) == (18 * 19) % 67);
	REQUIRE((firstInt *= thirdInt) == ((18 * 19) * 65) % 67);
	REQUIRE((thirdInt *= 1000) == 65000 % 67);
	thirdInt = 19;
	REQUIRE(thirdInt * secondInt == (19 *19) % 67);
	REQUIRE(thirdInt * 25 == (25 * 19) % 67);
}

TEST_CASE("8: intModulo, operator /") {
/*
	operator*= (const intModulo &rightHandSide);
	operator*= (const someType &rightHandSide);
	operator*  (const intModulo &rightHandSide);
	operator*  (const someType &rightHandSide);
*/
	intModulo firstInt(85); /* 18 */
	intModulo secondInt(19);
	intModulo thirdInt(-69); /* 65 */
	REQUIRE(firstInt.modInv() == 41);
	REQUIRE((secondInt /= firstInt) == (19 * 41) % 67);
	REQUIRE((thirdInt /= firstInt) == (65 * 41) % 67);
	REQUIRE((secondInt /= 17) == (19 * 41 * 4) % 67);
	thirdInt = 65;
	REQUIRE(thirdInt / firstInt == (65 * 41) % 67);
	REQUIRE(thirdInt / 25 == (65 * 59) % 67);
}

TEST_CASE("9: polynomeOfInts, operator +") {
/*
	operator+= (const polynomeOfInts &rightHandSide);
	operator+= (const someType &rightHandSide);
	operator+  (const polynomeOfInts &rightHandSide);
	operator+  (const someType &rightHandSide);
*/
	polynomeOfInts firstPolynome({3, 4, 9});
	REQUIRE(firstPolynome[1] == 4);
	polynomeOfInts secondPolynome({2, 1});
	polynomeOfInts thirdPolynome({19, 12, 34, 15});
	REQUIRE(thirdPolynome[2] == 34);
	REQUIRE(((firstPolynome += secondPolynome) == polynomeOfInts{5, 5, 9}));
	REQUIRE((firstPolynome == polynomeOfInts{5, 5, 9}));
	REQUIRE(((firstPolynome += thirdPolynome) == polynomeOfInts{24, 17, 43, 15}));
	REQUIRE(((thirdPolynome += 1000) == polynomeOfInts{1019, 12, 34, 15}));
	REQUIRE((thirdPolynome + secondPolynome == polynomeOfInts{1021, 13, 34, 15}));
	REQUIRE((thirdPolynome + 25 == polynomeOfInts{1044, 12, 34, 15}));
}

TEST_CASE("10: polynomeOfInts, operator -") {
/*
	operator-= (const polynomeOfInts &rightHandSide);
	operator-= (const someType &rightHandSide);
	operator-  (const polynomeOfInts &rightHandSide);
	operator-  (const someType &rightHandSide);
*/
	polynomeOfInts firstPolynome({3, 4, 9});
	REQUIRE(firstPolynome[1] == 4);
	polynomeOfInts secondPolynome({2, 1});
	polynomeOfInts thirdPolynome({19, 12, 34, 15});
	REQUIRE(thirdPolynome[2] == 34);
	REQUIRE(((firstPolynome -= secondPolynome) == polynomeOfInts{1, 3, 9}));
	REQUIRE((firstPolynome == polynomeOfInts{1, 3, 9}));
	REQUIRE(((firstPolynome -= thirdPolynome) == polynomeOfInts{-18, -9, -25, -15}));
	REQUIRE(((thirdPolynome -= 1000) == polynomeOfInts{-981, 12, 34, 15}));
	REQUIRE((thirdPolynome - secondPolynome == polynomeOfInts{-983, 11, 34, 15}));
	REQUIRE((thirdPolynome - 25 == polynomeOfInts{-1006, 12, 34, 15}));
}

TEST_CASE("11: polynomeOfInts, operator *") {
/*
	operator*= (const polynomeOfInts &rightHandSide);
	operator*= (const someType &rightHandSide);
	operator*  (const polynomeOfInts &rightHandSide);
	operator*  (const someType &rightHandSide);
*/
	polynomeOfInts firstPolynome({3, 4, 9});
	REQUIRE(firstPolynome[1] == 4);
	polynomeOfInts secondPolynome({2, 1});
	polynomeOfInts thirdPolynome({19, 12, 34, 15}); 
	REQUIRE(thirdPolynome[2] == 34);
	REQUIRE((firstPolynome *= secondPolynome) == polynomeOfInts{6, 11, 22, 9});
	REQUIRE(firstPolynome == polynomeOfInts{6, 11, 22, 9});
	REQUIRE((firstPolynome *= thirdPolynome) == polynomeOfInts{114, 281, 754, 899, 1021, 636, 135});
	REQUIRE((thirdPolynome *= 1000) == polynomeOfInts{19000, 12000, 34000, 15000});
	thirdPolynome = {12, 943, 25};
	REQUIRE(thirdPolynome * secondPolynome == polynomeOfInts{24, 1898, 993, 25});
	REQUIRE(thirdPolynome * polynomeOfInts{2, 4} == polynomeOfInts{24, 1934, 3822, 100});
}

TEST_CASE("12: polynomeOfInts, operator /") {
/*
	operator*= (const polynomeOfInts &rightHandSide);
	operator*= (const someType &rightHandSide);
	operator*  (const polynomeOfInts &rightHandSide);
	operator*  (const someType &rightHandSide);
*/
	polynomeOfInts firstPolynome({3, 4, 9}); 
	REQUIRE(firstPolynome[1] == 4);
	polynomeOfInts secondPolynome({2, 1});
	polynomeOfInts thirdPolynome({19, 12, 34, 15}); 
	REQUIRE(thirdPolynome[2] == 34);
	REQUIRE(((firstPolynome /= secondPolynome) == polynomeOfInts{-14, 9}));
	REQUIRE((firstPolynome  == polynomeOfInts{-14, 9}));
	REQUIRE(((firstPolynome /= 3) == polynomeOfInts{-4, 3}));
	REQUIRE((thirdPolynome  / secondPolynome == polynomeOfInts{4, 4, 15}));
}

TEST_CASE("13: polynomeModulo, operator +") {
/*
	operator+= (const polynomeModulo &rightHandSide);
	operator+= (const someType &rightHandSide);
	operator+  (const polynomeModulo &rightHandSide);
	operator+  (const someType &rightHandSide);
*/
	intModulo :: changeModulo(17);
	polynomeModulo :: changeModulo({7, 4, 2, 5});
	polynomeModulo firstPolynome({3, 4, 9}); 
	REQUIRE(firstPolynome == polynomeModulo{3, 4, 9});
	polynomeModulo secondPolynome({2, 1});
	polynomeModulo thirdPolynome({19, 12, 34, 15}); /* {15, 0, 11} */
	REQUIRE(thirdPolynome  == polynomeModulo{15, 0, 11});
	REQUIRE((firstPolynome += secondPolynome) == polynomeModulo{5, 5, 9});
	REQUIRE(firstPolynome  == polynomeModulo{5, 5, 9});
	REQUIRE((firstPolynome += thirdPolynome) == polynomeModulo{3, 5, 3});
	REQUIRE((thirdPolynome += 1000) == polynomeModulo{1015, 0, 11});
	REQUIRE(thirdPolynome  + secondPolynome == polynomeModulo{1017, 1, 11});
	REQUIRE(thirdPolynome  + 25 == polynomeModulo{1040, 0, 11});
}

TEST_CASE("14: polynomeModulo, operator -") {
/*
	operator-= (const polynomeModulo &rightHandSide);
	operator-= (const someType &rightHandSide);
	operator-  (const polynomeModulo &rightHandSide);
	operator-  (const someType &rightHandSide);
*/
	intModulo :: changeModulo(17);
	polynomeModulo :: changeModulo({7, 4, 2, 5});
	polynomeModulo firstPolynome({3, 4, 9}); 
	REQUIRE(firstPolynome == polynomeModulo{3, 4, 9});
	polynomeModulo secondPolynome({2, 1});
	polynomeModulo thirdPolynome({19, 12, 34, 15}); /* {15, 0, 11} */
	REQUIRE(thirdPolynome == polynomeModulo{15, 0, 11});
	REQUIRE((firstPolynome -= secondPolynome) == polynomeModulo{1, 3, 9});
	REQUIRE((firstPolynome -= thirdPolynome) == polynomeModulo{3, 3, 15});
	REQUIRE((thirdPolynome -= 1000) == polynomeModulo{-985, 0, 11});
	REQUIRE(thirdPolynome  - secondPolynome == polynomeModulo{-987, 16, 11});
	REQUIRE(thirdPolynome  - 25 == polynomeModulo{-1010, 0, 11});
}

TEST_CASE("15: polynomeModulo, operator *") {
/*
	operator*= (const polynomeModulo &rightHandSide);
	operator*= (const someType &rightHandSide);
	operator*  (const polynomeModulo &rightHandSide);
	operator*  (const someType &rightHandSide);
*/
	intModulo :: changeModulo(17);
	polynomeModulo :: changeModulo({7, 4, 2, 5});
	polynomeModulo firstPolynome({3, 4, 9}); 
	REQUIRE(firstPolynome == polynomeModulo{3, 4, 9});
	polynomeModulo secondPolynome({2, 1});
	polynomeModulo thirdPolynome({19, 12, 34, 15}); /* {15, 0, 11} */
	REQUIRE(thirdPolynome  == polynomeModulo{15, 0, 11});
	REQUIRE((firstPolynome *= secondPolynome) == polynomeModulo{6, 11, 22, 9});
	REQUIRE((firstPolynome *= thirdPolynome) == polynomeModulo{90, 165, 396, 256, 242, 99});
	REQUIRE((thirdPolynome *= 1000) == polynomeModulo{15000, 0, 11000});
	REQUIRE(thirdPolynome  * secondPolynome == polynomeModulo{30000, 15000, 22000, 11000});
	REQUIRE(thirdPolynome  * 25 == polynomeModulo{25 * 15000, 0, 11000 * 25});
}

TEST_CASE("16: polynomeModulo, operator /") {
/*
	operator*= (const polynomeModulo &rightHandSide);
	operator*= (const someType &rightHandSide);
	operator*  (const polynomeModulo &rightHandSide);
	operator*  (const someType &rightHandSide);
*/
	intModulo :: changeModulo(17);
	polynomeModulo :: changeModulo({7, 4, 2, 5});
	polynomeModulo firstPolynome({3, 4, 9}); 
	REQUIRE(firstPolynome == polynomeModulo{3, 4, 9});
	polynomeModulo secondPolynome({2, 1});
	polynomeModulo thirdPolynome({19, 12, 34, 15}); /* {15, 0, 11} */
	REQUIRE(thirdPolynome  == polynomeModulo{15, 0, 11});
	std :: cout << 1 / secondPolynome << std :: endl;
	REQUIRE((firstPolynome /= secondPolynome) == polynomeModulo{1, 3, 9});
	REQUIRE((firstPolynome /= thirdPolynome) == polynomeModulo{3, 3, 15});
	REQUIRE((thirdPolynome /= 1000) == polynomeModulo{-985, 0, 11});
	REQUIRE(thirdPolynome  / secondPolynome == polynomeModulo{-987, 16, 11});
	REQUIRE(thirdPolynome  / 25 == polynomeModulo{-1010, 0, 11});
}

TEST_CASE("-1: Additionnal tests on ints") {
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

TEST_CASE("-2: Additionnal tests on intModulos") {
	intModulo :: changeModulo(701);
	intModulo firstInt(700);
	REQUIRE(firstInt == 700);								/* Constructor, == */
	intModulo :: changeModulo(7);
	REQUIRE(intModulo :: giveModulo() == 7);
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

