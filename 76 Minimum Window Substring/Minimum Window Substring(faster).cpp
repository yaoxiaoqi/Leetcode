class Solution {
public:
    int tLen;
    string minWindow(string s, string t) {
        vector<int> mapping(128,0);
        int tLen = t.size();
        
        for (auto ch: t) {
            ++mapping[ch];
        }
        
        int minLen = INT_MAX;
        int matchNum = 0;
        int start = 0, head = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (mapping[s[i]] > 0) {
                ++matchNum;
            }
            --mapping[s[i]];
            while (matchNum == tLen) {
                if (i - start + 1 < minLen) {
                    head = start;
                    minLen = i - start + 1;
                }
                // only letter in t can be equal or greater than 0, before plus one
                if (mapping[s[start++]]++ >= 0) {
                    --matchNum;
                }
            }
        }
        
        return minLen == INT_MAX? "": s.substr(head, minLen);
    }
};
