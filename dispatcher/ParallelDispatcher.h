#ifndef PARALLELDISPATCHER_H_
#define PARALLELDISPATCHER_H_

#include <vector>
#include <functional>
#include <thread>

/// Example class using STL threads and variadic templates.
/// This is a container class that allows a client to run a method
/// on each object in a separte thread. A variadic templates is used
/// to pass arguments to the method.
template <class T>
class ParallelDispatcher
{
public:

  /// Call each agent on a separate thread.
  /// Arguments are the method name followed by method arguments.
  template <class Fn, class... Args>
  void call(Fn&& method, Args&&... args)
  {
    std::vector<std::thread> threads;

    for (auto agent = agents.begin(); agent != agents.end(); ++agent) {
      threads.push_back( std::thread(method, *agent, args...) );
    }
    for (auto thread = threads.begin(); thread != threads.end(); ++thread) {
      thread->join();
    }
  }

  /// Add an agent to the collection.
  void add(T *agent)
  {
    agents.push_back(agent);
  }

  /// Collection of agents to be called.
  std::vector<T*> agents;
};
#endif
