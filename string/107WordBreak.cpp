bool wordBreak(string &s, unordered_set<string> &dict) {
    // write your code here
    int begin = 0;
    int sizeS = s.size();
    int sizeD = dict.size();
    if(sizeS == 0 && sizeD == 0) {
        return true;
    }
    if (sizeS == 0 ||sizeD == 0) {
        return false;
    }
    return wordBreakCore(s, 0, sizeS, dict, sizeD);
}

bool wordBreakCore(string &s, int begin, int sizeS, unordered_set<string> &dict, int sizeD) {
    if(sizeS == 0) {
        return true;
    }
    bool flag = false;
    for(auto iter = dict.begin(); iter != dict.end(); iter++) {
        int size = (*iter).size();
        if(s.compare(begin, size, *iter) == 0) {
            flag = true;
            return wordBreakCore(s, begin + size, sizeS - size, dict, sizeD);
        }
    }
    if(!flag)
        return false;
}