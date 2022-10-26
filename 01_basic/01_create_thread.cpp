#include "bits/stdc++.h"

using namespace std;

const int kCount = 1e3;
void ThreadFunc() {
  for (int i = 0; i < kCount; ++i) {
    cout << "thread func executing" << endl;
  }
}

int main(int argc, char const *argv[]) {
  thread thread_obj(ThreadFunc);

  for (int i = 0; i < kCount; ++i) {
    cout << "main func executing " << endl;
  }

  thread_obj.join();
  cout << "exit main function" << endl;

  return 0;
}
