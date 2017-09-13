class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        char markString[26];
        vector<string> result;
        bool resultAnagrams = false;
        bool existAnagrams = false;
        /*check all the combination of two string items in the vactor
        (1) compare vec[i] to (item in vec[i+1, end])
            if true:
                put item in vec[i+1, end] to result;
                and we should erase the item to ignore duplicate comparation;
            to garantee push the base str(vec[i]) to result only once, we can
            push it at the end of each compare loop if condition meet(existAnagrams)
        */
        for(int i = 0; i < strs.size() - 1; i++) {
            existAnagrams = false;
            for(int j = i + 1; j < strs.size(); j++) {
                resultAnagrams = isAnagrams(strs[i], strs[i].size(), \
                strs[j], strs[j].size(), markString, 26);
                if(resultAnagrams) {
                    existAnagrams = true;
                    result.push_back(strs[j]);
                    strs.erase(strs.begin()+j);
                    //erase one, so the index will still keep j in next loop step;
                    //first j--, then j++ (at the end of each loop step)
                    j--;
                }
            }
            if(existAnagrams) {
                result.push_back(strs[i]);
            }
        }
        return result;
    }
    
    /*both equal & anagrams satisfy the condition*/
    bool isAnagrams(string str1, int len1, string str2, int len2, char *mark, int markLen) {
        //first check length, reduce the execute time
        if(len1 != len2) {
            return false;
        }
        if(len1 == 0) {
            return true;
        }
        //each time, must clean the state array
        memset(mark, 0, markLen);
        //record the state of str1
        for(int index = 0; index < len1; index++) {
            mark[str1[index] - 'a']++;
        }
        /*if str1 & str2 satisfy the condition, then minus the state of str2, the result is zero
        if not, because len(str1) == len(str2), then when minus the state of str2, soon or later,
        the state of the character in str2 will be (< 0);
            in this method, checking result is along with state calculating.
            another method split the two steps, fist calculate the state, then check the calculated 
        state again; this method is more slower, especially in the condition: most of the items are
        different.
        */
        for(int index = 0; index < len2; index++) {
            mark[str2[index] - 'a']--;
            if(mark[str2[index] - 'a'] < 0) {
                return false;
            }
        }
        //for(int index = 0; index < markLen; index++) {
        //   if(mark[index] != 0)
        //        return false;
        //}
        return true;
    }
};
