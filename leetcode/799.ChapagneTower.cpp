class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        long double glasses[200][200];
        for(int i = 0; i <= 199; i++)
        {
            for(int j = 0; j <= 199; j++)
            {
                glasses[i][j] = 0.0;
            }
        }
        glasses[0][0] += poured;
        for(int i = 0; i < 101; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                long double now = max((long double)(0), glasses[i][j] - 1);
                glasses[i+1][j] += (now * (0.5));
                glasses[i + 1][j + 1] += (now * (0.5));
            }
        }
        return min(glasses[query_row][query_glass], (long double)(1));
    }
};
