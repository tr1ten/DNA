#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX_CHILD 27
struct TrieNode
{
    TrieNode *childrens[MAX_CHILD] = {nullptr};
    bool terminal;
    TrieNode(bool terminal = false) : terminal(terminal){};
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        auto temp = root;
        for (auto c : word)
        {
            int val = c - 'a';
            auto child = temp->childrens[val];
            if (child)
            {
                temp = child;
            }
            else
            {
                temp->childrens[val] = new TrieNode(false);
                temp = temp->childrens[val];
            }
        }
        temp->terminal = true;
    }

    bool search(string word)
    {
        auto temp = root;
        for (auto c : word)
        {
            int val = c - 'a';
            auto child = temp->childrens[val];
            if (child)
            {
                temp = child;
            }
            else
            {
                return false;
            }
        }
        return temp->terminal;
    }

    bool startsWith(string prefix)
    {
        auto temp = root;
        for (auto c : prefix)
        {
            int val = c - 'a';
            auto child = temp->childrens[val];
            if (child)
            {
                temp = child;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{

    return 0;
}