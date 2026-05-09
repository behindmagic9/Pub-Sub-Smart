#pragma once
#include"IObserver.h"
#include"ISubject.h"

class ConcreteObserver : public IObserver
{
	std::weak_ptr<ISubject> _subject;
	std::string _name;
public:
	ConcreteObserver(std::shared_ptr<ISubject> ,const std::string&);
	void update(Event&) override;
};

