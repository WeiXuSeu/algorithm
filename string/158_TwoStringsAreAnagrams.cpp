class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        int base[256];
        for (int i = 0; i < 256; i++)
            base[i] = 0;
        for (int i = 0; i < s.length(); i++) {
            base[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++) {
            base[t[i]]--;
            if (base[t[i] < 0]) 
                return false;
        }
        for (int i = 0; i < 256; i++) {
            if(base[i]!=0)
                return false;
        }
        return true;
        // write your code here
    }
};