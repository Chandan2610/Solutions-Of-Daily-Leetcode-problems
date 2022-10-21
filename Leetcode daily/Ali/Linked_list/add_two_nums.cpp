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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum=new ListNode();
        ListNode *p = sum;
        int carry=0;
        
        while(l1 || l2 || carry){
            int val = 0;
            if(l1){
                val += l1->val;
                l1 =l1->next;
            }
            if(l2){
                val += l2->val;
                l2 =l2->next;
            }
            val += carry;
            carry = val/10;
            ListNode *temp = new ListNode(val%10);
            p->next = temp;
            p =p->next;
            
        }
        return sum->next;
    }
};
