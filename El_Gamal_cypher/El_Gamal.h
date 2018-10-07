#ifndef EL_GAMAL_H
#define EL_GAMAL_H

class Message{
	public:
		unsigned int a,b;
		int M;
		//unsigned int openM;
};

class El_Gamal{
	private:
		int rndNum;
		int secNum;
		Message message;
		
	public:
		El_Gamal(int random,int secret){
			rndNum = random ;
			secNum = secret;
		};
		unsigned int g,p;
		unsigned int pubNum;
		unsigned int gen_g(unsigned int g);
		unsigned int gen_p(unsigned int p);
		unsigned int gen_random_number();
		unsigned int gen_public_number();
		unsigned int gen_secret_number();
		Message encrypt_message(unsigned int receiver,unsigned int message);
		Message decrypt_message(Message encrypt_message);
};

#endif EL_GAMAL_H