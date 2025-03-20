#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int burstTime;
};

class CircularQueue {
private:
    int front, rear, size;
    int capacity;
    Process *arr;
public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new Process[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }
    ~CircularQueue() {
        delete[] arr;
    }
    bool isEmpty() {
        return (size == 0);
    }
    bool isFull() {
        return (size == capacity);
    }
    void enqueue(Process p) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = p;
        size++;
    }
    Process dequeue() {
        if (isEmpty()){
            cout << "Queue is empty!\n";
            return {-1, -1};
        }
        Process temp = arr[front];
        front = (front + 1) % capacity;
        size--;
        return temp;

    }
};

struct CompareProcess {
    bool operator()(const Process &p1, const Process &p2) {
        return p1.burstTime > p2.burstTime;
    }
};

void roundRobinScheduling(Process processes[], int n, int quantum) {
    CircularQueue cq(n);
    for (int i = 0; i < n; i++) {
        cq.enqueue(processes[i]);
    }
    
    int currentTime = 0;
    cout << "Round Robin Scheduling Simulation:\n";
    while (!cq.isEmpty()){
        Process current = cq.dequeue();
        cout << "Time " << currentTime << ": Process " << current.pid << " executed. ";
        if (current.burstTime > quantum) {
            currentTime += quantum;
            current.burstTime -= quantum;
            cout << "Remaining burst time: " << current.burstTime << "\n";
            cq.enqueue(current);
        } else {
            currentTime += current.burstTime;
            cout << "Completed at time " << currentTime << "\n";
        }
    }
    cout << "\n";
}
// to 
void shortestJobFirstScheduling(Process processes[], int n) {
    priority_queue<Process, vector<Process>, CompareProcess> pq;
    for (int i = 0; i < n; i++) {
        pq.push(processes[i]);
    }
    
    int currentTime = 0;
    cout << "Shortest Job First Scheduling Simulation:\n";
    while(!pq.empty()){
        Process current = pq.top();
        pq.pop();
        cout << "Time " << currentTime << ": Process " << current.pid 
             << " executed with burst time " << current.burstTime << ". ";
        currentTime += current.burstTime;
        cout << "Completed at time " << currentTime << "\n";
    }
}

int main() {
    const int numProcesses = 6;
    Process processesRR[numProcesses] = {
        {1, 10},
        {2, 4},
        {3, 6},
        {4, 8},
        {5, 2},
        {6, 12}
    };
    
    Process processesSJF[numProcesses] = {
        {1, 10},
        {2, 4},
        {3, 6},
        {4, 8},
        {5, 2},
        {6, 12}
    };
    
    int quantum = 4; 
    
    roundRobinScheduling(processesRR, numProcesses, quantum);
    
    shortestJobFirstScheduling(processesSJF, numProcesses);
    
    return 0;
}
