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
    int getListLength(ListNode* head) {
        if (head == NULL) {
            return 0;
        }
        ListNode* p = head;
        int cnt = 0;
        while (p) {
            ++cnt;
            p = p->next;
        }
        return cnt;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        ListNode* p = headA;
        ListNode* q = headB;
        if (lenA > lenB) {
            int diff = lenA - lenB;
            for (int i = 0; i < diff; i++) {
                p = p -> next;
            }
        } else if (lenA < lenB) {
            int diff = lenB - lenA;
            for (int i = 0; i < diff; i++) {
                q = q -> next;
            }
        }
        
        while (p && q && (p != q)) {
            p = p -> next;
            q = q -> next;
        }
        if (p && q) {
            return p;
        }
        return NULL;
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
    headB -> next = p1;
    cout << s.getIntersectionNode(head, headB) << endl;
    return 0;
}
