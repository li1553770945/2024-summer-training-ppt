#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(c==0&&a==b){
        cout<<"Aoki";
        return 0;
    }
    if(a==b&&c==1){
        cout<<"Takahashi";
        return 0;
    }
    int aa = a;
    int bb = b;
    for(int i=1;i<=aa+bb;i++){
        cout<<i<<" "<<a<<" "<<b<<" "<<c<<endl;
        if(a>0&&b>0)
        {
            if(c==0)
            {
                a--;
                c=1;
            }
            else{
                b--;
                c=0;
            }
        }
        
        if(a<=0||b<=0)
        {
            if(a<=0)
                cout<<"Aoki";
            else if(b<=0)
                cout<<"Takahashi";
            return 0;
        }
    }
    //if(a<=0)cout<<"Aoki";
    //else if(b<=0)cout<<"Takahashi";
    return 0;
}