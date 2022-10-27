#include "bits/stdc++.h"

using namespace std;


class Wallet {
 public:
  Wallet() : balance_(0) {}

  int get_balance() const { return balance_; }

  void Deposit(int money) {
    lock_.lock();

    for (int i = 0; i < money; ++i) {
      ++balance_;
    }
    
    lock_.unlock();
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
