class Solution(object):
    def isUgly(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n < 1:
            return False
        
        prime_factors = [2,3,5]

        for factor in prime_factors:

            while n % factor == 0:
                n /= factor
        
        return n ==1