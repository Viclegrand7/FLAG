#include "KICV_ELLD_6.hh"

/*
HAL HAL HAL HAL HAL HAL
HAL   QUESTION  6   HAL
HAL HAL HAL HAL HAL HAL
*/

std :: vector <intModulo> polynomeModulo :: att_modulo{1, 2 << 29};

std :: string polynomeModulo :: toString						()													const {
	std :: string result("");
	if (att_value.size())
		result += std :: to_string(att_value[0].giveValue());
	if (att_value.size() > 1)
		result += " + " + std :: to_string(att_value[1].giveValue()) + "x";
	for (unsigned int i = 2 ; i < att_value.size() ; ++i)
		result += " + " + std :: to_string(att_value[i].giveValue()) + "x^" + std :: to_string(i);
	return result;
}

intModulo &polynomeModulo :: operator[]							(unsigned int position) {
	if (position < att_value.size())
		return att_value[position];
	while (att_value.size() <= position)
		att_value.push_back(0);
	return att_value[position];			/* Basically we can now do a[6] = 2, when a = x^2 + 2 */
}

intModulo  polynomeModulo :: operator[]							(unsigned int position)								const {
	if (position < att_value.size())
		return att_value[position];
	return 0;
}

polynomeModulo &polynomeModulo :: operator+= 	(const polynomeModulo &rightHandSide) {
	unsigned int maximumValue = att_value.size() < rightHandSide.att_value.size() ? att_value.size() : rightHandSide.att_value.size();	/* Remember which is smallest */
	for (unsigned int i = att_value.size() ; i < rightHandSide.att_value.size() ; ++i) /* This only proccs if rightHandSide has higher exponent coefficients */
		att_value.push_back(rightHandSide[i]);

	for (unsigned int i = 0 ; i < maximumValue ; ++i)	/* We deal with either the left part of rightHandSide, or the total of it */
		att_value[i] += rightHandSide[i];
	normalize();
	return *this;
}

polynomeModulo &polynomeModulo :: operator+= 	(const std :: vector <intModulo> &rightHandSide) {
	unsigned int maximumValue = att_value.size() < rightHandSide.size() ? att_value.size() : rightHandSide.size();	/* Remember which is smallest */
	for (unsigned int i = att_value.size() ; i < rightHandSide.size() ; ++i) /* This only proccs if rightHandSide has higher exponent coefficients */
		att_value.push_back(rightHandSide[i]);

	for (unsigned int i = 0 ; i < maximumValue ; ++i)	/* We deal with either the left part of rightHandSide, or the total of it */
		att_value[i] += rightHandSide[i];
	normalize();
	return *this;
}

polynomeModulo operator+ 						(const polynomeModulo &leftHandSign, 				const polynomeModulo &rightHandSide) {
	polynomeModulo localValue(leftHandSign);
	return localValue += rightHandSide;
}

polynomeModulo &polynomeModulo :: operator-= 	(const polynomeModulo &rightHandSide) {
	unsigned int maximumValue = att_value.size() < rightHandSide.att_value.size() ? att_value.size() : rightHandSide.att_value.size();	/* Remember which is smallest */
	for (unsigned int i = att_value.size() ; i < rightHandSide.att_value.size() ; ++i) /* This only proccs if rightHandSide has higher exponent coefficients */
		att_value.push_back(-rightHandSide[i]);

	for (unsigned int i = 0 ; i < maximumValue ; ++i)	/* We deal with either the left part of rightHandSide, or the total of it */
		att_value[i] -= rightHandSide[i];
	normalize();
	return *this;
}

polynomeModulo &polynomeModulo :: operator-= 	(const std :: vector <intModulo> &rightHandSide) {
	unsigned int maximumValue = att_value.size() < rightHandSide.size() ? att_value.size() : rightHandSide.size();	/* Remember which is smallest */
	for (unsigned int i = att_value.size() ; i < rightHandSide.size() ; ++i) /* This only proccs if rightHandSide has higher exponent coefficients */
		att_value.push_back(-rightHandSide[i]);

	for (unsigned int i = 0 ; i < maximumValue ; ++i)	/* We deal with either the left part of rightHandSide, or the total of it */
		att_value[i] -= rightHandSide[i];
	normalize();
	return *this;
}

