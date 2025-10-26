#include "ArrayQueue.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    cout << "Array queue test" << endl;


    ArrayQueue<int> numQueue;
    cout << "[Step 1] Empty queue created." << endl;
    cout << "Is the queue empty? " << (numQueue.isEmpty() ? "Yes" : "No") << endl;

    // Try to view front and back on empty queue
    try {
        cout << "Front: " << numQueue.front() << endl;
    } catch (string& err) {
        cout << "Front error: " << err << endl;
    }
    try {
        cout << "Back: " << numQueue.back() << endl;
    } catch (string& err) {
        cout << "Back error: " << err << endl;
    }

 
    cout << "\n[Step 2] Enqueue a single value (-10)" << endl;
    numQueue.enqueue(-10);
    cout << "Queue length: " << numQueue.getLength() << endl;
    cout << "Front: " << numQueue.front() << " | Back: " << numQueue.back() << endl;

    cout << "\n[Step 3] Removing one element..." << endl;
    numQueue.dequeue();
    cout << "Queue length: " << numQueue.getLength() << endl;
    cout << "Is empty? " << (numQueue.isEmpty() ? "Yes" : "No") << endl;


    cout << "\n[Step 4] Enqueue 10 values (0–9)" << endl;
    for (int i = 0; i < 10; ++i) {
        numQueue.enqueue(i);
    }
    cout << "Queue length: " << numQueue.getLength() << endl;
    cout << "Front: " << numQueue.front() << " | Back: " << numQueue.back() << endl;


    cout << "\n[Step 5] Creating queueCopy via copy constructor..." << endl;
    ArrayQueue<int> queueCopy = numQueue;
    cout << "queueCopy length: " << queueCopy.getLength() << endl;
    cout << "queueCopy Front: " << queueCopy.front()
         << " | Back: " << queueCopy.back() << endl;

    cout << "\n[Step 6] Printing and clearing original queue..." << endl;
    cout << "Original queue elements: ";
    while (!numQueue.isEmpty()) {
        cout << numQueue.front() << ' ';
        numQueue.dequeue();
    }
    cout << endl;
    cout << "Original queue is empty? " << (numQueue.isEmpty() ? "Yes" : "No") << endl;

    cout << "\n[Step 7] Creating queueAssigned and assigning from queueCopy..." << endl;
    ArrayQueue<int> queueAssigned;
    queueAssigned = queueCopy;
    cout << "queueAssigned length: " << queueAssigned.getLength() << endl;
    cout << "Front: " << queueAssigned.front()
         << " | Back: " << queueAssigned.back() << endl;

    cout << "\n[Step 8] Clearing queueCopy..." << endl;
    queueCopy.clear();
    cout << "queueCopy is empty? " << (queueCopy.isEmpty() ? "Yes" : "No") << endl;

   
    cout << "\n[Step 9] Checking that queueAssigned still has data:" << endl;
    cout << "queueAssigned length: " << queueAssigned.getLength() << endl;
    cout << "queueAssigned front: " << queueAssigned.front()
         << " | back: " << queueAssigned.back() << endl;

    
    cout << "\n[Step 10] Random enqueue/dequeue simulation (5 random ops)" << endl;
    srand(static_cast<unsigned>(time(0)));
    for (int step = 0; step < 5; ++step) {
        int action = rand() % 2; // 0 = enqueue, 1 = dequeue
        if (action == 0) {
            int val = rand() % 100;
            queueAssigned.enqueue(val);
            cout << "Enqueued " << val << " | Length: " << queueAssigned.getLength() << endl;
        } else {
            if (!queueAssigned.isEmpty()) {
                cout << "Dequeued " << queueAssigned.front() << endl;
                queueAssigned.dequeue();
            } else {
                cout << "Skip dequeue (empty)" << endl;
            }
        }
    }

    // Final stats
    cout << "\nFinal queueAssigned length: " << queueAssigned.getLength() << endl;
    if (!queueAssigned.isEmpty()) {
        cout << "Front: " << queueAssigned.front()
             << " | Back: " << queueAssigned.back() << endl;
    } else {
        cout << "Queue is empty at end of run." << endl;
    }

    cout << "\n Test done" << endl;
    return 0;
}
