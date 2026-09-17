#include <bits/stdc++.h>
using namespace std;

int main(){
    //your code
    int t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        vector<int>nums(n);
        for(int i = 0; i<n; i++){
            cin>>nums[i];
        }
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int maxi = 0;
        for(int i = 1; i<n; i++){
            if(nums[i]-nums[i-1] <=k){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else{
                cnt = 0;
            }
        }
        cout<<n-maxi-1<<endl;
    }

    return 0;
}