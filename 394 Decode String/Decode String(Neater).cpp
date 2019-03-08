class Solution {
public:
    bool isDigit(char &ch) {
        return ch >= '0' && ch <= '9';
    }
    
    string decodeString(string str) {
        int i = 0;
        return decodeString(str, i);
    }
    
    string decodeString(string& str, int& i) {
        int repeatNum = 0;
        string num = "", result = "";
        while(i < str.size()) {
            if (str[i] == ']') {
                ++i;
                break;
            }
            if (isDigit(str[i])) {
                num += str[i];
                ++i;
            } else if (str[i] == '[') {
                repeatNum = stoi(num);
                num = "";
                ++i;
                string content = decodeString(str, i);
                for (int j = 0; j < repeatNum; j++) {
                    result += content;
                }
            } else {
                result += str[i];
                ++i;
            }
        }
        return result;
    }
};
