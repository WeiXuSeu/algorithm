class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        int sLen = str.length();
        if (sLen == 0)
            return;
        int realOffset = offset % sLen;
        
        int start = 0;
        int end = sLen - realOffset -1;
        //rotate first part
        rotateStr(str, start, end);
        //rotate second part
        start = sLen-realOffset;
        end = sLen - 1;
        rotateStr(str, start, end);
        //rotate whole string
        start = 0;
        end = sLen - 1;
        rotateStr(str, start, end);
    }
    
    void rotateStr(string &str, int start, int end) {
        char tmp;
        for(; start < end; start++, end--){
            tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;
        }  
    }
};