#include "KICV_ELLD_4_5.hh"

/*
HAL HAL HAL HAL HAL HAL HAL
HAL   QUESTION  4 - 5   HAL
HAL HAL HAL HAL HAL HAL HAL
*/

justAnInt &polynomeOfInts :: operator[]							(unsigned int position) {
	if (position < att_value.size())
		return att_value[position];
	while (att_value.size() <= position)
		att_value.push_back(0);
	return att_value[position];			/* Basically we can now do a[6] = 2, when a = x^2 + 2 */
}

justAnInt  polynomeOfInts :: operator[]							(unsigned int position)								const {
	if (position < att_value.size())
		return att_value[position];
	return 0;
}

polynomeOfInts &polynomeOfInts :: operator+= 	(const polynomeOfInts &rightHandSide) {
	unsigned int maximumValue = att_value.size() < rightHandSide.att_value.size() ? att_value.size() : rightHandSide.att_value.size();	/* Remember which is smallest */
	for (unsigned int i = att_value.size() ; i < rightHandSide.att_value.size() ; ++i) /* This only proccs if rightHandSide has higher exponent coefficients */
		att_value.push_back(rightHandSide[i]);

	for (unsigned int i = 0 ; i < maximumValue ; ++i)	/* We deal with either the left part of rightHandSide, or the total of it */
		att_value[i] += rightHandSide[i];
	return *this;
}

polynomeOfInts &polynomeOfInts :: operator+= 	(const std :: vector <justAnInt> &rightHandSide) {
	unsigned int maximumValue = att_value.size() < rightHandSide.size() ? att_value.size() : rightHandSide.size();	/* Remember which is smallest */
	for (unsigned int i = att_value.size() ; i < rightHandSide.size() ; ++i) /* This only proccs if rightHandSide has higher exponent coefficients */
		att_value.push_back(rightHandSide[i]);

	for (unsigned int i = 0 ; i < maximumValue ; ++i)	/* We deal with either the left part of rightHandSide, or the total of it */
		att_value[i] += rightHandSide[i];
	return *this;
}

polynomeOfInts operator+ 						(const polynomeOfInts &leftHandSign, 				const polynomeOfInts &rightHandSide) {
	polynomeOfInts localValue(leftHandSign);
	return localValue += rightHandSide;
}

polynomeOfInts &polynomeOfInts :: operator-= 	(const polynomeOfInts &rightHandSide) {
	unsigned int maximumValue = att_value.size() < rightHandSide.att_value.size() ? att_value.size() : rightHandSide.att_value.size();	/* Remember which is smallest */
	for (unsigned int i = att_value.size() ; i < rightHandSide.att_value.size() ; ++i) /* This only proccs if rightHandSide has higher exponent coefficients */
		att_value.push_back(-rightHandSide[i]);

	for (unsigned int i = 0 ; i < maximumValue ; ++i)	/* We deal with either the left part of rightHandSide, or the total of it */
		att_value[i] -= rightHandSide[i];
	return *this;
}

polynomeOfInts &polynomeOfInts :: operator-= 	(const std :: vector <justAnInt> &rightHandSide) {
	unsigned int maximumValue = att_value.size() < rightHandSide.size() ? att_value.size() : rightHandSide.size();	/* Remember which is smallest */
	for (unsigned int i = att_value.size() ; i < rightHandSide.size() ; ++i) /* This only proccs if rightHandSide has higher exponent coefficients */
		att_value.push_back(-rightHandSide[i]);

	for (unsigned int i = 0 ; i < maximumValue ; ++i)	/* We deal with either the left part of rightHandSide, or the total of it */
		att_value[i] -= rightHandSide[i];
	return *this;
}

polynomeOfInts operator- 						(const polynomeOfInts &leftHandSign, 				const polynomeOfInts &rightHandSide) {
	polynomeOfInts localValue(leftHandSign);
	return localValue -= rightHandSide;
}

polynomeOfInts polynomeOfInts :: operator-		() const {
	polynomeOfInts localValue(*this);
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		localValue[i] = -att_value[i];
	return localValue;
}

polynomeOfInts &polynomeOfInts :: operator*=	(const polynomeOfInts &rightHandSide) {
	unsigned int maximumExponent(att_value.size() + rightHandSide.att_value.size());
	std :: vector <justAnInt> localCopy(att_value); /* We will make a copy, just because it is easier */
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		att_value[i] = 0;							/* Reset our vector. Might be faster to make the copy the right size with full 0s and copy after */
	while (att_value.size() < maximumExponent)
		att_value.push_back(0);						/* Get the right size in our this */
	if (localCopy.size() < rightHandSide.att_value.size()) {
		for (unsigned int i = 0 ; i < maximumExponent ; ++i)
			for (unsigned int j = localCopy.size() ; j > 0 ;) {
				--j;
				att_value[i] += localCopy[j] * rightHandSide.att_value[i - j]; /* Careful, we move j HERE, in the first */
			}
		return *this;
	}
	for (unsigned int i = 0 ; i < maximumExponent ; ++i)
		for (unsigned int j = rightHandSide.att_value.size() ; j > 0 ;) {
			--j;
			att_value[i] += localCopy[i - j] * rightHandSide.att_value[j];
		}
	return *this;
}

