//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/23.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* ans_header = ans;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = 0;
            if (l1 != NULL && l2 != NULL) {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 != NULL) {
                sum = l1->val + carry;
                l1 = l1->next;
            } else {
                sum = l2->val + carry;
                l2 = l2->next;
            }
            carry = sum / 10;
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
        }
        
        if (carry > 0) {
            ans->next = new ListNode(carry);
        }
        return ans_header->next;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(8);
    ListNode* a = s.addTwoNumbers(l1, l2);
    while(a!=NULL) {
        cout << a->val << " ";
        a = a->next;
    }
    cout << endl;
    return 0;
}
