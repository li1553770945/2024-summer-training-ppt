#include<iostream>
#include <queue>
#include <vector>

using namespace std;
int Q,x,opt;
struct Node{
    int x;
    Node(int _x)
    {
        x = _x;
    }
    bool operator < (const Node &rhs)const
    {
        return x>rhs.x;
    }
};
priority_queue<Node> qu;//越小越优先的优先队列

queue<int> q;//普通队列
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>Q;
	while(Q--){
		cin>>opt;
		if(opt==1)
        {//1操作
			cin>>x;
			q.push(x);
		}
		else if(opt==2)
        {//2操作
			if(qu.size())
            {
				cout<<qu.top().x<<endl;
				qu.pop();
			}
			else
            {
				cout<<q.front()<<endl;
				q.pop();
			}
		}
		else
        {//3操作
			while(q.size())
            {
				qu.push( Node(q.front()));//将普通队列中的数转移到优先队列中
				q.pop();
			}
		}
	}
	return 0;
}