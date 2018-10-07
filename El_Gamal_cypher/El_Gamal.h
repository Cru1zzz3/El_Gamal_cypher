#ifndef EL_GAMAL_H
#define EL_GAMAL_H

class Message{
public:
	unsigned int a,b;
	int M;
};

class El_Gamal{
private:
	int rndPubNum;
	int secNum;
	Message message;
public:
	/* El_Gamal(int random,int secret)
	{
	rndPubNum = random ;
	secNum = secret;
	}; */
	unsigned int g,p;
	unsigned int pubNum;
	unsigned int gen_g(unsigned int g);
	unsigned int gen_p(unsigned int p);
	unsigned int gen_random_number();
	unsigned int gen_public_number(int secNum);
	unsigned int gen_public_from_random(int rndPubNum);
	unsigned int gen_secret_number(int secNum);
	Message encrypt_message(unsigned int receiver,unsigned int message);
	Message decrypt_message(Message encrypt_message);
};

#endif EL_GAMAL_H