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
const int MX = 1e5 + 1;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(begin(nums), end(nums));
        ll left = 0, cnt = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == mx) cnt++;
            if (cnt == k) {
                while (nums[left] != mx) left++;
                res += left + 1;
            } else if (cnt == k + 1) {
                while (nums[left] != mx) left++;
                cnt--;
                left++;
                while (nums[left] != mx) left++;
                res += left + 1;
            }
        }
        return res;
    }
};
