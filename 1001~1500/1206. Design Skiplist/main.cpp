/**
 * Source: t.ly/ssPRA
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 51 ms, faster than 73.36% of C++ online submissions
 * Memory Usage: 33.59 MB, less than 64.09% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <cstdlib>
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
    Node *next, *down;
    int val;

    Node(int a, Node *b, Node *c) {
        val = a;
        next = b;
        down = c;
    }
};


class Skiplist {
    Node *root;
    vector<Node *> insertPos;
public:
    Skiplist() {
        root = new Node(-1, nullptr, nullptr);
    }

    bool search(int target) {
        Node *cur = root;
        while (cur) {
            while (cur->next && cur->next->val < target) {
                cur = cur->next;
            }
            if (cur->down) cur = cur->down;
            else break;
        }
        return cur->next && cur->next->val == target;
    }

    void add(int num) {
        insertPos.clear();
        bool shouldInsert = true;
        Node *cur = root, *prev = nullptr;
        while (cur) {
            while (cur->next && cur->next->val < num) {
                cur = cur->next;
            }
            insertPos.push_back(cur);
            cur = cur->down;
        }
        while (!insertPos.empty() && shouldInsert) {
            Node *pos = insertPos.back();
            insertPos.pop_back();
            pos->next = new Node(num, pos->next, prev);
            prev = pos->next;
            shouldInsert = (rand() & 1) == 1;
        }
        if (shouldInsert) {
            root = new Node(-1, new Node(num, nullptr, prev), root);
        }
    }

    bool erase(int num) {
        bool found = false;
        Node *cur = root;
        while (cur) {
            while (cur->next && cur->next->val < num) {
                cur = cur->next;
            }
            if (cur->next && cur->next->val == num) {
                found = true;
                Node *i = cur->next;
                cur->next = i->next;
                delete i;
            }
            cur = cur->down;
        }
        return found;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */