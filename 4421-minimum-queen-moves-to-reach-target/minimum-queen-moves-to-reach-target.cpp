class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int dx = abs(source[0] - target[0]);
        int dy = abs(source[1] - target[1]);

        if (dx == 0 && dy == 0)
            return 0;

        if (dx == 0 || dy == 0 || dx == dy)
            return 1;

        return 2;
    }
};