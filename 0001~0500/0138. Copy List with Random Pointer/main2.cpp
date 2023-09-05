/**
 * Source: https://rb.gy/cegim
 * Date: 2023/9/5
 * Skill:
 * Runtime: 0 ms, faster than 100% of C++ online submissions
 * Memory Usage: 11.31 MB, less than 32.41% of C++ online submissions
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
        Node* cur = head;
        while (cur) {
            Node *node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            if (!cur->next)
                break;
            cur = cur->next->next;
        }
        Node* new_head = head->next;
        Node* node = new_head;
        head->next = new_head->next;
        cur = head->next;
        while (cur) {
            node->next = cur->next;
            node = node->next;
            cur->next = node->next;
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