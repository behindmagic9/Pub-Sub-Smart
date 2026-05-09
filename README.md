// this architecture is getting complex
```
main()
│
├── shared_ptr<ISubject>
│        │
│        ▼
│   ConcreteSubject (BROKER)
│
├── shared_ptr<IObserver>
│        │
│        ▼
│   ConcreteObserver
│        │
│        └──── weak_ptr<ISubject>
│
├── shared_ptr<IPublisher>
│        │
│        ▼
│   ConcretePublisher
│        │
│        └──── weak_ptr<ISubject>
│
└── Broker internally stores:
         weak_ptr<IObserver>
```
```
Publisher.publish(Event)
        |
        v
Broker.notify(Event)
        |
        v
Find Topic Subscribers
        |
        v
Observer.update(Event)
``` 
Pros: 

1. Loose coupling - everythign goes through broker , none other know eachother
2. safe memory management - shared and weak pointer use
3. Extensible - easy to add new topics , publishers , observers
4. Automatic clean up of dead subscribrers

Cons : 

1.shard_ptr and weak_ptr are expensive
- as they use :
                 - atomic refernce counting
                 - ysnchornization

                in every : 
                    lock()
                    sahred_ptr copy
                    destroy

This creates: 
1. cache contention
2. memory fencing
3. may cause cpu atomic instructions    


notify complexity:

best case : O(n)
worst case : O(n2) - if many weak ptr expired , reshifting of the vector

unordered_map

- cause cashe  miss
- poor locality

