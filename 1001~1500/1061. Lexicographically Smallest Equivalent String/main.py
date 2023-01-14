"""
Source: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
Date: 2023/1/14
Skill:
Ref:
Runtime: 49 ms, faster than 64.37%
Memory Usage: 13.9 MB, less than 56.90%
Time complexity:
Space complexity:
Constraints:
    s1, s2, and baseStr consist of lowercase English letters.
"""

from typing import List, Optional
from collections import defaultdict


class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        representation, res = [i for i in range(26)], ""

        def find_parent(child):
            if representation[child] == child: return child
            if representation[child] != child:
                representation[child] = find_parent(representation[child])
                return representation[child]

        for i in range(len(s1)):
            if find_parent(ord(s1[i]) - ord("a")) < find_parent(ord(s2[i]) - ord("a")):
                representation[find_parent(ord(s2[i]) - ord("a"))] = find_parent(ord(s1[i]) - ord("a"))
            elif find_parent(ord(s1[i]) - ord("a")) > find_parent(ord(s2[i]) - ord("a")):
                representation[find_parent(ord(s1[i]) - ord("a"))] = find_parent(ord(s2[i]) - ord("a"))

        for w in baseStr:
            res += chr(find_parent(ord(w) - ord("a"))+ord("a"))

        return res

if __name__ == "__main__":
    s = Solution
    s1 = "leetcode"
    s2 = "programs"
    baseStr = "sourcecode"
    res = s.smallestEquivalentString(s, s1, s2, baseStr)