polynomeOfInts &polynomeOfInts :: operator*=	(const std :: vector <justAnInt> &rightHandSide) {
	unsigned int maximumExponent(att_value.size() + rightHandSide.size());
	std :: vector <justAnInt> localCopy(att_value); /* We will make a copy, just because it is easier */
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		att_value[i] = 0;							/* Reset our vector. Might be faster to make the copy the right size with full 0s and copy after */
	while (att_value.size() < maximumExponent)
		att_value.push_back(0);						/* Get the right size in our this */
	if (localCopy.size() < rightHandSide.size()) {
		for (unsigned int i = 0 ; i < maximumExponent ; ++i)
			for (unsigned int j = localCopy.size() ; j > 0 ;) {
				--j;
				att_value[i] += localCopy[j] * rightHandSide[i - j]; /* Careful, we move j HERE, in the first */
			}
		return *this;
	}
	for (unsigned int i = 0 ; i < maximumExponent ; ++i)
		for (unsigned int j = rightHandSide.size() ; j > 0 ;) {
			--j;
			att_value[i] += localCopy[i - j] * rightHandSide[j];
		}
	return *this;
}

polynomeOfInts operator* 						(const polynomeOfInts &leftHandSign, 				const polynomeOfInts &rightHandSide) {
	polynomeOfInts localValue(leftHandSign);
	return localValue *= rightHandSide;
}

polynomeOfInts &polynomeOfInts :: operator/=	(const polynomeOfInts &rightHandSide) {
	if (att_value.size() < rightHandSide.att_value.size()) {
		att_value.clear();	/* The answer is 0 */
		att_value.push_back(0);
		return *this;
	}
	polynomeOfInts localCopy(*this);
	att_value.clear();
	for (unsigned int i = 0 ; i <= localCopy.att_value.size() - rightHandSide.att_value.size() ; ++i) /* It basically is the size of the size difference */
		att_value.push_back(0);
	unsigned int currentExponent(att_value.size() - 1); 	/* To remember where we're at. It IS non zero, so non UB */
	while (localCopy) {
		polynomeOfInts temporary;
		for (unsigned int i = 0 ; i < currentExponent ; ++i)
			temporary.att_value.push_back(0);
		temporary.att_value.back() = localCopy.att_value.back() / rightHandSide.att_value.back();
		att_value[currentExponent] = temporary.att_value.back();
		localCopy -= (temporary *= rightHandSide);
		--currentExponent;
		localCopy.att_value.pop_back(); 	/* We have made sure last element was zero */
	}
	while (!(att_value.back()))
		att_value.pop_back();
	return *this;
}

polynomeOfInts &polynomeOfInts :: operator/=	(const std :: vector <justAnInt> &rightHandSide) {
	if (att_value.size() < rightHandSide.size()) {
		att_value.clear();	/* The answer is 0 */
		att_value.push_back(0);
		return *this;
	}
	polynomeOfInts localCopy(*this);
	att_value.clear();
	for (unsigned int i = 0 ; i <= localCopy.att_value.size() - rightHandSide.size() ; ++i) /* It basically is the size of the size difference */
		att_value.push_back(0);
	unsigned int currentExponent(att_value.size() - 1); 	/* To remember where we're at. It IS non zero, so non UB */
	while (localCopy) {
		polynomeOfInts temporary;
		for (unsigned int i = 0 ; i < currentExponent ; ++i)
			temporary.att_value.push_back(0);
		temporary.att_value.back() = localCopy.att_value.back() / rightHandSide.back();
		att_value[currentExponent] = temporary.att_value.back();
		localCopy -= (temporary *= rightHandSide);
		--currentExponent;
		localCopy.att_value.pop_back(); 	/* We have made sure last element was zero */
	}
	while (!(att_value.back()))
		att_value.pop_back();
	return *this;
}

polynomeOfInts operator/ 						(const polynomeOfInts &leftHandSign, 				const polynomeOfInts &rightHandSide) {
	polynomeOfInts localValue(leftHandSign);
	return localValue /= rightHandSide;
}

polynomeOfInts &polynomeOfInts :: operator%=	(const polynomeOfInts &rightHandSide) {
	return *this *= rightHandSide * (*this / rightHandSide);
}

polynomeOfInts &polynomeOfInts :: operator%=	(const std :: vector <justAnInt> &rightHandSide) {
	return *this *= rightHandSide * (*this / rightHandSide);
}

