#include <iostream>
#include <chrono>
#include <thread>
#include "ParallelDispatcher.h"

/// Simple class to demonstrate ParallelDispatcher.
class Greeter {
public:
  Greeter(const std::string& name, int delay) : name(name), delay(delay) {
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

  Greeter alice("Alice", 2);
  dispatcher.add(&alice); 

  Greeter bob("Bob", 1);
  dispatcher.add(&bob); 

  Greeter charlie("Charlie", 5);
  dispatcher.add(&charlie); 

  dispatcher.call(&Greeter::greet, "Hi there!");   

  return 0;
}
