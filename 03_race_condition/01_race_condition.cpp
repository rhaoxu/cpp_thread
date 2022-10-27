#include "bits/stdc++.h"

using namespace std;

/*
So, if initially money in wallet is 0. Then after completion of all thread’s
execution money in Wallet should be 5000.

But, as all threads are modifying the shared data at same time, it might be
possible that in some scenarios money in wallet at end will be much lesser than
5000.





 */
class Wallet {
 public:
  Wallet() : balance_(0) {}

  int get_balance() const { return balance_; }

  void Deposit(int money) {
    for (int i = 0; i < money; ++i) {
      ++balance_;
    }
  }

 private:
  int balance_;
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
