#include <bits/stdc++.h>
using namespace std;

int childN, queryN;
int a, b;
bool flag = true;

int main(){
    cin >> childN >> queryN;
    set<int> classA, classB;
    vector<vector<int> > allQuery(childN+1, vector<int>(childN+1, 0));
    vector<int> color(childN+1, 0);
    //记录敌对关系
    for(int i = 0; i < queryN; i++){
        cin >> a >> b;
        allQuery[a][b] = 1;
    }
    
    //染色法
    for(int i = 1; i <= childN; i++){
        if(!color[i]) color[i] = 1;
        for(int j = 1; j <= childN; j++){
            if(allQuery[i][j]){
                if(color[j] != color[i]){
                    color[j] = -color[i];
                }
                else{
                    cout<< 0 << endl;
                    return 0;
                }
            }
        }
        
    }
    
    cout<< 1 << endl;
    return 0;
}