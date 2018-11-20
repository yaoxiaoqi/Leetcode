class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> answer;
        int pos = findClosetElem(arr, x);
        vector<int> range;
        range.push_back(max(pos - k + 1, 0));
        range.push_back(min(pos + k - 1, int(arr.size()) - 1));
        if (k >= (range[1] - range[0] + 1)) {
            answer.insert(answer.begin(), arr.begin()+range[0], arr.begin()+range[1] + 1);
            return answer;
        }
        int left = range[0];
        int dist = INT_MAX;
        int sum = 0;
        for (int i = range[0]; i <= range[1]; i++) {
            sum += abs(arr[i]-x);
            if (i-range[0]+1 == k) {
                if (sum < dist) {
                    left = i-k+1;
                    dist = sum;
                }
            }
            if (i-range[0]+1 > k) {
                sum = sum - abs(arr[i-k]-x);
                if (sum < dist) {
                    left = i-k+1;
                    dist = sum;
                }
            }
        }
        answer.insert(answer.begin(), arr.begin() + left, arr.begin() + left + k);
        return answer;
    }
private:
    int findClosetElem(vector<int>& arr, int x) {
        int left = 0, right = int(arr.size() - 1);
        int mid = left + (right - left) / 2;
        int tmp = mid;
        while(left + 1 < right) {
            mid = left + (right - left) / 2;
            if (abs(arr[tmp]-x) > abs(arr[mid]-x)) {
                tmp = mid;
            }
            if (arr[mid] == x) {
                return mid;
            } else if (x < arr[mid]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (abs(arr[tmp]-x) > abs(arr[left]-x)) tmp = left;
        if (abs(arr[tmp]-x) > abs(arr[right]-x)) tmp = right;
        return tmp;
    }
};
