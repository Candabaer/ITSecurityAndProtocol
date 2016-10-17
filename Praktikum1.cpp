#include <iostream>
#include <stdlib.h>

using namespace std;

int myModulo(int mod, int number){
	number = abs(number);
	mod = abs(mod);
	while(true){
		if(number >= mod){
			number-=mod;
		}if(number < mod){
			return number;
		}
	}
	return number;
}


int main(/*int argc, const char* argv[]*/){
	int mod;
	int number;

	while (true){
		cout << "Input the modulo: ";
		cin >> mod;
		cout << "Input the Number: ";
		cin >> number;
		cout << number <<" % "<< mod << " = " << myModulo(mod, number)<< endl << endl;
		int x = number % mod;
		cout << number <<" !% "<< mod << " = " << (number % mod) << endl << endl;
	}
}


