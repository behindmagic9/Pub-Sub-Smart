#pragma once
#include"IPublisher.h"
#include"ISubject.h"
#include<memory>

class ConcretePublisher : public IPublisher
{
	std::weak_ptr<ISubject> _subject;
	Topic _topic;
public:
	ConcretePublisher(std::shared_ptr<ISubject>,const Topic&);
	void publish(Event& e)override;
};