class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        int counter = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == 'X')
                {
                    xCount++;
                    ++counter;
                }
                else if(board[i][j] == 'O')
                {
                    oCount++;
                    ++counter;
                }
            }
        }
        if(counter == 0)
        {
            return true;
        }
        vector<string> &str = board;
        //xcount checking
        if(xCount < oCount || xCount > oCount+1)
        {
            return false;
        }
        //check for tic tac toe pattern
        int pattern = 0;
        int isX = 0, isO = 0;
        for(int i = 0; i < 3; i++)
        {
            bool isT = true;
            int ctr = 0;
            if(str[i][0] == ' ')
            {
                ++ctr;
            }
            for(int j = 1; j < 3; j++)
            {
                if(str[i][j] == ' ')
                {
                    ++ctr;
                }
                if(str[i][j] != str[i][j-1])
                {
                    isT = false;
                    break;
                }
            }
            if(ctr == 3)
            {
                continue;
            }
            if(isT)
            {
                if(str[i][0] == 'X')
                {
                    isX++;
                }
                else
                {
                    isO++;
                }
                ++pattern;
            }
        }
        for(int i = 0; i < 3; i++)
        {
            bool isT = true;
            int ctr = 0;
            if(str[0][i] == ' ')
            {
                ++ctr;
            }
            for(int j = 1; j < 3; j++)
            {
                if(str[j][i] == ' ')
                {
                    ++ctr;
                }
                if(str[j][i] != str[j-1][i])
                {
                    isT = false;
                    break;
                }
            }
            if(ctr == 3)
            {
                continue;
            }
            if(isT)
            {
                if(str[0][i] == 'X')
                {
                    isX++;
                }
                else
                {
                    isO++;
                }
                ++pattern;
            }
        }
        //diagonal 1
        
        if(str[1][1] == str[0][0] && str[2][2] == str[1][1] && (str[1][1] == 'O' || str[1][1] == 'X'))
        {
            ++pattern;
            if(str[1][1] == 'X')
            {
                isX++;
            }
            else
            {
                isO++;
            }
        }
        if(str[1][1] == str[0][2] && str[2][0] == str[1][1] && (str[1][1] == 'O' || str[1][1] == 'X'))
        {
            ++pattern;
            if(str[1][1] == 'X')
            {
                isX++;
            }
            else
            {
                isO++;
            }
        }
        if(pattern > 1)
        {
            return false;
        }
        if(pattern == 1)
        {
            if(isX == 1)
            {
                if(xCount > oCount)
                {
                    return true;
                }
                return false;
            }
            else
            {
                if(oCount == xCount)
                {
                    return true;
                }
                return false;
            }
        }
        return true;
        
    }
};