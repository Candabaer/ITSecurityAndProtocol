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
unsigned long long prime = 2148532933;
unsigned long long generator = 1001;
unsigned long long publicKeyCarl = 1992854757;


unsigned long long privatKeyCarl = generatePrivateKey(prime, generator, publicKeyCarl);
	cout << "Der PK: " << generatePrivateKey(prime, generator, publicKeyCarl)<<endl;
}
