/**
* author: vu dinh huong. vukihai98@gmail.com
**/
#include <bits/stdc++.h>
using namespace std;

// Complete the substrings function below.
int substrings(string n) {
    long tenpow[200005] ={0}; // tenpow[i] = 10^i % 1000000007
    long sum[200005][10]={0}; // sum[i][j] = (j*10^1 + j*10^2 +... + j*10^i )%1000000007
    tenpow[0] = 1;
    for(int i=0; i<=9; i++) sum[0][i] = i;
    for(int i=1; i<200005; i++){
        tenpow[i] = tenpow[i-1]*10;
        tenpow[i] %= 1000000007;
        for(int j=0; j<=9; j++){
            sum[i][j] = sum[i-1][j] + j*tenpow[i]%1000000007;
            sum[i][j] %= 1000000007;
        }
    }

    // sum of sub seq: abc = a + ab + abc +b + bc + c
    //(a*100+a*10+a)*1 +  (b*10+b)*2 +   c*3
    long res = 0;
    for(int i=0; i<n.length(); i++){
        res += (i+1)*sum[n.length()-i-1][n[i]-'0']%1000000007;
        res %= 1000000007;
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
