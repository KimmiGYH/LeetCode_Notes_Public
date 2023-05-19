class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            int i = 0, j = image[0].size() - 1;
            while (i <= j) {
                int tmp = row[i];
                row[i++] = row[j] ^ 1;
                row[j--] = tmp ^ 1;
            }
        }
        return image;
    }
};