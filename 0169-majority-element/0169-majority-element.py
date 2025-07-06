class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        if len(nums) < 3:
            return nums[0]
        if len(nums) % 2 != 0:
            return nums[(len(nums)//2)]

        return nums[(len(nums)//2)]