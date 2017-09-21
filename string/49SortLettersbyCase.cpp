class Solution {
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
    void sortLetters(string &chars) {
        // write your code here
        int end = chars.size() - 1;
        int start = 0;
        while(start < end) {
            if(isUpperCase(chars[start]) && isLowerCase(chars[end])) {
                swap(chars, start, end);
                start++;
                end--;
            }
            else if(isUpperCase(chars[start])) {
                end--;
            }
            else if(isLowerCase(chars[end])) {
                start++;
            }
            else{
                start++;
                end--;
            }
        }
    }
    
    void swap(string &str, int x, int y) {
        char tmp = str[x];
        str[x] = str[y];
        str[y] = tmp;
    }
    
    bool isLowerCase(char x) {
        if(x <= 'z' && x >= 'a') {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool isUpperCase(char x) {
        if(x <= 'Z' && x >= 'A') {
            return true;
        }
        else {
            return false;
        }
    }
};