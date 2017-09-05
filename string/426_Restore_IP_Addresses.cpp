class Solution {
public:
    /*
     * @param s: the IP string
     * @return: All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string &s) {
        // write your code here
        
        vector<string> result;
        string str1, str2, str3, str4;
        int size = s.size();
        /*
        4 layers loop, include all possible combinations in all conditions;
        accroding to a specifical string, first, check if one combination possible accroding to length, then check if each item valid;
        */
        for(int i = 1; i <= 3; i++) {
            for(int j = 1; j <= 3; j++) {
                for(int k = 1; k <=3; k++) {
                    for(int h = 1; h <= 3; h++) {
                        if(i + j + k + h == size) {
                            str1 = s.substr(0, i);
                            str2 = s.substr(i, j);
                            str3 = s.substr(i+j, k);
                            str4 = s.substr(i+j+k, h);
                            if(valid(str1) && valid(str2) && valid(str3) && valid(str4)) {
                                result.push_back(str1 + "." + str2 + "." + str3 + "." + str4);
                            }
                        }
                    }
                    
                }
            }
        }
        return result;
    }
    
    bool valid(string &s) {
        if(s.size() != 1 && s[0] == '0')
            return false;
        return stoi(s) < 256;
    }
};