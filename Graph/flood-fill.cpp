class Solution {
public:
    void colorImage(int i, int j ,vector<vector<int>>& image, int color, int initalColor){
        if(i < 0 || j < 0 || i >= image.size() || j>= image[0].size() || image[i][j] != initalColor){
            return;
        }

        image[i][j] = color;
        colorImage(i+1, j, image, color, initalColor);
        colorImage(i-1, j, image, color, initalColor);
        colorImage(i, j+1, image, color, initalColor);
        colorImage(i, j-1, image, color, initalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }

        colorImage(sr,sc,image,color,image[sr][sc]);
        return image;
    }
};
