class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        previous_step,current_step = 0, 1

        for _ in range(n):
            previous_step, current_step = current_step, previous_step + current_step

        return current_step
        