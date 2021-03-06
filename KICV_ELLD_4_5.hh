#ifndef __KICV_ELLD__FLAG_4_5
#define __KICV_ELLD__FLAG_4_5

#include "KICV_ELLD_1_2.hh"
#include <iostream>
#include <vector>

/*
HAL HAL HAL HAL HAL HAL HAL
HAL   QUESTION  4 - 5   HAL
HAL HAL HAL HAL HAL HAL HAL
*/

class polynomeOfInts {
/* Attributes */
	std :: vector <justAnInt> att_value;				/* The real values. We are using vectors */
/* Methods */
public:
	unsigned int size											() const {return att_value.size();}
	static polynomeOfInts extendedEuclidean						(polynomeOfInts a, polynomeOfInts b, polynomeOfInts *u0, polynomeOfInts *v0, bool wantATrace = true);
/* Operator [] */
	justAnInt &operator[]										(unsigned int position);
	justAnInt  operator[]										(unsigned int position) 				const;
/* Operator + */
	polynomeOfInts &operator+= 									(const polynomeOfInts &rightHandSide);
	polynomeOfInts &operator+= 									(const std :: vector <justAnInt> &rightHandSide);
	template<typename someType> polynomeOfInts &operator+= 		(const someType &rightHandSide);
	friend polynomeOfInts operator+ 							(const polynomeOfInts &leftHandSide,	const polynomeOfInts &rightHandSide);
	template<typename someType> polynomeOfInts operator+ 		(const someType &rightHandSide) 		const;
	template<typename someType> friend polynomeOfInts operator+ (const someType &leftHandSide, 			const polynomeOfInts &rightHandSide);
/* Operator - */
	polynomeOfInts &operator-= 									(const polynomeOfInts &rightHandSide);
	polynomeOfInts &operator-= 									(const std :: vector <justAnInt> &rightHandSide);
	template<typename someType> polynomeOfInts &operator-= 		(const someType &rightHandSide);
	friend polynomeOfInts operator- 							(const polynomeOfInts &leftHandSide,	const polynomeOfInts &rightHandSide);
	template<typename someType> polynomeOfInts operator- 		(const someType &rightHandSide) 		const;
	template<typename someType> friend polynomeOfInts operator- (const someType &leftHandSide, 			const polynomeOfInts &rightHandSide);
	polynomeOfInts operator- 									()										const;
/* Operator * */
	polynomeOfInts &operator*= 									(const polynomeOfInts &rightHandSide);
	polynomeOfInts &operator*= 									(const std :: vector <justAnInt> &rightHandSide);
	template<typename someType> polynomeOfInts &operator*= 		(const someType &rightHandSide);
	friend polynomeOfInts operator* 							(const polynomeOfInts &leftHandSide,	const polynomeOfInts &rightHandSide);
	template<typename someType> polynomeOfInts operator* 		(const someType &rightHandSide) 		const;
	template<typename someType> friend polynomeOfInts operator* (const someType &leftHandSide, 			const polynomeOfInts &rightHandSide);
/* Operator / */
	polynomeOfInts &operator/= 									(const polynomeOfInts &rightHandSide);
	polynomeOfInts &operator/= 									(const std :: vector <justAnInt> &rightHandSide);
	template<typename someType> polynomeOfInts &operator/= 		(const someType &rightHandSide);
	friend polynomeOfInts operator/ 							(const polynomeOfInts &leftHandSide,	const polynomeOfInts &rightHandSide);
	template<typename someType> polynomeOfInts operator/ 		(const someType &rightHandSide) 		const;
	template<typename someType> friend polynomeOfInts operator/ (const someType &leftHandSide, 			const polynomeOfInts &rightHandSide);
/* Operator % */
	polynomeOfInts &operator%= 									(const polynomeOfInts &rightHandSide);
	polynomeOfInts &operator%= 									(const std :: vector <justAnInt> &rightHandSide);
	template<typename someType> polynomeOfInts &operator%= 		(const someType &rightHandSide);
	friend polynomeOfInts operator% 							(const polynomeOfInts &leftHandSide,	const polynomeOfInts &rightHandSide);
	template<typename someType> polynomeOfInts operator% 		(const someType &rightHandSide) 		const;
	template<typename someType> friend polynomeOfInts operator% (const someType &leftHandSide, 			const polynomeOfInts &rightHandSide);
/* Operator = */
	template<typename someType> polynomeOfInts &operator=		(const someType &rightHandSide);
	polynomeOfInts &operator=									(const polynomeOfInts &rightHandSide);
/* Operator == */
	bool operator==												(const polynomeOfInts &rightHandSide)	const;
	bool operator==			 									(const std :: vector <justAnInt> &rightHandSide)								const;
	template<typename someType> bool operator==					(const std :: initializer_list <someType> &rightHandSide);
	template<typename someType> bool operator==					(const someType &rightHandSide) 		const;
	template<typename someType> friend bool operator==			(const someType &leftHandSide,			const polynomeOfInts &rightHandSide);
	bool operator!=												(const polynomeOfInts &rightHandSide) 	const;
	bool operator!=			 									(const std :: vector <justAnInt> &rightHandSide)								const;
	template<typename someType> bool operator!=					(const std :: initializer_list <someType> &rightHandSide);
	template<typename someType> bool operator!=					(const someType &rightHandSide) 		const;
	template<typename someType> friend bool operator!=			(const someType &leftHandSide,			const polynomeOfInts &rightHandSide);
/* Conversion */
	explicit operator bool										() 										const;
/* Operator > */
	bool operator>												(const polynomeOfInts &rightHandSide)	const;
	bool operator>			 									(const std :: vector <justAnInt> &rightHandSide)								const;
	template<typename someType> bool operator>					(const std :: initializer_list <someType> &rightHandSide);
	template<typename someType> bool operator>					(const someType &rightHandSide)			const;
	template<typename someType> friend bool operator>			(const someType &leftHandSide,			const polynomeOfInts &rightHandSide);
	bool operator>=												(const polynomeOfInts &rightHandSide) 	const;
	bool operator>=			 									(const std :: vector <justAnInt> &rightHandSide)								const;
	template<typename someType> bool operator>=					(const std :: initializer_list <someType> &rightHandSide);
	template<typename someType> bool operator>=					(const someType &rightHandSide)		 	const;
	template<typename someType> friend bool operator>=			(const someType &leftHandSide,			const polynomeOfInts &rightHandSide);
/* Operator < */
	bool operator<												(const polynomeOfInts &rightHandSide) 	const;
	bool operator<			 									(const std :: vector <justAnInt> &rightHandSide)								const;
	template<typename someType> bool operator<					(const std :: initializer_list <someType> &rightHandSide);
	template<typename someType> bool operator<					(const someType &rightHandSide)	 		const;
	template<typename someType> friend bool operator<			(const someType &leftHandSide,			const polynomeOfInts &rightHandSide);
	bool operator<=												(const polynomeOfInts &rightHandSide) 	const;
	bool operator<=			 									(const std :: vector <justAnInt> &rightHandSide)								const;
	template<typename someType> bool operator<=					(const std :: initializer_list <someType> &rightHandSide);
	template<typename someType> bool operator<=					(const someType &rightHandSide) 		const;
	template<typename someType> friend bool operator<=			(const someType &leftHandSide,			const polynomeOfInts &rightHandSide);
#if _cplusplus >= 201907L
/* Three way comparison, the 'spaceship operator' */
	auto operator<=>											(const polynomeOfInts &rightHandSide)	const;
	auto operator<=>											(const std :: vector <justAnInt> &rightHandSide)								const;
	template<typename someType> auto operator<=>					(const std :: initializer_list <someType> &rightHandSide);
	template<typename someType> auto operator<=>				(const someType &rightHandSide)			const;
	template<typename someType> friend auto operator<=>			(const someType &leftHandSide,			const polynomeOfInts &rightHandSide);
#endif /* _cplusplus >= 201907L */
/* Operator in/de crement */
	/*
	polynomeOfInts &operator++									();
	polynomeOfInts &operator--									();
	polynomeOfInts operator++									(int);
	polynomeOfInts operator--									(int);
	*/
/* Operator << */
	friend std :: ostream &operator<<							(std :: ostream &out,					const polynomeOfInts &rightHandSide);
/* Constructors */
	template<typename someType> polynomeOfInts					(const someType &rightHandSide);
	template<typename someType> polynomeOfInts					(const std :: initializer_list <someType> &rightHandSide);
	polynomeOfInts												(const polynomeOfInts &rightHandSide);
	polynomeOfInts												(const std :: vector <justAnInt> &rightHandSide);
	polynomeOfInts												();
};

