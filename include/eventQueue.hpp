#pragma once

#include <boost/thread.hpp>
#include <queue>

class Event;

class EventQueue {
  public:
    void push(Event inputEvent);
    Event pop();

    bool isEmpty();

    boost::condition_variable cond; 
    boost::mutex mut;

  private:
    std::queue<Event> queue;
    boost::shared_mutex queueMutex;
};
