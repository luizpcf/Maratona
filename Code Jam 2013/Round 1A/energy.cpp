#include<iostream>
#include<cstdlib>
#define MAX 10
struct torre{
    int maximo;
    int minimo;
    int peso;
};

struct ordenada{
   int peso;
   int posicao;
};

using namespace std;

int compare (const void * a, const void * b)
{
  return ( (*(ordenada*)b).peso - (*(ordenada*)a).peso );
}

int main()
{
    int t;
    cin>>t;
    torre torres[MAX];
    ordenada ordem[MAX];
    for(int i=0;i<t;i++)
    {
        int total = 0;
        int e, r, n;
        cin>>e>>r>>n;
        for(int j=0;j<n;j++)
        {
            cin>>torres[j].peso;
            ordem[j].peso=torres[j].peso;
            torres[j].maximo=e;
            torres[j].minimo=0;
            ordem[j].posicao=j;
        }

        qsort (ordem, n, sizeof(ordenada), compare);

        for(int j=0;j<n;j++)
        {
            int pos = ordem[j].posicao;
            if(torres[pos].maximo<=torres[pos].minimo) continue;

            for(int k=pos+1, val=1;k<n;k++,val++)
            {
                if(torres[pos].peso<=torres[k].peso)break;
                if(val*r>e)
                {
                    torres[k].maximo=e;
                    break;
                }else
                {

                    torres[k].maximo=val*r;
                    if(torres[k].minimo>torres[k].maximo)
                        torres[k].maximo = torres[k].minimo;
                }
            }
            for(int k=pos-1, val=1;k>=0;k--,val++)
            {
                if(torres[pos].peso<=torres[k].peso)break;
                if(torres[pos].maximo - val*r <0)
                {
                    torres[k].minimo=0;
                    break;
                }else
                {
                    torres[k].minimo = torres[pos].maximo - val*r;
                }
            }
        }
        cout<<"Debug -> ";
        for(int j=0;j<n;j++)
        {
            total+=torres[j].peso*(torres[j].maximo-torres[j].minimo);
            cout<<torres[j].peso*(torres[j].maximo-torres[j].minimo)<<" - ";
        }
        cout<<endl;

        cout<<"Case #"<<i+1<<": "<<total<<endl;
    }
}