template<typename someType> polynomeOfInts &polynomeOfInts :: operator+= 	(const someType &rightHandSide) {
	if (att_value.size()) {
		att_value[0] += rightHandSide;
		return *this;
	}
	att_value.push_back(rightHandSide);
	return *this;
}

template<typename someType> polynomeOfInts polynomeOfInts :: operator+ 		(const someType &rightHandSide) const {
	polynomeOfInts localCopy(*this);
	return localCopy += rightHandSide;
}

template<typename someType> polynomeOfInts operator+ 						(const someType &leftHandSide, const polynomeOfInts rightHandSide) {
	polynomeOfInts localCopy(rightHandSide);
	return localCopy += leftHandSide;
}


template<typename someType> polynomeOfInts &polynomeOfInts :: operator-= 	(const someType &rightHandSide) {
	if (rightHandSide >= 0) {
		if (att_value.size()) {
			att_value[0] -= rightHandSide;
			return *this;
		}
		att_value.push_back(rightHandSide);
	}
	return *this += (- rightHandSide); /* Substracting negative <=> adding positive */
}

template<typename someType> polynomeOfInts polynomeOfInts :: operator- 		(const someType &rightHandSide) const {
	polynomeOfInts localCopy(*this);
	return localCopy -= rightHandSide;
}

