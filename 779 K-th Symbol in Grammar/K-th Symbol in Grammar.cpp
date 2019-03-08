class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1 && K == 1) return 0;
        int no = K%2? K/2+1: K/2;
        int num = kthGrammar(N-1, no);
        if (num) return K%2;
        else return K%2?0:1;
    }
};
