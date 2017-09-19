class Solution {
public:
    /*
     * @param : A string
     * @param : A string
     * @return: Count the number of distinct subsequences
     */
     
    /* 
    f(i,j) 表示在S的前i个字符，T的前j个字符中满足条件的个数
                f(i-1, j), S[i] != T[j]
    f(i,j) =    f(i-1, j) + f(i-1, j-1), S[i] == T[j]
                1, j == 0
                0, i == 0
    */
    int numDistinct(string S, string T) {
        // write your code here
        int result = 0;
        int sizeS = S.size();
        int sizeT = T.size();
        int vec[2][sizeS+1];
        for(int j = 0; j <= sizeS; j++) {
            vec[0][j] = 1;
        }
        for(int i = 1; i <= sizeT; i++) {
            vec[i%2][0] = 0;
            for(int j = 1; j <= sizeS; j++) {
                if(S[j - 1] == T[i - 1]) {
                    vec[i%2][j] = vec[i%2][j-1] + vec[(i+1)%2][j-1];
                }
                else {
                    vec[i%2][j] = vec[i%2][j-1];
                }
            }
        }
        result = vec[sizeT%2][sizeS];
        return result;
    }
};