#include <iostream>
using namespace std;

class OSSimulator {
public:
    void demonstrateProcessScheduling() {
        cout << "Demonstrating Process Scheduling:\n";
        cout << "1. Creating processes\n";
        cout << "2. Assigning priorities\n";
        cout << "3. Scheduling using Round Robin\n";
        cout << "4. Context switching between processes\n";
    }

    void demonstrateMemoryManagement() {
        cout << "Demonstrating Memory Management:\n";
        cout << "1. Allocating memory blocks\n";
        cout << "2. Handling page faults\n";
        cout << "3. Implementing page replacement (LRU)\n";
    }

    void demonstrateFileSystem() {
        cout << "Demonstrating File System Operations:\n";
        cout << "1. Creating files and directories\n";
        cout << "2. Implementing file permissions\n";
        cout << "3. Handling file access requests\n";
    }
};

int main() {
    OSSimulator simulator;
    simulator.demonstrateProcessScheduling();
    simulator.demonstrateMemoryManagement();
    simulator.demonstrateFileSystem();
    return 0;
}