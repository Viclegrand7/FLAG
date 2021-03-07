#include "homework.hh"


justAnInt &justAnInt :: operator+=								(const someType &rightHandSide) {
	att_value += rightHandSide;
}

template<typename someType> justAnInt &justAnInt :: operator+=	(const someType &rightHandSide) {
	att_value += rightHandSide;
}

template<typename someType> justAnInt justAnInt :: operator+	(const someType &rightHandSide) const {
	justAnInt localCopy(*self);
	return localCopy += rightHandSide;
}

template<typename someType> justAnInt operator+					(const someType &leftHandSide, const justAnInt &rightHandSide) const {
	justAnInt localCopy(rightHandSide);
	return localCopy += leftHandSide;	
}


justAnInt &justAnInt :: operator-=								(const justAnInt &rightHandSide) {
	att_value -= rightHandSide;
}

template<typename someType> justAnInt &justAnInt :: operator-=	(const someType &rightHandSide) {
	justAnInt localCopy(*self);
	return localCopy -= rightHandSide;
}

template<typename someType> justAnInt justAnInt :: operator-	(const someType &rightHandSide) const {
	justAnInt localCopy(rightHandSide);
	return localCopy -= leftHandSide;	
}

template<typename someType> justAnInt operator-					(const someType &leftHandSide, const justAnInt &rightHandSide) const {
	justAnInt localCopy(rightHandSide);
	return localCopy -= leftHandSide;	
}


justAnInt &operator*=											(const justAnInt &rightHandSide) {
	att_value *= rightHandSide;
}

template<typename someType> justAnInt &justAnInt :: operator*=	(const someType &rightHandSide) {
	att_value *= rightHandSide;
}

template<typename someType> justAnInt justAnInt :: operator*	(const someType &rightHandSide) const {
	justAnInt localCopy(*self);
	return localCopy *= rightHandSide;
}

template<typename someType> justAnInt operator*					(const someType &leftHandSide, const justAnInt &rightHandSide) const {
	justAnInt localCopy(rightHandSide);
	return localCopy *= leftHandSide;	
}


justAnInt &operator/=											(const someType &rightHandSide) {
	att_value /= rightHandSide;	
}

template<typename someType> justAnInt &justAnInt :: operator/=	(const someType &rightHandSide) {
	att_value /= rightHandSide;	
}

template<typename someType> justAnInt justAnInt :: operator/	(const someType &rightHandSide) const {
	justAnInt localCopy(*self);
	return localCopy /= rightHandSide;
}

template<typename someType> justAnInt operator/					(const someType &leftHandSide, const justAnInt &rightHandSide) const {
	justAnInt localCopy(rightHandSide);
	return localCopy /= leftHandSide;	
}

justAnInt justAnInt :: extendedEuclidean(justAnInt a, justAnInt b, justAnInt *u0, justAnInt *v0, bool wantATrace) {
	bool needToClearU(false), needToClearV(false);
	if (wantATrace) {
		std :: cout.setf(ios :: left); /* Text left justified */
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
					u0 = v0:
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
			std :: cout.width(13);	std :: cout << a.toStr();
			std :: cout.width(13);	std :: cout << b.toStr();
			std :: cout.width(13);	std :: cout << *u0.toStr();
			std :: cout.width(13);	std :: cout << *v0.toStr() << std :: endl;			
		}
	}
	if (needToClearU)
		delete u0;
	if (needToClearV)
		delete v0;
	return a;
}


intModulo intModulo :: extendedEuclidean(intModulo a, intModulo b, intModulo *u0, intModulo *v0, bool wantATrace = true) {
	bool needToClearU(false), needToClearV(false);
	if (wantATrace) {
		std :: cout.setf(ios :: left); /* Text left justified */
		std :: cout.width(13);	std :: cout << "a";
		std :: cout.width(13);	std :: cout << "b";
		std :: cout.width(13);	std :: cout << "u";
		std :: cout.width(13);	std :: cout << "v" << std :: endl;
	}
	if (!u0) {
		needToClearV = true;
		v0 = new justAnInt;
	}
	if (!v0) {
		needToClearU = true;
		v0 = new justAnInt;
	}

	if (b > a) {
		{
			justAnInt *tmpSwap(u0);
			u0 = v0:
			v0 = tmpSwap;
		}
		{
			justAnInt tmpSwap(a);
			a = b;
			b = tmpSwap;
		}
	}

	*v0 = 0;
	*u0 = 1;
	justAnInt u1 = 0;
	justAnInt v1 = 1;
	justAnInt tmp, rest;
	while (b) {
		rest = a / b;
		tmp = b; b = a - rest * b; a = tmp;
		tmp = u1; u1 = *u0 - rest * u1; *u0 = tmp;
		tmp = v1; v1 = *v0 - rest * v1; *v0 = tmp;
		if (wantATrace) {
			std :: cout.width(13);	std :: cout << a.toStr();
			std :: cout.width(13);	std :: cout << b.toStr();
			std :: cout.width(13);	std :: cout << *u0.toStr();
			std :: cout.width(13);	std :: cout << *v0.toStr() << std :: endl;			
		}
	}
	if (needToClearU)
		delete u0;
	if (needToClearV)
		delete v0;
	return a;
}

intModulo intModulo :: modInv() {
	intModulo inverse(0);
	extendedEuclidean(att_modulo, att_value, NULL, &inverse);
	return inverse;
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