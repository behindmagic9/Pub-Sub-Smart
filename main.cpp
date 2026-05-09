// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Observer/ConcreteObserver.h"
#include"Observer/ConcreteSubject.h"
#include "Observer/IObserver.h"
#include "Observer/ConcretePublisher.h"

#include <iostream>
#include<memory>

int main()
{
    std::shared_ptr<ISubject> broker = std::make_shared<ConcreteSubject>();

    const Topic& animal = Topic::Animal;
    const Topic& birds = Topic::Birds;

    std::shared_ptr<IObserver> obs1 = std::make_shared<ConcreteObserver>(broker, "obs1");
    std::shared_ptr<IObserver> obs2 = std::make_shared<ConcreteObserver>(broker, "obs2");
    std::shared_ptr<IObserver> obs3 = std::make_shared<ConcreteObserver>(broker, "obs3");
    std::shared_ptr<IObserver> obs4 = std::make_shared<ConcreteObserver>(broker, "obs4");
    std::shared_ptr<IObserver> obs5 = std::make_shared<ConcreteObserver>(broker, "obs5");
    std::shared_ptr<IObserver> obs6 = std::make_shared<ConcreteObserver>(broker, "obs6");
    std::shared_ptr<IObserver> obs7 = std::make_shared<ConcreteObserver>(broker, "obs7");
    std::shared_ptr<IObserver> obs8 = std::make_shared<ConcreteObserver>(broker, "obs8");
    std::shared_ptr<IObserver> obs9 = std::make_shared<ConcreteObserver> (broker, "obs9");

    std::shared_ptr<IPublisher> publisher1 = std::make_shared<ConcretePublisher>(broker, animal);
    std::shared_ptr<IPublisher> publisher2 = std::make_shared<ConcretePublisher>(broker, birds);

    broker->subscribe(obs1, animal);
    broker->subscribe(obs2, animal);
    broker->subscribe(obs3, animal);
    broker->subscribe(obs4, animal);
    broker->subscribe(obs5, animal);
    broker->subscribe(obs6, animal);
    broker->subscribe(obs7, animal);
    broker->subscribe(obs8, animal);
    broker->subscribe(obs9, animal);

    broker->subscribe(obs1, birds);
    broker->subscribe(obs2, birds);
    broker->subscribe(obs3, birds);
    broker->subscribe(obs4, birds);
    broker->subscribe(obs5, birds);
    broker->subscribe(obs6, birds);
    broker->subscribe(obs7, birds);
    broker->subscribe(obs8, birds);
    broker->subscribe(obs9, birds);

    Event e1 {
        animal,
        "tiger fled",
    };

    Event e2{
        birds,
        "birds fled",
    };


    publisher1->publish(e1);
    publisher1->publish(e2);

    publisher2->publish(e1);
    publisher2->publish(e2);

}
    