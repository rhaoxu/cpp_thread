#include "bits/stdc++.h"

using namespace std;

/*
NOTE:

std::lock_guard is a class template, which implements the RAII for mutex.
It wraps the mutex inside it’s object and locks the attached mutex in its
constructor. When it’s destructor is


 */
class Wallet {
 public:
  Wallet() : balance_(0) {}

  int get_balance() const { return balance_; }

  void Deposit(int money) {
    lock_guard<mutex> my_loack_guard(lock_);
    
    for (int i = 0; i < money; ++i) {
      ++balance_;
    }
    // mutex is automatically released when lock
    // goes out of scope
  }

 private:
  int balance_;
  mutex lock_;
};

int TestMultithreadedWallet() {
  Wallet wallet_obj;

  vector<thread> workers;

  int num_of_workers = 5;
  for (int i = 0; i < num_of_workers; ++i)
    workers.emplace_back(thread(&Wallet::Deposit, &wallet_obj, 1000));

  for (auto& worker : workers)
    if (worker.joinable()) worker.join();

  return wallet_obj.get_balance();
}

int main(int argc, char const* argv[]) {
  for (int i = 0; i < 1000; ++i) {
    int balance = TestMultithreadedWallet();
    if (balance != 5000) {
      cout << "Error at " << i << " th wallet, and its balance is " << balance
           << endl;
    }
  }

  return 0;
}
