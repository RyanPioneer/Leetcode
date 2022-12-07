"""
Source: https://leetcode.com/problems/top-k-frequent-elements/
Date: 2022/12/7
Skill: 
Runtime: 1014 ms, faster than 87.36% 
Memory Usage: 18.5 MB, less than 91.95%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 10^5
"""

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import Counter
        c=[x[0] for x in list(Counter(nums).most_common(k))]
        return c