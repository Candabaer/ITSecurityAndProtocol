#include <math.h>
#include <iostream>
#include <stdlib.h>


/*Kleinste Primzahl >= 200, 211 aus mathe.tu-freiberg.de */

using namespace std;

int publicKeyGenerator(unsigned long long prime,unsigned long long generator,unsigned long long privateKey){
	unsigned long long publicKey=generator;

	for(int i = 0;i < privateKey-1;i++){
		publicKey *= generator;
		publicKey %= prime;
	}

//	cout << "KeyEntwicklung im betrieb " << publicKey<< endl;
	return publicKey;
}

bool checkCorrectness(unsigned long long publicKey[], unsigned long long privateKey[], unsigned long long  prime){
	
	unsigned long long K[2];
	unsigned long long tmp;
	
	for(int i = 0;i<2;i++){
		K[i]=publicKeyGenerator(prime, publicKey[i], privateKey[((i+1)%2)]);
	}

	cout << "Common Secret ist: " << K[0] << endl;	
	if(K[0]==K[1])
		return true;	
	else
		return false;

}

/*Alice is 0, Bob is 1*/

int main(/*int argc, const char* argv[]*/){
	unsigned long long generator;
	unsigned long long prime;
	unsigned long long publicKey[2];
	unsigned long long privateKey[2];
	cout << "Input the generator\n";
	cin >> generator;
	cout << "Input the Prime\n";
	cin >> prime;

	for (int i = 0; i < 2; i++){	
		while(true){
			cout << "All Inputs have to be > 0" << endl; 
			cout << "Input the private key\n";
			cin >> privateKey[i];	
		if(generator > prime || privateKey[i] > (prime-2)){
			cout << "generator or PrivateKey to big choose a smaller one, retry input\n\n\n";
		}else{
			break;
		}	
		}
	cout << endl << endl <<"PublicKey: " << publicKeyGenerator(prime, generator, privateKey[i]) << endl;
	publicKey[i] = publicKeyGenerator(prime, generator, privateKey[i]);
	}
	cout << endl << "Is the math I did true? \n" << checkCorrectness(publicKey, privateKey, prime) << endl;
}


