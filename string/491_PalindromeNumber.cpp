class Solution {
public:
    
    /*
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        // write your code here
        char str[32];
        int tmp;
        int len = 0;
        while(num > 0) {
            tmp = num % 10;
            str[len++] = '0' + tmp;
            num = num / 10;
        }
        int start = 0;
        int end = len - 1;
        for(; start < end; start++, end--) {
            if (str[start] != str[end]) {
                return false;
            }
        }
        return true;
    }
};