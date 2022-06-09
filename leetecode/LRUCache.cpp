#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>
#include <unordered_set>
using namespace std;
class LRUCache
{
    int _capacity;
    int _count;
    unordered_set<int> qm;
    deque<int> q;
    unordered_map<int, int> hm;
    void addToQueue(int key)

    {
        if (qm.count(key))
        {

            for (auto iter = q.begin(); iter != q.end();)
            {
                if (*iter == key)
                {
                    q.erase(iter);
                    qm.erase(key);
                    break;
                }
                else
                {
                    iter++;
                }
            }
        }
        q.push_back(key);
        qm.insert(key);
    }

public:
    LRUCache(int capacity) : _capacity(capacity), _count(0) {}

    int get(int key)
    {
        if (hm.count(key))
        {
            this->addToQueue(key);
            return hm[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (hm.count(key))
        {
            hm[key] = value;
            this->addToQueue(key);
            return;
        }
        if (this->_count >= this->_capacity)
        {
            int lkey = q.front();
            q.pop_front();
            hm.erase(lkey);
            this->_count--;
        }
        hm[key] = value;
        this->addToQueue(key);
        this->_count++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{

    return 0;
}
