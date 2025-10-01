class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        strs.sort()

        first = strs[0]
        last = strs[-1]
        minLength = min(len(first), len(last))

        i = 0

        while i < minLength and first[i] == last[i]:
            i += 1

        return first[:i]