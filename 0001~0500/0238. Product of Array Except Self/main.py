"""
Source: https://leetcode.com/problems/product-of-array-except-self/description/
Date: 2023/1/19
Skill:
Ref:
Runtime: 233 ms, faster than 88.64%
Memory Usage: 21.2 MB, less than 90.28%
Time complexity:
Space complexity:
Constraints:
    -30 <= nums[i] <= 30
"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product_of_array, zero_num, res = 1, 0, []
        for i in range(len(nums)):
            if nums[i] != 0:
                product_of_array *= nums[i]
            else:
                zero_num += 1

        if zero_num >= 2: return [0 for _ in range(len(nums))]

        for i in range(len(nums)):
            if zero_num == 0:
                res.append(product_of_array//nums[i])
            else:
                if nums[i] != 0: res.append(0)
                else: res.append(product_of_array)

        return res

if __name__ == "__main__":
    s = Solution
    nums = [0,-5]
    print(s.subarraysDivByK(s, nums, 10))