class Solution {
public:
    int ans;
    void helper(int index, string tiles, vector<int>& current) {
        if (index == tiles.size()) {
            ans++;
            return;
        }

        current.push_back(tiles[index]);
        helper(index + 1, tiles, current);

        current.pop_back();

        helper(index + 1, tiles, current);
    }
    int numTilePossibilities(string tiles) {
        vector<int> current;
        helper(0, tiles, current);
        return ans;
    }
};