class Solution(object):
    def averageValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        s, c = 0, 0
        for num in nums:
            if num % 6 == 0:
                s +=num
                c +=1
        return s // c if c > 0 else 0
        