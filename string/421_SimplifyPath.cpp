class Solution {
public:
    /*
     * @param path: the original path
     * @return: the simplified path
     */
    string simplifyPath(string &path) {
        // write your code here
        string result;
        int steps = 0;
        int size = path.size();
        char splitChar = '/';
        //invalid format: (1) size == 0, (2) not start with '/'
        if(size == 0 || path[0] != splitChar)
            return result;
        //whole string: "/"
        if(size == 1 && path[0] == splitChar) {
            return path;
        }
        //make the path end with '/', so for each part, the end flag is same '/'
        if(path[size - 1] != splitChar) {
            path.push_back(splitChar);
            //adjust path size
            size++;
        }
        result = validPathSimplify(path, size, splitChar);
        return result;
    }
    
    string validPathSimplify(string &path, int size, char splitChar) {
        string result;
        deque<char> queueStr;
        string currentPath(".");
        string parentPath("..");
        //initial the result string, put first char '/' into it
        //then the left string's pattern is the same for each part: "xxxxx/"
        queueStr.push_back(path[0]);
        //get the string between two continus '/'
        int lastSplit = 0;
        int index = 1;
        while(index < size) {
            if(path[index] == splitChar) {
                //for '//' get together, just do nothing, ignore the next one,
                //prvent to be processed in else logic: push_back
                if (index - lastSplit == 1) {
                    ;
                }
                //match ".", just pop_back the current part
                else if (path.compare(lastSplit + 1, index - lastSplit - 1, currentPath) == 0) {
                    queueStr.pop_back();
                }
                //match "..", pop back nearst two parts if allowed, (queueStr.size() > 1, "/.. --> /")
                else if (path.compare(lastSplit + 1, index - lastSplit - 1, parentPath) == 0) {
                    while(queueStr.size() > 1  && queueStr.back() != splitChar) {
                        queueStr.pop_back();
                    }
                    if(queueStr.size() > 1 ) {
                        queueStr.pop_back();
                    }
                    while(queueStr.size() > 1  && queueStr.back() != splitChar) {
                        queueStr.pop_back();
                    }
                }
                else {
                    queueStr.push_back(path[index]);
                }
                //update lastSplit flag
                lastSplit = index;
            }
            else {
                queueStr.push_back(path[index]);
            }
            index++;
        }
        if(queueStr.size() != 1 && queueStr.back() == splitChar) {
            queueStr.pop_back();
        }
        for(int i = 0; i < queueStr.size(); i++) {
            result.push_back(queueStr[i]);
        }
        return result;
    }
};