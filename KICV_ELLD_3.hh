#ifndef __KICV_ELLD__FLAG_3
#define __KICV_ELLD__FLAG_3

//#include "KISV_ELLD_1_2.hh"
#include <iostream>
#include <string>

typedef uint32_t smallInt;
typedef uint64_t bigInt;


/*
HAL HAL HAL HAL HAL HAL
HAL   QUESTION  3   HAL
HAL HAL HAL HAL HAL HAL
*/

class intModulo {
/* Attributes */
	smallInt att_value;				/* The real value */
	static smallInt att_modulo;		/* Modulo value. The same for everyone */
/* Methods */
	std :: string toStr										() const 	{return std :: to_string(att_value);}
	intModulo quotient										(const intModulo &rightHandSide) const;
public:
	void normalize											();
	static intModulo extendedEuclidean						(intModulo a, intModulo b, intModulo *u0, intModulo *v0, bool wantATrace = true);
	intModulo modInv										() const;
	static void changeModulo								(const smallInt &);
	static smallInt giveModulo								()			{return att_modulo;}
/* Operator + */
	intModulo &operator+= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator+= 		(const someType &rightHandSide);
	friend intModulo operator+ 								(const intModulo &leftHandSide,		const intModulo &rightHandSide);
	template<typename someType> intModulo operator+ 		(const someType &rightHandSide) 	const;
	template<typename someType> friend intModulo operator+  (const someType &leftHandSide, 		const intModulo &rightHandSide);
/* Operator - */
	intModulo &operator-= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator-= 		(const someType &rightHandSide);
	friend intModulo operator- 								(const intModulo &leftHandSide,		const intModulo &rightHandSide);
	template<typename someType> intModulo operator- 		(const someType &rightHandSide) 	const;
	template<typename someType> friend intModulo operator-  (const someType &leftHandSide, 		const intModulo &rightHandSide);
	intModulo operator- 									()									const;
/* Operator * */
	intModulo &operator*= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator*= 		(const someType &rightHandSide);
	friend intModulo operator* 								(const intModulo &leftHandSide,		const intModulo &rightHandSide);
	template<typename someType> intModulo operator* 		(const someType &rightHandSide) 	const;
	template<typename someType> friend intModulo operator*  (const someType &leftHandSide, 		const intModulo &rightHandSide);
/* Operator / */
	intModulo &operator/= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator/= 		(const someType &rightHandSide);
	friend intModulo operator/ 								(const intModulo &leftHandSide,		const intModulo &rightHandSide);
	template<typename someType> intModulo operator/ 		(const someType &rightHandSide) 	const;
	template<typename someType> friend intModulo operator/  (const someType &leftHandSide, 		const intModulo &rightHandSide);
/* Operator = */
	template<typename someType> intModulo &operator=		(const someType &rightHandSide);
	intModulo &operator=									(const intModulo &rightHandSide);
/* Operator == */
	bool operator==											(const intModulo &rightHandSide) 	const;
	template<typename someType> bool operator==				(const someType &rightHandSide) 	const;
	template<typename someType> friend bool operator==		(const someType &leftHandSide,		const intModulo &rightHandSide);
	bool operator!=											(const intModulo &rightHandSide) 	const;
	template<typename someType> bool operator!=				(const someType &rightHandSide) 	const;
	template<typename someType> friend bool operator!=		(const someType &leftHandSide,		const intModulo &rightHandSide);
/* Conversion */
	explicit operator bool									() 									const;
/* Operator > */
	bool operator>											(const intModulo &rightHandSide) 	const;
	template<typename someType> bool operator>				(const someType &rightHandSide) 	const;
	template<typename someType> friend bool operator>		(const someType &leftHandSide,		const intModulo &rightHandSide);
	bool operator>=											(const intModulo &rightHandSide) 	const;
	template<typename someType> bool operator>=				(const someType &rightHandSide) 	const;
	template<typename someType> friend bool operator>=		(const someType &leftHandSide,		const intModulo &rightHandSide);
/* Operator < */
	bool operator<											(const intModulo &rightHandSide) 	const;
	template<typename someType> bool operator<				(const someType &rightHandSide) 	const;
	template<typename someType> friend bool operator<		(const someType &leftHandSide,		const intModulo &rightHandSide);
	bool operator<=											(const intModulo &rightHandSide) 	const;
	template<typename someType> bool operator<=				(const someType &rightHandSide) 	const;
	template<typename someType> friend bool operator<=		(const someType &leftHandSide,		const intModulo &rightHandSide);
#if _cplusplus >= 201907L

/* Three way comparison, the 'spaceship operator' */
	auto operator<=>										(const intModulo &rightHandSide)	const;
	template<typename someType> auto operator<=>			(const someType &rightHandSide)		const;
	template<typename someType> friend auto operator<=>		(const someType &leftHandSide,		const intModulo &rightHandSide);

#endif /* _cplusplus >= 201907L */
/* Operator in/de crement */
	intModulo &operator++									();
	intModulo &operator--									();
	intModulo operator++									(int);
	intModulo operator--									(int);
/* Operator << */
	friend std :: ostream &operator<<						(std :: ostream &out,				const intModulo &rightHandSide);
/* Constructors */
	template<typename someType> intModulo					(const someType &rightHandSide);
	intModulo												(const intModulo &rightHandSide);
	intModulo												();
};

