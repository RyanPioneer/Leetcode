/**
 * Source: t.ly/2XmFi
 * Date: 2024/6/2
 * Skill:
 * Ref:
 * Runtime: 27 ms, faster than 67.60% of C++ online submissions
 * Memory Usage: 25.14 MB, less than 29.47% of C++ online submissions
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

typedef pair<int, int> PII;
#define MK make_pair
const int MX = 1e2+2;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> n(begin(nums), end(nums));
        int res = 0;
        while (head) {
            if (n.find(head->val) != end(n)) {
                res++;
                while (head->next && n.find(head->next->val) != end(n)) {
                    head = head->next;
                }
            }
            head = head->next;
        }
        return res;
    }
};