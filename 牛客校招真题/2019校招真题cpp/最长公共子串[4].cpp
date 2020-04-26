#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int ans = 0;
    int p = str.find(',');
    string a = str.substr(0,p), b = str.substr(p+1);
    int lenA = a.length(), lenB = b.length();
    int DP[lenA+1][lenB+1];
    for(int i = 0; i < lenA; i++)
        for(int j = 0; j < lenB; j++){
            if(a[i] == b[j]){
                DP[i+1][j+1] = DP[i][j] + 1;
                if(DP[i+1][j+1] > ans)
                    ans = DP[i+1][j+1];
            }
            else{
                DP[i+1][j+1] = 0;
            }
        }
    
    cout << ans << endl;
    return 0;
}