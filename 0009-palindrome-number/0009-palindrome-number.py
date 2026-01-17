class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if(x < 0):
            return False
        rev = 0
        temp = x
        while(x > 0):
            d = x % 10
            rev = rev*10 + d
            x = x//10
        if(temp == rev):
            return True
        else:
            return False

        