#include "KICV_ELLD_1_2.hh"

/*
HAL HAL HAL HAL HAL HAL HAL
HAL   QUESTIONS 1 - 2   HAL
HAL HAL HAL HAL HAL HAL HAL
*/

justAnInt &justAnInt :: operator+=			(const justAnInt &rightHandSide) {
	att_value += rightHandSide.att_value;
	return *this;
}

justAnInt &justAnInt :: operator+=			(const intModulo &rightHandSide) {
	att_value += rightHandSide.giveValue();
	return *this;
}

justAnInt &justAnInt :: operator-=			(const justAnInt &rightHandSide) {
	att_value -= rightHandSide.att_value;
	return *this;
}

justAnInt &justAnInt :: operator-=			(const intModulo &rightHandSide) {
	att_value -= rightHandSide.giveValue();
	return *this;
}

justAnInt justAnInt :: operator-			() const {
	justAnInt localValue(*this);
	localValue.att_value = - att_value;
	return localValue;
}

justAnInt &justAnInt :: operator*=			(const justAnInt &rightHandSide) {
	att_value *= rightHandSide.att_value;
	return *this;
}

justAnInt &justAnInt :: operator*=			(const intModulo &rightHandSide) {
	att_value *= rightHandSide.giveValue();
	return *this;
}

justAnInt &justAnInt :: operator/=			(const justAnInt &rightHandSide) {
	att_value /= rightHandSide.att_value;
	return *this;
}

justAnInt &justAnInt :: operator/=			(const intModulo &rightHandSide) {
	att_value /= rightHandSide.giveValue();
	return *this;
}

justAnInt &justAnInt :: operator=			(const justAnInt &rightHandSide) {
	att_value = rightHandSide.att_value;
	return *this;
}

bool justAnInt :: operator==				(const justAnInt &rightHandSide) const {
	return att_value == rightHandSide.att_value;
}

bool justAnInt :: operator!=				(const justAnInt &rightHandSide) const {
	return att_value != rightHandSide.att_value;
}

bool justAnInt :: operator>					(const justAnInt &rightHandSide) const {
	return att_value > rightHandSide.att_value;
}

bool justAnInt :: operator>=				(const justAnInt &rightHandSide) const {
	return att_value >= rightHandSide.att_value;
}

bool justAnInt :: operator<					(const justAnInt &rightHandSide) const {
	return att_value < rightHandSide.att_value;
}

bool justAnInt :: operator<=				(const justAnInt &rightHandSide) const {
	return att_value <= rightHandSide.att_value;
}

std :: ostream &operator<<			(std :: ostream &out,				const justAnInt &rightHandSide) {
	return out << rightHandSide.toStr();
}


justAnInt :: justAnInt						(const justAnInt &rightHandSide)	: att_value(rightHandSide.att_value) {}

justAnInt :: justAnInt						() 									: att_value(0) {}

justAnInt :: operator bool					() const {
	return att_value;
}




int64_t justAnInt :: extendedEuclidean(justAnInt a, justAnInt b, justAnInt *u0, justAnInt *v0, bool wantATrace) {
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
		u0 = new justAnInt;
	}
	if (!v0) {
		needToClearV = true;
		v0 = new justAnInt;
	}
	if (b > a) {
		{
			justAnInt *tmpSwap(u0);
			u0 = v0;
			v0 = tmpSwap;
		}
		{
			justAnInt tmpSwap(a);
			a = b;
			b = tmpSwap;
		}
	}
	*u0 = 1;
	*v0 = 0;
	if (wantATrace) {
		std :: cout.width(13);	std :: cout << a.	toStr();
		std :: cout.width(13);	std :: cout << b.	toStr();
		std :: cout.width(13);	std :: cout << u0->	toStr();
		std :: cout.width(13);	std :: cout << v0->	toStr() << std :: endl;			
	}
	justAnInt u1 = 0;
	justAnInt v1 = 1;
	justAnInt tmp, quotient;
	while (b) {
		quotient = a / b;
		tmp = b; b = a - quotient * b; a = tmp;
		tmp = u1; u1 = *u0 - quotient * u1; *u0 = tmp;
		tmp = v1; v1 = *v0 - quotient * v1; *v0 = tmp;
		if (wantATrace) {
			std :: cout.width(13);	std :: cout << a.	toStr();
			std :: cout.width(13);	std :: cout << b.	toStr();
			std :: cout.width(13);	std :: cout << u0->	toStr();
			std :: cout.width(13);	std :: cout << v0->	toStr() << std :: endl;			
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

