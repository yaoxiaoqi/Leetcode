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

class MyLinkedList {
public:
    struct Node {
        int val;
        Node *next;
        Node(int x): val(x), next(NULL) {}
    };
    Node* head;
    
    /** Initialize your data structure here. */
    MyLinkedList() : head(NULL) {
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* p = head;
        int cnt = 0;
        while(p) {
            if (cnt == index) {
                return p->val;
            }
            ++cnt;
            p = p->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* cur = new Node(val);
        Node* p = head;
        cur->next = p;
        head = cur;
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* cur = new Node(val);
        if (head == NULL) {
            head = cur;
            return;
        }
        Node* p = head;
        while(p && p->next) {
            p = p->next;
        }
        p->next = cur;
        return;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node* cur = new Node(val);
        Node* p = head;
        if (index == 0) {
            cur->next = p;
            head = cur;
            return;
        }
        int cnt = 0;
        while(p != NULL) {
            if (cnt == index - 1) {
                cur->next = p->next;
                p->next = cur;
                break;
            }
            ++cnt;
            p = p->next;
        }
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0) {
            if (head) {
                head = head->next;
            }
        } else {
            Node* p = head;
            int cnt = 0;
            while(p != NULL) {
                if (cnt == index - 1) {
                    if (p->next) {
                        p->next = p->next->next;
                    }
                    break;
                }
                ++cnt;
                p = p->next;
            }
        }
        return;
    }
    
    void display() {
        Node* p = head;
        while(p) {
            cout << p->val << endl;
            p = p->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

int main() {
    MyLinkedList obj;
    obj.addAtHead(10);
    obj.addAtTail(20);
    obj.addAtHead(4);
    obj.addAtIndex(3, 2);
    obj.deleteAtIndex(4);
    cout << obj.get(4) << endl;
    obj.display();
    
    
//    vector<int> a = {1, 4, 4, 5};
//    int ans = s.minSubArrayLen(9, a);
////    for (auto i : a) {
////        cout << i << " ";
////    }
////    cout << endl;
//    cout << ans << endl;
    return 0;
}
