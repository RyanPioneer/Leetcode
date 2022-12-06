"""
Source: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
Date: 2022/12/2
Skill: 
Runtime: 750 ms, faster than 34.17%
Memory Usage: 15.5 MB, less than 19.57%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= arr.length <= 10^4
    1 <= arr[i] <= 10^5
"""

from typing import List

class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        mx = -1
        for i in reversed(range(len(arr))):
            mx, arr[i] = max(mx,arr[i]), mx
        return arr