#include <bits/stdc++.h>

using namespace std;

struct Process {
    int id;
    int BT;
    int AT;
    int priority;
    int remTime;
    int WT;
    int TAT;
    int CT;
    vector<pair<int, int>> execIntervals;
};

class Scheduler {
private:
    vector<Process> processes;
    double avgWT;
    double avgTAT;
    int timeQuantum;

public:
    Scheduler(int quantum = 4) : timeQuantum(quantum) {}

    void addProcess(int id, int BT, int priority = 0, int AT = 0) {
        Process p = {id, BT, AT, priority, BT, 0, 0, 0, vector<pair<int, int>>()};
        processes.push_back(p);
    }

    void clearProcesses() {
        processes.clear();
    }

    void executeFCFS() {
        vector<Process> temp = processes;
        sort(temp.begin(), temp.end(), [](const Process& a, const Process& b) {
            return a.AT < b.AT;
        });

        int currTime = 0;
        for(Process& p : temp) {
            if(currTime < p.AT) currTime = p.AT;

            /*
            currtime = ct 
            tat = ct - bt
            wt  = tat - bt
                = ct - at - bt 
                = ct - bt - at
                = start - at 
            */  

            p.WT = currTime - p.AT;
            p.CT = currTime + p.BT;
            p.TAT = p.CT - p.AT;
            p.execIntervals.push_back({currTime, p.CT});
            currTime = p.CT;


        }
        processes = temp;
        calcAvg();
    }

    void executeSJF() {
        vector<Process> temp = processes;
        vector<Process> result;
        int currTime = 0;
        
        while(!temp.empty()) {
            vector<Process> available;
            for(const Process& p : temp) {
                if(p.AT <= currTime) available.push_back(p);
            }
            
            if(available.empty()) {
                currTime++;
                continue;
            }
            
            auto shortestJob = min_element(available.begin(), available.end(),
                [](const Process& a, const Process& b) { return a.BT < b.BT; });
            
            Process selected = *shortestJob;
            selected.WT = currTime - selected.AT;
            selected.CT = currTime + selected.BT;
            selected.TAT = selected.CT - selected.AT;
            selected.execIntervals.push_back({currTime, selected.CT});
            currTime = selected.CT;
            result.push_back(selected);
            
            temp.erase(remove_if(temp.begin(), temp.end(),
                [selected](const Process& p) { return p.id == selected.id; }), temp.end());
        }
        processes = result;
        calcAvg();
    }

    void executeSRTF() {
        vector<Process> temp = processes;
        vector<Process> result = processes;
        int currTime = 0;
        int completed = 0;
        int lastProcess = -1;
        
        while(completed != processes.size()) {
            int shortestRem = INT_MAX;
            int selectedInd = -1;
            
            for(int i = 0; i < temp.size(); i++) {
                if(temp[i].AT <= currTime && temp[i].remTime < shortestRem && temp[i].remTime > 0) {
                    shortestRem = temp[i].remTime;
                    selectedInd = i;
                }
            }
            
            if(selectedInd == -1) {
                currTime++;
                continue;
            }
            
            if(lastProcess != selectedInd && lastProcess != -1 && temp[lastProcess].remTime > 0) {
                result[lastProcess].execIntervals.back().second = currTime;
            }
            
            if(lastProcess != selectedInd) {
                result[selectedInd].execIntervals.push_back({currTime, currTime + 1});
            }
            
            temp[selectedInd].remTime--;
            currTime++;
            lastProcess = selectedInd;
            
            if(temp[selectedInd].remTime == 0) {
                completed++;
                result[selectedInd].CT = currTime;
                result[selectedInd].TAT = currTime - result[selectedInd].AT;
                result[selectedInd].WT = result[selectedInd].TAT - result[selectedInd].BT;
                result[selectedInd].execIntervals.back().second = currTime;
            }
        }
        processes = result;
        calcAvg();
    }

    void executePriorityScheduling() {
        auto compareProcess = [](const Process& a, const Process& b) {
            if(a.priority == b.priority) {
                return a.AT > b.AT;
            }
            return a.priority > b.priority;
        };
        
        priority_queue<Process, vector<Process>, decltype(compareProcess)> readyQueue(compareProcess);
        vector<Process> result = processes;
        vector<Process> notArrived = processes;
        int currTime = 0;
        int completed = 0;
        
        sort(notArrived.begin(), notArrived.end(), 
            [](const Process& a, const Process& b) { return a.AT < b.AT; });
        
        while(completed != processes.size()) {
            while(!notArrived.empty() && notArrived.front().AT <= currTime) {
                readyQueue.push(notArrived.front());
                notArrived.erase(notArrived.begin());
            }
            
            if(readyQueue.empty()) {
                if(!notArrived.empty()) {
                    currTime = notArrived.front().AT;
                    continue;
                }
                break;
            }
            
            Process currentProcess = readyQueue.top();
            readyQueue.pop();
            
            int processInd = currentProcess.id - 1;
            
            result[processInd].WT = currTime - result[processInd].AT;
            
            currTime += currentProcess.BT;
            
            result[processInd].CT = currTime;
            result[processInd].TAT = currTime - result[processInd].AT;
            
            result[processInd].execIntervals.push_back({currTime - currentProcess.BT, currTime });
            
            completed++;
        }
        
        processes = result;
        calcAvg();
    }

