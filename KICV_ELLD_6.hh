#ifndef __KICV_ELLD__FLAG_6
#define __KICV_ELLD__FLAG_6

#include "KICV_ELLD_3.hh"
#include <iostream>
#include <string>
#include <vector>

/*
HAL HAL HAL HAL HAL HAL
HAL   QUESTION  6   HAL
HAL HAL HAL HAL HAL HAL
*/

class polynomeModulo {
/* Attributes */
	std :: vector <intModulo> att_value;				/* The real values. We are using vectors */
	static std :: vector <intModulo> att_modulo;		/* Modulo value. The same for everyone */
/* Methods */
	polynomeModulo quotient										(const polynomeModulo &rightHandSide) const;
public:
	void normalize												();
	static polynomeModulo extendedEuclidean						(polynomeModulo a, polynomeModulo b, polynomeModulo *u0, polynomeModulo *v0, bool wantATrace = true);
	polynomeModulo modInv										() const;
	static void changeModulo									(const std :: vector <intModulo>&);
/* Operator [] */
	intModulo &operator[]										(unsigned int position)			{return att_value[position];}
	intModulo  operator[]										(unsigned int position) const 	{return att_value[position];}
/* Operator + */
	polynomeModulo &operator+= 									(const polynomeModulo &rightHandSide);
	polynomeModulo &operator+= 									(const std :: vector <intModulo> &rightHandSide);
	template<typename someType> polynomeModulo &operator+= 		(const someType &rightHandSide);
	friend polynomeModulo operator+ 							(const polynomeModulo &leftHandSide,	const polynomeModulo &rightHandSide);
	template<typename someType> polynomeModulo operator+ 		(const someType &rightHandSide) 		const;
	template<typename someType> friend polynomeModulo operator+ (const someType &leftHandSide, 			const polynomeModulo &rightHandSide);
/* Operator - */
	polynomeModulo &operator-= 									(const polynomeModulo &rightHandSide);
	polynomeModulo &operator-= 									(const std :: vector <intModulo> &rightHandSide);
	template<typename someType> polynomeModulo &operator-= 		(const someType &rightHandSide);
	friend polynomeModulo operator- 							(const polynomeModulo &leftHandSide,	const polynomeModulo &rightHandSide);
	template<typename someType> polynomeModulo operator- 		(const someType &rightHandSide) 		const;
	template<typename someType> friend polynomeModulo operator- (const someType &leftHandSide, 			const polynomeModulo &rightHandSide);
	polynomeModulo operator- 									()										const;
/* Operator * */
	polynomeModulo &operator*= 									(const polynomeModulo &rightHandSide);
	polynomeModulo &operator*= 									(const std :: vector <intModulo> &rightHandSide);
	template<typename someType> polynomeModulo &operator*= 		(const someType &rightHandSide);
	friend polynomeModulo operator* 							(const polynomeModulo &leftHandSide,	const polynomeModulo &rightHandSide);
	template<typename someType> polynomeModulo operator* 		(const someType &rightHandSide) 		const;
	template<typename someType> friend polynomeModulo operator* (const someType &leftHandSide, 			const polynomeModulo &rightHandSide);
/* Operator / */
	polynomeModulo &operator/= 									(const polynomeModulo &rightHandSide);
	polynomeModulo &operator/= 									(const std :: vector <intModulo> &rightHandSide);
	template<typename someType> polynomeModulo &operator/= 		(const someType &rightHandSide);
	friend polynomeModulo operator/ 							(const polynomeModulo &leftHandSide,	const polynomeModulo &rightHandSide);
	template<typename someType> polynomeModulo operator/ 		(const someType &rightHandSide) 		const;
	template<typename someType> friend polynomeModulo operator/ (const someType &leftHandSide, 			const polynomeModulo &rightHandSide);
/* Operator = */
	template<typename someType> polynomeModulo &operator=		(const someType &rightHandSide);
	polynomeModulo &operator=									(const polynomeModulo &rightHandSide);
	polynomeModulo &operator= 									(const std :: vector <intModulo> &rightHandSide);
/* Operator == */
	bool operator==												(const polynomeModulo &rightHandSide)	const;
	bool operator==			 									(const std :: vector <intModulo> &rightHandSide)								const;
	template<typename someType> bool operator==					(const someType &rightHandSide) 		const;
	template<typename someType> friend bool operator==			(const someType &leftHandSide,			const polynomeModulo &rightHandSide);
	bool operator!=												(const polynomeModulo &rightHandSide) 	const;
	bool operator!=			 									(const std :: vector <intModulo> &rightHandSide)								const;
	template<typename someType> bool operator!=					(const someType &rightHandSide) 		const;
	template<typename someType> friend bool operator!=			(const someType &leftHandSide,			const polynomeModulo &rightHandSide);
/* Conversion */
	explicit operator bool										() 										const;
/* Operator > */
	bool operator>												(const polynomeModulo &rightHandSide)	const;
	bool operator>			 									(const std :: vector <intModulo> &rightHandSide)								const;
	template<typename someType> bool operator>					(const someType &rightHandSide)			const;
	template<typename someType> friend bool operator>			(const someType &leftHandSide,			const polynomeModulo &rightHandSide);
	bool operator>=												(const polynomeModulo &rightHandSide) 	const;
	bool operator>=			 									(const std :: vector <intModulo> &rightHandSide)								const;
	template<typename someType> bool operator>=					(const someType &rightHandSide)		 	const;
	template<typename someType> friend bool operator>=			(const someType &leftHandSide,			const polynomeModulo &rightHandSide);
/* Operator < */
	bool operator<												(const polynomeModulo &rightHandSide) 	const;
	bool operator<			 									(const std :: vector <intModulo> &rightHandSide)								const;
	template<typename someType> bool operator<					(const someType &rightHandSide)	 		const;
	template<typename someType> friend bool operator<			(const someType &leftHandSide,			const polynomeModulo &rightHandSide);
	bool operator<=												(const polynomeModulo &rightHandSide) 	const;
	bool operator<=			 									(const std :: vector <intModulo> &rightHandSide)								const;
	template<typename someType> bool operator<=					(const someType &rightHandSide) 		const;
	template<typename someType> friend bool operator<=			(const someType &leftHandSide,			const polynomeModulo &rightHandSide);
#if _cplusplus >= 201907L
/* Three way comparison, the 'spaceship operator' */
	auto operator<=>											(const polynomeModulo &rightHandSide)	const;
	auto operator<=>											(const std :: vector <intModulo> &rightHandSide)								const;
	template<typename someType> auto operator<=>				(const someType &rightHandSide)			const;
	template<typename someType> friend auto operator<=>			(const someType &leftHandSide,			const polynomeModulo &rightHandSide);
#endif /* _cplusplus >= 201907L */

/* Operator in/de crement */
	/*
	polynomeModulo &operator++									();
	polynomeModulo &operator--									();
	polynomeModulo operator++									(int);
	polynomeModulo operator--									(int);
	*/
/* Operator << */
	friend std :: ostream &operator<<							(std :: ostream &out,					const polynomeModulo &rightHandSide);
/* Constructors */
	template<typename someType> polynomeModulo					(const someType &rightHandSide);
	polynomeModulo												(const polynomeModulo &rightHandSide);
	polynomeModulo												(const std :: vector <intModulo> &rightHandSide);
	polynomeModulo												();
};

