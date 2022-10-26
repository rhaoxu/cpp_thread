

All codes from the following link

https://thispointer.com/c-11-multithreading-part-1-three-different-ways-to-create-threads/



Case 1: Never call join() or detach() on std::thread object with no associated executing thread


```c++
std::thread threadObj( (WorkerThread()) );
threadObj.join();
threadObj.join(); // It will cause Program to Terminate
```


```c++
std::thread threadObj( (WorkerThread()) );
threadObj.detach();
threadObj.detach(); // It will cause Program to Terminate

```


Case 2 : Never forget to call either join or detach on a std::thread object with associated executing thread
```c++
#include <iostream>
#include <thread>
#include <algorithm>
class WorkerThread
{
public:
    void operator()()     
    {
        std::cout<<"Worker Thread "<<std::endl;
    }
};
int main()  
{
    std::thread threadObj( (WorkerThread()) );
    // Program will terminate as we have't called either join or detach with the std::thread object.
    // Hence std::thread's object destructor will terminate the program
    return 0;
}
```



