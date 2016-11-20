#include <math.h>
#include <iostream>
#include <stdlib.h>



using namespace std;

/*Alice is 0, Bob is 1*/


unsigned long long generatePrivateKey(unsigned long long prime, unsigned long long generator, unsigned long long publicKey){
unsigned long long privatKey=1;
unsigned long long fakePubKey=generator;
	while(true){
		fakePubKey*=generator;
		fakePubKey%=prime;
		privatKey++;
		if(publicKey==fakePubKey)
			break;		
	}
return privatKey;
}

unsigned long long checkCorrectness(unsigned long long prime, unsigned long long publicKey, unsigned long long privatKey){
unsigned long long commonSecret = publicKey;
	for(unsigned long long i = 0;i < privatKey-1;i++){
                commonSecret *= publicKey;
                commonSecret %= prime;
        }
return commonSecret;
}

int main(/*unsigned long long argc, const char* argv[]*/){
unsigned long long prime = 307;
unsigned long long generator = 5;
unsigned long long publicKeyCarl = 67;
unsigned long long publicKeyDave = 172;


unsigned long long privatKeyCarl = generatePrivateKey(prime, generator, publicKeyCarl);
unsigned long long privatKeyDave = generatePrivateKey(prime, generator, publicKeyDave);
	cout << "Carls PK: " <<generatePrivateKey(prime, generator, publicKeyCarl)<<endl;
	cout << "Dave PK: " <<generatePrivateKey(prime, generator, publicKeyDave)<<endl;

cout <<"Common Secret: "<< checkCorrectness(prime, publicKeyCarl, privatKeyDave) << endl;
cout <<"Common Secret: "<<checkCorrectness(prime, publicKeyDave, privatKeyCarl) << endl;

}
