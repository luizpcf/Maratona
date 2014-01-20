#include<iostream>

using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int maxi[2][101]={0}, n, m, matrix[101][101];
        cin>>n>>m;

        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                cin>>matrix[j][k];
                if(matrix[j][k]>maxi[0][j])
                    maxi[0][j]=matrix[j][k];
                if(matrix[j][k]>maxi[1][k])
                    maxi[1][k]=matrix[j][k];
            }
        }
        bool possible = true;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(matrix[j][k] < maxi[0][j] && matrix[j][k] < maxi[1][k])
                    possible=false;
            }
        }

/*
        for(int j=0;j<n;j++)
        {
            cout<<maxi[0][j]<<' ';
        }
        cout<<'\n';
        for(int k=0;k<m;k++)
        {
            cout<<maxi[1][k]<<' ';
        }
        cout<<'\n';
*/
        if(possible)
            cout<<"Case #"<<i+1<<": YES\n";
        else
            cout<<"Case #"<<i+1<<": NO\n";
    }

    return 0;
}
