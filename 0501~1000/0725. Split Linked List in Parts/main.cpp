/**
 * Source: https://rb.gy/raqpc
 * Date: 2023/9/6
 * Skill:
 * Runtime: 4 ms, faster than 88.44% of C++ online submissions
 * Memory Usage: 8.96 MB, less than 15.59% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        ListNode* node = head;
        int num = 0;
        while (node) {
            num++;
            node = node->next;
        }
        node = head;
        while (node && num > 0) {
            res.push_back(node);
            int count = 1;
            if (k < num)
                count = num / k + (num % k != 0 ? 1 : 0);
            for (int i = 0; i < count - 1; i++)
                node = node->next;
            ListNode* tmp = node->next;
            node->next = nullptr;
            node = tmp;
            num -= count;
            k -= 1;
        }
        for (int i = 0; i < k; i++)
            res.push_back(nullptr);
        return res;
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
    std::multiset<int> mySet = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // Create a reverse iterator to iterate from the end (highest values) to the beginning.
    std::multiset<int>::reverse_iterator rit = mySet.rbegin();

    // Print the top 4 highest values.
    for (int i = 0; i < 4 && rit != mySet.rend(); ++i, ++rit) {
        std::cout << *rit << " ";
    }
}