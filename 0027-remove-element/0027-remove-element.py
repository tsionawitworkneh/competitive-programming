class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        valid_index = 0

        for current_num in nums:

            if current_num != val:
                nums[valid_index] = current_num

                valid_index += 1
        

        return valid_index
        