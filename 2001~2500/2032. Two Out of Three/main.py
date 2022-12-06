"""
Source: https://leetcode.com/problems/two-out-of-three/
Date: 2022/12/3
Skill: 
Runtime: 135 ms, faster than 68.66% 
Memory Usage: 14 MB, less than 35.83%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums1.length, nums2.length, nums3.length <= 100
    1 <= nums1[i], nums2[j], nums3[k] <= 100
"""

from typing import List
from collections import Counter

class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        s1, s2, s3 = set(nums1), set(nums2), set(nums3)
        return (s1&s2) | (s2&s3) | (s1&s3)