template<typename someType> intModulo &intModulo :: operator+= (const someType &rightHandSide) {
	if (rightHandSide >= 0) {
		bigInt localCopy(rightHandSide);
		localCopy %= att_modulo; /* Making sure we do not overflow */
		att_value += localCopy;
		att_value %= att_modulo;	
		return *this;		
	}
	int64_t tmpRightHandSide(rightHandSide);
	do {
		tmpRightHandSide += att_modulo;
	} while (tmpRightHandSide < 0);
	att_value += tmpRightHandSide;
	att_value %= att_modulo;
	return *this;
}
/*
intModulo intModulo :: operator+  (const intModulo leftHandSide, const intModulo &rightHandSide) {

}
*/
template<typename someType> intModulo intModulo :: operator+ (const someType &rightHandSide) const {
	intModulo localCopy(*this);
	return localCopy += rightHandSide;
}

template<typename someType> intModulo operator+ (const someType &leftHandSide, const intModulo rightHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy += leftHandSide;
}


template<typename someType> intModulo &intModulo :: operator-= (const someType &rightHandSide) {
	if (rightHandSide >= 0) {
		bigInt localCopy(rightHandSide);
		localCopy %= att_modulo; /* Making sure we do not try to overflow */
		att_value += att_value >= localCopy ? 0 : att_modulo; /* We do not want to go negative */
		att_value -= localCopy;
		return *this;		
	}
	return *this += (- rightHandSide); /* Substracting negative <=> adding positive */
}

template<typename someType> intModulo intModulo :: operator- (const someType &rightHandSide) const {
	intModulo localCopy(*this);
	return localCopy -= rightHandSide;
}

template<typename someType> intModulo operator- (const someType &leftHandSide, const intModulo rightHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy -= leftHandSide;
}


template<typename someType> intModulo &intModulo :: operator*= (const someType &rightHandSide) {
	if (rightHandSide >= 0) {
		bigInt localValue(att_value);
		localValue *= (rightHandSide % att_modulo);
		att_value = localValue % att_modulo;
		return *this;		
	}
	int64_t tmpRightHandSide(rightHandSide);
	do {
		tmpRightHandSide += att_modulo;
	} while (tmpRightHandSide < 0);

	bigInt localValue(att_value);
	localValue *= rightHandSide;
	att_value = localValue % att_modulo;
	return *this;

}

