class Solution {
public:
    /*
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        vector<string> result;
        //record the number and related string
        vector<string> vec(8);
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 3; j++ ) {
                vec[i].push_back(i*3 + j + 'a');
            }
        }
        vec[5].push_back('s');
        vec[6] = "tuv";
        vec[7] = "wxyz";
        int size = digits.size();
        int index = 0;
        string str;
        /*only when size > 0, calculate the result; otherwith an empty string ""
        will be add to the result, when size = 0*/
        if(size > 0) {
            Combination(digits, vec, index, size, result, str);
        }
        return result;
    }
    
    void Combination(string &digits, vector<string> &vecStr, int index, int &size, \
    vector<string> &result, string str ) {
        if(index == size) {
            result.push_back(str);
        }
        int vecIndex = digits[index] - '0' -2;
        for (int i = 0; i < vecStr[vecIndex].size(); i++) {
            str.push_back(vecStr[vecIndex][i]);
            Combination(digits, vecStr, index + 1, size, result, str);
            //restore to original stat of str before enter to next loop step when return back
            str.pop_back();
        }
    }
};