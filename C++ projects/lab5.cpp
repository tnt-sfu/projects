//Lab5
#include <iostream>
using namespace std;

// Naming constant of height and width
const int width = 5;
const int height = 4;

//void function for C
void drawC()
{
   int i = 1;
    while (i <= height)
    {
        if (i == 1 || i == height)
            {for (int i=1;i<=width;i++)
                {
                cout << "C";
                }
            cout<<endl;
            }
        else
        cout<<"C"<<endl;
        i++;
    } 
}

//void function for M
void drawM()
{
    int x = 1;
    while ( x <= height)
    {
        int j = 1;
        while (j<=width)
        {
            if (x>1&&j%2==0)
            {
                cout <<" ";
            }
            else
            {
                cout << "M";
            };
        j++;
        }
    cout << endl;
    x++;
    } 
}

//void function for P
void drawP ()
{
    for(int i = 1; i <= height;i++)
    {
        for(int j = 1; j <= width;j++)
        {
            if(i==2)
            {
                if(j==2||j==3||j==4)
                {
                    cout << " ";
                }
                else
                {
                    cout <<"P";
                }
            }
            else if(i==4)
            {
                if(j==2||j==3||j==4||j==5)
                cout << " ";
                else
                {
                    cout << "P";
                }
            
            }
            else
            {
                cout << "P";
            }
        }
    cout << endl;    
    }
}

//void function for T
void drawT()
{
    for(int i = 1; i <= height;i++)
    {
        for(int j = 1; j <= width;j++)
        {
            if(i>1)
            {
                if(j==3)
                {
                    cout << "T";
                }
                else
                {
                    cout << " ";
                }
            }
            else
            {
                cout << "T";
            }
        }
    cout << endl;
    }
}

//void function for 1
void draw1 ()
{
    for(int i = 1; i <= height;i++)
    {
        for(int j = 1; j <= width;j++)
        {
            if(i==1)
            {
                if(j==1||j==4||j==5)
                {
                    cout << " ";
                }
                else
                {
                    cout << "1";
                }
            }
            else if(i==4)
            {
                cout << "1";
            }
            else
            {
                if(j==3)
                {
                    cout << "1";
                }
                else
                {
                    cout << " ";
                }
            }
        }   
    cout << endl;
    }    
}

//void function for 3
void draw3()
{
    for(int i = 1; i <= height+1;i++)
    {
        for(int j = 1; j <= width;j++)
        {
            if (i==1||i==3||i==5)
            {
                if(j==5)
                {
                    cout << " ";
                }
                else
                {
                    cout << "3";
                }
            }
            else
            {
                if(j==5)
                {
                    cout << "3";
                }
                else
                {
                    cout << " ";
                }
            }
        }
    cout << endl;
    }
}

//void function for 0
void draw0()
{
    for(int i = 1; i <= height;i++)
    {
        for(int j = 1; j <= width;j++)
        {
            if (i==1||i==4)
            {
                cout << "0";
            }
            else
            {
                if(j==1||j==5)
                {
                    cout << "0";
                }
                else
                {
                    cout << " ";
                }
            }
        }
    cout<<endl;
    }    
}
// Calling all functions inside main
int main() 
{
    drawC();
    cout <<endl;
    drawM();
    cout << endl;
    drawP();
    cout << endl;
    drawT();
    cout << endl;
    draw1();
    cout << endl;
    draw3();
    cout << endl;
    draw0();

    return 0;
}