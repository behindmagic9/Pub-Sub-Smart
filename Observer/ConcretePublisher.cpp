#include "ConcretePublisher.h"

ConcretePublisher::ConcretePublisher(std::shared_ptr<ISubject> subject ,const Topic &topic) : _subject(subject),  _topic(topic){
	
}

void ConcretePublisher::publish(Event& e) {

	if (e.topic != _topic) {
		return;
	}
	if (auto subject = _subject.lock()) {
		subject->notify(e);
	}
}