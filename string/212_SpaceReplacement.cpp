class Solution {
public:
    /*
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // write your code here
        if (length == 0)
            return NULL;
        int lenSpace = 0;
        char space = ' ';
        for (int i = 0; i < length; i++) {
            if (string[i] == space) {
                lenSpace++;
            }
        }
        int newLength = length + 2 * lenSpace;
        string[newLength] = '\0';
        int oldIndex = length - 1;
        int newIndex = newLength - 1;
        while(lenSpace > 0) {
            if (string[oldIndex] == space) {
                string[newIndex--] = '0';
                string[newIndex--] = '2';
                string[newIndex--] = '%';
                lenSpace--;
            }
            else {
                string[newIndex--] = string[oldIndex];
            }
            oldIndex--;
        }
        return newLength;
    }
};