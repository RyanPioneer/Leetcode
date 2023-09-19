/**
 * Source: https://rb.gy/so1mr
 * Date: 2023/9/18
 * Skill:
 * Runtime: 51 ms, faster than 68.09% of C++ online submissions
 * Memory Usage: 32.45 MB, less than 48.37% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m, n <= 500
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
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int sz1 = nums1.size(), sz2 = nums2.size();
        for (int i = max(0, k - sz2); i <= sz1 && k - i >= 0; i++) {
            int space1 = sz1 - i, space2 = sz2 - (k - i);
            vector<int> arr1 = helper(space1, nums1), arr2 = helper(space2, nums2);
            vector<int> cur_res;
            int l1 = arr1.size(), l2 = arr2.size(), pos1 = 0, pos2 = 0;
            while (pos1 < l1 && pos2 < l2) {
                if (arr1[pos1] > arr2[pos2])
                    cur_res.push_back(arr1[pos1++]);
                else if (arr1[pos1] < arr2[pos2])
                    cur_res.push_back(arr2[pos2++]);
                else {
                    if (pos1 == l1 - 1)
                        cur_res.push_back(arr2[pos2++]);
                    else if (pos2 == l2 - 1)
                        cur_res.push_back(arr1[pos1++]);
                    else if (arr1[pos1 + 1] > arr2[pos2 + 1])
                        cur_res.push_back(arr1[pos1++]);
                    else if (arr1[pos1 + 1] < arr2[pos2 + 1])
                        cur_res.push_back(arr2[pos2++]);
                    else {
                        if (arr1[pos1] > arr1[pos1 + 1])
                            cur_res.push_back(arr1[pos1++]);
                        else {
                            int t1 = pos1, t2 = pos2;
                            while (t1 < l1 && t2 < l2 && arr1[t1] == arr2[t2]) {
                                t1++; t2++;
                            }
                            if (t2 == l2)
                                cur_res.push_back(arr1[pos1++]);
                            else if (t1 == l1)
                                cur_res.push_back(arr2[pos2++]);
                            else if (arr1[t1] > arr2[t2])
                                cur_res.push_back(arr1[pos1++]);
                            else
                                cur_res.push_back(arr2[pos2++]);
                        }
                    }
                }
            }
            while (pos1 < l1)
                cur_res.push_back(arr1[pos1++]);
            while (pos2 < l2)
                cur_res.push_back(arr2[pos2++]);
            res = max(res, cur_res);    // Note
        }
        return res;
    }
    vector<int> helper(int space, vector<int>& nums) {
        int sz = nums.size();
        deque<int> q;
        for (int i = 0; i < sz; i++) {
            while (!q.empty() && nums[i] > q.back() && space > 0) {
                q.pop_back();
                space--;
            }
            q.push_back(nums[i]);
        }
        while (space) {
            q.pop_back();
            space--;
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop_front();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums1{3,9,9,6,9,6,2,1,1,7,7,7,1,4,9,9,6,9,5,3,6,4,6,3,8,2,5,1,1,7,9,2,3,7,4,0,3,4,4,0,2,6,7,3,0,8,8,8,6,0,1,7,8,0,2,7,5,8,7,5,2,4,0,7,3,6,3,6,3,9,6,8,1,6,9,6,2,5,9,5,1,9,2,1,4,0,7,9,8,0,4,1,0,8,7,9,7,6,6,8,8,8,3,7,5,3,2,0,4,9,1,1,3,4,9,7,9,8,4,9,6,4,7,1,9,7,4,0,4,6,0,2,0,8,9,3,0,9,9,2};
    vector<int> nums2{8,8,9,1,6,3,0,4,1,4,1,8,0,3,1,2,7,9,3,2,5,5,2,7,9,5,2,2};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
    vector<int> res = s.maxNumber(nums1, nums2, 140);
    for (auto i: res)
        cout << i << endl;
}