#include <iostream>
#include "El_Gamal.h"
#include <ctime>
using namespace std;

unsigned int El_Gamal::gen_random_number(){
	
	srand(time(NULL));

	//return El_Gamal::rndNum = rand() % El_Gamal::p;
	return El_Gamal::rndNum = 7;
}; 

unsigned int El_Gamal::gen_public_number(){
	if (rndNum == 0)
		El_Gamal::pubNum = pow(g,El_Gamal::secNum);
	else
		El_Gamal::pubNum = pow(g,El_Gamal::rndNum);
	return El_Gamal::pubNum = pubNum % El_Gamal::p;
};

unsigned int El_Gamal::gen_secret_number(){
	//return El_Gamal::rndNum = rand() % El_Gamal::p;
	return El_Gamal::secNum = 13;
};

Message El_Gamal::encrypt_message(unsigned int receiver,unsigned int newMessage){
	//Message::closeM = newMessage;
	message.M = -1;
	message.a = El_Gamal::pubNum;
	unsigned long long tmp = 0;
	tmp = (pow(receiver,El_Gamal::rndNum) * newMessage);
	message.b = tmp % p;
	return message;
};

 Message El_Gamal::decrypt_message(Message encryptedMessage){
	Message decryptedMessage = encryptedMessage;
	unsigned long long tmp;
	tmp = pow(decryptedMessage.a,(p-1-El_Gamal::secNum));
	unsigned long long up = 0, down = 0;
	decryptedMessage.M = ((decryptedMessage.b * tmp)  % p); 
	return decryptedMessage;
 };

unsigned int El_Gamal::gen_g(unsigned int g){
	return El_Gamal::g = g;
};

unsigned int El_Gamal::gen_p(unsigned int p){
	return El_Gamal::p = p;
};



