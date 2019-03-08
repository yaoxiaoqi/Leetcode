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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        
        // assume n is valid
        while (n) {
            --n;
            fast = fast->next;
        }
        if (fast == NULL) {
            head = head -> next;
        } else {
            while (fast -> next != NULL) {
                slow = slow -> next;
                fast = fast -> next;
            }
            
            if (slow -> next) {
                slow -> next = slow -> next -> next;
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
    head->next = p1;
    p1->next = p2;
    s.display(s.removeNthFromEnd(headB, 1));
    return 0;
}
