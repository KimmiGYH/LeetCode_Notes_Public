class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            int i = 0, j = image[0].size() - 1;
            while (i <= j) {
                if (row[i] == row[j])
                    row[i] = row[j] ^= 1;
                i++, j--;
            }
        }
        return image;
    }
};