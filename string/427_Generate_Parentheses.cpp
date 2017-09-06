class Solution {
public:
    /*
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
     
    /*
    针对一个长度为2n的合法排列，第1到2n个位置都满足如下规则：左括号的个数大于等于右括号的个数。
	所以，我们就可以按照这个规则去打印括号：假设在位置k我们还剩余left个左括号和right个右括号，
	如果left>0，则我们可以直接打印左括号，而不违背规则。能否打印右括号，我们还必须验证left和
	right的值是否满足规则，如果left>=right，则我们不能打印右括号，因为打印会违背合法排列的规则，
	否则可以打印右括号。如果left和right均为零，则说明我们已经完成一个合法排列，可以将其打印出来。
	通过深搜，我们可以很快地解决问题。
    */
    vector<string> generateParenthesis(int n) {
        // write your code here
        vector<string> result;
        int lLeft = n, rLeft = n;
        string str;
        getAllParenthesis(result, str, n, n);
        return result;
    }
    
    void getAllParenthesis(vector<string> &result, string str, int lLeft, int rLeft) {
        if(lLeft == 0 && rLeft == 0) {
            result.push_back(str);
        }
        
        if(lLeft > 0) {
            getAllParenthesis(result, str + '(', lLeft - 1, rLeft);
        }
        
        if(rLeft > 0 && rLeft > lLeft) {
            getAllParenthesis(result, str + ')', lLeft, rLeft -1);
        }
    }
};