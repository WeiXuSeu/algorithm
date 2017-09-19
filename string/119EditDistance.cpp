class Solution {
public:
    /*
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
     
    /*
                j, i = 0;
    d[i,j] =    i, j = 0;
                min(d[i-1][j-1] +diff, d[i][j-1], d[i-1][j]), diff = (str[i] == str[j]);
                
        --------------------------------
                a0, a1, ... , aj
              0, 1, 2,  ... , j
           b0 1, x, x, d[i,j]
           b1 2,
           b3 3,
    
    */
    int minDistance(string &word1, string &word2) {
        // write your code here
        int result = 0;
        int size1 = word1.size();
        int size2 = word2.size();
        if(size1 == 0) {
            return result = size2;
        }
        if(size2 == 0) {
            return result = size1;
        }
        result = minDistanceCore(word1, size1, word2, size2);
        return result;
        
    }
    
    int minDistanceCore(string &str1, int size1, string &str2, int size2) {
        int result = 0;
        // use two arrays in turn instead of arrar[size1+1][size2+2]
        int vec[2][size1 + 1];
        int diff = 0;
        for(int j = 0; j <= size1; j++) {
            vec[0][j] = j;
        }
        for(int i = 1; i <= size2; i++ ) {
            vec[i % 2][0] = i;
            for(int j = 1; j <= size1; j++) {
                // position in vec is vec[i%2][j], responding chars are (str1[j-1], str2[i -1])
                if(str1[j - 1] == str2[i - 1]) {
                    diff = 0;
                }
                else {
                    diff = 1;
                }
                vec[i%2][j] = minInThree(vec[(i+1)%2][j-1] + diff, vec[(i+1)%2][j] + 1, \
                              vec[i%2][j-1] + 1);
            }
        }
        result = vec[size2%2][size1];
        return result;
    }
    
    int minInThree(int a, int b, int c) {
        int min;
        min = a < b ? a : b;
        min = min < c ? min : c;
        return min;
    }
};