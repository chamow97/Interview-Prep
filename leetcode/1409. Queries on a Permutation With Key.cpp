class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> position(m, 0);
        for(int i = 0; i < m; i++) {
            position[i] = i + 1;
        }
        vector<int> answer;
        for(int i = 0; i < queries.size(); i++) {
            int pos = -1;
            for(int j = 0; j < m; j++) {
                if(queries[i] == position[j]) {
                    pos = j;
                    answer.push_back(j);
                    break;
                }
            }
            int val = position[pos];
            int temp = position[0];
            position[0] = val;
            for(int j = 1; j <= pos; j++) {
                val = position[j];
                position[j] = temp;
                temp = val;
            }
        }
        return answer;
    }
};