polynomeOfInts operator% 						(const polynomeOfInts &leftHandSign, 				const polynomeOfInts &rightHandSide) {
	return rightHandSide;
}

polynomeOfInts& polynomeOfInts :: operator= 	(const polynomeOfInts &rightHandSide) {
	att_value = rightHandSide.att_value;
	return *this;
}

polynomeOfInts& polynomeOfInts :: operator= 	(const std :: vector <justAnInt> &rightHandSide) {
	att_value = rightHandSide;
	return *this;
}

bool polynomeOfInts :: operator==				(const polynomeOfInts &rightHandSide) 				const {
	if (att_value.size() !=rightHandSide.att_value.size())
		return false;
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		if (att_value[i] != rightHandSide[i])
			return false;
	return true;
}

bool polynomeOfInts :: operator==				(const std :: vector <justAnInt> &rightHandSide) 	const {
	if (att_value.size() !=rightHandSide.size())
		return false;
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		if (att_value[i] != rightHandSide[i])
			return false;
	return true;
}

bool polynomeOfInts :: operator!=				(const polynomeOfInts &rightHandSide) 				const {
	if (att_value.size() !=rightHandSide.att_value.size())
		return true;
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		if (att_value[i] != rightHandSide[i])
			return true;
	return false;
}

bool polynomeOfInts :: operator!=				(const std :: vector <justAnInt> &rightHandSide) 	const {
	if (att_value.size() !=rightHandSide.size())
		return true;
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		if (att_value[i] != rightHandSide[i])
			return true;
	return false;
}

polynomeOfInts :: operator bool					() const {
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		if (att_value[i])
			return true;
	return false;
}

bool polynomeOfInts :: operator>				(const polynomeOfInts &rightHandSide) 				const {
	if (att_value.size() > rightHandSide.att_value.size())
		return true;
	if (att_value.size() < rightHandSide.att_value.size())
		return false;
	for (unsigned int i = att_value.size() ; i > 0 ;) {
		--i;
		if (att_value[i] > rightHandSide[i])
			return true;
		if (att_value[i] < rightHandSide[i])
			return false;
	}
	return false;
}

bool polynomeOfInts :: operator>				(const std :: vector <justAnInt> &rightHandSide) 	const {
	if (att_value.size() > rightHandSide.size())
		return true;
	if (att_value.size() < rightHandSide.size())
		return false;
	for (unsigned int i = att_value.size() ; i > 0 ;) {
		--i;
		if (att_value[i] > rightHandSide[i])
			return true;
		if (att_value[i] < rightHandSide[i])
			return false;
	}
	return false;
}

bool polynomeOfInts :: operator>=				(const polynomeOfInts &rightHandSide) 				const {
	if (att_value.size() > rightHandSide.att_value.size())
		return true;
	if (att_value.size() < rightHandSide.att_value.size())
		return false;
	for (unsigned int i = att_value.size() ; i > 0 ;) {
		--i;
		if (att_value[i] > rightHandSide[i])
			return true;
		if (att_value[i] < rightHandSide[i])
			return false;
	}
	return true;
}

bool polynomeOfInts :: operator>=				(const std :: vector <justAnInt> &rightHandSide) 	const {
	if (att_value.size() > rightHandSide.size())
		return true;
	if (att_value.size() < rightHandSide.size())
		return false;
	for (unsigned int i = att_value.size() ; i > 0 ;) {
		--i;
		if (att_value[i] > rightHandSide[i])
			return true;
		if (att_value[i] < rightHandSide[i])
			return false;
	}
	return true;
}

bool polynomeOfInts :: operator<				(const polynomeOfInts &rightHandSide) 				const {
	if (att_value.size() > rightHandSide.att_value.size())
		return false;
	if (att_value.size() < rightHandSide.att_value.size())
		return true;
	for (unsigned int i = att_value.size() ; i > 0 ;) {
		--i;
		if (att_value[i] > rightHandSide[i])
			return false;
		if (att_value[i] < rightHandSide[i])
			return true;
	}
	return false;
}

bool polynomeOfInts :: operator<				(const std :: vector <justAnInt> &rightHandSide) 	const {
	if (att_value.size() > rightHandSide.size())
		return false;
	if (att_value.size() < rightHandSide.size())
		return true;
	for (unsigned int i = att_value.size() ; i > 0 ;) {
		--i;
		if (att_value[i] > rightHandSide[i])
			return false;
		if (att_value[i] < rightHandSide[i])
			return true;
	}
	return false;
}

bool polynomeOfInts :: operator<=				(const polynomeOfInts &rightHandSide) 				const {
	if (att_value.size() > rightHandSide.att_value.size())
		return false;
	if (att_value.size() < rightHandSide.att_value.size())
		return true;
	for (unsigned int i = att_value.size() ; i > 0 ;) {
		--i;
		if (att_value[i] > rightHandSide[i])
			return false;
		if (att_value[i] < rightHandSide[i])
			return true;
	}
	return true;
}

