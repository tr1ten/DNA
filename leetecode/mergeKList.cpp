#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
    {
        return list2;
    }
    else if (!list2)
    {
        return list1;
    }
    else
    {
        ListNode *nhead;
        if (list1->val < list2->val)
        {
            nhead = list1;
            list1 = list1->next;
        }
        else
        {
            nhead = list2;
            list2 = list2->next;
        }
        ListNode *temp = nhead;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (!list1 && !list2)
        {
            return nhead;
        }
        temp->next = list1 ? list1 : list2;
        return nhead;
    }
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *prev = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        prev = mergeTwoLists(prev, lists[1]);
    }
    return prev;
}
