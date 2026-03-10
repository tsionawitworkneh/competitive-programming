class Solution(object):
    def arraySign(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 1
        for x in nums: 
            if x == 0: return 0 
            if x < 0: ans *= -1
        return ans 