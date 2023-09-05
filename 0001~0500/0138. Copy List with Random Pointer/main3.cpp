/**
 * Source: https://rb.gy/cegim
 * Date: 2023/9/5
 * Skill:
 * Runtime: 3 ms, faster than 96.91% of C++ online submissions
 * Memory Usage: 11.29 MB, less than 60.38% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      0 <= n <= 1000
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        unordered_map<Node*, Node*> old2new;
        Node* new_head = new Node(head->val), *node = head;
        Node *cur = new_head;
        old2new[head] = new_head;
        while (node->next) {
            cur->next = new Node(node->next->val);
            cur = cur->next;
            node = node->next;
            old2new[node] = cur;
        }
        cur = new_head; node = head;
        while (node) {
            if (node->random)
                cur->random = old2new[node->random];
            node = node->next;
            cur = cur->next;
        }
        return new_head;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    string ss = "1101111";
}