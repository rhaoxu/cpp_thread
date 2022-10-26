#include "bits/stdc++.h"

using namespace std;

struct Worker {
  Worker(int i) : order_id(i) {}
  void operator()() {
    cout << order_id << "th Worker thread " << this_thread::get_id()
         << " is executing" << endl;
  }

  int order_id;
};

int main(int argc, char const* argv[]) {
  vector<thread> workers;
  for (int i = 0; i < 10; ++i) {
    workers.emplace_back(thread(Worker(i + 1)));
  }

  cout << "wait for all the worker thread to finish" << endl;
  // 1)
  // for (int i = 0; i < workers.size(); ++i)
  //   if (workers[i].joinable()) workers[i].join();

  // NOTE: const auto& worker: workers, will throw error
  // 2)
  for (auto& worker : workers)
    if (worker.joinable()) worker.join();

  // 3)
  // for_each(workers.begin(), workers.end(), mem_fn(&thread::detach));
  cout << "exiting from main thread" << endl;
  return 0;
}
