"""
Source: https://leetcode.com/problems/detect-capital/description/
Date: 2023/1/2
Skill:
Runtime: 35 ms, faster than 81.79%
Memory Usage: 13.8 MB, less than 56.30%
Time complexity:
Space complexity:
Constraints:
    1 <= word.length <= 100
    word consists of lowercase and uppercase English letters.
"""

from typing import List

class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        a, capitals = "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        if len(word) == 1: return True
        if word[1] in a:
            for i in range(2, len(word)):
                if word[i] not in a:
                    return False
            return True
        else:
            for i in range(len(word)):
                if word[i] not in capitals:
                    return False
            return True




if __name__ == "__main__":
    s = Solution