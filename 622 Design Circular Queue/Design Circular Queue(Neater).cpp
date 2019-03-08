//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/23.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int head = -1, tail = -1;
    int size = -1;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        if (isEmpty())
            head = 0;
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
    
    void display() {
//        cout << head << tail << endl;
        if (isEmpty()) {
            return;
        } else {
            if (tail > head) {
                for (int i = head; i <= tail; i++) {
                    cout << data[i] << " ";
                }
                cout << endl;
            } else if (tail < head) {
                for (int i = head; i < size; i++) {
                    cout << data[i] << " ";
                }
                for (int i = 0; i <= tail; i++) {
                    cout << data[i] << " ";
                }
                cout << endl;
            } else {
                cout << data[head] << endl;
            }
        }
        return;
    }
};

int main() {
    MyCircularQueue circularQueue(2);
    circularQueue.enQueue(1);  // return true
    circularQueue.display();
    circularQueue.enQueue(2);  // return true
    circularQueue.enQueue(3);  // return true
    circularQueue.enQueue(4);  // return false, the queue is full
    circularQueue.display();
//    cout << circularQueue.Rear() << endl;  // return 3
//    cout << circularQueue.isFull() << endl;  // return true
    circularQueue.deQueue();  // return true
    circularQueue.display();
    circularQueue.deQueue();
    circularQueue.deQueue();
    circularQueue.deQueue();
//    circularQueue.enQueue(4);  // return true
//    cout << circularQueue.Rear() << endl;  // return 4
    circularQueue.display();
    return 0;
}
