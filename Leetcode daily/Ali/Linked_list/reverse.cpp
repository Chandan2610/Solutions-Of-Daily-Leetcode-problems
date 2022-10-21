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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *d=NULL;
        if(head==NULL || head->next == NULL)
            return head;
        ListNode *q = head->next;
        while(head){
            head->next = d;
            d = head;
            head = q;
            if(q)
                q = q->next;
        }
        return d;
    }
};
