#include <iostream>
#include "El_Gamal.h"

#include <random>
#include <vector>

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

using namespace std;

#define RAND_MAX 100


unsigned int El_Gamal::gen_random_number(){
	return El_Gamal::rndPubNum = rand() % El_Gamal::p;
}; 

unsigned int El_Gamal::gen_public_number(int secNum){
	cpp_int tmp = ((cpp_int)pow(g,El_Gamal::secNum) % p);
	return El_Gamal::pubNum = tmp.convert_to<int>();	
};

unsigned int El_Gamal::gen_public_from_random(int rndPubNum){
	cpp_int tmp = ((cpp_int)pow(g,El_Gamal::rndPubNum));
	tmp = tmp % p;
	return El_Gamal::pubNum = tmp.convert_to<int>();
};

unsigned int El_Gamal::gen_secret_number(int secNum){
	return El_Gamal::secNum = secNum;
};

Message El_Gamal::encrypt_message(unsigned int receiver,unsigned int newMessage){
	message.a = gen_public_from_random(El_Gamal::rndPubNum);
	cpp_int tmp = boost::multiprecision::pow((cpp_int)receiver,rndPubNum);
	tmp = tmp * newMessage;
	tmp = tmp % p;
	message.b = tmp.convert_to<int>();
	message.M = -1;
	return message;
};

Message El_Gamal::decrypt_message(Message encryptedMessage){
	int message;
	cpp_int tmp = (cpp_int)pow(encryptedMessage.a,(p-1-El_Gamal::secNum));
	tmp = (encryptedMessage.b * tmp) % p;
	message = tmp.convert_to<int>();
	encryptedMessage.M = message; 
	return encryptedMessage;
};


bool prime(int n){ 
	for(int i = 2;i <= sqrt(n); i++)
		if(n % i == 0)
			return false;
	return true;
}

vector<int> factorize (int n, vector<int> factor){
	for (int i = 2; i <= n/2; i++)
		if (n % i == 0)
			factor.push_back(i);
	return factor;
};

int firstRoot(int p){
	vector<int> factor;
	int  reminder;
	int g;
	int phi = p - 1;
	factor = factorize(phi,factor);
	bool found = false;
	while (found == false){
		for (g = 2; g < p; g++){
			for (int i = 0; i < factor.size(); i++){
				reminder = ((int)pow(g,factor[i]) % p);
				if ( reminder == 1){
					found = false;
				}
				else {
					found = true;
				}
			}
			if (found == true)
				break;
		}
	}
	return g;
};

unsigned int El_Gamal::gen_g(unsigned int p){	
	return El_Gamal::g = firstRoot(El_Gamal::p);
};

unsigned int El_Gamal::gen_p(){
	int rndPrime; 
	bool primeCheck = false;
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(10, 30);

	while (!primeCheck){
		rndPrime = distribution(generator);
		primeCheck = prime(rndPrime);
	}
	return El_Gamal::p = rndPrime;
};


