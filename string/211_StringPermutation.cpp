	class Solution {
public:
    /*
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    bool Permutation(string A, string B) {
        // write your code here
        int Alen = A.length();
        int Blen = B.length();
        if (Alen != Blen) {
            return false;
        }
        int base[256];
        for(int index = 0; index < 256; index++) {
            base[index] = 0;
        }
        for(int index = 0; index < Alen; index++) {
            base[A[index]]++;
        }
        for(int index = 0; index < Blen; index++) {
            base[B[index]]--;
            if (base[B[index] < 0]) {
                return false;
            }
        }
        for(int index = 0; index < 256; index++) {
            if (base[index] != 0) {
                return false;
            }
        }
        return true;
    }
};