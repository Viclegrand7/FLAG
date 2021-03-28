#include "KICV_ELLD_3.hh"

/*
HAL HAL HAL HAL HAL HAL
HAL   QUESTION  3   HAL
HAL HAL HAL HAL HAL HAL
*/

smallInt intModulo :: att_modulo = UINT32_MAX;

intModulo &intModulo :: operator+= 	(const intModulo &rightHandSide) {
	att_value += rightHandSide.att_value;
	att_value %= att_modulo;
	return *this;
}

intModulo operator+ 				(const intModulo &leftHandSide, const intModulo &rightHandSide) {
	intModulo localValue(leftHandSide);
	return localValue += rightHandSide;
}

intModulo &intModulo :: operator-= 	(const intModulo &rightHandSide) {
	att_value += att_value >= rightHandSide.att_value ? 0 : att_modulo; /* We do not want to go negative */
	att_value -= rightHandSide.att_value;
	return *this;
}

intModulo operator- 				(const intModulo &leftHandSide, const intModulo &rightHandSide) {
	intModulo localValue(leftHandSide);
	return localValue -= rightHandSide;
}

intModulo intModulo :: operator-	() const {
	intModulo localValue(*this);
	localValue.att_value = att_modulo - (att_value % att_modulo); /* Modulo is there just in case. Should never be an issue though */
	return localValue;
}

intModulo &intModulo :: operator*= 	(const intModulo &rightHandSide) {
	bigInt localValue(att_value);
	localValue *= rightHandSide.att_value;
	att_value = localValue % intModulo :: att_modulo;
	return *this;
}

intModulo operator* 				(const intModulo &leftHandSide, const intModulo &rightHandSide) {
	intModulo localValue(leftHandSide);
	return localValue *= rightHandSide;
}

intModulo &intModulo :: operator/=	(const intModulo &rightHandSide) {
	intModulo divider(rightHandSide.modInv());
	return *this *= divider;
}

intModulo operator/ 				(const intModulo &leftHandSide, const intModulo &rightHandSide) {
	intModulo localValue(leftHandSide);
	return localValue /= rightHandSide;
}

intModulo& intModulo :: operator= 	(const intModulo &rightHandSide) {
	att_value = rightHandSide.att_value % att_modulo;
	return *this;
}

bool intModulo :: operator==		(const intModulo &rightHandSide) 	const {
	return att_value == rightHandSide.att_value;
}

bool intModulo :: operator!=		(const intModulo &rightHandSide) 	const {
	return att_value != rightHandSide.att_value;
}

intModulo :: operator bool			() const {
	return att_value;
}

bool intModulo :: operator>			(const intModulo &rightHandSide) 	const {
	return att_value > rightHandSide.att_value;
}

bool intModulo :: operator>=		(const intModulo &rightHandSide) 	const {
	return att_value >= rightHandSide.att_value;
}

bool intModulo :: operator<			(const intModulo &rightHandSide) 	const {
	return att_value < rightHandSide.att_value;
}

bool intModulo :: operator<=		(const intModulo &rightHandSide) 	const {
	return att_value <= rightHandSide.att_value;
}
#if _cplusplus >= 201907L

auto intModulo :: operator<=>		(const intModulo &rightHandSide)	const {
	return att_value <=> rightHandSide.att_value;
}

#endif /* _cplusplus >= 201907L */

intModulo &intModulo :: operator++	() {
	++att_value;
	return *this;
}

intModulo &intModulo :: operator--	() {
	--att_value;
	return *this;
}

intModulo intModulo :: operator++	(int) {
	intModulo localValue(*this);
	++att_value;
	return localValue;
}

intModulo intModulo :: operator--	(int) {
	intModulo localValue(*this);
	--att_value;
	return localValue;
}

std :: ostream &operator<<			(std :: ostream &out,				const intModulo &rightHandSide) {
	return out << rightHandSide.att_value;
}


intModulo :: intModulo				(const intModulo &rightHandSide)	: att_value(rightHandSide.att_value) {}

intModulo :: intModulo				()									: att_value(0) {}


intModulo intModulo :: quotient		(const intModulo &rightHandSide) 	const {
	intModulo localValue(*this);
	intModulo result(0);
	while (localValue >= rightHandSide) {
		localValue -= rightHandSide;
		++result;
	}
	return result;
}

void intModulo :: normalize() {
	att_value %= att_modulo;
}

intModulo intModulo :: modInv		() const {
	intModulo inverse(0);
	if (intModulo :: extendedEuclidean(intModulo(att_modulo), intModulo(att_value), NULL, &inverse, false) != (smallInt) 1) {
		std :: cout << std :: endl << std :: endl << std :: endl << std :: endl << std :: endl << std :: endl 
				<< "The modulo you chose was not prime with that value, could not invert it" << std :: endl
				<< "Now generating certificate, being the trace of the Extended Euclidean algorithm" << std :: endl;
		intModulo :: extendedEuclidean(intModulo(att_modulo), intModulo(att_value), NULL, NULL, true); /* Let us print our result */
		exit(1);
	}
	return inverse;
}

void intModulo :: changeModulo		(const smallInt &newValue) {
	if (newValue >= ((uint64_t) 1 << 31)) {
		std :: cout << "Error, you entered a value too high for this work" << std :: endl;
		return;
	}
	intModulo :: att_modulo = newValue;
}

intModulo intModulo :: extendedEuclidean(intModulo a, intModulo b, intModulo *u0, intModulo *v0, bool wantATrace) {
	if (!a) {
		++att_modulo;
		a = (att_modulo - 1);
		--att_modulo;
	}
	bool needToClearU(false), needToClearV(false);
	if (wantATrace) {
		std :: cout.setf(std :: ios :: left); /* Text left justified */
		std :: cout.width(13);	std :: cout << "a";
		std :: cout.width(13);	std :: cout << "b";
		std :: cout.width(13);	std :: cout << "u";
		std :: cout.width(13);	std :: cout << "v" << std :: endl;
	}
	if (!u0) {
		needToClearU = true;
		u0 = new intModulo;
	}
	if (!v0) {
		needToClearV = true;
		v0 = new intModulo;
	}
	if (b > a) {
		{
			intModulo *tmpSwap(u0);
			u0 = v0;
			v0 = tmpSwap;
		}
		{
			intModulo tmpSwap(a);
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
	intModulo u1 = 0;
	intModulo v1 = 1;
	intModulo tmp, quotient;
	while (b) {
		quotient = a.quotient(b);	/* We cannot use the sign '/' because we overloaded it to use this function indirectly */
		tmp = b; b = a - quotient * b; a = tmp;
		tmp = u1; u1 = *u0 - quotient * u1; *u0 = tmp;
		tmp = v1; v1 = *v0 - quotient * v1; *v0 = tmp;
		if (wantATrace) {
			std :: cout.width(13);	std :: cout << a;
			std :: cout.width(13);	std :: cout << b;
			std :: cout.width(13);	std :: cout << *u0;
			std :: cout.width(13);	std :: cout << *v0 << std :: endl;			
		}
	}
	if (needToClearU)
		delete u0;
	if (needToClearV)
		delete v0;
	if (wantATrace)
		std :: cout << std :: endl << std :: endl;
	return a.att_value;
}

