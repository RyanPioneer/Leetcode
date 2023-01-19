"""
Source: https://leetcode.com/problems/subarray-sums-divisible-by-k/
Date: 2023/1/19
Skill: Prefix Sums and Counting
Ref:
Runtime: 289 ms, faster than 96.94%
Memory Usage: 18.9 MB, less than 63.55%
Time complexity:
Space complexity:
Constraints:
    -10^4 <= nums[i] <= 10^4
"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        res, sz, my_dict, cur_sum = 0, len(nums), defaultdict(int), 0
        my_dict[0] = 1
        for num in nums:
            cur_sum = (num+cur_sum)%k
            res += my_dict[cur_sum]
            my_dict[cur_sum] += 1

        return res

if __name__ == "__main__":
    s = Solution
    nums = [0,-5]
    print(s.subarraysDivByK(s, nums, 10))