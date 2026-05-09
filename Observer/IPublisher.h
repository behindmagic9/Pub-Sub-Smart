#pragma once
#include"ISubject.h"
#include<unordered_map>
#include<vector>
#include<string>
#include"../Event.h"

class IPublisher {
public:
	virtual void publish(Event &e) = 0;
	virtual ~IPublisher() = default;
};