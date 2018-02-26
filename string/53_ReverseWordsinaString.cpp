class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string s) {
        // write your code here
        //"   abd  d fddd "
        //delte the space at begin and end!
        string result;
        char space = ' ';
        int spaceSize = 0;
        int end = s.size()-1;
        int start = 0;
        int wordFirst = 0, wordEnd = 0;
        while(end > start) {
            if(s[end] == space)
                end--;
            else
                break;
        }
        while(end > start) {
            if(s[start] == space)
                start++;
            else
                break;
        }
        result = s.substr(start, end - start +1);
        
        //delete space at middle
        int index = 0;
        while(index < result.size()) {
            if(result[index] == space && index + 1 < result.size() && result[index+1] == space) {
                spaceSize++;
            }
            else if(result[index] == space && index + 1 < result.size() && result[index+1] != space)
            {
                result.erase(index-spaceSize+1, spaceSize);
                spaceSize = 0;
                index = index - spaceSize;
            }
            index++;
        }
        
        //revise the word in the string
        index = 0;
        while(index < result.size()) {
            if(index + 1 == result.size()) {
                reverse(result.begin()+wordFirst, result.begin()+index+1);
                break;
            }
            else if(result[index] == space) {
                reverse(result.begin()+wordFirst, result.begin()+index);
                wordFirst = index+1;
            }
            index++;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    
    }
};