class Solution {
public:
    /*
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        string result;
        int num = strs.size();
        int minSize = 0;
        /*
        case1: input: ["abc"]
               output: "abc"
        */
        if(num > 0) {
            minSize = strs[0].size(); 
        }
        for(int i = 1; i < num; i++) {
            if(strs[i].size() < minSize) {
                minSize = strs[i].size();
            }
        }
        bool isEqual = true;
        int equalLen = 0;
        for(int i = 0; i < minSize; i++) {
            isEqual = true;
            for(int j = 0; j < num -1; j++) {
                if(strs[j][i] != strs[j+1][i]) {
                    isEqual = false;
                    break;
                }
            }
            if(isEqual) {
                equalLen++;
            }
            else {
                break;
            }
        }
        if(equalLen > 0) {
            result = strs[0].substr(0, equalLen);
        }
        return result;
    }
};