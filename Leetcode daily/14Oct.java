class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if(head.next==null){
            return null;
        }
        ListNode fast=head,slow=head,prev=null;
        while(fast!=null && fast.next!=null){
            fast=fast.next.next;
            prev=slow;
            slow=slow.next;
        }
        prev.next=prev.next.next;
        return head;
    }
}
