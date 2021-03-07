#ifndef __KISV_ELLD__FLAG
#define __KISV_ELLD__FLAG

#include <iostream>
#include <string>

typedef uint32_t smallInt;
typedef uint64_t bigInt;


/*
HAL HAL HAL HAL HAL HAL HAL
HAL   QUESTIONS 1 - 2   HAL
HAL HAL HAL HAL HAL HAL HAL
*/

class justAnInt {
/* Attributes*/
	int64_t att_value;
/* Methods */
	std :: string toStr() {return std :: to_string(att_value);}
public:
	static int64_t extendedEuclidean(justAnInt a, justAnInt b, justAnInt *u0, justAnInt *v0, bool wantATrace = true);
	int64_t giveValue() {return att_value;}
/* Operator + */
	justAnInt &operator+=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator+=		(const someType &rightHandSide);
	template<typename someType> justAnInt operator+			(const someType &rightHandSide) const;
	template<typename someType> friend justAnInt operator+	(const someType &leftHandSide, const justAnInt &rightHandSide);
/* Operator - */
	justAnInt &operator-=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator-=		(const someType &rightHandSide);
	template<typename someType> justAnInt operator-			(const someType &rightHandSide) const;
	template<typename someType> friend justAnInt operator-	(const someType &leftHandSide, const justAnInt &rightHandSide);
/* Operator * */
	justAnInt &operator*=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator*=		(const someType &rightHandSide);
	template<typename someType> justAnInt operator*			(const someType &rightHandSide) const;
	template<typename someType> friend justAnInt operator*	(const someType &leftHandSide, const justAnInt &rightHandSide);
/* Operator / */
	justAnInt &operator/=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator/=		(const someType &rightHandSide);
	template<typename someType> justAnInt operator/			(const someType &rightHandSide) const;
	template<typename someType> friend justAnInt operator/	(const someType &leftHandSide, const justAnInt &rightHandSide);
/* Operator = */
	template<typename someType> justAnInt &operator=		(const someType &rightHandSide);
	justAnInt &operator=									(const justAnInt &rightHandSide);
/* Operator == */
	template<typename someType> bool operator==				(const someType &rightHandSide) const;
	bool operator==											(const justAnInt &rightHandSide) const;
	template<typename someType> bool operator!=				(const someType &rightHandSide) const;
	bool operator!=											(const justAnInt &rightHandSide) const;
	explicit operator bool									() const;
/* Operator > */
	template<typename someType> bool operator>				(const someType &rightHandSide) const;
	bool operator>											(const justAnInt &rightHandSide) const;
	template<typename someType> bool operator>=				(const someType &rightHandSide) const;
	bool operator>=											(const justAnInt &rightHandSide) const;
/* Operator < */
	template<typename someType> bool operator<				(const someType &rightHandSide) const;
	bool operator<											(const justAnInt &rightHandSide) const;
	template<typename someType> bool operator<=				(const someType &rightHandSide) const;
	bool operator<=											(const justAnInt &rightHandSide) const;
/* Constructors */
	template<typename someType> justAnInt(const someType &rightHandSide);
	justAnInt(const justAnInt &rightHandSide);
	justAnInt();
};

template<typename someType> justAnInt &justAnInt :: operator+=	(const someType &rightHandSide) {
	att_value += rightHandSide;
	return *this;
}

template<typename someType> justAnInt justAnInt :: operator+	(const someType &rightHandSide) const {
	justAnInt localCopy(*this);
	return localCopy += rightHandSide;
}

template<typename someType> justAnInt operator+					(const someType &leftHandSide, const justAnInt &rightHandSide) {
	justAnInt localCopy(rightHandSide);
	return localCopy += leftHandSide;	
}

template<typename someType> justAnInt &justAnInt :: operator-=	(const someType &rightHandSide) {
	att_value -= rightHandSide;
	return *this;
}

template<typename someType> justAnInt justAnInt :: operator-	(const someType &rightHandSide) const {
	justAnInt localCopy(*this);
	return localCopy -= rightHandSide;
}

template<typename someType> justAnInt operator-					(const someType &leftHandSide, const justAnInt &rightHandSide) {
	justAnInt localCopy(rightHandSide);
	return localCopy -= leftHandSide;	
}


template<typename someType> justAnInt &justAnInt :: operator*=	(const someType &rightHandSide) {
	att_value *= rightHandSide;
	return *this;
}

