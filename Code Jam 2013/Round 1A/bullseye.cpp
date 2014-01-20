#include<iostream>

using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int j=0; long long r, t,resp;
        cin>>r>>t;
        resp=(r+1)*(r+1)-r*r;
        while(resp<=t)
        {
            j++;
            t-=resp;
            r+=2;
            resp=(r+1)*(r+1)-r*r;
        }
        cout<<"Case #"<<i+1<<": "<<j<<endl;
    }
}
