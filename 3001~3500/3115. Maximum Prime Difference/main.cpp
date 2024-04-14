/**
 * Source: is.gd/YSwPrb
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 93 ms, faster than 66.67% of C++ online submissions
 * Memory Usage: 107.54 MB, less than 100.00% of C++ online submissions
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

const int MX = 101;


class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int isPrime[MX] = {0};

        isPrime[1] = 1;
        for (int i = 2; i <= sqrt(MX); i++) {
            if (isPrime[i] == 0) {
                int j = i * i;
                while (j < MX) {
                    isPrime[j] = 1;
                    j += i;
                }
            }
        }

        int left = 0, n = nums.size();

        while (left < n && isPrime[nums[left]]) left++;

        int right = left;

        for (int i = right + 1; i < n; i++) {
            if (!isPrime[nums[i]]) right = i;
        }
        return right - left;
    }

};