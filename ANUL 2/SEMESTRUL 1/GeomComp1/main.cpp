#include <iostream>

using namespace std;

class Punct
{
public:
    float x,y,z;
    Punct(int i,int j,int k)
    {
        x=i;y=j;z=k;
    }
};

int main()
{
    Punct A1(1,0,2),A2(1,0,2),A3(0,0,1);
    float a;
    int ok =0;

    if((A1.x != A2.x) || (A1.y != A2.y) || (A1.z != A2.z))
    {
        if(A1.x != A2.x)
        {
        a = (A3.x - A1.x) / (A2.x - A1.x);

        if((A3.y - A1.y) == a * (A2.y - A1.y) )
            if((A3.z - A1.z) == a * (A2.z - A1.z) )
                ok = 1;
        }

        else if(A1.y != A2.y)
            {
                a = (A3.y - A1.y) / (A2.y - A1.y);
                if((A3.x - A1.x) == a * (A2.x - A1.x) )
                    if((A3.z - A1.z) == a * (A2.z - A1.z) )
                        ok = 1;

            }

        else if(A1.z != A2.z)
            {
                a = (A3.z - A1.z) / (A2.z - A1.z);
                if((A3.x - A1.x) == a * (A2.x - A1.x) )
                    if((A3.y - A1.y) == a * (A2.y - A1.y) )
                        ok = 1;
            }

        if(ok)
        {
            cout<<"coliniare"<<endl;
            cout<<"A3 = "<<1-a<<"A1 + "<<a<<"A2";
        }
        else cout<<"necoliniare"<<endl;

    }

    else
    {
        cout<<"A2 = "<<1<<"A1"<<" + "<<0<<"A3";

    }

}
