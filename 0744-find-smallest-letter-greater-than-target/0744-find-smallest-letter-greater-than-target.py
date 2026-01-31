class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        left, right = 0, len(letters) - 1

        while left <= right:
            mid = (left + right) 
            if letters[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1

    # If left is out of bounds, wrap around
        return letters[left] if left < len(letters) else letters[0]