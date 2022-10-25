// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

ListNode* deleteMiddle(ListNode* head) {
    
    if(head==NULL || head->next==NULL) return NULL;       //if 0 or 1 node is present, return NULL
    
    ListNode *prev=NULL, * slow=head, * fast=head;        //Maintain 3 Pointers; prev, slow, fast
    
    while(fast!=NULL and fast->next!=NULL){                  
        prev=slow;                                        //update prev = slow
        slow=slow->next;                                  //increment slow once, slow = slow->next; 
        fast=fast->next->next;                            //increment fast twice, fast = fast->next->next;
    }
    
    prev->next=slow->next;                                //update connection 
    delete slow;                                          //deleting middle node
    return head;                                          //return head;
}
