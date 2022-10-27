#include "bits/stdc++.h"

using namespace std;


/* 

NOTE: 
condition_variable condition_var_;

wait()
notify_one()
unique_lock




 */

class Application {
 public:
  Application() : data_load_(false) {}

  void LoadData() {
    // Make This Thread sleep for 1 Second
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Loading Data from XML" << endl;

    // Lock The Data structure
    lock_guard<mutex> guard(m_mutex_);

    // Set the flag to true, means data is loaded
    data_load_ = true;
    // Notify the condition variable
    condition_var_.notify_one();
  }

  bool IsDataLoaded() { return data_load_; }

  void MainTask() {
    cout << "Do some handshaking" << endl;

    unique_lock<mutex> u_lock(m_mutex_);

    condition_var_.wait(u_lock, bind(&Application::IsDataLoaded, this));
    cout << "Processing on loaded data" << endl;
  }

 private:
  mutex m_mutex_;
  condition_variable condition_var_;
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
