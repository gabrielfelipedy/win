#ifndef _H_CLIENT
#define _H_CLIENT

#include <iostream>

class Client {
	public:
    Client();
    
		std::string getName();
		std::string getService();
		void setName(std::string name);
		void setService(std::string service);
		bool isFull();
	private:
		std::string name;
		std::string service;
		std::string dateOfPayment;
};

#endif
