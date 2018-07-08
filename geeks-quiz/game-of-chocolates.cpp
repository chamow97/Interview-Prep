#include <iostream>
using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a == 0 && b == 0)
        {
            cout << "Bunty\n";
        }
        else if(a == 0 || b == 0 || a == b)
        {
            cout << "Dolly\n";
        }
        else
        {
            if(a > b)
            {
                swap(a, b);
            }
            if((b+1)/2 == a)
            {
                cout << "Bunty\n";
            }
            else
            {
                cout << "Dolly\n";
            }
        }
    }
	return 0;
}