polynomeModulo operator- 						(const polynomeModulo &leftHandSign, 				const polynomeModulo &rightHandSide) {
	polynomeModulo localValue(leftHandSign);
	return localValue -= rightHandSide;
}

polynomeModulo polynomeModulo :: operator-		() const {
	polynomeModulo localValue(*this);
	for (unsigned int i = 0 ; i < att_modulo.size() ; ++i)
		localValue[i] = -att_value[i];
	localValue.normalize();
	return localValue;
}

polynomeModulo &polynomeModulo :: operator*=	(const polynomeModulo &rightHandSide) {
	unsigned int maximumExponent(att_value.size() + rightHandSide.att_value.size() - 1);
	std :: vector <intModulo> localValue(0);
	while(localValue.size() < maximumExponent)
		localValue.push_back(0);
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		for (unsigned int j = 0 ; j < rightHandSide.att_value.size() ; ++j)
			localValue[i + j] += att_value[i] * rightHandSide.att_value[j];
	att_value = localValue;
	normalize();
	return *this;
}

polynomeModulo &polynomeModulo :: operator*=	(const std :: vector <intModulo> &rightHandSide) {
	unsigned int maximumExponent(att_value.size() + rightHandSide.size() - 1);
	std :: vector <intModulo> localValue(0);
	while(localValue.size() < maximumExponent)
		localValue.push_back(0);
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		for (unsigned int j = 0 ; j < rightHandSide.size() ; ++j)
			localValue[i + j] += att_value[i] * rightHandSide[j];
	att_value = localValue;
	normalize();
	return *this;
}

polynomeModulo operator* 						(const polynomeModulo &leftHandSign, 				const polynomeModulo &rightHandSide) {
	polynomeModulo localValue(leftHandSign);
	return localValue *= rightHandSide;
}

polynomeModulo &polynomeModulo :: operator/=	(const polynomeModulo &rightHandSide) {
	polynomeModulo divider(rightHandSide.modInv());
	return *this *= divider;
}

polynomeModulo &polynomeModulo :: operator/=	(const std :: vector <intModulo> &rightHandSide) {
	polynomeModulo localValue(rightHandSide);
	polynomeModulo divider(localValue.modInv());
	return *this *= divider;
}

polynomeModulo operator/ 						(const polynomeModulo &leftHandSign, 				const polynomeModulo &rightHandSide) {
	polynomeModulo localValue(leftHandSign);
	return localValue /= rightHandSide;
}

polynomeModulo& polynomeModulo :: operator= 	(const polynomeModulo &rightHandSide) {
	att_value = rightHandSide.att_value;
	normalize();
	return *this;
}

bool polynomeModulo :: operator==				(const polynomeModulo &rightHandSide) 				const {
	if (att_value.size() !=rightHandSide.att_value.size())
		return false;
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		if (att_value[i] != rightHandSide[i])
			return false;
	return true;
}

bool polynomeModulo :: operator==				(const std :: vector <intModulo> &rightHandSide) 	const {
	if (att_value.size() !=rightHandSide.size())
		return false;
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		if (att_value[i] != rightHandSide[i])
			return false;
	return true;
}

bool polynomeModulo :: operator!=				(const polynomeModulo &rightHandSide) 				const {
	if (att_value.size() !=rightHandSide.att_value.size())
		return true;
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		if (att_value[i] != rightHandSide[i])
			return true;
	return false;
}

bool polynomeModulo :: operator!=				(const std :: vector <intModulo> &rightHandSide) 	const {
	if (att_value.size() !=rightHandSide.size())
		return true;
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		if (att_value[i] != rightHandSide[i])
			return true;
	return false;
}

