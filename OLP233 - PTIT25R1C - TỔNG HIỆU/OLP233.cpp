#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long long a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    long long p[n + 1];
    p[1] = a[1];
    for(int i = 2; i <= n; i++) p[i] = p[i - 1] + a[i];
    long long total = 0;
    for(int i = 1; i <= n; i++) total += (p[n] - p[i] - (n - i) * a[i]);
    cout << total << endl;
    return 0;
}
