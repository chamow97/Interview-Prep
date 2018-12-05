class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
       int n = board.size();
       vector<int> list;
       for(int i = 0; i < board.size(); i++)
       {
           if((n - i - 1) % 2 == 1)
           {
               reverse(board[i].begin(), board[i].end());
           }
       }
        //list.push_back(0);
       for(int i = 0; i < board.size() / 2; i++)
       {
           swap(board[i], board[board.size() - i - 1]);
       } 
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < n; j++)
           {
               list.push_back(board[i][j]);
           }
       }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        queue<int> q;
        q.push(1);
        map<int, int> m;
       m[1] = 0;
        while(!q.empty())
       {
           int now = q.front();
            if(now == n * n)
            {
                return m[now];
            }
           q.pop();
           for(int i = now + 1; i <= min(n * n, now + 6); i++)
           {
               int curr = i;
               if(list[curr - 1] != -1)
               {
                   curr = list[curr - 1];
               }
               if(!m.count(curr))
               {
                   m[curr] = m[now] + 1;
                   q.push(curr);
               }
           }
       }
        return -1;
        
    }
};