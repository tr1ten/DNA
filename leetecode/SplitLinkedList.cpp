#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<int> ll;
    ListNode *temp = head;
    while (temp)
    {
        ll.push_back(temp->val);
        temp = temp->next;
    }
    int lsize = ll.size();
    int epart = lsize / k;
    int counter = lsize % k;
    int i = 0;
    vector<ListNode *> res;
    while (i < lsize)
    {
        int j = i;
        if (counter > 0)
        {
            i += epart + 1;
            counter--;
        }
        else
        {
            i += epart;
        }
        ListNode *tempHead = nullptr;
        ListNode *temp = nullptr;
        while (j < i)
        {
            if (tempHead)
            {
                temp->next = new ListNode(ll[j]);
                temp = temp->next;

            }
            else
            {
                tempHead = new ListNode(ll[j]);
                temp = tempHead;
            }
            j++;
        }
        res.push_back(tempHead);
    }
    while (res.size() < k)
    {
        res.push_back(nullptr);
    }
    return res;
}
int main()
{
    ListNode head = ListNode(1);
    ListNode f = ListNode(2);
    ListNode s = ListNode(3);
    f.next = &s;
    head.next = &f;
    auto res = splitListToParts(&head, 5);
    cout<< res[0]->val;
    return 0;
}
