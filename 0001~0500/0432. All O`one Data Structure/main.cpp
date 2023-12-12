/**
 * Source: is.gd/OvCmgP
 * Date: 2023/12/12
 * Skill:
 * Ref:
 * Runtime: 99 ms, faster than 80.67% of C++ online submissions
 * Memory Usage: 55.79 MB, less than 40.24% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


class Node {
public:
    unordered_set<string> str;
    int cnt;
    Node *next = nullptr, *prev = nullptr;
    Node (int n) : cnt(n){}
};

class AllOne {
    Node *head, *tail;
    unordered_map<string, Node *> mp;
public:
    AllOne() {
        head = new Node(0);
        tail = head;
    }

    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            if (head->next == nullptr) {
                Node *a = new Node(1);
                head->next = a;
                a->prev = head;
                tail = a;
            } else if (head->next->cnt != 1) {
                Node *a = new Node(1);
                a->prev = head;
                a->next = head->next;
                head->next->prev = a;
                head->next = a;
            }
            head->next->str.insert(key);
            mp[key] = head->next;
            return;
        }
        Node * cur = mp[key];
        if (cur->next == nullptr) {
            Node *a = new Node(cur->cnt + 1);
            cur->next = a;
            a->prev = cur;
        } else if (cur->next->cnt != cur->cnt + 1) {
            Node *a = new Node(cur->cnt + 1);
            a->prev = cur;
            a->next = cur->next;
            cur->next->prev = a;
            cur->next = a;
        }
        cur->str.erase(key);
        cur->next->str.insert(key);
        mp[key] = cur->next;
        if (cur->next->next == nullptr) tail = cur->next;
        if (cur->str.size() == 0) {
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
        }
    }

    void dec(string key) {
        Node * cur = mp[key];
        cur->str.erase(key);
        mp.erase(key);
        if (cur->cnt != 1) {
            if (cur->prev->cnt != cur->cnt - 1) {
                Node *a = new Node(cur->cnt - 1);
                a->next = cur;
                a->prev = cur->prev;
                cur->prev->next = a;
                cur->prev = a;
            }
            cur->prev->str.insert(key);
            mp[key] = cur->prev;
        }
        if (cur->str.size() == 0) {
            cur->prev->next = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            else tail = cur->prev;
        }
    }

    string getMaxKey() {
        if (tail->cnt == 0) return "";
        return *tail->str.begin();
    }

    string getMinKey() {
        if (head->next == nullptr) return "";
        return *(head->next->str.begin());
    }
};