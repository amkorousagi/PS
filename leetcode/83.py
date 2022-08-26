# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        temp = head.next
        prior = head
        while temp != None:
            # print(str(temp.val))
            # print(str(temp.next))
            if prior.val == temp.val:
                if temp.next == None:
                    prior.next = None
                    return head
                prior.next = temp.next
                temp = temp.next
                continue
            prior = temp
            temp = temp.next
        return head