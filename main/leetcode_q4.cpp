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
#define MK(X, Y) make_pair(X, Y)
typedef pair<int, int> PII;
typedef pair<char, char> PCC;
ll mod = 1e9+7;
const int MX = 1e5+1;


class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size(), mi = INT32_MAX;
        vector<int> nums2;
        for (int i = 0; i < n; i++) nums2.push_back(i);
        vector<int> res = nums2;

        function<void(int)> dfs = [&](int pos) {
            if (pos == n) {
                int num = 0;
                for (int i = 0; i < n; i++) {
                    num += abs(nums2[i] - nums[nums2[(i + 1) % n]]);
                }
                if (num <= mi) {
                    if (num < mi) {
                        for (int i = 0; i < n; i++) {
                            res[i] = nums2[i];
                        }
                    } else {
                        bool change = false;
                        for (int i = 0; i < n; i++) {
                            if (nums2[i] == res[i]) continue;
                            if (nums2[i] < res[i]) change = true;
                            break;
                        }
                        if (change) {
                            for (int i = 0; i < n; i++) {
                                res[i] = nums2[i];
                            }
                        }
                    }
                    mi = num;
                }
                return;
            }
            for (int i = pos; i < n; i++) {
                swap(nums2[pos], nums2[i]);
                dfs(pos + 1);
                swap(nums2[pos], nums2[i]);
            }
        };

        dfs(0);
        return res;
    }
};