#include "bits/stdc++.h"

using namespace std;

class DummyClass {
 public:
  DummyClass() {}
  DummyClass(const DummyClass& obj) {}
  void sampleMemberFunc1(int& x) {
    x = 20;
    std::cout << "Inside Sample Member Function x is " << x << std::endl;
  }

  void sampleMemberFunc2(int& x) {
    x = 30;
    std::cout << "Inside Sample Member Function x is " << x << std::endl;
  }
};

int main() {
  DummyClass dummy_obj;
  int x = 10;
  cout << "Inside Main thread x is " << x << endl;

  // std::thread thread_obj(&DummyClass::sampleMemberFunc1, &dummy_obj, ref(x));
  std::thread thread_obj(&DummyClass::sampleMemberFunc2, &dummy_obj, ref(x));
  thread_obj.join();

  cout << "Inside Main thread x is " << x << endl;
  return 0;
}