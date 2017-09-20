class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    //f(i) = g(0,i) || (f(j) && g(j+1, i)); j in (0, i-1)
    //g(0,i) = true, substr[0,i] can be represented by dict
    
    bool wordBreak(string &s, unordered_set<string> &dict) {
        // write your code here
        int size = s.size();
        int sizeD = dict.size();
        if(size == 0 && sizeD == 0) {
            return true;
        }
        int maxLen = 0;
        bool status[size];
        memset(status, 0, size);
        maxLen = maxDictLen(dict);
        /* use maxLen to reduce the check process
        (1) when find g(0, i), also the str length and dict max length
        (2) when check f(j), g(j+1, i), also len(g(j+1, i )) < maxLen
        */
        for(int i = 0; i < size; i++) {
            if((i+1) <= maxLen && dict.find(s.substr(0, i+1)) != dict.end()) {
                status[i] = true;
            }
            else {
                for(int j = 1; j <= maxLen && j <= i; j++) {
                    if(status[i - j] && dict.find(s.substr(i - j + 1, j)) != dict.end()) {
                        status[i] = true;
                        break;
                    }
                }    
            }
        }
        return status[size-1];
    }
    
    int maxDictLen(unordered_set<string> &dict) {
        int maxLen = 0;
        for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++)
            maxLen = maxLen > (*iter).size() ? maxLen : (*iter).size();
        return maxLen;
    }
};