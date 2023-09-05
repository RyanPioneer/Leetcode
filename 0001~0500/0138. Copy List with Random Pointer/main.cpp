/**
 * Source: https://rb.gy/cegim
 * Date: 2023/9/5
 * Skill:
 * Runtime: 3 ms, faster than 96.91% of C++ online submissions
 * Memory Usage: 11.51 MB, less than 8.55% of C++ online submissions
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
        int idx = 0;
        unordered_map<int, Node*> idx2node;
        unordered_map<Node*, int> node2idx;
        node2idx[head] = 0;
        Node* new_head = new Node(head->val), *node = head;
        Node *cur = new_head;
        idx2node[0] = new_head;
        while (node->next) {
            cur->next = new Node(node->next->val);
            cur = cur->next;
            idx++;
            idx2node[idx] = cur;
            node = node->next;
            node2idx[node] = idx;
        }
        cur = new_head; node = head;
        while (node) {
            if (node->random)
                cur->random = idx2node[node2idx[node->random]];
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