template<typename someType> polynomeModulo &polynomeModulo :: operator+= 	(const someType &rightHandSide) {
	if (att_value.size()) {
		att_value[0] += rightHandSide;
		return *this;
	}
	att_value.push_back(rightHandSide);
}

template<typename someType> polynomeModulo polynomeModulo :: operator+ 		(const someType &rightHandSide) const {
	polynomeModulo localCopy(*this);
	return localCopy += rightHandSide;
}

template<typename someType> polynomeModulo operator+ 						(const someType &leftHandSide, const polynomeModulo rightHandSide) {
	polynomeModulo localCopy(rightHandSide);
	return localCopy += leftHandSide;
}


template<typename someType> polynomeModulo &polynomeModulo :: operator-= 	(const someType &rightHandSide) {
	if (rightHandSide >= 0) {
		if (att_value.size()) {
			att_value[0] -= rightHandSide;
			return *this;
		}
		att_value.push_back(rightHandSide);
	}
	return *this += (- rightHandSide); /* Substracting negative <=> adding positive */
}

template<typename someType> polynomeModulo polynomeModulo :: operator- 		(const someType &rightHandSide) const {
	polynomeModulo localCopy(*this);
	return localCopy -= rightHandSide;
}

template<typename someType> polynomeModulo operator-				 		(const someType &leftHandSide, 	const polynomeModulo rightHandSide) {
	polynomeModulo localCopy(rightHandSide);
	return localCopy -= leftHandSide;
}


template<typename someType> polynomeModulo &polynomeModulo :: operator*= 	(const someType &rightHandSide) {
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		att_value[i] *= rightHandSide;
	return *this;
}

