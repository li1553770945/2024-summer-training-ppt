#include <stdio.h>
int a[401][401];
int ask(int x1,int y1,int x2,int y2){
	return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}
int main(){
	int n,m,size = -1;
	scanf("%i%i",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++){
			scanf("%i",&a[i][j]);
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	for (int i = 1;i <= n;i++)
		for (int k = i;k <= n;k++)
			for (int j = 1,l = j;j <= m;j++){
				int max_l ;
				while (l <= m)
				{
					if (ask(i,j,k,l) >= 0)
						max_l = l;
					
					l++;
				}
				if (l > m){
					continue;
				}
				int ans = (k - i + 1) * (l - j + 1);
				size = size < ans ? ans : size;
			}
	printf("%i",size);
	return 0;
}