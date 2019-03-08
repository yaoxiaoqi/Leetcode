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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* p = head;
        while (p -> next) {
            p = p -> next;
        }
        ListNode* oldtail = p;
        ListNode* tail = oldtail;
        ListNode* odd = head;
        ListNode* even;
        
        while (true) {
            if (odd == oldtail) {
                return head;
            }
            even = odd -> next;
            if (odd->next->next) {
                odd -> next = odd -> next -> next;
                odd = odd->next;
            }
            tail -> next = even;
            even -> next = NULL;
            tail = even;
            if (even == oldtail) {
                return head;
            }
        }
        return head;
    }
    
    void display(ListNode* head) {
        while (head) {
            cout << head -> val << " ";
            head = head -> next;
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* headB = new ListNode(10);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(4);
    head->next = p1;
//    p1->next = p2;
//    p2->next = headB;
//    headB->next = p3;
    s.display(s.oddEvenList(head));
    return 0;
}
