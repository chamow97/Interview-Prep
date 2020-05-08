class Solution {
public:
    bool isCollinear(int x1, int x2, int x3, int y1, int y2, int y3) {
        long double area = (long double)(0.5 * ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))));
        return area == 0.0;
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        long double slope = 0.0;
        if(coordinates.size() <= 2) {
            return true;
        }
        for(int i = 0; i <= (coordinates.size() - 3); i++) {
            if(!isCollinear(coordinates[i][0], coordinates[i + 1][0], coordinates[i + 2][0], coordinates[i][1], coordinates[i + 1][1], coordinates[i + 2][1])) {
                return false;
            }
        }
        return true;
    }
};
