#include <iostream>
#include <stdlib.h>

using namespace std;

int myModulo(int mod, int number){
	if(mod >=0 && number>=0){
		while(true){
			if(number >= mod){
				number-=mod;
			}if(number < mod){
				return number;
			}
		}
	}else if(mod < 0 && number < 0){
		while(true){
			if(number <= mod){
				number-=mod;
			}if(number > mod){
				return number;
			}
		}
	}else if (number < 0 && mod > 0){
		while(true){
			if(number <= mod){
				number+=mod;
			}if(number < mod && number > 0){
				return number;
			}
		}
	}
	else if (number > 0 && mod < 0){
		while(true){
			if(number >= mod){
				number+=mod;
			}if(number > mod && number < 0){
				return number;
			}
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


