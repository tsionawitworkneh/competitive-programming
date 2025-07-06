class Solution(object):
    def buildArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = [0] * len(nums)
        for i in range(len(nums)):
            result[i] = nums[nums[i]]
        return result
        