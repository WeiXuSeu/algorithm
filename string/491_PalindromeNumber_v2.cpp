class Solution {
public:
    bool isPalindrome(int x) {
        //算出x的倒置数a，比较a是否和x相等就行了
        int a = 0, b = x;
        while(b > 0){
            a = a * 10 + b % 10;
            b /= 10;
        }
        if(a == x)
            return true;
        else
            return false;
        
    }
};