//
// Created by Dinesh Hemnani on 8/21/22.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ret;
        ListNode r = ret;
        int carry=0;
        while (l1 or l2) {
            int vl1 = l1->val == 0 ? 0 : l1->val;
            int vl2 = l2->val == 0 ? 0 : l2->val;
            int sum = vl1 + vl2 + carry;
            carry = sum % 10;
            if (carry > 0){
                ret.val = 0;
            }
            else {
                ret.val = sum;
            }
            l1 = l1->next;
            l2 = l2->next;
            ListNode n;
            ret.next = &n;
            ret = *ret.next;
        }
        return r.next;
    }
};

void ll_printer(ListNode* l1){
    while (l1->val != 0){
        cout << l1->val << endl;
        l1 = l1->next;
    }
    cout << "Done" << endl;
}

int main(){
    // INCOMPLETE
    Solution s;
    ListNode l1 = {2};
    ListNode l2 = {4};
    ListNode l3 = {3};
    l1.next = &l2;
    l2.next = &l3;
    ListNode h1 = {5};
    ListNode h2 = {6};
    ListNode h3 = {4};
    h1.next = &h2;
    h2.next = &h3;
    auto res = s.addTwoNumbers(&l1,&h1);
    ll_printer(res);
//    ll_printer(&h1);
    cout << "Done" << endl;
}
