#include <math.h>
#include <iostream>
#include <stdlib.h>



using namespace std;

/*Alice is 0, Bob is 1*/

bool checkCorrectness(unsigned int publicKey[], unsigned int privateKey[], unsigned int prime){
	
	unsigned int K[2];
	unsigned int tmp;
	tmp = (int)(pow(publicKey[1], privateKey[0])+0,5);
	K[0] = fmod (tmp, prime);
	tmp = (int)(pow(publicKey[0], privateKey[1])+0,5);
	K[1] = fmod(tmp,prime);
	if(K[0]==K[1])
		return true;	
	else
		return false;
	

}


int main(/*int argc, const char* argv[]*/){
unsigned int prime = 307;
unsigned int generator = 5;
unsigned int publicKeyCarl = 67;
unsigned int publicKeyDave = 172;


unsigned int tmp = log(publicKeyCarl)/log(generator);
unsigned int privateKeyCarl = tmp%prime;
		tmp = log(publicKeyDave)/log(generator);
unsigned int privateKeyDave =tmp%prime;

cout << "Private Key Carl " << privateKeyCarl << endl;
cout << "Private Key Dave " << privateKeyDave << endl;
//Debug check


unsigned int privateKeys[2];
unsigned int publicKeys[2];
privateKeys[0] = privateKeyCarl;
privateKeys[1] = privateKeyDave;
publicKeys[0] = publicKeyCarl;
publicKeys[1] = publicKeyDave;


cout << "Check if calculation are true with common Secret: " << checkCorrectness(publicKeys, privateKeys, prime)<< endl;
}
