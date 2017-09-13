class Solution {
public:
    /*
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        // write your code here
        int maxLen = 0;
        int len = 0;
        //use begin to recode the begining position of a target substr
        //use index to recode the dynamic end position
        int begin = 0;
        int dupIndex = 0;
        bool array[256];
        int size = s.size();
        memset(array, 0, 256);
        /*if s[index] not exist in the previous target string, append to it: index ++,
        and recode it as existed;
          if s[index] already existed in the previous substr, create a new target substr,
        find the positon(dupIndex) of s[index] in previous str, mask the str before dupIndex
        as false(equal delete them), and update the new begin = dupIndex;
        new substr, add one, delete at least one;
        e.g: "bcadcxxxx" ---> bcad --> adc (when 'c' duplicted, delete 'bc' in 'bcad') 
          in each condition, compare the substr len and the maxLen
        */
        for(int index = 0; index < size; index++ ) {
            if(array[s[index]] == false) {
                array[s[index]] = true;
                len = index - begin + 1;
                if(len > maxLen) {
                    maxLen = len;
                }
            }
            else {
                dupIndex = s.find(s[index], begin);
                for(int j = begin; j < dupIndex; j++) {
                    array[s[j]] = false;
                }
                begin = dupIndex + 1;
            }
        }
        return maxLen;
    } 
};