class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source == NULL ||target == NULL)
            return -1;
        int sLen = 0;
        int tLen = 0;
        int tIndex = 0;
        sLen = strlen(source);
        tLen = strlen(target);
        if (tLen == 0) {
            return 0;
        }
        //to make sure the target string is shorter than the compared string 
        //got from the source string
        for(int i = 0; i <= sLen - tLen; i++) {
            if(source[i] == target[0]) {
                tIndex = 1;
                while(tIndex < tLen) {
                    if (target[tIndex] == source[tIndex+i])
                        tIndex++;
                    else 
                        break;
                }
                if (tIndex == tLen) {
                    return i;
                }
            }
        }
        return -1;
    }
};
