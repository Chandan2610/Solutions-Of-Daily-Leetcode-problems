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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 || !list2)
            return list1? list1 : list2;
        
        if(list2->val < list1->val){
            ListNode *temp=list1;
            list1 = list2;
            list2 = temp;
        }
        ListNode *head = list1;
        
        while(list1->next && list2){
            if(list2->val <= list1->next->val){
                ListNode *temp = list2;
                list2 = list2->next;
                temp->next = list1->next;
                list1->next = temp;
            }
            list1 = list1->next;
        }
        if(list2){
            list1->next = list2;
        }
        return head;
    }
};/**
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 || !list2)
            return list1? list1 : list2;
        
        if(list2->val < list1->val){
            ListNode *temp=list1;
            list1 = list2;
            list2 = temp;
        }
        ListNode *head = list1;
        
        while(list1->next && list2){
            if(list2->val <= list1->next->val){
                ListNode *temp = list2;
                list2 = list2->next;
                temp->next = list1->next;
                list1->next = temp;
            }
            list1 = list1->next;
        }
        if(list2){
            list1->next = list2;
        }
        return head;
    }
}