    void executeRoundRobin() {
        vector<Process> temp = processes;
        vector<Process> result = processes;
        vector<int> readyQueue;
        int currTime = 0;
        int timeQuantum = 4;
        int completed = 0;
        
        sort(temp.begin(), temp.end(), [](const Process& a, const Process& b) {
            return a.id < b.id;
        });
        
        for (auto& p : temp) {
            p.remTime = p.BT;
        }
        
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i].AT == 0) {
                readyQueue.push_back(i);
            }
        }
        
        int index = 0;
        while (completed != temp.size()) {
            if (readyQueue.empty()) {
                currTime++;
                continue;
            }
            
            int currentProcess = readyQueue[index];
            int executeTime = min(timeQuantum, temp[currentProcess].remTime);
            
            result[currentProcess].execIntervals.push_back({currTime, currTime + executeTime});
            
            temp[currentProcess].remTime -= executeTime;
            currTime += executeTime;
            
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i].AT <= currTime && temp[i].remTime > 0 && 
                    find(readyQueue.begin(), readyQueue.end(), i) == readyQueue.end()) {
                    readyQueue.push_back(i);
                }
            }
            
            if (temp[currentProcess].remTime > 0) {
                index = (index + 1) % readyQueue.size();
            } else {
                result[currentProcess].CT = currTime;
                result[currentProcess].TAT = currTime - result[currentProcess].AT;
                result[currentProcess].WT = result[currentProcess].TAT - result[currentProcess].BT;
                completed++;
                readyQueue.erase(readyQueue.begin() + index);
                if (!readyQueue.empty()) {
                    index = index % readyQueue.size();
                }
            }
        }
        
        processes = result;
        calcAvg();
    }


    void displayGanttChart() {
        cout << "\nGantt Chart:\n";
        cout << string(50, '-') << endl;
        
        vector<pair<int, pair<int, int>>> allIntervals;
        for(const Process& p : processes) {
            for(const auto& interval : p.execIntervals) {
                allIntervals.push_back({p.id, interval});
            }
        }
        
        sort(allIntervals.begin(), allIntervals.end(),
             [](const auto& a, const auto& b) { return a.second.first < b.second.first; });
        
        for(const auto& interval : allIntervals) {
            cout << "| P" << interval.first << " ";
        }
        cout << "|\n" << string(50, '-') << "\n";
        
        cout << "0";
        for(const auto& interval : allIntervals) {
            cout << setw(5) << interval.second.second;
        }
        cout << "\n\n";
    }

    void displayProcessDetails() {
        cout << "\nProcess Details:\n";
        cout << setw(10) << "Process" << setw(15) << "Arrival" << setw(15) << "Burst"
             << setw(15) << "Priority" << setw(15) << "Waiting" << setw(20) << "Turnaround"
             << setw(20) << "Completion\n";
        
        for(const Process& p : processes) {
            cout << setw(10) << "P" + to_string(p.id)
                 << setw(15) << p.AT
                 << setw(15) << p.BT
                 << setw(15) << p.priority
                 << setw(15) << p.WT
                 << setw(20) << p.TAT
                 << setw(20) << p.CT << "\n";
        }
        
        cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << avgWT << " ms\n";
        cout << "Average Turnaround Time: " << avgTAT << " ms\n";
    }

private:
    void calcAvg() {
        avgWT = 0;
        avgTAT = 0;
        for(const Process& p : processes) {
            avgWT += p.WT;
            avgTAT += p.TAT;
        }
        avgWT /= processes.size();
        avgTAT /= processes.size();
    }
};

int main() {
    Scheduler scheduler;
//    
    scheduler.addProcess(1, 5, 0, 0);
    scheduler.addProcess(2, 3, 0, 1);
    scheduler.addProcess(3, 8, 0, 2);
    scheduler.addProcess(4, 6, 0, 3);



    cout << "\nFCFS Scheduling:";
    scheduler.executeFCFS();
    scheduler.displayGanttChart();
    scheduler.displayProcessDetails();

    scheduler.clearProcesses();


//
    scheduler.addProcess(1, 5, 0, 0);
    scheduler.addProcess(2, 3, 0, 0);
    scheduler.addProcess(3, 8, 0, 0);
    scheduler.addProcess(4, 6, 0, 0);
    scheduler.addProcess(5, 1, 0, 0);
    scheduler.addProcess(6, 2, 0, 0);

    cout << "\nSJF Scheduling:";
    scheduler.executeSJF();
    scheduler.displayGanttChart();
    scheduler.displayProcessDetails();

    scheduler.clearProcesses();

//
    scheduler.addProcess(1, 8, 0, 0);
    scheduler.addProcess(2, 4, 0, 1);
    scheduler.addProcess(3, 9, 0, 2);
    scheduler.addProcess(4, 5, 0, 3);   

    cout << "\nSRTF Scheduling:";
    scheduler.executeSRTF();
    scheduler.displayGanttChart();
    scheduler.displayProcessDetails();

    scheduler.clearProcesses();

//  
    scheduler.addProcess(1, 10, 3, 0);
    scheduler.addProcess(2, 1, 1, 0);
    scheduler.addProcess(3, 2, 4, 0);
    scheduler.addProcess(4, 1, 5, 0);
    scheduler.addProcess(5, 5, 2, 0);

    cout << "\nPriority Scheduling:";
    scheduler.executePriorityScheduling();
    scheduler.displayGanttChart();
    scheduler.displayProcessDetails();

    scheduler.clearProcesses();

//

    scheduler.addProcess(1, 24, 0, 0);
    scheduler.addProcess(2, 3, 0, 0);
    scheduler.addProcess(3, 3, 0, 0);

    cout << "\nRound Robin Scheduling:";
    scheduler.executeRoundRobin();
    scheduler.displayGanttChart();
    scheduler.displayProcessDetails();

    scheduler.clearProcesses();

    return 0;
}