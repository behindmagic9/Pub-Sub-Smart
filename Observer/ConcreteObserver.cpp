#include "ConcreteObserver.h"
#include<iostream>

ConcreteObserver::ConcreteObserver(std::shared_ptr<ISubject> subject, const std::string& name) : _subject(subject) , _name(name){

}

void ConcreteObserver::update(Event& e) {
	std::cout << "called for " << this->_name << "publisher is " << e.topic  << " the data is now : " << e.data << std::endl;
}