#include <iostream>
#include <chrono>
#include <thread>
#include "ParallelDispatcher.h"

/// Simple class to demonstrate ParallelDispatcher.
class DelayedGreeter {
public:
  DelayedGreeter(const std::string& name, int delay) : name(name), delay(delay) {
  }

  void greet(const std::string& message) {
    std::this_thread::sleep_for(std::chrono::seconds(delay));
    std::cout << message <<  " (from " << name << ")" << std::endl;
  }

  std::string name;
  int delay;
};

int main(int argc, char** argv) {
  ParallelDispatcher<Greeter> dispatcher;

  DelayedGreeter alice("Alice", 2);
  dispatcher.add(&alice); 

  DelayedGreeter bob("Bob", 1);
  dispatcher.add(&bob); 

  DelayedGreeter charlie("Charlie", 5);
  dispatcher.add(&charlie); 

  dispatcher.call(&DelayedGreeter::greet, "Hi there!");   

  return 0;
}
