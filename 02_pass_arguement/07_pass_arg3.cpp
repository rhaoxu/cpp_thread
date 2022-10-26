

#include "bits/stdc++.h"

using namespace std;

/*
NOTE: unexpected behaviour

Similarly be careful while passing pointer to memory located on heap to thread.
Because it might be possible that some thread deletes that memory before new
thread tries to access it. In such scenario accessing invalid address can cause
unexpected behaviour.
 */

void NewThreadCallback(int* p) {
  // now p point to an unknown address
  std::cout << "Inside Thread :  "
               " : p = "
            << p << "   *p =" << *p << std::endl;
  std::chrono::milliseconds dura(1000);
  std::this_thread::sleep_for(dura);
  *p = 19;
}

void StartNewThread() {
  int* p = new int();
  *p = 10;
  std::cout << "Inside Main Thread :  "
               " : *p = "
            << *p << std::endl;
  std::thread t(NewThreadCallback, p);
  t.detach();
  delete p;
  p = nullptr;
}

int main() {
  StartNewThread();
  cout << "waiting for all threads complted execution" << endl;
  std::chrono::milliseconds dura(2000);
  std::this_thread::sleep_for(dura);
  return 0;
}