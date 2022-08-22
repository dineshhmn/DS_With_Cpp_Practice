//
// Created by Dinesh Hemnani on 8/22/22.
//

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
    vector<int> m;
    while (head){
        m.push_back(head->val);
        head = head->next;
    }
    int n = m.size()-1;
    int l = 0;
    while (l < n){
        if (m[l] != m[n]){
            return false;
        }
        l++;
        n--;
    }
    return true;
    }
};

int main(){
    Solution s;
    ListNode h1 = ListNode(1);
    ListNode h2 = ListNode(2);
    ListNode h3 = ListNode(2);
    ListNode h4 = ListNode(1);
    h1.next = &h2;
    h2.next = &h3;
    h3.next = &h4;
    auto res = s.isPalindrome(&h1);
    if (res){
        cout << "Returning True" << endl;
    }
    else {
        cout << "Returning False" << endl;
    }
}