#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode *head)
{
    vector<int> bin;
    ListNode *temp = head;
    while (temp)
    {
        bin.push_back(temp->val);
        temp = temp->next;
    }
    int n = bin.size();
    int num=0;
    for (int i = n-1; i >=0; i--)
    {
        num +=pow(2,n-1-i)*bin[i];
    }
    return num;
    
    
}
int main()
{

    return 0;
}