template<typename someType> polynomeOfInts operator-				 		(const someType &leftHandSide, 	const polynomeOfInts rightHandSide) {
	polynomeOfInts localCopy(leftHandSide);
	return localCopy -= rightHandSide;
}


template<typename someType> polynomeOfInts &polynomeOfInts :: operator*= 	(const someType &rightHandSide) {
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		att_value[i] *= rightHandSide;
	return *this;
}

template<typename someType> polynomeOfInts polynomeOfInts :: operator* 		(const someType &rightHandSide) const {
	polynomeOfInts localCopy(*this);
	return localCopy *= rightHandSide;
}

template<typename someType> polynomeOfInts operator* 						(const someType &leftHandSide, 	const polynomeOfInts &rightHandSide) {
	polynomeOfInts localCopy(rightHandSide);
	return localCopy *= leftHandSide;
}


template<typename someType> polynomeOfInts &polynomeOfInts :: operator/= 	(const someType &rightHandSide) {
	if (att_value.size() < 1) {
		att_value.clear();	/* The answer is 0 */
		att_value.push_back(0);
		return *this;
	}
	polynomeOfInts localCopy(rightHandSide);
	return *this /= localCopy;
}

template<typename someType> polynomeOfInts polynomeOfInts :: operator/ 		(const someType &rightHandSide) const {
	polynomeOfInts localCopy(*this);
	return localCopy /= rightHandSide;
}

template<typename someType> polynomeOfInts operator/ 						(const someType &leftHandSide, 	const polynomeOfInts &rightHandSide) {
	polynomeOfInts localCopy(leftHandSide);
	return localCopy /= rightHandSide;
}


template<typename someType> polynomeOfInts &polynomeOfInts :: operator%= 	(const someType &rightHandSide) {
	return *this -= rightHandSide * (*this / rightHandSide);
}

template<typename someType> polynomeOfInts polynomeOfInts :: operator% 		(const someType &rightHandSide) const {
	polynomeOfInts localCopy(*this);
	return localCopy /= rightHandSide;
}

template<typename someType> polynomeOfInts operator% 						(const someType &leftHandSide, 	const polynomeOfInts &rightHandSide) {
	polynomeOfInts localCopy(rightHandSide);
	return localCopy /= leftHandSide;
}


template<typename someType> polynomeOfInts &polynomeOfInts :: operator=		(const someType &rightHandSide) {
	att_value.clear();
	att_value.push_back(rightHandSide);
	return *this;
}

