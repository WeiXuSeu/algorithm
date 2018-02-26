class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        int base[26];
        for (int i = 0; i < 26; i++) {
            base[i] = 0;
        }
        for (int i = 0; i < A.length(); i++) {
            base[A[i]-'A']++;
        }
        for (int i = 0; i < B.length(); i++) {
            base[B[i]-'A']--;
            if (base[B[i]-'A'] < 0)
                return false;
        }
        return true;
        // write your code here
    }
};
