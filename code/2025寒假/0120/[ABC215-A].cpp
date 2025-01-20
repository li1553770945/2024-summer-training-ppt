#include <iostream>
using namespace std;



int main()
{
    // 读取输入
    string s;
    cin >> s;

    // 目标字符串
    string target = "Hello,World!";

    // 判断是否完全匹配
    if(s==target)
    {
        cout<<"AC"<<endl;
    }
    else
    {
        cout<<"WA"<<endl;
    }
    return 0;
}
