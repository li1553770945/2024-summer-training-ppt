#include <cstdio>
using namespace std;

typedef long long LL;

int main(int argc, char** argv)
{
	LL n;
	scanf("%lld", &n);
	n <<= 1LL;
	int cnt = 0;
	for(LL i=1; i*i<=n; i++)
    //n % i == 0:i是n的因子，后面的条件是说奇偶性不同
		if(n % i == 0 && i % 2 != n / i % 2)
			cnt ++;
	printf("%d\n", cnt *2);
	return 0;
}