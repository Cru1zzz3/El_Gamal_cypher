#include <iostream>
#include <cmath>
#include "El_Gamal.h"

using namespace std;

int main(){
	El_Gamal alice;
	El_Gamal bob;
	int secNum,gNum,pNum;
	int messageNum;
	int pubBobNum;
	Message encryptedMessage;
	Message decryptedMessage;
	// 1 part
	cout << "Input g number: ";
	cin >> gNum;
	bob.g = alice.gen_g(gNum);

	cout << "Input p number: ";
	cin >> pNum;
	bob.p = alice.gen_p(pNum);

	cout << "Input Bob secret number: ";
	cin >> secNum;	

	cout << "Bob public number is " << 
		bob.gen_public_number(bob.gen_secret_number(secNum)) << endl;

	cout << "Your random value k is: " <<
		alice.gen_public_from_random(alice.gen_random_number()) << endl;

	// 2 part 
	cout << "Input Bob public number: ";
	cin >> pubBobNum;
	bob.gen_public_number(pubBobNum);

	cout << "Input your message number: ";
	cin >> messageNum;
	encryptedMessage = alice.encrypt_message(pubBobNum,messageNum);
	cout << "Message " << messageNum << " successfully encrypted" << endl << endl;

	// 3 part
	decryptedMessage = bob.decrypt_message(encryptedMessage);
	if (messageNum == decryptedMessage.M)
		cout << "Decrypted succsessfull! Message is " << decryptedMessage.M << endl;
	else
		cout << "Decryption failed!" << endl;

	system("pause");
	return 0;
};
