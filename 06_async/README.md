

Calling std::async with function pointer as callback

```c++
string fetchDataFromDB(string recvdData) {
  // Make sure that function takes 5 seconds to complete
  this_thread::sleep_for(seconds(5));
  // Do stuff like creating DB Connection and fetching Data
  return "DB_" + recvdData;
}


int main(int argc, char const *argv[]) {
  std::future<std::string> resultFromDB =
    std::async(std::launch::async, fetchDataFromDB, "Data");

  // Fetch Data from DB
  //  Will block till data is available in future<std::string> object.
  std::string dbData = resultFromDB.get();

  return 0;
}
```


Calling std::async with Lambda function as callback
```c++
int main(int argc, char const *argv[]) {
  // Calling std::async with lambda function
  std::future<std::string> resultFromDB = std::async(
    [](std::string recvdData) {
      std::this_thread::sleep_for(seconds(5));
      // Do stuff like creating DB Connection and fetching Data
      return "DB_" + recvdData;
    },
    "Data");

  return 0;
}

```



Calling std::async with Function Object as callback

```c++

struct DataFetcher {
  std::string operator()(std::string recvdData) {
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    // Do stuff like fetching Data File
    return "File_" + recvdData;
  }
};

int main(int argc, char const *argv[]) {
  // Calling std::async with function object
  std::future<std::string> fileResult = std::async(DataFetcher(), "Data");

  return 0;
}

```



