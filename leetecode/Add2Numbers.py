class Solution:
    def mergeTwoLists(self, l1, l2):
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        pointer_1 = l1
        pointer_2 = l2
        sort_pointer = None

        if pointer_1.val < pointer_2.val:
            sort_pointer = pointer_1
            pointer_1 = pointer_1.next
        else:
            sort_pointer = pointer_2
            pointer_2 = pointer_2.next
        head = sort_pointer
        while pointer_1 or pointer_2:
            if pointer_1 is None:
                sort_pointer.next = pointer_2
                break
            if pointer_2 is None:
                sort_pointer.next = pointer_1
                break
            if pointer_1.val < pointer_2.val:
                sort_pointer.next = pointer_1
                pointer_1 = pointer_1.next
            else:
                sort_pointer.next = pointer_2
                pointer_2 = pointer_2.next
            print('Sort pointer :', sort_pointer.val)
            sort_pointer = sort_pointer.next
        return head
