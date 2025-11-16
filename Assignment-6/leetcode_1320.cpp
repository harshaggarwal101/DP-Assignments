class Solution {
public:
    pair<int, int> getpos(char c) {
        if (c == '#') return {-1, -1};
        int idx = c - 'A';
        return {idx / 6, idx % 6};
    }

    int dist(char a, char b) {
        if (a == '#' || b == '#') return 0;
        auto [x1, y1] = getpos(a);
        auto [x2, y2] = getpos(b);
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int dp[301][27][27];

    int solve(string &word, int i, char l, char r) {
        if (i == word.size()) return 0;

        int li = (l == '#' ? 26 : l - 'A');
        int ri = (r == '#' ? 26 : r - 'A');

        if (dp[i][li][ri] != -1) return dp[i][li][ri];

        char curr = word[i];

        int moveLeft = dist(l, curr) + solve(word, i + 1, curr, r);
        int moveRight = dist(r, curr) + solve(word, i + 1, l, curr);

        return dp[i][li][ri] = min(moveLeft, moveRight);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, '#', '#');
    }
};
