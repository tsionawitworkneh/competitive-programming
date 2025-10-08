import math
class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        left = 1
        right = num

        while left <= right:
            mid = math.floor((left+right) / 2)

            if num == mid **2:
                return True
            elif mid**2 < num:
                left = mid + 1
            else:
                right = mid -1
        

        return False
