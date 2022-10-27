#include "bits/stdc++.h"

using namespace std;

class Application {
 public:
  Application() : data_load_(false) {}

  void LoadData() {
    // Make This Thread sleep for 1 Second
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Loading Data from XML" << endl;
    // Lock The Data structure
    lock_guard<mutex> guard(app_lock_);
    // Set the flag to true, means data is loaded
    data_load_ = true;
  }

  void MainTask() {
    cout << "Do some handshaking" << endl;

    app_lock_.lock();

    while (!data_load_) {
      app_lock_.unlock();
      this_thread::sleep_for(chrono::milliseconds(100));

      app_lock_.lock();
    }

    app_lock_.unlock();
    cout << "Processing on loaded data" << endl;
  }

 private:
  mutex app_lock_;
  bool data_load_;
};

int main() {
  Application app;
  thread thread_1(&Application::MainTask, &app);
  thread thread_2(&Application::LoadData, &app);
  thread_2.join();
  thread_1.join();

  return 0;
}
