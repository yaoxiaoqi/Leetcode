class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* output = new ListNode(0);
        ListNode* tail = output;
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        while(a) {
            tail->next = a;
            a = a->next;
            tail = tail->next;
        }
        while(b) {
            tail->next = b;
            b = b->next;
            tail = tail->next;
        }
        return output->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        while (lists.size() > 1) {
            int i = 0, j = lists.size()-1;
            for (; i < j; i++, j--) {
                lists[i] = merge(lists[i], lists[j]);
            }
            lists.resize(j+1);
        }
        return lists[0];
    }
};
