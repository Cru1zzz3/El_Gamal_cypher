#include <iostream>
#include <cmath>
#include <random>
#include "El_Gamal.h"

using namespace std;

int main(){

	random_device random_device;
	mt19937 generator(random_device());

	El_Gamal alice;
	El_Gamal bob;
	int secNum,gNum,pNum;
	int messageNum;
	int pubBobNum;
	int choice = 1;
	Message encryptedMessage;
	Message decryptedMessage;
	// 1 part
	bob.g = alice.gen_g(bob.p = alice.gen_p());
	cout << "g = " << bob.g << " p = " << bob.p << endl;

	cout << "Input Bob secret number: ";
	cin >> secNum;	

	cout << "Bob public number is " << 
		bob.gen_public_number(bob.gen_secret_number(secNum)) << endl;

	// 2 part 
	cout << "Input Bob public number: ";
	cin >> pubBobNum;
	bob.gen_public_number(pubBobNum);

	cout << "Your random value k is: " <<
		alice.gen_random_number() << endl;

	cout << "Input your message number: ";
	cin >> messageNum;
	encryptedMessage = alice.encrypt_message(pubBobNum,messageNum);
	cout << "Message " << " successfully encrypted" << endl << endl;

	// 3 part
	decryptedMessage = bob.decrypt_message(encryptedMessage);
	if (messageNum == decryptedMessage.M)
		cout << "Decrypted succsessfull! Message is " << decryptedMessage.M << endl;
	else
		cout << "Decryption failed!" << endl ;

	cout << endl;

	system("pause");
	return 0;
};