template<typename someType> bool polynomeOfInts :: operator==				(const std :: initializer_list <someType> &rightHandSide) {
	unsigned int minimumLength(att_value.size() < rightHandSide.size() ? att_value.size() : rightHandSide.size());
	for (unsigned int i = 0 ; i < minimumLength ; ++i)
		if (att_value[i] != rightHandSide[i])
			return false;
	unsigned int maximumLength(att_value.size() > rightHandSide.size() ? att_value.size() : rightHandSide.size());
	if (maximumLength != minimumLength) {
		if (maximumLength == att_value.size()) {
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (att_value[i] != 0)
					return false;
		}
		else 
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (rightHandSide[i] != 0)
					return false;
	}
	return true;
}

template<typename someType> bool polynomeOfInts :: operator==				(const someType &rightHandSide) const {
	if (att_value.size() == 1)
		return att_value[0] == rightHandSide;
	return false;
}

template<typename someType> bool operator==									(const someType &leftHandSide,	const polynomeOfInts &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return rightHandSide[0] == leftHandSide;
	return false;
}

template<typename someType> bool polynomeOfInts :: operator!=				(const std :: initializer_list <someType> &rightHandSide) {
	unsigned int minimumLength(att_value.size() < rightHandSide.size() ? att_value.size() : rightHandSide.size());
	for (unsigned int i = 0 ; i < minimumLength ; ++i)
		if (att_value[i] != rightHandSide[i])
			return true;
	unsigned int maximumLength(att_value.size() > rightHandSide.size() ? att_value.size() : rightHandSide.size());
	if (maximumLength != minimumLength) {
		if (maximumLength == att_value.size()) {
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (att_value[i] != 0)
					return true;
		}
		else 
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (rightHandSide[i] != 0)
					return true;
	}
	return false;
}

template<typename someType> bool polynomeOfInts :: operator!=				(const someType &rightHandSide) const {
	if (att_value.size() == 1)
		return att_value[0] != rightHandSide;
	return true;
}

template<typename someType> bool operator!=									(const someType &leftHandSide,	const polynomeOfInts &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return rightHandSide[0] != leftHandSide;
	return true;
}

template<typename someType> bool polynomeOfInts :: operator>				(const std :: initializer_list <someType> &rightHandSide) {
	unsigned int minimumLength(att_value.size() < rightHandSide.size() ? att_value.size() : rightHandSide.size());
	unsigned int maximumLength(att_value.size() > rightHandSide.size() ? att_value.size() : rightHandSide.size());
	if (maximumLength != minimumLength) {
		if (maximumLength == att_value.size()) {
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (att_value[i] != 0)
					return true;
		}
		else 
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (rightHandSide[i] != 0)
					return false;
	}
	for (unsigned int i = minimumLength ; i > 0 ;) {
		--i;
		if (att_value[i] > rightHandSide[i])
			return true;
	}
	return false;
}

template<typename someType> bool polynomeOfInts :: operator>				(const someType &rightHandSide)	const {
	if (att_value.size() > 1)
		return true;
	if (att_value.size())
		return att_value[0] > rightHandSide;
	return false;
}

template<typename someType> bool operator>									(const someType &leftHandSide,	const polynomeOfInts &rightHandSide) {
	if (!(rightHandSide.att_value.size()))
		return true;
	if (rightHandSide.att_value.size() > 1)
		return false;
	return leftHandSide > rightHandSide[0];
}

template<typename someType> bool polynomeOfInts :: operator>=				(const std :: initializer_list <someType> &rightHandSide) {
	unsigned int minimumLength(att_value.size() < rightHandSide.size() ? att_value.size() : rightHandSide.size());
	unsigned int maximumLength(att_value.size() > rightHandSide.size() ? att_value.size() : rightHandSide.size());
	if (maximumLength != minimumLength) {
		if (maximumLength == att_value.size()) {
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (att_value[i] != 0)
					return true;
		}
		else 
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (rightHandSide[i] != 0)
					return false;
	}
	for (unsigned int i = minimumLength ; i > 0 ;) {
		--i;
		if (att_value[i] > rightHandSide[i])
			return true;
	}
	return true;
}

