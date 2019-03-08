class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, columns;
        int flag_row = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            if (rows.find(i) != rows.end()) {
                flag_row = 1;
            } else {
                flag_row = 0;
            }
            for (int j = 0; j < matrix[0].size(); j++) {
                if (flag_row) {
                    matrix[i][j] = 0;
                } else if (columns.find(j) != columns.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