template<typename someType> justAnInt justAnInt :: operator*	(const someType &rightHandSide) const {
	justAnInt localCopy(*this);
	return localCopy *= rightHandSide;
}

template<typename someType> justAnInt operator*					(const someType &leftHandSide, const justAnInt &rightHandSide) {
	justAnInt localCopy(rightHandSide);
	return localCopy *= leftHandSide;	
}


template<typename someType> justAnInt &justAnInt :: operator/=	(const someType &rightHandSide) {
	att_value /= rightHandSide;	
	return *this;
}

template<typename someType> justAnInt justAnInt :: operator/	(const someType &rightHandSide) const {
	justAnInt localCopy(*this);
	return localCopy /= rightHandSide;
}

template<typename someType> justAnInt operator/					(const someType &leftHandSide, const justAnInt &rightHandSide) {
	justAnInt localCopy(rightHandSide);
	return localCopy /= leftHandSide;	
}


template<typename someType> bool justAnInt :: operator==		(const someType &rightHandSide) const {
	return att_value == rightHandSide;
}

template<typename someType> bool justAnInt :: operator!=		(const someType &rightHandSide) const {
	return att_value != rightHandSide.att_value;
}

template<typename someType> bool justAnInt :: operator>			(const someType &rightHandSide) const {
	return att_value > rightHandSide;
}

template<typename someType> bool justAnInt :: operator>=		(const someType &rightHandSide) const {
	return att_value >= rightHandSide;
}

template<typename someType> bool justAnInt :: operator<			(const someType &rightHandSide) const {
	return att_value < rightHandSide;
}

template<typename someType> bool justAnInt :: operator<=		(const someType &rightHandSide) const {
	return att_value <= rightHandSide;
}

template<typename someType> justAnInt &justAnInt :: operator=	(const someType &rightHandSide) {
	att_value = rightHandSide;
	return *this;
}

template<typename someType> justAnInt :: justAnInt				(const someType &rightHandSide) {
	att_value = rightHandSide;
}


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
	std :: string toStr() {return std :: to_string(att_value);}
public:
	intModulo modInv() const;
/* Operator + */
	intModulo &operator+= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator+= 		(const someType &rightHandSide);
	template<typename someType> intModulo operator+ 		(const someType &rightHandSide) const;
	template<typename someType> friend intModulo operator+  (const someType &leftHandSide, const intModulo rightHandSide);
/* Operator - */
	intModulo &operator-= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator-= 		(const someType &rightHandSide);
	template<typename someType> intModulo operator- 		(const someType &rightHandSide) const;
	template<typename someType> friend intModulo operator-  (const someType &leftHandSide, const intModulo rightHandSide);
/* Operator * */
	intModulo &operator*= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator*= 		(const someType &rightHandSide);
	template<typename someType> intModulo operator* 		(const someType &rightHandSide) const;
	template<typename someType> friend intModulo operator*  (const someType &leftHandSide, const intModulo rightHandSide);
/* Operator / */
	intModulo &operator/= 									(const intModulo &rightHandSide);
	template<typename someType> intModulo &operator/= 		(const someType &rightHandSide);
	template<typename someType> intModulo operator/ 		(const someType &rightHandSide) const;
	template<typename someType> friend intModulo operator/  (const someType &leftHandSide, const intModulo rightHandSide);
/* Operator = */
	template<typename someType> intModulo &operator=		(const someType &rightHandSide);
	intModulo &operator=									(const intModulo &rightHandSide);
/* Operator == */
	template<typename someType> bool operator==				(const someType &rightHandSide) const;
	bool operator==											(const intModulo &rightHandSide) const;
	template<typename someType> bool operator!=				(const someType &rightHandSide) const;
	bool operator!=											(const intModulo &rightHandSide) const;
	explicit operator bool									() const;
/* Operator > */
	template<typename someType> bool operator>				(const someType &rightHandSide) const;
	bool operator>											(const intModulo &rightHandSide) const;
	template<typename someType> bool operator>=				(const someType &rightHandSide) const;
	bool operator>=											(const intModulo &rightHandSide) const;
/* Operator < */
	template<typename someType> bool operator<				(const someType &rightHandSide) const;
	bool operator<											(const intModulo &rightHandSide) const;
	template<typename someType> bool operator<=				(const someType &rightHandSide) const;
	bool operator<=											(const intModulo &rightHandSide) const;
