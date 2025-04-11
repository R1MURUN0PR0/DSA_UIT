
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 5;
int a[N];
int count[N];

double median(int d){
    double ans = 0 , sum = 0;
    for(int i = 0 ; i <= 200 ; i++){
        sum += count[i];
        if(sum >= (d + 1) / 2){
            ans = i;
            break;
        }
    }

    if(d % 2 == 1)
        return ans;

    sum = 0;
    for(int i = 0 ; i <= 200 ; i++){
        sum += count[i];
        if(sum >= (d + 1) / 2 + 1){
            ans = (ans + i) / 2.0;
            break;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    int n , d;
    cin >> n >> d;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];

    int i = 1, j = 1 , res = 0;
    while(i <= n){
        while(i - j > d){
            count[a[j]]--;
            j++;
        }
        
        if(i > d && median(d) * 2 <= a[i]){
            res++;
        }
        count[a[i]]++;
        i++;
    }
    cout << res;
    return 0;
}