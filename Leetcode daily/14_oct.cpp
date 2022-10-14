#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        ListNode *newNode = new ListNode(-1,head);
        ListNode* prev = newNode;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return newNode->next;
    }
};