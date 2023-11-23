/**
 * Source: is.gd/klqugv
 * Date: 2023/11/23
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 98.08% of C++ online submissions
 * Memory Usage: 10.08 MB, less than 92.39% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
ll mod = 1e9+7;
const int MX = 500 + 2;


class BIT {
public:
    int arr[MX] = {0};

    void update(int idx, int num) {
        while (idx < MX) {
            arr[idx] = max(num, arr[idx]);
            idx += idx & -idx;
        }
    }

    int query_max(int idx) {
        int num = 0;
        while (idx > 0) {
            num = max(num, arr[idx]);
            idx -= idx & -idx;
        }
        return num;
    }
};


class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = SZ(nums1), len2 = SZ(nums2), res = 0;
        BIT *tree = new BIT();
        for (int i = 0; i < len1; i++) {
            for (int j = len2 - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    int num = tree->query_max(j) + 1;
                    res = max(res, num);
                    tree->update(j + 1, num);
                }
            }
        }
        return res;
    }
};