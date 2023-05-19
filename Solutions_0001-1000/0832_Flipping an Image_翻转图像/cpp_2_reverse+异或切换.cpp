class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image.size(), n = image[0].size();
        for (int i = 0; i < m; i++) {
            reverse(image[i].begin(), image[i].end());
            for (int j = 0; j < n; j++)
                image[i][j] ^= 1;
        }
        return image;
    }
};

// --------------------------------------------------------

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            reverse(row.begin(), row.end());
            for (auto& x : row)
                x ^= 1;
        }
        return image;
    }
};