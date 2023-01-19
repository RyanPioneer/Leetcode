"""
Source: https://leetcode.com/problems/maximum-subarray/description/
Date: 2023/1/18
Skill: Divide & Conquer
Ref:
Runtime: 1077 ms, faster than 40.43%
Memory Usage: 80.1 MB, less than 5.91%
Time complexity:
Space complexity:
Constraints:
    -10^4 <= nums[i] <= 10^4
"""

from typing import List, Optional
import math

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sz = len(nums)
        left_max, right_max = [nums[i] for i in range(sz)], [nums[i] for i in range(sz)]
        for i in range(1, sz):
            if left_max[i-1] > 0: left_max[i] += left_max[i-1]
            if right_max[sz-i] > 0: right_max[sz-i-1] += right_max[sz-i]

        def max_sub_array(l, r):
            if l > r: return -math.inf
            if l == r: return nums[l]
            mid = (l+r)//2
            return max(max_sub_array(l, mid-1), max_sub_array(mid+1, r), left_max[mid] + max(0, right_max[mid+1]))

        return max_sub_array(0, sz-1)

if __name__ == "__main__":
    s = Solution
    nums = [5,4,-1,7,8]
    print(s.maxSubArray(s, nums))