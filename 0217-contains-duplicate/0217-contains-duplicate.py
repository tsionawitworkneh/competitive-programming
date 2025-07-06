class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        list_length = len(nums)
        set_length = len(set(nums))

        if(set_length < list_length):
            return True
        else:
            return False