class Solution {
public:
    /*
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        int size = s.size();
        int maxLen = 0;
        string result;
        //search for all possible length of substr
        for(int len = 1; len <= size; len++) {
            for(int index = 0; index <= size - len; index++) {
                if(isPalindromicStr(s.substr(index, len), len) && len > maxLen) {
                    result = s.substr(index, len);
                    maxLen = len;
                    //because there exists one unique longest palindromic substring
                    //so in each loop of lenth: len, if find one, no need to search again;
                    break;
                }
            }
        }
        return result;
    }
    
    bool isPalindromicStr(string str, int size) {
        int start = 0;
        int end = size -1;
        while(start < end) {
            if(str[start] == str[end]) {
                start++;
                end--;
            } 
            else {
                return false;
            }
        }
        return true;
    }
};