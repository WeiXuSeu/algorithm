class Solution {
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        // if the length of two strings are the same, one modified;
        // if the length gap of two strings is just one, one deleted;
        // if gap > 1 , false;
        int sizeS = s.size();
        int sizeT = t.size();
        string strLong = sizeS >= sizeT ? s : t;
        string strShort = sizeS < sizeT ? s : t;
        int sizeLong = strLong.size();
        int sizeShort = strShort.size();
        bool result = false;
        if (sizeLong - sizeShort == 1) {
            result = isOneDeleted(strLong, strShort);
        }
        if (sizeLong - sizeShort == 0) {
            result = isOneModified(strLong, strShort);
        }
        return result;
    }    
        
        
    bool isOneDeleted(string &s, string &t) {
        int gap = 0;
        bool result = false;
        int sizeT = t.size();
        int indexT = 0;
        int indexS = 0;
        while(indexT < sizeT) {
            if(gap > 1) {
                break;
            }
            if(s[indexS] != t[indexT]) {
                gap++;
                indexS++;
            }
            else {
                indexS++;
                indexT++;
            }
        }
        /*for gap = 1, indexS can reach the end, find the total gap
        for gap = 0, for [0, sizeT), all is the same, but s has one more character, 
        so total gap is 1.
        */
        if(gap == 1 || gap == 0) {
            result = true;
        }
        return result;
    }
        
    bool isOneModified(string &s, string &t) {
        int gap = 0;
        int size = s.size();
        bool result = false;
        for(int i = 0; i < size; i++) {
            if(s[i] != t[i]) {
                gap++;
            }
            if(gap > 1) {
                break;
            }
        }
        if(gap == 1) {
            result = true;
        }
        return result;
    }
    
};