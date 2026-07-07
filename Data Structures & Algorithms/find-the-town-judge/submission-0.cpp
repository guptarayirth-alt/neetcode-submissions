class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n + 1, 0);   // score[p] = inDegree - outDegree for person p

        for (auto& t : trust) {
            int a = t[0];   // truster
            int b = t[1];   // trustee
            score[a]--;      // a trusts someone -> loses a point
            score[b]++;      // b is trusted -> gains a point
        }

        for (int p = 1; p <= n; p++) {
            if (score[p] == n - 1) {
                return p;
            }
        }

        return -1;
    }
};