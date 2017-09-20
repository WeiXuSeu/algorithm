class Solution {
public:
    /*
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
     /*
     f(i,j): common str end with str1[i], str2[j];
     f(i,i) = 0, str1[i] != str2[j];
     f(i,j) = 1 + f(i-1, j-1), str1[i] == str2[j];
     so the max value may appear in anywhere of f(i, j);
     we must use a state to keep it(maxLen in this case);
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int result = 0;
        int sizeA = A.size();
        int sizeB = B.size();
        if(sizeA == 0 || sizeB == 0) {
            return 0;
        }
        string longStr = sizeA > sizeB ? A : B;
        string shortStr = sizeA > sizeB ? B : A;
        int longSize = sizeA > sizeB ? sizeA : sizeB;
        int shortSize = sizeA > sizeB ? sizeB : sizeA;
        int commonLen[2][longSize + 1];
        int maxLen = 0;
        memset(commonLen[0], 0, (longSize + 1)*sizeof(int));
        memset(commonLen[1], 0, (longSize + 1)*(sizeof(int)));
        for(int i = 1; i <= shortSize; i++) {
            for(int j = 1; j <= longSize; j++) {
                if(shortStr[i-1] == longStr[j-1]) {
                    commonLen[i%2][j] = commonLen[(i+1)%2][j-1] + 1;
                    maxLen = maxLen > commonLen[i%2][j] ? maxLen : commonLen[i%2][j];
                }
                else {
                    commonLen[i%2][j] = 0;
                }
            }
        }
        return maxLen;
    }
};