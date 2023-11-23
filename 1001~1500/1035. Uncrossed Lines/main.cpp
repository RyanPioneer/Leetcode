/**
 * Source: is.gd/klqugv
 * Date: 2023/11/23
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
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
const int MX = 500 + 2;


class BIT {
public:
    int arr[MX] = {0};

    void update(int idx, int num) {
        for (; idx < MX; idx += idx & -idx) {
            arr[idx] = max(num, arr[idx]);
        }
    }

    int query_max(int idx) {
        int num = 0;
        for (; idx > 0; idx -= idx & -idx) {
            num = max(num, arr[idx]);
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