"""
Source: https://leetcode.com/problems/shuffle-the-array/
Date: 2022/12/6
Skill: ni = V/M, n2i = V%M
Runtime: 66 ms, faster than 86.9% 
Memory Usage: 14.1 MB, less than 91.31%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= n <= 500
    nums.length == 2n
    1 <= nums[i] <= 10^3
"""

from typing import List

class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        upper_bound = 1001
        for i in range(n,2*n):
            nums[i] += upper_bound * nums[i-n]
        for i in range(n):
            nums[2*i] = nums[n+i]//upper_bound
            nums[2*i+1] = nums[n+i]%upper_bound
        return nums