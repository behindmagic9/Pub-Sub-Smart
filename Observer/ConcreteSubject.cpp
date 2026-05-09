#include "ConcreteSubject.h"
#include <string>

// std::unordered_map<std::string, std::vector<IObserver*>> record;

void ConcreteSubject::subscribe(std::shared_ptr<IObserver> obs,const Topic& topic) {
	// add the observer to the particular topic 's vector
	record[topic].push_back(obs);
}

void ConcreteSubject::unsubscribe(std::shared_ptr<IObserver> obs,const Topic& topic) {
	// remove the observer from the particular topic 's vector
	auto it = record.find(topic);

	if (it == record.end()) {
		return;
	}

	auto& vec = it->second;

	// "Move all matching elements to the end, .. remove move all elements to the last of the vector and then in series it then erase them."
	vec.erase(	
		std::remove_if(vec.begin(), vec.end(), [&](const std::weak_ptr<IObserver>& wk_ptr) {
			auto sp = wk_ptr.lock();
			return !sp || sp == obs;
		}), vec.end()
	);
}

void ConcreteSubject::notify(Event& e) {
	// find the topic in the map and call update function related to all the observer 
	const Topic& topic = e.topic;
	auto it = record.find(topic);

	if (it == record.end()) {
		return;
	}

	auto& vec = it->second;

	// here the complexity is going to O(n) in Average 
	// and O(n2) in worst case .. of too many expired obervers element by which the vector should have to shift in the erase section
	for (auto iter = it->second.begin(); iter != it->second.end();) {
		if (auto obs = iter->lock()) {
			obs->update(e);
			iter++;
		}
		else {
			iter = it->second.erase(iter);
		}
	}

	// to avoid O(n2) ->  O(n)
	// notify all valid observers

	/*for (auto& wk_ptr : vec) {
		if (auto obs = wk_ptr.lock()) {
			obs->update(e);
		}
	}

	// then removing expired observers in one loop again
	vec.erase(
		std::remove_if(vec.begin(), vec.end(), [](const std::weak_ptr<IObserver>& wk_pt) {
			return wk_pt.expired();
		}), vec.end()
	);*/

}