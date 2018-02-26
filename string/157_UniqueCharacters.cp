class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        char charset[256];
        int index;
        memset(charset,0,256);
        for(int i = 0; i < str.size(); i++) {
            index = str[i];
            charset[index]++;
            if(charset[index] > 1) {
                return false;
            }
        }
        return true;
    }
};