template<typename someType> intModulo intModulo :: operator* (const someType &rightHandSide) const {
	intModulo localCopy(*this);
	return localCopy *= rightHandSide;
}

template<typename someType> intModulo operator* (const someType &leftHandSide, const intModulo rightHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy *= leftHandSide;
}


template<typename someType> intModulo &intModulo :: operator/= (const someType &rightHandSide) {
	if (rightHandSide > 0) {
		intModulo divider(rightHandSide);
		divider = divider.modInv();
		return *this *= divider;
	}
	int64_t localCopy(rightHandSide);
	localCopy %= att_modulo;
	localCopy += att_modulo;
	intModulo divider(localCopy);
	divider = divider.modInv();
	return *this *= divider;
}

template<typename someType> intModulo intModulo :: operator/ (const someType &rightHandSide) const {
	intModulo localCopy(*this);
	return localCopy /= rightHandSide;
}

template<typename someType> intModulo operator/ (const someType &leftHandSide, const intModulo rightHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy /= leftHandSide;
}

template<typename someType> intModulo &intModulo :: operator=	(const someType &rightHandSide) {
	att_value = rightHandSide % att_modulo;
	return *this;
}

template<typename someType> bool intModulo :: operator==		(const someType &rightHandSide) const {
	return att_value == intModulo(rightHandSide).att_value;
}

template<typename someType> bool operator==						(const someType &leftHandSide,	const intModulo &rightHandSide) {
	return rightHandSide.att_value == intModulo(leftHandSide).att_value;
}

template<typename someType> bool intModulo :: operator!=		(const someType &rightHandSide) const {
	return att_value != intModulo(rightHandSide).att_value;
}

template<typename someType> bool operator!=						(const someType &leftHandSide,	const intModulo &rightHandSide) {
	return rightHandSide.att_value != intModulo(leftHandSide).att_value;
}

template<typename someType> bool intModulo :: operator>			(const someType &rightHandSide) const {
	return att_value > intModulo(rightHandSide).att_value;
}

template<typename someType> bool operator>						(const someType &leftHandSide,	const intModulo &rightHandSide) {
	return intModulo(leftHandSide).att_value > rightHandSide.att_value;
}

template<typename someType> bool intModulo :: operator>=		(const someType &rightHandSide) const {
	return att_value >= intModulo(rightHandSide).att_value;
}

template<typename someType> bool operator>=						(const someType &leftHandSide,	const intModulo &rightHandSide) {
	return intModulo(leftHandSide).att_value >= rightHandSide.att_value;
}

template<typename someType> bool intModulo :: operator<			(const someType &rightHandSide) const {
	return att_value < intModulo(rightHandSide).att_value;
}

template<typename someType> bool operator<						(const someType &leftHandSide,	const intModulo &rightHandSide) {
	return intModulo(leftHandSide).att_value < rightHandSide.att_value;
}

template<typename someType> bool intModulo :: operator<=		(const someType &rightHandSide) const {
	return att_value <= intModulo(rightHandSide).att_value;
}

template<typename someType> bool operator<=						(const someType &leftHandSide,	const intModulo &rightHandSide) {
	return intModulo(leftHandSide).att_value <= rightHandSide.att_value;
}

#if _cplusplus >= 201907L
	template<typename someType> auto intModulo :: operator<=>		(const someType &rightHandSide)	const {
		return att_value <=> intModulo(rightHandSide).att_value;
	}

	template<typename someType> auto operator<=>					(const someType &leftHandSide,	const intModulo &rightHandSide) {
		return intModulo(leftHandSide).att_value <=> rightHandSide.att_value;
	}
#endif /* _cplusplus >= 201907L */

template<typename someType> intModulo :: intModulo				(const someType &rightHandSide) {
	if (rightHandSide >= 0)
		att_value = rightHandSide % att_modulo;
	else 
		att_value = att_modulo - (rightHandSide % att_modulo);
}



#endif /*__KICV_ELLD__FLAG_3*/