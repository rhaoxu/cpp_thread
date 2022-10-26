#include "bits/stdc++.h"

using namespace std;

const int kCount = 1e3;

class ThreadRAII {
 public:
  ThreadRAII(thread& thread_obj) : thread_(thread_obj){};
  ~ThreadRAII() {
    if (thread_.joinable()) thread_.join();
  }

 private:
  thread& thread_;
};

void ThreadFunc() {
  stringstream ss;
  ss << this_thread::get_id();
  string msg = "thread func id " + ss.str() + " is executing\n";
  for (int i = 0; i < kCount; ++i) {
    cout << msg;
  }
}

int main(int argc, char const* argv[]) {
  thread thread_obj1(ThreadFunc);
  thread thread_obj2(ThreadFunc);
  ThreadRAII wrapper_obj1(thread_obj1);
  ThreadRAII wrapper_obj2(thread_obj2);

  return 0;
}
