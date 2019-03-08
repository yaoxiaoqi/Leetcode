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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            ++len;
        }
        
        ListNode* q = head;
        for (int i = 0; i < len / 2; i++) {
            q = q -> next;
        }
        
        ListNode* prev = NULL;
        while (q) {
            ListNode* tmp = q;
            q = q -> next;
            tmp -> next = prev;
            prev = tmp;
        }
        
        while (prev && head) {
            if (head->val != prev->val) {
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;
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
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(1);
    ListNode* p4 = new ListNode(3);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
//    p3->next = p4;
//    s.display(s.isPalindrome(head));
    cout << s.isPalindrome(head) << endl;
    return 0;
}
