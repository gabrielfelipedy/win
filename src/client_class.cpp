#include <iostream>
#include "client_class.h"

Client::Client() {
  this->name = "default";
  this->service = "default";
}

std::string Client::getName() {
	return this->name;
}
	
std::string Client::getService() {
	return this->service;
}

void Client::setName(std::string name) {
	this->name = name;
}

void Client::setService(std::string service) {
	this->service = service;
}

bool Client::isFull() {
	return this->service.size() != 0 && this->name.size() != 0;
}