template<typename someType> bool polynomeOfInts :: operator>=				(const someType &rightHandSide)	const {
	if (att_value.size() == 1)
		return att_value[0] >= rightHandSide;
	if (att_value.size())
		return true;
	return false;
}

template<typename someType> bool operator>=									(const someType &leftHandSide,	const polynomeOfInts &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return leftHandSide >= rightHandSide[0];
	if (rightHandSide.att_value.size())
		return false;
	return true;
}

template<typename someType> bool polynomeOfInts :: operator<				(const std :: initializer_list <someType> &rightHandSide) {
	unsigned int minimumLength(att_value.size() < rightHandSide.size() ? att_value.size() : rightHandSide.size());
	unsigned int maximumLength(att_value.size() > rightHandSide.size() ? att_value.size() : rightHandSide.size());
	if (maximumLength != minimumLength) {
		if (maximumLength == att_value.size()) {
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (att_value[i] != 0)
					return false;
		}
		else 
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (rightHandSide[i] != 0)
					return true;
	}
	for (unsigned int i = minimumLength ; i > 0 ;) {
		--i;
		if (att_value[i] < rightHandSide[i])
			return true;
	}
	return false;
}

template<typename someType> bool polynomeOfInts :: operator<				(const someType &rightHandSide)	const {
	if (att_value.size() == 1)
		return att_value[0] < rightHandSide;
	if (att_value.size())
		return false;
	return true;
}

template<typename someType> bool operator<									(const someType &leftHandSide,	const polynomeOfInts &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return leftHandSide < rightHandSide[0];
	if (rightHandSide.att_value.size())
		return true;
	return false;
}

template<typename someType> bool polynomeOfInts :: operator<=				(const std :: initializer_list <someType> &rightHandSide) {
	unsigned int minimumLength(att_value.size() < rightHandSide.size() ? att_value.size() : rightHandSide.size());
	unsigned int maximumLength(att_value.size() > rightHandSide.size() ? att_value.size() : rightHandSide.size());
	if (maximumLength != minimumLength) {
		if (maximumLength == att_value.size()) {
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (att_value[i] != 0)
					return false;
		}
		else 
			for (unsigned int i = minimumLength ; i < maximumLength ; ++i)
				if (rightHandSide[i] != 0)
					return true;
	}
	for (unsigned int i = minimumLength ; i > 0 ;) {
		--i;
		if (att_value[i] < rightHandSide[i])
			return true;
	}
	return true;
}

template<typename someType> bool polynomeOfInts :: operator<=				(const someType &rightHandSide) const {
	if (att_value.size() == 1)
		return att_value[0] <= rightHandSide;
	if (att_value.size())
		return false;
	return true;
}

template<typename someType> bool operator<=									(const someType &leftHandSide,	const polynomeOfInts &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return leftHandSide <= rightHandSide[0];
	if (rightHandSide.att_value.size())
		return true;
	return false;
}

#if _cplusplus >= 201907L
template<typename someType> auto polynomeOfInts :: operator<=>				(const std :: initializer_list <someType> &rightHandSide) {
	return att_value <=> rightHandSide;
}

template<typename someType> auto polynomeOfInts :: operator<=>				(const someType &rightHandSide)	const {
	if (att_value.size() == 1)
		return att_value[0] <=> rightHandSide;
	if (att_value.size())
		return std :: strong_ordering :: greater;
	return std :: strong_ordering :: less;
}

template<typename someType> auto operator<=>								(const someType &leftHandSide,	const polynomeOfInts &rightHandSide) {
	if (rightHandSide.att_value.size() == 1)
		return leftHandSide <=> rightHandSide[0];
	if (rightHandSide.att_value.size())
		return std :: strong_ordering :: less;
	return std :: strong_ordering :: greater;
}
#endif /* _cplusplus >= 201907L */

template<typename someType> polynomeOfInts :: polynomeOfInts 				(const someType &rightHandSide) {
	att_value.push_back(rightHandSide);
}

template<typename someType> polynomeOfInts :: polynomeOfInts				(const std :: initializer_list <someType> &rightHandSide) {
	for (auto it = rightHandSide.begin() ; it != rightHandSide.end() ; ++it)
		att_value.push_back(*it);
}


#endif /*__KICV_ELLD__FLAG_6*/