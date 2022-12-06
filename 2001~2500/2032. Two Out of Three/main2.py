"""
Source: https://leetcode.com/problems/two-out-of-three/
Date: 2022/12/3
Skill: 
Runtime: 67 ms, faster than 98.90%
Memory Usage: 13.8 MB, less than 83.23% 
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
        cnt = Counter()
        for nums in nums1, nums2, nums3: cnt.update(set(nums))
        return [key for key, freq in cnt.items() if freq >= 2]