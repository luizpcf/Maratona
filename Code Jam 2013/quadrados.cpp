#include<iostream>

using namespace std;
int main()
{
    unsigned long long i=0;
    while(i*i<1000000000000000)
    {
        unsigned long long n,num,dig,rev;
        n = num = i;
        rev = 0;
        while (num > 0)
        {
            dig = num % 10;
            rev = rev * 10 + dig;
            num = num / 10;
        }

        if(rev==n)
        {
            //cout<<rev<< ' ' << n<<endl;
            n = num = i*i;
            rev = 0;
            while (num > 0)
            {
                dig = num % 10;
                rev = rev * 10 + dig;
                num = num / 10;
            }
            if(rev==n)
            {
                //cout<<rev<< ' ' << n<<endl;
                cout<<i*i<<", ";
            }
        }
        i++;
    }
}