bool polynomeOfInts :: operator<=				(const std :: vector <justAnInt> &rightHandSide) 	const {
	if (att_value.size() > rightHandSide.size())
		return false;
	if (att_value.size() < rightHandSide.size())
		return true;
	for (unsigned int i = att_value.size() ; i > 0 ;) {
		--i;
		if (att_value[i] > rightHandSide[i])
			return false;
		if (att_value[i] < rightHandSide[i])
			return true;
	}
	return true;
}

#if _cplusplus >= 201907L
auto polynomeOfInts :: operator<=>				(const polynomeOfInts &rightHandSide)				const {
	return att_value <=> rightHandSide.att_value; /* It should be implemented correctly in the first place, so we can do this */
}

auto polynomeOfInts :: operator<=>				(const std :: vector <justAnInt> &rightHandSide)	const {
	return att_value <=> rightHandSide; /* It should be implemented correctly in the first place, so we can do this */
}
#endif /* _cplusplus >= 201907L */
/*
polynomeOfInts &polynomeOfInts :: operator++	() {
	++att_value;
	return *this;
}

polynomeOfInts &polynomeOfInts :: operator--	() {
	--att_value;
	return *this;
}

polynomeOfInts polynomeOfInts :: operator++		(int) {
	polynomeOfInts localValue(*this);
	++att_value;
	return localValue;
}

polynomeOfInts polynomeOfInts :: operator--		(int) {
	polynomeOfInts localValue(*this);
	--att_value;
	return localValue;
}
*/
std :: ostream &operator<<						(std :: ostream &out,				const polynomeOfInts &rightHandSide) {
	if (rightHandSide.att_value.size())
		out << rightHandSide[0];
	if (rightHandSide.att_value.size() > 1)
		out << " + " << rightHandSide[1] << "x";
	for (unsigned int i = 2 ; i < rightHandSide.att_value.size() ; ++i)
		out << " + " << rightHandSide[i] << "x ^ " << i;
	return out;
}


polynomeOfInts :: polynomeOfInts				(const polynomeOfInts &rightHandSide)			: att_value(rightHandSide.att_value) {}

polynomeOfInts :: polynomeOfInts				(const std :: vector <justAnInt> &rightHandSide): att_value(rightHandSide) {}

polynomeOfInts :: polynomeOfInts				()												: att_value(0) {}


polynomeOfInts polynomeOfInts :: extendedEuclidean(polynomeOfInts a, polynomeOfInts b, polynomeOfInts *u0, polynomeOfInts *v0, bool wantATrace) {
	bool needToClearU(false), needToClearV(false);
	if (wantATrace) {
		std :: cout.setf(std :: ios :: left); /* Text left justified */
		std :: cout.width(20);	std :: cout << "a";
		std :: cout.width(20);	std :: cout << "b";
		std :: cout.width(20);	std :: cout << "u";
		std :: cout.width(20);	std :: cout << "v" << std :: endl;
	}
	if (!u0) {
		needToClearU = true;
		u0 = new polynomeOfInts;
	}
	if (!v0) {
		needToClearV = true;
		v0 = new polynomeOfInts;
	}
	if (b > a) {
		{
			polynomeOfInts *tmpSwap(u0);
			u0 = v0;
			v0 = tmpSwap;
		}
		{
			polynomeOfInts tmpSwap(a);
			a = b;
			b = tmpSwap;
		}
	}
	*u0 = 1;
	*v0 = 0;
	if (wantATrace) {
		std :: cout.width(13);	std :: cout << a;
		std :: cout.width(13);	std :: cout << b;
		std :: cout.width(13);	std :: cout << *u0;
		std :: cout.width(13);	std :: cout << *v0 << std :: endl;			
	}
	polynomeOfInts u1 = 0;
	polynomeOfInts v1 = 1;
	polynomeOfInts tmp, quotient;
	while (b) {
		quotient = a / b;
		tmp = b; b = a - quotient * b; a = tmp;
		tmp = u1; u1 = *u0 - quotient * u1; *u0 = tmp;
		tmp = v1; v1 = *v0 - quotient * v1; *v0 = tmp;
		if (wantATrace) {
			std :: cout.width(20);	std :: cout << a;
			std :: cout.width(20);	std :: cout << b;
			std :: cout.width(20);	std :: cout << *u0;
			std :: cout.width(20);	std :: cout << *v0 << std :: endl;			
		}
	}
	if (wantATrace)
		std :: cout << std :: endl << std :: endl;
	if (needToClearU)
		delete u0;
	if (needToClearV)
		delete v0;
	return a.att_value;
}

