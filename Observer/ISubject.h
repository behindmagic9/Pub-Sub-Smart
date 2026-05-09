#pragma once
#include"IObserver.h"
#include"IPublisher.h"
#include<string>
#include"../Event.h"
#include<memory>

class IPublisher;
class IObserver;
class ISubject {
	public:
		virtual void subscribe(std::shared_ptr<IObserver>,const Topic&) = 0;
		virtual void unsubscribe(std::shared_ptr<IObserver>,const Topic&) = 0;
		virtual void notify(Event&) = 0;
		virtual ~ISubject() = default;
};