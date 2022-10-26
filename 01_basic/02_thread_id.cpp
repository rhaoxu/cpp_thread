#include "bits/stdc++.h"

using namespace std;

/* 
NOTE: thread with lambda
 */

int main(int argc, char const *argv[]) {
  thread thread_obj1(
    []() { cout << "thread func id: " << this_thread::get_id() << endl; });
  thread thread_obj2(
    []() { cout << "thread func id: " << this_thread::get_id() << endl; });

  thread_obj1.join();
  thread_obj2.join();
  cout << "main func id: " << this_thread::get_id() << endl;
  cout << "exit main function" << endl;

  return 0;
}
