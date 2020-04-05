#define f first
#define s second

class Solution {
public:
    vector< pair<int, char> > sortThree(int a, int b, int c, char aa, char bb, char cc) {
        vector< pair<int, char> > arr(3);
        arr[0].f = a;
        arr[1].f = b;
        arr[2].f = c;
        arr[0].s = aa;
        arr[1].s = bb;
        arr[2].s = cc;
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        return arr;
    }
    string longestDiverseString(int a, int b, int c) {
        vector< pair<int, char> > arr = sortThree(a, b, c, 'a', 'b', 'c');
        string ans = "";
        while(1) {
            if(arr[0].f > 0) {
                int minL = min(arr[0].f, 2);
                for(int j = 0; j < minL; j++) {
                    ans += arr[0].s;
                }
                arr[0].f -= minL;
                if(arr[0].f >= arr[1].f) {
                    if(arr[1].f > 0) {
                        for(int j = 0; j < 1; j++) {
                        ans += arr[1].s;
                        }
                        arr[1].f -= 1;
                    } else {
                        break;
                    }          
                }
            } else {
                break;
            }
            arr = sortThree(arr[0].f, arr[1].f, arr[2].f, arr[0].s, arr[1].s, arr[2].s);
        }
        return ans;
    }
};
