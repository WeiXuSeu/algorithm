class Solution {
public:
    /*
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        int size = s.size();
        int result = 0;
		//exception1: size = 0 or the 1st character is '0';
        if(size == 0 || s[0] == '0') {
            return 0;
        }
		//exception2: when s[i+1] ='0', s[i] must be '0' or '1', only 10, 20 in [1, 26]
		//exception3: 00 can not in the string.
        for(int i = 0; i < size-1; i++)
        {
            if((s[i] <= '0' || s[i] > '2') && s[i+1] == '0')
                return 0;
        }
        
        char *str = (char *)malloc(size +1);
        str[size] = '\0';
        for(int i = 0; i < size; i++) {
			//exception4: each char in the string must be in ['0', '9'];
            if(s[i] >= '0' && s[i] <= '9') {
                str[i] = s[i];
            }
            else {
                return 0;
            }
        }
		// process the legal string;
        result = numDecodingsCore(str);
        free(str);
        return result;
    }
    
    int numDecodingsCore(char *s) {
        // write your code here
		/*
		(1) f(n) = f(n-1) + f(n-2) --> when match some contition;
		(2) when s[0,1] = 10 or 20, we must put them together, then f(n) = f(n-2);
		(3) when s[0,1] in [11,19],[21,26] we can put them together or just split the first one. f(n) = f(n-1) + f(n-2);
		(4) else, we cannot put two characters together, f(n) = f(n-1);
		(5) a special case, s[0] = '0';
		    for example: 11011XXXXXXXXXX, meet (2), we can split it to: f(1011XXXXXXXXXXX) + f(011XXXXXXXXXXXXX),
			but in fact, we must put 10 together, so 011XXXXXXXXXXXXX not exist, make f(011XXXXXXXXXXXXX) =  0;
			so when s[0] = '0', return 0;
 		*/
        if(*s == '\0' || *(s+1) == '\0') {
            return 1;
        }
        if(s[0] == '0') {
            return 0;
        }
        else if(s[1] == '0') {
            return numDecodingsCore(s+2);
        }
        else if(s[0] =='1' || (s[0] == '2' && s[1] >= '1' && s[1] <= '6')) {
            return numDecodingsCore(s+1) + numDecodingsCore(s+2);
        }
        else {
            return numDecodingsCore(s+1);
        }
    }
};