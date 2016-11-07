#include <math.h>
#include <iostream>
#include <stdlib.h>



using namespace std;

/*Alice is 0, Bob is 1*/

bool checkCorrectness(double publicKey[], double privateKey[], double prime){
	
	double K[2];
	double tmp;
	tmp = pow(publicKey[1], privateKey[0]);
	K[0] = fmod (tmp, prime);
	tmp = pow(publicKey[0], privateKey[1]);
	K[1] = fmod(tmp,prime);
	if(K[0]==K[1])
		return true;	
	else
		return false;
	

}


int main(/*int argc, const char* argv[]*/){
double prime = 307;
double generator = 5;
double publicKeyCarl = 67;
double publicKeyDave = 172;


double tmp = log(publicKeyCarl)/log(generator);
double privateKeyCarl = fmod(tmp,prime);
		tmp = log(publicKeyDave)/log(generator);
double privateKeyDave = fmod(tmp,prime);

cout << "Private Key Carl " << privateKeyCarl << endl;
cout << "Private Key Dave " << privateKeyDave << endl;
//Debug check
tmp = pow(privateKeyDave,generator);
cout << "tmp: " << tmp <<endl;
unsigned int result = tmp % prime;
cout <<"result: "<< result<< endl;
if(tmp == publicKeyDave){
	cout << "Correct"<<endl;
}

double privateKeys[2];
double publicKeys[2];
privateKeys[0] = privateKeyCarl;
privateKeys[1] = privateKeyDave;
publicKeys[0] = publicKeyCarl;
publicKeys[1] = publicKeyDave;


cout << "Check if calculation are true with common Secret: " << checkCorrectness(publicKeys, privateKeys, prime)<< endl;
}

