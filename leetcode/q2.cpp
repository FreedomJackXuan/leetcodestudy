//
// Created by jac on 18-12-6.
//


//  Definition for singly-linked list
//

/*
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int tmp = 0;
        ListNode *listNode = new ListNode(0);
        ListNode *tail = listNode;
        ListNode *p = l1;
        ListNode *q = l2;
        while (p != NULL || q != NULL) {
            int i = (p!=NULL) ? p->val : 0;
            int j = (q!=NULL) ? q->val : 0;
            int sum = i + j + tmp;
            int s = sum % 10;
            tmp = sum / 10;
            tail->next = new ListNode(s);
            tail = tail->next;
            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
        }
        if (tmp > 0) {
            tail->next = new ListNode(tmp);
        }
        return listNode->next;
    }
};