string addBinary(string a, string b) {
    // write your code here
	/*result must be a empty string here. If set it '0', we will append to it and then reverse it.
	so it will get wrong, eg:01 --> 10, 1 --> 1*/
    string result;
    string aStr, bStr;
    char sum = 0;
    char step = 0;
    int gap = 0;
    int aSize = a.size(), bSize = b.size();
    int len = aSize > bSize ? aSize : bSize;
    //reverse
    for(int index = aSize - 1; index >= 0; index--) {
        aStr.push_back(a[index]);
    }
    for(int index = bSize - 1; index >= 0; index--) {
        aStr.push_back(b[index]);
    }
    
    gap = aSize > bSize ? (aSize - bSize):(bSize - aSize);
	//gap here can be zero, nzero will be empty under this case;
    string nzero(gap, '0');
    if(aSize > bSize) {
        bStr  = bStr + nzero;
    }
    else {
        aStr  = aStr + nzero;
    }
    
    for(int index = 0; index < len; index++){
        sum = step + aStr[index] + bStr[index] - '0' - '0' ;
        if(sum == 0 || sum == 1) {
            result.push_back('0' + sum);
            step = 0;
        }
        else if (sum == 2) {
            result.push_back('0');
            step = 1;
        }
        else if (sum == 3){
            result.push_back('1');
            step = 1;
        }
    }
    
    if(step == 1) {
        result.push_back('1');
    }
    int size = result.size();
    for (int index = size - 1; index > 0; index--) {
        if(result[index] == '0') {
            result.pop_back();
        }
        else {
            break;
        }
    }
    
    int start = 0, end = result.size() - 1;
    char tmp;
    for(; start < end; start++, end--) {
        tmp = result[start];
        result[start] = result[end];
        result[end] = tmp;
    }
    
    return result;
}
