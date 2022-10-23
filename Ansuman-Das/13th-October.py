# There is a singly-linked list head and we want to delete a node node in it.

# You are given the node to be deleted node. You will not be given access to the first node of head.

# All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

# Delete the given node. 


class Solution(object):
    def deleteNode(self, node):
        
        nextNode = node.next
        node.val = nextNode.val
        node.next = nextNode.next
        nextNode.next = None
        del(nextNode)
