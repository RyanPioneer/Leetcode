# Source: https://leetcode.com/problems/custom-sort-string/
# Date: 2021/7/14
# Constraints: 
#      order has length at most 26, and no character is repeated in order.
#      str has length at most 200.
#      order and str consist of lowercase letters only.
# blocks can be commented out by Cmd+K, Cmd+C 

from typing import Collection

def customSortString(self, S: str, T: str) -> str:
        ans, cnt = [], Collection.Counter(T)            # count each char in T. 
        for c in S:
            if cnt[c]: ans.extend(c * cnt.pop(c))       # sort chars both in T and S by the order of S.
        for c, v in cnt.items():
            ans.extend(c * v)                           # group chars in T but not in S.
        return ''.join(ans);