class Solution {
public:
    void dfs(vector<vector<int>> &image, int newColor, int sr, int sc, int currColor) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != currColor) {
            return;
        }
        image[sr][sc] = newColor;
        dfs(image, newColor, sr + 1, sc, currColor);
        dfs(image, newColor, sr - 1, sc, currColor);
        dfs(image, newColor, sr, sc - 1, currColor);
        dfs(image, newColor, sr, sc + 1, currColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc] == newColor) {
            return image;
        }
        dfs(image, newColor, sr, sc, image[sr][sc]);
        return image;
    }
};
