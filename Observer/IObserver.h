#pragma once
#include"ISubject.h"
#include<string>
#include"../Event.h"

class IObserver {
public:
	virtual void update(Event&) = 0;
	virtual ~IObserver() = default;
};