#include <math.h>
#include <iostream>
#include <stdlib.h>


/*Kleinste Primzahl >= 200, 211 aus mathe.tu-freiberg.de */

using namespace std;

int publicKeyGenerator(unsigned int prime,unsigned int generator,unsigned int privateKey){
	unsigned int publicKey;
		
	unsigned int quad = pow(generator,privateKey);
	publicKey = quad % prime;
	return publicKey;	
}

bool checkCorrectness(unsigned int   publicKey[], unsigned int  privateKey[], unsigned int  prime){
	
	unsigned int K[2];
	unsigned int tmp;
	tmp = pow(publicKey[1], privateKey[0]);
	K[0] = tmp % prime;
	tmp = pow(publicKey[0], privateKey[1]);
	K[1] = tmp % prime;
	cout << "Gemeinsame Secret: " << K[0]<< endl;
	if(K[0]==K[1])
		return true;	
	else
		return false;
	

}

/*Alice is 0, Bob is 1*/

int main(/*int argc, const char* argv[]*/){
	unsigned int generator, prime;
	unsigned int publicKey[2];
	unsigned int privateKey[2];
	
	for (int i = 0; i < 2; i++){	
		while(true){
			cout << "All Inputs have to be > 0" << endl; 
			cout << "Input the private key\n";
			cin >> privateKey[i];	
			cout << "Input the generator\n";
			cin >> generator;
			cout << "Input the Prime\n";
			cin >> prime;
			if(generator > prime || privateKey[i] > (prime-2)){
				cout << "generator or PrivateKey to big choose a smaller one, retry input\n\n\n";
			}else{
				break;
			}
		}
	cout << endl << endl << publicKeyGenerator(prime, generator, privateKey[i]) << endl;
	publicKey[i] = publicKeyGenerator(prime, generator, privateKey[i]);
	}
	cout << endl << "Is the math I did true? \n" << checkCorrectness(publicKey, privateKey, prime) << endl;
}


