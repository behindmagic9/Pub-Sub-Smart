#pragma once
#include"ISubject.h"
#include<unordered_map>
#include "IObserver.h"
#include<vector>
#include<memory>

class ConcreteSubject  : public ISubject
{	
	std::unordered_map<Topic, std::vector<std::weak_ptr<IObserver>>,Topichash> record;
public:
	void subscribe(std::shared_ptr<IObserver>,const Topic&) override;
	void unsubscribe(std::shared_ptr<IObserver>,const Topic&) override;
	void notify(Event& e) override;
};