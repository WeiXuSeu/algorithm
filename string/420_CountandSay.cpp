class Solution {
public:
    /*
     * @param n: the nth
     * @return: the nth sequence
     */
    string countAndSay(int n) {
        // write your code here
        string value = "1";
        string tmp = "";
        char x;
        int len=0;
        int size = 0;
        int index = 0;
        if(n <= 0) { 
            value = "0";
        }
        while(n > 1) {
            index = 0;
            x = value[0];
            len = 0;
            size = value.size();
            // it about, str[i]-- continous, str(len(str[i]))+str[i]
            while(index < size)
            {
                if(x == value[index] && index == size-1) {
                    tmp.push_back('0'+len+1);
                    tmp.push_back(x);
                }
                else if(x == value[index] && x != value[index+1]){
                    tmp.push_back('0'+len+1);
                    tmp.push_back(x);
                    x = value[index+1];
                    len = 0;
                }
                else if (x == value[index]){
                    len++;
                }
                index++;
            }
            value = tmp;
            tmp = "";
            n--;
        }
        return value;
    }
};