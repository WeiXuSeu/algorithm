class Solution {
public:
    /*
     * @param s: A string
     * @return: the length of last word
     */
    int lengthOfLastWord(string s) {
        // write your code here
        int strLen = s.size();
        int endIndex = strLen - 1;
        int begin = 0, end = 0;
        char space = ' ';
        int len = 0;
        while(s[endIndex] == space)
            endIndex--;
        end = endIndex;
        while(endIndex >= 0)
        {
            if (s[endIndex] == space) {
                begin = endIndex + 1;
                break;
            }
            else if (endIndex == 0) {
                begin = endIndex;
                break;
            }
            else {
                endIndex--;
            }
        }
        len = (end >= begin) ? (end - begin + 1):(len);
        return len;
        
    }
};