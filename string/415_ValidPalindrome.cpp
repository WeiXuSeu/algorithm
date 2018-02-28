class Solution {
public:
    /*
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string s) {
        // write your code here
        bool result = true;
        string value = s;
        string tmp = "";
        int gap = 'a' - 'A';
        for(int index = 0; index < s.size(); index++) {
            if(s[index]>='0' && s[index] <= '9') {
                tmp.push_back(s[index]);
            }
            else if(s[index] >= 'A' && s[index] <= 'Z') {
                tmp.push_back(s[index] + gap);
            }
            else if(s[index] >= 'a' && s[index] <= 'z') {
                tmp.push_back(s[index]);
            }
        }
        
        int begin = 0, end = tmp.size()-1;
        for (; begin <= end; begin++, end--) {
            if(tmp[begin] != tmp[end]) {
                result = false;
                break;
            }
        }
        return result;
    }
};