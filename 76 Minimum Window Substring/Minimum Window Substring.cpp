class Solution {
public:
    int tLen;
    string minWindow(string s, string t) {
        unordered_map<char, int> mapping;
        vector<int> index;
        int tLen = t.size();
        tLen = t.size();

        // different letter number in t
        for (auto ch: t) {
            ++mapping[ch];
        }
        // the index of t's letter in s
        for (int i = 0; i < s.size(); i++) {
            if (mapping.count(s[i])) {
                index.push_back(i);
            }
        }
        
        string result = "";
        int minLen = INT_MAX;
        int matchNum = 0;
        int start = 0, head = 0;
        for (int i = 0; i < index.size();i++) {
            if (mapping[s[index[i]]] > 0) {
                ++matchNum;
            }
            --mapping[s[index[i]]];
            while (matchNum == tLen) {
                if (index[i] - index[start] + 1 < minLen) {
                    minLen = index[i] - index[start] + 1;
                    head = index[start];
                }
                if (mapping[s[index[start++]]]++ == 0) {
                    --matchNum;
                }
            }
        }
        return minLen == INT_MAX? "": s.substr(head, minLen);
    }
};
