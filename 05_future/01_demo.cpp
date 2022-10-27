#include "bits/stdc++.h"

using namespace std;

void Initiazer(promise<int>* promise_obj) {
  cout << "Inside Thread" << endl;
  promise_obj->set_value(35);
}

int main() {
  // create promise obj
  promise<int> promise_obj;
  // fetch future obj from promise obj
  future<int> future_obj = promise_obj.get_future();

  thread th(Initiazer, &promise_obj);

  // block until promise obj return a value
  cout << future_obj.get() << endl;

  th.join();

  // continue work
  cout << "exist..." << endl;
  return 0;
}