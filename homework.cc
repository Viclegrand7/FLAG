#include "homework.hh"


/*
HAL HAL HAL HAL HAL HAL HAL
HAL   QUESTIONS 1 - 2   HAL
HAL HAL HAL HAL HAL HAL HAL
*/

justAnInt &justAnInt :: operator+=			(const justAnInt &rightHandSide) {
	att_value += rightHandSide.att_value;
	return *this;
}

justAnInt &justAnInt :: operator-=			(const justAnInt &rightHandSide) {
	att_value -= rightHandSide.att_value;
	return *this;
}

justAnInt &justAnInt :: operator*=			(const justAnInt &rightHandSide) {
	att_value *= rightHandSide.att_value;
	return *this;
}

justAnInt &justAnInt :: operator/=			(const justAnInt &rightHandSide) {
	att_value /= rightHandSide.att_value;
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

justAnInt &justAnInt :: operator=			(const justAnInt &rightHandSide) {
	att_value = rightHandSide.att_value;
	return *this;
}

justAnInt :: justAnInt						(const justAnInt &rightHandSide) {
	att_value = rightHandSide.att_value;
}

justAnInt :: justAnInt						() {
	att_value = 0;
}

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
	if (u0) {
		if (v0) {
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
			else {
				needToClearV = true;
				v0 = new justAnInt;
			}
			*v0 = 0;
		}
		else {
			needToClearU = true;
			v0 = new justAnInt;
		}
		*u0 = 1;
	}
	justAnInt u1 = 0;
	justAnInt v1 = 1;
	justAnInt tmp, rest;
	while (b) {
		rest = a / b;
		tmp = b; b = a - rest * b; a = tmp;
		tmp = u1; u1 = *u0 - rest * u1; *u0 = tmp;
		tmp = v1; v1 = *v0 - rest * v1; *v0 = tmp;
		if (wantATrace) {
			std :: cout.width(13);	std :: cout << a.	toStr();
			std :: cout.width(13);	std :: cout << b.	toStr();
			std :: cout.width(13);	std :: cout << u0->	toStr();
			std :: cout.width(13);	std :: cout << v0->	toStr() << std :: endl;			
		}
	}
	if (needToClearU)
		delete u0;
	if (needToClearV)
		delete v0;
	return a.att_value;
}



/*
HAL HAL HAL HAL HAL HAL
HAL   QUESTION  3   HAL
HAL HAL HAL HAL HAL HAL
*/

intModulo &intModulo :: operator+= (const intModulo &rightHandSide) {
	att_value += rightHandSide.att_value;
	att_value %= intModulo :: att_modulo;
	return *this;
}

intModulo &intModulo :: operator-= (const intModulo &rightHandSide) {
	att_value += att_value > rightHandSide.att_value ? 0 : att_modulo; /* We do not want to go negative */
	att_value -= rightHandSide.att_value;
	return *this;
}

intModulo &intModulo :: operator*= (const intModulo &rightHandSide) {
	bigInt localValue(att_value);
	localValue *= rightHandSide.att_value;
	att_value = localValue % intModulo :: att_modulo;
	return *this;
}

intModulo &intModulo :: operator/= (const intModulo &rightHandSide) {
	intModulo divider(rightHandSide.modInv());
	return *this *= divider;
}

intModulo :: intModulo				(const intModulo &rightHandSide) {
	att_value = rightHandSide.att_value;
}

intModulo :: intModulo				() {
	att_value = 0;
}

intModulo :: operator bool	() const {
	return att_value;
}

intModulo intModulo :: modInv() const {
	justAnInt inverse(0);
	if (justAnInt :: extendedEuclidean(justAnInt(att_modulo), justAnInt(att_value), NULL, &inverse, false) != 1) {
		justAnInt :: extendedEuclidean(justAnInt(att_modulo), justAnInt(att_value), NULL, NULL, true); /* Let us print our result */
		std :: cout << std :: endl << std :: endl << "The modulo you chose was not prime with that value, could not invert it" << std :: endl;
		exit(1);
	}
	return intModulo(inverse.giveValue());
}


/*
myOwnIsPrime(number, numberOfTries) in Python (BEURK) :

if (n % 2 == 0):
	return False
d = n - 1
r = 0
while (d % 2 == 0):
	r += 1
	d = d // 2
#Now we have n = pow(2, r) * d + 1
d = int(d)
while (k > 0):
	k -= 1
	a = randrange(2, n - 1)
	x = pow(a, d, n)
	if x == 1 or x == n - 1:
		continue #Didn't fail yet
	for i in range(r):
		x = pow(x, 2, n)
		if x == n - 1:
			break #Didn't fail yet, breaking the for, not proccing the else
	else:
		#We did not break, meaning we are composite
		return False
#Reached end of while, nothing odd
return True #Not true as in 'isPrime', but 'isLikelyPrime'
*/