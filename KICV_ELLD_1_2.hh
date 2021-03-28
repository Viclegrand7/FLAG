#ifndef __KICV_ELLD__FLAG_1_2
#define __KICV_ELLD__FLAG_1_2

#include <iostream>
#include <string>

/*
HAL HAL HAL HAL HAL HAL HAL
HAL   QUESTIONS 1 - 2   HAL
HAL HAL HAL HAL HAL HAL HAL
*/

class justAnInt {
/* Attributes*/
	int64_t att_value;
/* Methods */
	std :: string toStr										() const {return std :: to_string(att_value);}
public:
	static int64_t extendedEuclidean						(justAnInt a, justAnInt b, justAnInt *u0, justAnInt *v0, bool wantATrace = true);
	int64_t giveValue										() {return att_value;}
/* Operator + */
	justAnInt &operator+=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator+=		(const someType &rightHandSide);
	justAnInt operator+										(const justAnInt &rightHandSide);
	template<typename someType> justAnInt operator+			(const someType &rightHandSide) 	const;
	template<typename someType> friend justAnInt operator+	(const someType &leftHandSide, 		const justAnInt &rightHandSide);
/* Operator - */
	justAnInt &operator-=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator-=		(const someType &rightHandSide);
	justAnInt operator-										(const justAnInt &rightHandSide);
	template<typename someType> justAnInt operator-			(const someType &rightHandSide) 	const;
	template<typename someType> friend justAnInt operator-	(const someType &leftHandSide, 		const justAnInt &rightHandSide);
	justAnInt operator-										()								 	const;
/* Operator * */
	justAnInt &operator*=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator*=		(const someType &rightHandSide);
	justAnInt operator*										(const justAnInt &rightHandSide);
	template<typename someType> justAnInt operator*			(const someType &rightHandSide) 	const;
	template<typename someType> friend justAnInt operator*	(const someType &leftHandSide, 		const justAnInt &rightHandSide);
/* Operator / */
	justAnInt &operator/=									(const justAnInt &rightHandSide);
	template<typename someType> justAnInt &operator/=		(const someType &rightHandSide);
	justAnInt operator/										(const justAnInt &rightHandSide);
	template<typename someType> justAnInt operator/			(const someType &rightHandSide) 	const;
	template<typename someType> friend justAnInt operator/	(const someType &leftHandSide, 		const justAnInt &rightHandSide);
/* Operator = */
	template<typename someType> justAnInt &operator=		(const someType &rightHandSide);
	justAnInt &operator=									(const justAnInt &rightHandSide);
/* Operator == */
	template<typename someType> bool operator==				(const someType &rightHandSide) 	const;
	bool operator==											(const justAnInt &rightHandSide) 	const;
	template<typename someType> bool operator!=				(const someType &rightHandSide) 	const;
	bool operator!=											(const justAnInt &rightHandSide) 	const;
/* Conversion */
	explicit operator bool									() 									const;
/* Operator > */
	template<typename someType> bool operator>				(const someType &rightHandSide) 	const;
	bool operator>											(const justAnInt &rightHandSide) 	const;
	template<typename someType> bool operator>=				(const someType &rightHandSide) 	const;
	bool operator>=											(const justAnInt &rightHandSide) 	const;
/* Operator < */
	template<typename someType> bool operator<				(const someType &rightHandSide) 	const;
	bool operator<											(const justAnInt &rightHandSide) 	const;
	template<typename someType> bool operator<=				(const someType &rightHandSide) 	const;
	bool operator<=											(const justAnInt &rightHandSide) 	const;
/* Operator << */
	friend std :: ostream &operator<<						(std :: ostream &out,				const justAnInt &rightHandSide);
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


template<typename someType> justAnInt &justAnInt :: operator=	(const someType &rightHandSide) {
	att_value = rightHandSide;
	return *this;
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

template<typename someType> justAnInt :: justAnInt				(const someType &rightHandSide) {
	att_value = rightHandSide;
}



#endif /*__KICV_ELLD__FLAG_1_2*/