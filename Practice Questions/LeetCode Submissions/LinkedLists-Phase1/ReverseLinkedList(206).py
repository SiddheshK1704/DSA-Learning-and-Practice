'''
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode | None) -> ListNode | None:
        t1=head
        t2=None
        while(t1!=None):
            c=t1.next #for the next node
            t1.next=t2 #to make it point to none in the first iteration, then where t2 is in the next iterations(reverse the pointer)
            t2=t1 #t2 becomes what t1 is now(current node)
            t1=c #and t1 goes to its next node. CYCLE KEEPS REPEATING UNTIL T1 REACHES NULL
        return t2

        '''
          while t1 != None:

            c = t1.next       # SAVE the next node
            t1.next = t2      # REVERSE the pointer
            t2 = t1           # MOVE t2 to current node
            t1 = c            # MOVE t1 to the saved next node

        return t2'''
                 