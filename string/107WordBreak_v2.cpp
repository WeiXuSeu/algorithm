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
        bool status[size];
        memset(status, 0, size);
        for(int i = 0; i < size; i++) {
            if(dict.find(s.substr(0, i+1)) != dict.end()) {
                status[i] = true;
            }
            else {
                for(int j = 0; j < i; j++) {
                    if(status[j] && dict.find(s.substr(j+1, i - j)) != dict.end()) {
                        status[i] = true;
                        break;
                    }
                }    
            
            }
        }
        return status[size-1];
    }
};