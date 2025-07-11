class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        for i in range(size):
            min_idx = i
            for j in range(i+1,size):
                if nums[min_idx] > nums[j]:
                    min_idx = j
            
            nums[min_idx],nums[i] = nums[i],nums[min_idx]
        