polynomeModulo :: operator bool					() const {
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		if (att_value[i])
			return true;
	return false;
}

bool polynomeModulo :: operator>				(const polynomeModulo &rightHandSide) 				const {
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

bool polynomeModulo :: operator>				(const std :: vector <intModulo> &rightHandSide) 	const {
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

bool polynomeModulo :: operator>=				(const polynomeModulo &rightHandSide) 				const {
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

bool polynomeModulo :: operator>=				(const std :: vector <intModulo> &rightHandSide) 	const {
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

bool polynomeModulo :: operator<				(const polynomeModulo &rightHandSide) 				const {
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

bool polynomeModulo :: operator<				(const std :: vector <intModulo> &rightHandSide) 	const {
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

bool polynomeModulo :: operator<=				(const polynomeModulo &rightHandSide) 				const {
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

bool polynomeModulo :: operator<=				(const std :: vector <intModulo> &rightHandSide) 	const {
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
auto polynomeModulo :: operator<=>				(const polynomeModulo &rightHandSide)				const {
	return att_value <=> rightHandSide.att_value; /* It should be implemented correctly in the first place, so we can do this */
}

auto polynomeModulo :: operator<=>				(const std :: vector <intModulo> &rightHandSide)	const {
	return att_value <=> rightHandSide; /* It should be implemented correctly in the first place, so we can do this */
}
#endif /* _cplusplus >= 201907L */
/*
polynomeModulo &polynomeModulo :: operator++	() {
	++att_value;
	return *this;
}

polynomeModulo &polynomeModulo :: operator--	() {
	--att_value;
	return *this;
}

polynomeModulo polynomeModulo :: operator++		(int) {
	polynomeModulo localValue(*this);
	++att_value;
	return localValue;
}

polynomeModulo polynomeModulo :: operator--		(int) {
	polynomeModulo localValue(*this);
	--att_value;
	return localValue;
}
*/
std :: ostream &operator<<						(std :: ostream &out,				const polynomeModulo &rightHandSide) {
	if (rightHandSide.att_value.size())
		out << rightHandSide[0];
	if (rightHandSide.att_value.size() > 1)
		out << " + " << rightHandSide[1] << "x";
	for (unsigned int i = 2 ; i < rightHandSide.att_value.size() ; ++i)
		out << " + " << rightHandSide[i] << "x^" << i;
	return out;
}


polynomeModulo :: polynomeModulo				(const polynomeModulo &rightHandSide)			: att_value(rightHandSide.att_value) {}

polynomeModulo :: polynomeModulo				(const std :: vector <intModulo> &rightHandSide): att_value(rightHandSide) {}

polynomeModulo :: polynomeModulo				()												: att_value(1) {}


polynomeModulo polynomeModulo :: quotient		(const polynomeModulo &rightHandSide) const {
	if (att_value.size() < rightHandSide.att_value.size())
		return polynomeModulo();
	polynomeModulo result(0);
	for (unsigned int i = 0 ; i < att_value.size() - rightHandSide.att_value.size(); ++i)
		result.att_value.push_back(0);
	polynomeModulo localValue(*this);

	unsigned int currentExponent(result.att_value.size() - 1);
	while (localValue.att_value.size() >= rightHandSide.att_value.size()) {
		result[currentExponent] = localValue.att_value.back() / rightHandSide.att_value.back();
		for (unsigned int i = 0 ; i < rightHandSide.att_value.size() ; ++i)
			localValue[i + currentExponent] -= result[currentExponent] * rightHandSide.att_value[i];
		--currentExponent;
		localValue.att_value.pop_back();
	}
	return result;
}

polynomeModulo polynomeModulo :: modInv			() const {
	polynomeModulo inverse;
	if (polynomeModulo :: extendedEuclidean(polynomeModulo(att_modulo), polynomeModulo(att_value), NULL, &inverse, false) != (smallInt) 1) {
		std :: cout << std :: endl << std :: endl << std :: endl << std :: endl << std :: endl << std :: endl 
				<< "The modulo you chose was not prime with that value, could not invert it" << std :: endl
				<< "Now generating certificate, being the trace of the Extended Euclidean algorithm" << std :: endl;
		polynomeModulo :: extendedEuclidean(polynomeModulo(att_modulo), polynomeModulo(att_value), NULL, NULL, true); /* Let us print our result */
		return polynomeModulo();
	}
	return inverse;
}

void polynomeModulo :: changeModulo				(const std :: vector <intModulo> &newValue) {
	att_modulo = newValue;
}

polynomeModulo polynomeModulo :: noNormaliseMultiply		(const polynomeModulo &rightHandSide) {
	unsigned int maximumExponent(att_value.size() + rightHandSide.att_value.size() - 1);
	std :: vector <intModulo> localValue(0);
	while(localValue.size() < maximumExponent)
		localValue.push_back(0);
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		for (unsigned int j = 0 ; j < rightHandSide.att_value.size() ; ++j)
			localValue[i + j] += att_value[i] * rightHandSide.att_value[j];
	att_value = localValue;
	return *this;
}


void polynomeModulo :: normalize				() {
	/* Let us first apply modulo */
	polynomeModulo localValue(quotient(att_modulo));
	if (!localValue) {
		while (att_value.size() > 1 && !(att_value.back()))
			att_value.pop_back();
		return;
	}
	localValue.noNormaliseMultiply(att_modulo);
	for (unsigned int i = 0 ; i < att_value.size() ; ++i)
		att_value[i] -= localValue[i];

	/* We are good to go. Erasing the useless 0s on top */
	while (att_value.size() > 1 &&  !(att_value.back()))
		att_value.pop_back();
}

polynomeModulo polynomeModulo :: extendedEuclidean(polynomeModulo a, polynomeModulo b, polynomeModulo *u0, polynomeModulo *v0, bool wantATrace) {
	bool needToClearU(false), needToClearV(false);
	if (!a) {
		att_modulo.push_back(0);
		a.att_value = att_modulo;
		a.att_value.pop_back();
		att_modulo.pop_back();
	}
	if (wantATrace) {
		std :: cout.setf(std :: ios :: left); /* Text left justified */
		std :: cout.width(30);	std :: cout << "a";
		std :: cout.width(30);	std :: cout << "u";
		std :: cout.width(30);	std :: cout << "v";
		std :: cout.width(30);	std :: cout << "q" << std :: endl;
	}
	if (!u0) {
		needToClearU = true;
		u0 = new polynomeModulo;
	}
	if (!v0) {
		needToClearV = true;
		v0 = new polynomeModulo;
	}
	if (b > a) {
		{
			polynomeModulo *tmpSwap(u0);
			u0 = v0;
			v0 = tmpSwap;
		}
		{
			polynomeModulo tmpSwap(a);
			a = b;
			b = tmpSwap;
		}
	}
	*u0 = 1;
	*v0 = 0;
	polynomeModulo u1(0);
	polynomeModulo v1(1);
	polynomeModulo tmp, quotient;
	if (wantATrace) {
		std :: cout.width(30); std :: cout << a.toString();
		std :: cout.width(30); std :: cout << u0->toString();
		std :: cout.width(30); std :: cout << v0->toString();			
	}
	while (b) {
		quotient = a.quotient(b);
		tmp = b; b = a - quotient * b; a = tmp;
		tmp = u1; u1 = *u0 - quotient * u1; *u0 = tmp;
		tmp = v1; v1 = *v0 - quotient * v1; *v0 = tmp;
		if (wantATrace) {
			std :: cout.width(30); std :: cout << a.toString();
			std :: cout.width(30); std :: cout << u0->toString();
			std :: cout.width(30); std :: cout << v0->toString();
			std :: cout.width(30); std :: cout << quotient.toString() << std :: endl;
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

