class Solution {
public:
    bool isDigit(char &ch) {
        return ch >= '0' && ch <= '9';
    }
    string decodeString(string str) {
        string num = "";
        int repeatNum = 0;
        stack<char> s;
        string result = "", content = "";
        bool isInParen = false;
        for (char ch: str) {
            if (isInParen) {
                if(ch == '[') s.push(ch);
                else if (ch == ']') {
                    if(s.top() == '[') s.pop();
                    if(s.empty()) {
                        isInParen = false;
                        content = decodeString(content);
                        for (int i = 0;i<repeatNum;i++) {
                            result+=content;
                        }
                        continue;
                    }
                }
                content += ch;
            } else {
                if (isDigit(ch)) {
                    num+=ch;
                } else if (ch == '[') {
                    repeatNum = stoi(num);
                    num = "";
                    s.push(ch);
                    isInParen = true;
                    content = "";
                } else {
                    result+=ch;
                }
            }
        }
        return result;
    }
};
