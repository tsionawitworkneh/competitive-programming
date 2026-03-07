class Solution(object):
    def mostWordsFound(self, sentences):
        """
        :type sentences: List[str]
        :rtype: int
        """

        count = 0
        for sentence in sentences:
            temp = len(sentence.split())
            if temp > count:
                count = temp 
        return count


        