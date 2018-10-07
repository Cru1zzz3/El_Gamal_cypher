#include <iostream>
#include "El_Gamal.h"
#include <ctime>
using namespace std;

unsigned int El_Gamal::gen_random_number(){
	srand(time(NULL));
	//return El_Gamal::rndNum = rand() % El_Gamal::p;
	return El_Gamal::rndPubNum = 7;
}; 

unsigned int El_Gamal::gen_public_number(int secNum){
	El_Gamal::pubNum = pow(g,El_Gamal::secNum);
	//return El_Gamal::pubNum = pubNum % El_Gamal::p;
	return pubNum = pubNum % p;
};

unsigned int El_Gamal::gen_public_from_random(int rndPubNum){
	int tmp = pow(g,El_Gamal::rndPubNum);
	//return El_Gamal::pubNum = pubNum % El_Gamal::p;
	return El_Gamal::pubNum = tmp % p;
};

unsigned int El_Gamal::gen_secret_number(int secNum){
	//return El_Gamal::rndNum = rand() % El_Gamal::p;
	return El_Gamal::secNum = secNum;
};

Message El_Gamal::encrypt_message(unsigned int receiver,unsigned int newMessage){
	//Message::closeM = newMessage;
	message.a = gen_public_from_random(El_Gamal::rndPubNum);
	unsigned long long tmp = 0;
	tmp = (pow(receiver,El_Gamal::rndPubNum) * newMessage);
	message.b = tmp % p;
	message.M = -1;
	return message;
};

 Message El_Gamal::decrypt_message(Message encryptedMessage){
	unsigned long long tmp;
	tmp = pow(encryptedMessage.a,(p-1-El_Gamal::secNum));
	encryptedMessage.M = ((encryptedMessage.b * tmp)  % p); 
	return encryptedMessage;
 };

unsigned int El_Gamal::gen_g(unsigned int g){
	//return El_Gamal::g = rand() % El_Gamal::p;
	return El_Gamal::g = g;
};

unsigned int El_Gamal::gen_p(unsigned int p){
	//return El_Gamal::p = rand() % El_Gamal::p;
	return El_Gamal::p = p;
};



