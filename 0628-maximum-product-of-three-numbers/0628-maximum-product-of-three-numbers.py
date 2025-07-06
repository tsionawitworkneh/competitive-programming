class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        max_pro1 = nums[-1] * nums[-2] * nums[-3]
        max_pro2 = nums[0] * nums[1] * nums[-1]

        result = max(max_pro1,max_pro2)

        return result
        