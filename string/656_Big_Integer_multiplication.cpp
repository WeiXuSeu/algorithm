string multiply(string &num1, string &num2) {
    // write your code here
    string result;
    int product;
    int carray = 0;
    int size1 = num1.size();
    int size2 = num2.size();
    int multiplier;
    int sum = 0;
    string str1 = size1 > size2 ? num1 : num2;
    string str2 = size1 > size2 ? num2 : num1;
    size1 = str1.size();
    size2 = str2.size();
    if(str2.size() == 1 && str2[0] == '0') {
        return "0";
    }
    vector<int> vec1;
    vector<int> vec2;
    vector<int> intResult(220, 0);
    vector<int> intMiddle;
    int intIndexEnd = intResult.size() - 1;
    for(int i = size1 - 1; i >= 0; i--) {
        vec1.push_back(str1[i]-'0');
    }
    for(int i = size2 - 1; i >= 0; i--) {
        vec2.push_back(str2[i]-'0');
    }

    for(int i = 0; i < size2; i++) {
        multiplier = vec2[i];
        for(int j = 0; j < size1; j++) {
            product = multiplier * vec1[j];
            intMiddle.push_back(product % 10 + carray);
            carray = product / 10;
        }
        if(carray > 0) {
            intMiddle.push_back(carray);
        }
        carray = 0;
        intMiddle.insert(intMiddle.begin(), i, 0);
        for(int k = i; k < intMiddle.size(); k++) {
            sum = intResult[k] + intMiddle[k] + carray;
            intResult[k] = sum % 10;
            carray = sum / 10;
        }
        if(carray > 0) {
            intResult[intMiddle.size()] = 1;
        }
        carray = 0;
        intMiddle.clear();
    }
    while(intIndexEnd >= 0) {
        if(intResult[intIndexEnd] == 0) {
            intIndexEnd--;
        }
        else {
            break;
        }
    }
    for(int i = intIndexEnd; i >= 0; i--) {
        result.push_back(intResult[i]+'0');
    }
    return result;
}