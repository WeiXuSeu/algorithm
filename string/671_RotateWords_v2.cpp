class Solution:
    """
    @param: words: A list of words
    @return: Return how many different rotate words
    """
    def countRotateWords(self, words):
        # Write your code here
        count = 0
        dict = set()
        exist = False
        
        if not words:
            return 0

        for word in words:
            for i in range(len(word)):
                new_word = word[i:] + word[0:i]
                if new_word in dict:
                    exist = True
                    break
            
            if False == exist:
                dict.add(word)
                count += 1
            exist = False

        return count