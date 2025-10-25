class Solution(object):
    def totalMoney(self, n):
        """
        :type n: int
        :rtype: int
        """
        w = n // 7
        r = n % 7
        sum_full = 7 * w * (w + 7) // 2
        sum_rem = r * (w + 1) + r * (r - 1) // 2
        return sum_full + sum_rem
        