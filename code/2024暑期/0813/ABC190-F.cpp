#include <iostream>
using namespace std;

typedef long long ll;
int n;
int a[300010];
int b[300010];
int c[300010];
int d[300010];
ll cnt;

void merge_sort(int l, int r){
    if(l + 1 >= r)
        return ;
    int mid = (l+r)/2;
    merge_sort(l, mid);
    merge_sort(mid, r);
    int l1 = l, r1= mid;
    int l2 = mid, r2 = r;
    int tot = l;
    while(l1 < r1 || l2 < r2) // 两边都排序之后，插入到一个新的数组b
    {
        if((l1 < r1 && a[l1] <= a[l2]) || l2 >= r2)
        {
            b[tot++] = a[l1++];
        }
        else
        {
            b[tot++] = a[l2++];
            cnt += 1ll*(r1 - l1);
        }
    }

    for(int i = l; i < r; i++)
        a[i] = b[i];    
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c[i] = a[i];
        d[i] = i;
    }
    cnt = 0;
    merge_sort(0, n);
    cout << cnt << "\n";
    for(int k = 0; k < n-1; k++)
    {
        int t = lower_bound(d, d+n, c[k]) - d;
        cnt -= 1ll*t;
        cnt += 1ll*(n - 1 - t);
        cout << cnt << "\n";
	}
    return 0;
}