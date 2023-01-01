"""
Source: https://leetcode.com/problems/next-greater-element-i/description/
Date: 2022/12/18
Skill: 
Runtime: 56 ms, faster than 86.4% 
Memory Usage: 14.2 MB, less than 56.82%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums1.length <= nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 10^4
    All integers in nums1 and nums2 are unique.
    All the integers of nums1 also appear in nums2.
"""

from typing import List
from collections import defaultdict

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans, dict, res = [-1]*len(nums2), defaultdict(int), []
        for cur in range(len(nums2)-1, -1, -1):
            next = cur+1
            while next < len(nums2) and nums2[next] <= nums2[cur]:
                next += ans[next] if ans[next] != -1 else len(nums2)
            ans[cur] = next-cur if next < len(nums2) else -1
            dict[nums2[cur]] = nums2[next] if next < len(nums2) else -1
        
        for index in range(len(nums1)):
            res.append(dict[nums1[index]])
        
        return res