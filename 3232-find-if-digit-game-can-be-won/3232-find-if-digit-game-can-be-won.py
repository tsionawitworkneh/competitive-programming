class Solution(object):
    def canAliceWin(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        count1 = 0
        count2 = 0
        for num in nums:
            if num < 10:
                count1 +=num
            else:
                count2 +=num
        return count1 != count2 
        