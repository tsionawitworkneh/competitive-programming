class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        valid_pairs = {'()', '[]', '{}'}

        for char in s:

            if char in '({[':
                stack.append(char)
            
            else:
                if not stack or stack.pop() + char not in valid_pairs:
                    return False
        

        return not stack


        