/* Constructors */
	template<typename someType> intModulo(const someType &rightHandSide);
	intModulo(const intModulo &rightHandSide);
	intModulo();
};

uint32_t intModulo :: att_modulo = UINT32_MAX;

template<typename someType> intModulo &intModulo :: operator+= (const someType &rightHandSide) {
	std :: cout << rightHandSide < 0 ? "Not YET\n" : ""; /* I am yet not sure what to do if we get a negative char or something that would overflow if added the modulo */
	rightHandSide %= att_modulo; /* Making sure we do not overflow */
	att_value += rightHandSide;
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

template<typename someType> intModulo operator+ (const someType &rightHandSide, const intModulo leftHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy += leftHandSide;
}


template<typename someType> intModulo &intModulo :: operator-= (const someType &rightHandSide) {
	std :: cout << rightHandSide < 0 ? "Not YET\n" : "";
	rightHandSide %= att_modulo; /* Making sure we do not try to overflow */
	att_value += att_value > rightHandSide.att_value ? 0 : att_modulo; /* We do not want to go negative */
	att_value -= rightHandSide.att_value;
	return *this;
}
/*
intModulo intModulo :: operator-  (const intModulo leftHandSide, const intModulo &rightHandSide) {

}
*/
template<typename someType> intModulo intModulo :: operator- (const someType &rightHandSide) const {
	intModulo localCopy(*this);
	return localCopy -= rightHandSide;
}

template<typename someType> intModulo operator- (const someType &leftHandSide, const intModulo rightHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy -= leftHandSide;
}


template<typename someType> intModulo &intModulo :: operator*= (const someType &rightHandSide) {
	std :: cout << rightHandSide < 0 ? "Not YET\n" : "";
	rightHandSide %= att_modulo; /* Making sure we do not overflow */

	bigInt localValue(att_value);
	localValue *= rightHandSide;
	att_value = localValue % att_modulo;
	return *this;
}
/*
intModulo intModulo :: operator*  (const intModulo leftHandSide, const intModulo &rightHandSide) {

}
*/
template<typename someType> intModulo intModulo :: operator* (const someType &rightHandSide) const {
	intModulo localCopy(*this);
	return localCopy *= rightHandSide;
}

template<typename someType> intModulo operator* (const someType &leftHandSide, const intModulo rightHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy *= leftHandSide;
}


template<typename someType> intModulo &intModulo :: operator/= (const someType &rightHandSide) {
	std :: cout << rightHandSide < 0 ? "Not YET\n" : "";
	rightHandSide %= att_modulo; /* Making sure we can do our stuff */


	intModulo divider(rightHandSide); /* Just a mere cast for now */
	divider = divider.modInv(); /*There we actually inverted it */
	return *this *= divider;
}
/*
intModulo intModulo :: operator/  (const intModulo leftHandSide, const intModulo &rightHandSide) {

}
*/
template<typename someType> intModulo intModulo :: operator/ (const someType &rightHandSide) const {
	intModulo localCopy(*this);
	return localCopy /= rightHandSide;
}

template<typename someType> intModulo operator/ (const someType &leftHandSide, const intModulo rightHandSide) {
	intModulo localCopy(rightHandSide);
	return localCopy /= leftHandSide;
}

template<typename someType> bool intModulo :: operator==		(const someType &rightHandSide) const {
	return att_value == rightHandSide;
}

template<typename someType> bool intModulo :: operator!=		(const someType &rightHandSide) const {
	return att_value != rightHandSide.att_value;
}

template<typename someType> bool intModulo :: operator>			(const someType &rightHandSide) const {
	return att_value > rightHandSide;
}

template<typename someType> bool intModulo :: operator>=		(const someType &rightHandSide) const {
	return att_value >= rightHandSide;
}

template<typename someType> bool intModulo :: operator<			(const someType &rightHandSide) const {
	return att_value < rightHandSide;
}

template<typename someType> bool intModulo :: operator<=		(const someType &rightHandSide) const {
	return att_value <= rightHandSide;
}



template<typename someType> intModulo &intModulo :: operator=	(const someType &rightHandSide) {
	att_value = rightHandSide;
	return *this;
}

template<typename someType> intModulo :: intModulo				(const someType &rightHandSide) {
	att_value = rightHandSide;
}



#endif /*__KISV_ELLD__FLAG*/