class Solution:
    def countDigits(self, num: int) -> int:
        count = 0
        temp = num

        while temp > 0:
            digit = temp % 10
            if num % digit == 0:
                count += 1
            temp //= 10
        return count

