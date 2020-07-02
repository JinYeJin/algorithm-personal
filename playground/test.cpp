#include<iostream>
#include<string>
 
#define endl "\n"
#define MAX 5000
#define Moduler 1000000
using namespace std;
 
int Arr[MAX];
int DP[MAX] , Len;
string Inp;
 
void Input()
{
    cin >> Inp;
    Len = Inp.length();
    for (int i = 1; i <= Len; i++)
    {
        Arr[i] = Inp[i - 1] - '0';
    }
}
 
void Solution()
{
    if (Len == 1 && Inp[0] == '0')
    {
        cout << 0 << endl;
        exit(0);
    }
 
    DP[0] = 1;
    for (int i = 1; i <= Len; i++)
    {
        if (Arr[i] >= 1 && Arr[i] <= 9)
        {
            DP[i] = (DP[i - 1] + DP[i]) % Moduler;
        }
 
        if (i == 1) continue;
 
        int Temp = Arr[i] + Arr[i - 1] * 10;
        if (Temp >= 10 && Temp <= 26)
        {
            DP[i] = (DP[i - 2] + DP[i]) % Moduler;
        }
    }
    
    //for (int i = 1; i < Len; i++)
    //{
    //    cout << "DP[" << i << "] = " << DP[i] << endl;
    //}
    cout << DP[Len] << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    FILE *stream = freopen("S2\\5\\input\\2011_input.txt", "r", stdin);
    if(!stream) perror("freopne");
 
    Solve();
 
    return 0;
}