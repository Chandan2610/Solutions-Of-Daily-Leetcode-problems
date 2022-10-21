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
    
    ListNode* reverse(ListNode* head){
        ListNode *prev=NULL,*next=NULL;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode *slow = head,*fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverse(slow->next);
        
        slow = slow->next;
        fast = head;
        
        while(slow){
            cout<<slow->val<<" "<<fast->val<<endl;
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
