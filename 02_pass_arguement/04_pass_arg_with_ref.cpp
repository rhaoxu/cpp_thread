#include "bits/stdc++.h"

using namespace std;

// https://thispointer.com//c11-multithreading-part-3-carefully-pass-arguments-to-threads/

/*
NOTE:
    As arguments are copied to new threads stack so, if you need to pass
    references in common way i.e.

    Even if threadCallback accepts arguments as reference but still changes done
    it are not visible outside the thread. Its because x in the thread function
    threadCallback is reference to the temporary value copied at the new
   thread’s stack.
   */

void ThreadCallback(int const &x) {
  int &y = const_cast<int &>(x);
  ++y;
  std::cout << "Inside Thread x = " << x << std::endl;
}

int main() {
  int x = 9;
  std::cout << "In Main Thread : Before Thread Start x = " << x << std::endl;
  
  // x still is 9
  std::thread threadObj(ThreadCallback, x);

  // x is 10
  //   std::thread threadObj(ThreadCallback, ref(x));

  threadObj.join();
  std::cout << "In Main Thread : After Thread Joins x = " << x << std::endl;

  return 0;
}