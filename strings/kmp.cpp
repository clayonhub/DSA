#include <bits/stdc++.h>
using namespace std;
vector<int> buildlps(string t){
    int n = t.size();
    int len = 0;
    vector<int>lps(n, 0);
    int i = 1;
    while(i<n){
        if(t[i]==t[len]){
            lps[i] = ++len;
            i++;
        }
        else{
            if(len>0){
                len = lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
int kmp(string s, string t){
    vector<int>lps = buildlps(t);
    int i = 0;
    int j = 0;
    int n = s.size();
    while(i<n){
        if(s[i]==t[j]){
            i++;
            j++;
            if(j==t.size()) return i-j;
        }
        else{
            if(j>0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return -1;
}

int main() {
    string s = "ABCDABCABCDABCD";
    string t = "ABCDABCD";
    int ind = kmp(s, t);
    cout<<"The string found at index: "<<ind<<endl;
    return 0;
}
