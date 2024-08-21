#include <iostream>
using namespace std;
int a, b, w;
int main()
{
	cin>>a>>b>>w;
    w *= 1000;
	int k=w/a, l; // k是最大的数量，l是最小
	if(w%a>k*(b-a))  // 不够分摊的，就说明是无解的
    {
        cout<<"UNSATISFIABLE"<<endl;
        return 0;
    }
	l=w/b+(w%b? 1: 0); // l可以直接计算，一定有解
	cout<<l<<' '<<k<<endl; // 输出
	return 0;
}
