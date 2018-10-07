#include <iostream>
#include <cmath>
#include "El_Gamal.h"

using namespace std;

int main(){
/*
	int a = 5;
	int b = 13;
	int r;
	r = pow(a,b);
	r = r % 23;
*/

	El_Gamal alice(3,0);
	El_Gamal bob(0,9);
	int m = 9;
	Message encryptedMessage;
	Message decryptedMessage;
	//alice.rndNum;
	//cout << "Input your secret number" << endl;
	bob.g = alice.gen_g(7);
	bob.p = alice.gen_p(11);

	alice.gen_random_number(); // взаимнопростое с (p-1)
	
	alice.gen_public_number();
	//bob.gen_secret_number();
	bob.gen_public_number();
	
	encryptedMessage = alice.encrypt_message(bob.pubNum,m);
	cout << "Message " << m << " successfully encrypted" << endl;
	decryptedMessage = bob.decrypt_message(encryptedMessage);
	if (m == decryptedMessage.M)
		cout << "Decrypted succsessfull! Message is " << decryptedMessage.M << endl;
	else
		cout << "Decryption failed!" << endl;
	
	system("pause");
	return 0;
};
