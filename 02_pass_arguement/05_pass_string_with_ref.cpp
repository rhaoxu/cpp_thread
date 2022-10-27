#include "bits/stdc++.h"

using namespace std;

// https://thispointer.com//c11-multithreading-part-3-carefully-pass-arguments-to-threads/

void ThreadCallbackWithString(string &s) {
  for (int i = 0; i < s.length(); ++i) s[i] = toupper(s[i]);
  cout << s << endl;
}

int main() {
  string msg("hello world");
  std::cout << "In Main Thread : Before Thread Start msg = " << msg
            << std::endl;

  // NOTE:
  // program will throw error without ref()
  // std::thread threadObj(ThreadCallbackWithString, msg);

  std::thread threadObj(ThreadCallbackWithString, ref(msg));
  threadObj.join();
  std::cout << "In Main Thread : After Thread Joins msg = " << msg << std::endl;

  return 0;
}