#include "bits/stdc++.h"

using namespace std;

/*
To Pass arguments to thread’s associated callable object or function just pass
additional arguments to the std::thread constructor. By default all arguments
are copied into the internal storage of new thread.


NOTE: so here, if we pass `string& str` will case error
 */

void ThreadCallback(int x, string str) {
  cout << "Passed Number = " << x << endl;
  cout << "Passed String = " << str << endl;
}
int main() {
  int x = 10;
  string str = "Sample String";
  thread thread_obj(ThreadCallback, x, str);
  thread_obj.join();
  return 0;
}