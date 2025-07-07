class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        cycle = set()

        while n != 1:
            if n in cycle:
                return False

            cycle.add(n)
            n = sum(int(num)**2 for num in str(n))
        return True