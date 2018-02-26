class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> result;
        int maxlen = 0;
        for(int i = 0; i < dictionary.size(); i++) {
            if (dictionary[i].length() >= maxlen) {
                maxlen = dictionary[i].length();
            }
        }
        for(int i=0; i<dictionary.size(); i++) {
            if(dictionary[i].length() >= maxlen) {
                result.push_back(dictionary[i]);
            }
        }
        return result;
    }
};