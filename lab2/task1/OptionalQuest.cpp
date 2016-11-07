#include <math.h>
#include <iostream>
#include <stdlib.h>



using namespace std;

/*Alice is 0, Bob is 1*/

bool checkCorrectness(unsigned int publicKey[], unsigned int privateKey[], unsigned int prime){
	
	unsigned int K[2];
	unsigned int tmp;
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
unsigned int prime = 2148532933;
unsigned int generator = 1001;
unsigned int publicKeyCarl = 199285757;


unsigned int tmp = log(publicKeyCarl)/log(generator);
unsigned int privateKeyAlice = fmod(tmp,prime);

cout << "Private Key Alice " << privateKeyAlice << endl;

tmp = (int)(pow(privateKeyAlice,generator)+0,5);
cout << "tmp: " << tmp <<endl;
unsigned int result = tmp % prime;
cout <<"result: "<< result<< endl;
if(tmp == publicKeyCarl){
	cout << "Correct"<<endl;
}


}

