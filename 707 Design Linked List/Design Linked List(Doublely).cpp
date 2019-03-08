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
        Node *prev, *next;
        Node(int x): val(x), prev(NULL), next(NULL) {}
    };
    Node *head, *tail;
    int size;
    
    /** Initialize your data structure here. */
    MyLinkedList() : head(NULL), tail(NULL), size(0) {
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size) {
            return -1;
        }
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
        if (head == NULL) {
            head = tail = cur;
        } else {
            cur->next = head;
            head->prev = cur;
            head = cur;
        }
        ++size;
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* cur = new Node(val);
        if (head == NULL) {
            head = tail = cur;
            return;
        }
        tail -> next = cur;
        cur -> prev = tail;
        tail = cur;
        ++size;
        return;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        Node* cur = new Node(val);
        Node* p = head;
        if (index == 0) {
            addAtHead(val);
            return;
        } else if (index == size) {
            addAtTail(val);
            return;
        } else {
            int cnt = 0;
            while (p) {
                if (cnt == index - 1) {
                    cur->next = p->next;
                    p->next->prev = cur;
                    cur->prev = p;
                    p->next = cur;
                    break;
                }
                ++cnt;
                p = p->next;
            }
            ++size;
        }
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        if (index == 0) {
            if (head) {
                head = head->next;
                if (head) {
                    head->prev = NULL;
                }
            }
        } else if (index == size - 1) {
            tail = tail->prev;
            if (tail) {
                tail->next = NULL;
            }
        } else {
            Node* p = head;
            int cnt = 0;
            while(p != NULL) {
                if (cnt == index - 1) {
                    if (p->next) {
                        p->next = p->next->next;
                        if (p->next) {
                            p->next->prev = p;
                        }
                    }
                    break;
                }
                ++cnt;
                p = p->next;
            }
        }
        --size;
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

int main() {
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
//    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 1);
//    linkedList.get(1);
//    linkedList.deleteAtIndex(1);
    linkedList.display();
    return 0;
}
