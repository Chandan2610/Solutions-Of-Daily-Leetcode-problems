# You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

# The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.


class Solution:
    def deleteMiddle(self, head: ListNode) -> ListNode:

        if not head.next: return None                   

        ptr1, ptr2 = head.next, head                                       

        while ptr1.next and ptr1.next.next:             
            ptr1 = ptr1.next.next                       
            ptr2 = ptr2.next                            
      
        ptr2.next = ptr2.next.next                      

        return head