template<typename someType> polynomeModulo polynomeModulo :: operator* 		(const someType &rightHandSide) const {
	polynomeModulo localCopy(*this);
	return localCopy *= rightHandSide;
}

template<typename someType> polynomeModulo operator* 						(const someType &leftHandSide, 	const polynomeModulo &rightHandSide) {
	polynomeModulo localCopy(rightHandSide);
	return localCopy *= leftHandSide;
}


template<typename someType> polynomeModulo &polynomeModulo :: operator/= 	(const someType &rightHandSide) {
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		att_value[i] /= rightHandSide;
	return *this;
}

template<typename someType> polynomeModulo polynomeModulo :: operator/ 		(const someType &rightHandSide) const {
	polynomeModulo localCopy(*this);
	return localCopy /= rightHandSide;
}

template<typename someType> polynomeModulo operator/ 						(const someType &leftHandSide, 	const polynomeModulo &rightHandSide) {
	polynomeModulo localCopy(rightHandSide);
	return localCopy /= leftHandSide;
}


template<typename someType> polynomeModulo &polynomeModulo :: operator=		(const someType &rightHandSide) {
	att_value.clear();
	att_value.push_back(rightHandSide);
	return *this;
}

template<typename someType> bool polynomeModulo :: operator==				(const someType &rightHandSide) const {
	if (att_value.size() == 1)
		return att_value[0] == rightHandSide;
	return false;
}

template<typename someType> bool operator==									(const someType &leftHandSide,	const polynomeModulo &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return rightHandSide[0] == leftHandSide;
	return false;
}

template<typename someType> bool polynomeModulo :: operator!=				(const someType &rightHandSide) const {
	if (att_value.size() == 1)
		return att_value[0] != rightHandSide;
	return true;
}

template<typename someType> bool operator!=									(const someType &leftHandSide,	const polynomeModulo &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return rightHandSide[0] != leftHandSide;
	return true;
}

template<typename someType> bool polynomeModulo :: operator>				(const someType &rightHandSide)	const {
	if (att_value.size() > 1)
		return true;
	if (att_value.size())
		return att_value[0] > rightHandSide;
	return false;
}

template<typename someType> bool operator>									(const someType &leftHandSide,	const polynomeModulo &rightHandSide) {
	if (!(rightHandSide.att_value.size()))
		return true;
	if (rightHandSide.att_value.size() > 1)
		return false;
	return leftHandSide > rightHandSide[0];
}

template<typename someType> bool polynomeModulo :: operator>=				(const someType &rightHandSide)	const {
	if (att_value.size() == 1)
		return att_value[0] >= rightHandSide;
	if (att_value.size())
		return true;
	return false;
}

template<typename someType> bool operator>=									(const someType &leftHandSide,	const polynomeModulo &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return leftHandSide >= rightHandSide[0];
	if (rightHandSide.att_value.size())
		return false;
	return true;
}

template<typename someType> bool polynomeModulo :: operator<				(const someType &rightHandSide)	const {
	if (att_value.size() == 1)
		return att_value[0] < rightHandSide;
	if (att_value.size())
		return false;
	return true;
}

template<typename someType> bool operator<									(const someType &leftHandSide,	const polynomeModulo &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return leftHandSide < rightHandSide[0];
	if (rightHandSide.att_value.size())
		return true;
	return false;
}

template<typename someType> bool polynomeModulo :: operator<=				(const someType &rightHandSide) const {
	if (att_value.size() == 1)
		return att_value[0] <= rightHandSide;
	if (att_value.size())
		return false;
	return true;
}

template<typename someType> bool operator<=									(const someType &leftHandSide,	const polynomeModulo &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return leftHandSide <= rightHandSide[0];
	if (rightHandSide.att_value.size())
		return true;
	return false;
}

#if _cplusplus >= 201907L
template<typename someType> auto polynomeModulo :: operator<=>				(const someType &rightHandSide)	const {
	if (att_value.size() == 1)
		return att_value[0] <=> rightHandSide;
	if (att_value.size())
		return std :: strong_ordering :: greater;
	return std :: strong_ordering :: less;
}

template<typename someType> auto operator<=>								(const someType &leftHandSide,	const polynomeModulo &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return leftHandSide <=> rightHandSide[0];
	if (rightHandSide.att_value.size())
		return std :: strong_ordering :: less;
	return std :: strong_ordering :: greater;
}
#endif /* _cplusplus >= 201907L */

template<typename someType> polynomeModulo :: polynomeModulo 				(const someType &rightHandSide) {
	att_value.clear();
	att_value.push_back(rightHandSide);
}


#endif /*__KICV_ELLD__FLAG_6*/