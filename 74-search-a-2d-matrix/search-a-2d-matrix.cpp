class Solution {
public:
    bool inSearchRow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int sR = 0, eR = n - 1;

        while (sR <= eR) {
            int mid = sR + (eR - sR) / 2;

            if (target == matrix[row][mid]) {
                return true;
            }
            else if (target > matrix[row][mid]) {
                sR = mid + 1;
            }
            else {
                eR = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int sr = 0, er = m - 1;

        while (sr <= er) {
            int mid = sr + (er - sr) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                return inSearchRow(matrix, target, mid);
            }
            else if (target > matrix[mid][n - 1]) {
                sr = mid + 1;
            }
            else {
                er = mid - 1;
            }
        }

        return false;
    }
};