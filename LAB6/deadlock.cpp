#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include "file.h"
using namespace std;

mutex mtx1; 
mutex mtx2; 

void threadF1() {
    cout<< "Thread 1: Trying to lock mutex 1 (file1.txt -> file3.txt)..." <<endl;
    mtx1.lock();
    cout<< "Thread 1: Locked mutex 1." <<endl;
    
    copyFileContent("file1.txt", "file3.txt");
    
    std::this_thread::sleep_for(chrono::seconds(1));
    
    cout<< "Thread 1: Trying to lock mutex 2 (file2.txt -> file4.txt)..." <<endl;
    mtx2.lock();
    cout<< "Thread 1: Locked mutex 2." <<endl;
    
    copyFileContent("file2.txt", "file4.txt");
    
    mtx2.unlock();
    mtx1.unlock();
    cout<< "Thread 1: Released both mutexes." <<endl;
}

void threadF2() {
    cout<< "Thread 2: Trying to lock mutex 2 (file2.txt -> file4.txt)..." <<endl;
    mtx2.lock();
    cout<< "Thread 2: Locked mutex 2." <<endl;
    
    copyFileContent("file2.txt", "file4.txt");
    
    std::this_thread::sleep_for(chrono::seconds(1));
    
    cout<< "Thread 2: Trying to lock mutex 1 (file1.txt -> file3.txt)..." <<endl;
    mtx1.lock();
    cout<< "Thread 2: Locked mutex 1." <<endl;
    
    copyFileContent("file1.txt", "file3.txt");
    
    mtx1.unlock(); 
    mtx2.unlock();
    
    cout<< "Thread 2: Released both mutexes." <<endl;
}

int main() {
    thread t1(threadF1);
    thread t2(threadF2);
    
    t1.join(); 
    t2.join();

    cout<< "Both threads finished execution." <<endl;
    return 0;
}
