"""
Source: https://leetcode.com/problems/maximum-tastiness-of-candy-basket/
Date: 2023/1/7
Skill:
Ref:
Runtime: 1556 ms, faster than 71.1%
Memory Usage: 26 MB, less than 33.1%
Time complexity:
Space complexity:
Constraints:
    2 <= k <= price.length <= 10^5
"""

from typing import List, Optional

class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()
        left, right = 0, (price[-1] - price[0]) // (k-1)

        def check(num):
            n, diff = 1, num
            for index in range(1, len(price)):
                diff -= price[index] - price[index-1]
                if diff <= 0:
                    n += 1
                    if n == k: return True
                    diff = num

            return False

        while left < right:
            mid = (left+right+1)//2
            ans = check(mid)
            if ans: left = mid
            else: right = mid-1

        return left