"""
Source: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
Date: 2022/12/2
Skill: 
Runtime: 340 ms, faster than 66.69%
Memory Usage: 15.1 MB, less than 99.79%
Time complexity: 2
Space complexity: 
Constraints: 
    4 <= nums.length <= 10^4
    1 <= nums[i] <= 10^4
"""

from typing import List

class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        a,b,c,d = 0,0,10001,10001
        for n in nums:
            if n > a:
                b = a
                a = n
            elif n > b:
                b = n
            if n < d:
                c = d
                d = n
            elif n < c:
                c = n;
        return a*b-c*d