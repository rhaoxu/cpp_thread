#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;


/* 

As both the functions fetchDataFromDB() & fetchDataFromFile() takes 5 seconds each and are running in a single thread so, total time consumed will be 10 seconds.
Now as fetching data from DB and file are independent of each other and also time consuming. So, we can run them in parallel.
One way to do is create a new thread pass a promise as an argument to thread function and fetch data from associated std::future object in calling thread.


 */
string fetchDataFromDB(string recvdData) {
  // Make sure that function takes 5 seconds to complete
  this_thread::sleep_for(seconds(5));
  // Do stuff like creating DB Connection and fetching Data
  return "DB_" + recvdData;
}
string fetchDataFromFile(string recvdData) {
  // Make sure that function takes 5 seconds to complete
  this_thread::sleep_for(seconds(5));
  // Do stuff like fetching Data File
  return "File_" + recvdData;
}

int main() {
  // Get Start Time
  system_clock::time_point start = system_clock::now();
  // Fetch Data from DB
  string dbData = fetchDataFromDB("Data");
  // Fetch Data from File
  string fileData = fetchDataFromFile("Data");
  // Get End Time
  auto end = system_clock::now();
  auto diff = duration_cast<chrono::seconds>(end - start).count();
  cout << "Total Time Taken = " << diff << " Seconds" << endl;
  // Combine The Data
  string data = dbData + " - " + fileData;
  // Printing the combined Data
  cout << "Data = " << data << endl;
  return 0;
}
