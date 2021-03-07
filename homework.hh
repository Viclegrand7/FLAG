#ifndef __KISV_ELLD__FLAG
#define __KISV_ELLD__FLAG

#include <iostream>
#include <string>

typedef smallInt uint32_t
typedef bigInt uint64_t

class justAnInt {
/* Attributes*/
	int64_t att_value;
/* Methods */
	std :: string toStr() {return std :: to_string(att_value);}
public:
	justAnInt &operator+=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator+=		(const someType &rightHandSide);
	template<typename someType> justAnInt operator+			(const someType &rightHandSide) const;
	template<typename someType> friend justAnInt operator+	(const someType &leftHandSide, const justAnInt &rightHandSide) const;

	justAnInt &operator-=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator-=		(const someType &rightHandSide);
	template<typename someType> justAnInt operator-			(const someType &rightHandSide) const;
	template<typename someType> friend justAnInt operator-	(const someType &leftHandSide, const justAnInt &rightHandSide) const;

	justAnInt &operator+=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator+=		(const someType &rightHandSide);
	template<typename someType> justAnInt operator*			(const someType &rightHandSide) const;
	template<typename someType> friend justAnInt operator*	(const someType &leftHandSide, const justAnInt &rightHandSide) const;

	justAnInt &operator/=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator/=		(const someType &rightHandSide);
	template<typename someType> justAnInt operator/			(const someType &rightHandSide) const;
	template<typename someType> friend justAnInt operator/	(const someType &leftHandSide, const justAnInt &rightHandSide) const;

	justAnInt extendedEuclidean(justAnInt a, justAnInt b, justAnInt *u0, justAnInt *v0, bool wantATrace = true);
};


class intModulo {
/* Attributes */
	smallInt att_value;				/* The real value */
	static smallInt att_modulo;		/* Modulo value. The same for everyone */
/* Methods */
	std :: string toStr() {return std :: to_string(att_value);}
public:
	intModulo &operator+= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator+= 		(const someType &rightHandSide);
//	intModulo operator+  (const intModulo &rightHandSide) const;
	template<typename someType> intModulo operator+ 		(const someType &rightHandSide) const;
	template<typename someType> friend intModulo operator+  (const someType &leftHandSide, const intModulo rightHandSide) const;

	intModulo &operator-= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator-= 		(const someType &rightHandSide);
//	intModulo operator+  (const intModulo &rightHandSide);
	template<typename someType> intModulo operator- 		(const someType &rightHandSide) const;
	template<typename someType> friend intModulo operator-  (const someType &leftHandSide, const intModulo rightHandSide) const;

	intModulo &operator*= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator*= 		(const someType &rightHandSide);
//	intModulo operator+  (const intModulo &rightHandSide);
	template<typename someType> intModulo operator* 		(const someType &rightHandSide) const;
	template<typename someType> friend intModulo operator*  (const someType &leftHandSide, const intModulo rightHandSide) const;

	intModulo &operator/= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator/= 		(const someType &rightHandSide);
//	intModulo operator+  (const intModulo &rightHandSide);
	template<typename someType> intModulo operator/ 		(const someType &rightHandSide) const;
	template<typename someType> friend intModulo operator/  (const someType &leftHandSide, const intModulo rightHandSide) const;

	intModulo extendedEuclidean(intModulo a, intModulo b, intModulo *u0, intModulo *v0, bool wantATrace = true);
	intModulo modInv();
};

intModulo &intModulo :: operator+= (const intModulo &rightHandSide) {
	att_value += rightHandSide.att_value;
	att_value %= att_modulo;
}

template<typename someType> intModulo &intModulo :: operator+= (const someType &rightHandSide) {
	std :: cout << rightHandSide < 0 ? "Not YET\n" : ""; /* I am yet not sure what to do if we get a negative char or something that would overflow if added the modulo */
	rightHandSide %= att_modulo; /* Making sure we do not overflow */
	att_value += rightHandSide;
	att_value %= att_modulo;	
}
/*
intModulo intModulo :: operator+  (const intModulo leftHandSide, const intModulo &rightHandSide) {

}
*/
template<typename someType> intModulo intModulo :: operator+ (const someType &rightHandSide) {
	intModulo localCopy(*self);
	return localCopy += rightHandSide;
}

template<typename someType> intModulo operator+ (const someType &rightHandSide, const intModulo leftHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy += leftHandSide;
}


intModulo &intModulo :: operator-= (const intModulo &rightHandSide) {
	att_value += att_value > rightHandSide.att_value ? 0 : att_modulo; /* We do not want to go negative */
	att_value -= rightHandSide.att_value;
}

template<typename someType> intModulo &intModulo :: operator-= (const someType &rightHandSide) {
	std :: cout << rightHandSide < 0 ? "Not YET\n" : "";
	rightHandSide %= att_modulo; /* Making sure we do not try to overflow */
	att_value += att_value > rightHandSide.att_value ? 0 : att_modulo; /* We do not want to go negative */
	att_value -= rightHandSide.att_value;
}
/*
intModulo intModulo :: operator-  (const intModulo leftHandSide, const intModulo &rightHandSide) {

}
*/
template<typename someType> intModulo intModulo :: operator- (const someType &rightHandSide) {
	intModulo localCopy(*self);
	return localCopy -= rightHandSide;
}

template<typename someType> intModulo operator- (const someType &leftHandSide, const intModulo rightHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy -= leftHandSide;
}


intModulo &intModulo :: operator*= (const intModulo &rightHandSide) {
	bigInt localValue(att_value);
	localValue *= rightHandSide.att_value;
	att_value = localValue % att_modulo;
}

template<typename someType> intModulo &intModulo :: operator*= (const someType &rightHandSide) {
	std :: cout << rightHandSide < 0 ? "Not YET\n" : "";
	rightHandSide %= att_modulo; /* Making sure we do not overflow */

	bigInt localValue(att_value);
	localValue *= rightHandSide;
	att_value = localValue % att_modulo;
}
/*
intModulo intModulo :: operator*  (const intModulo leftHandSide, const intModulo &rightHandSide) {

}
*/
template<typename someType> intModulo intModulo :: operator* (const someType &rightHandSide) {
	intModulo localCopy(*self);
	return localCopy *= rightHandSide;
}

template<typename someType> intModulo operator* (const someType &leftHandSide, const intModulo rightHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy *= leftHandSide;
}


intModulo &intModulo :: operator/= (const intModulo &rightHandSide) {
	intModulo divider(rightHandSide.modInv())
	att_value *= divider;
}

template<typename someType> intModulo &intModulo :: operator/= (const someType &rightHandSide) {
	std :: cout << rightHandSide < 0 ? "Not YET\n" : "";
	rightHandSide %= att_modulo; /* Making sure we can do our stuff */


	intModulo divider(rightHandSide); /* Just a mere cast for now */
	divider = divider.modInv(); /*There we actually inverted it */
	att_value *= divider;
}
/*
intModulo intModulo :: operator/  (const intModulo leftHandSide, const intModulo &rightHandSide) {

}
*/
template<typename someType> intModulo intModulo :: operator/ (const someType &rightHandSide) {
	intModulo localCopy(*self);
	return localCopy /= rightHandSide;
}

template<typename someType> intModulo operator/ (const someType &leftHandSide, const intModulo rightHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy /= leftHandSide;
}





#endif /*__KISV_ELLD__FLAG*/