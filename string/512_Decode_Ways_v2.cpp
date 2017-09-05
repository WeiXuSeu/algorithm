class Solution {
public:
    /*
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        // exception conditions, return 0
        int size = s.size();
        int result = 0;
        // exception case1: 1st character is '0';
        if(size == 0 || s[0] == '0') {
            return 0;
        }
        // exception case2: if s[i] == 0; then s[i-1] must in [1,2],
        // this include more than one continuous zero: '00'; 
        for(int i = 0; i < size-1; i++)
        {
            if((s[i] <= '0' || s[i] > '2') && s[i+1] == '0')
                return 0;
        }
        // exception case3: s[i] must in [0,9]
        for(int i = 0; i < size; i++) {
            if(s[i] < '0' || s[i] > '9') {
                return 0;
            }
        }
        // normal string, calculate the result;
        result = numDecodingsCore(s, size);
        return result;
    }
    
    int numDecodingsCore(string& s, int size) {
        // write your code here
        // just like jump ladders, each step must be 1 or 2, but with some conditions;
        /*
        f(n) = condition(f(n-1)) + condition(f(n-2));
        f(s[i]) ----> dp[i+1]
        dp[0] = 1; //initail data;
        dp[1] = 1; // normal string , cannot be zero, just one choice, 1 step;
        
        for s[index], index > 1,
            if s[index] = '0', then cannot choose go 1 step, 
                cdt(f(index-1)) = 0; else cdt(f(index-1)) = f(index-1);
            if (we can go 2 steps)
                cdt(f(index-2)) = f(index-2); else cdt(f(index-2)) = 0;
        */
        int dp[size + 1];
        dp[0] = 1; 
        dp[1] = 1;
        for (int i = 2; i <= size; i++)
        {
            if(s[i - 1] == '0') {
                dp[i] = 0;
            }
            else {
                dp[i] = dp[i - 1];
            }
            
            if(s[i - 2] == '1' || (s[i-2] == '2' && s[i - 1] <= '6')) {
                dp[i] += dp[i-2];
            }
        }
        return dp[size];

    }
};