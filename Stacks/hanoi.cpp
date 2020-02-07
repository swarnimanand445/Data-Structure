#include<bits/stdc++.h>
using namespace std;
//main objective is to move all the n disk from Pole A to Pole C using Pole B as auxx 
void hanoi(int n,char from_pole ,char to_pole,char auxx_pole)
{
    if(n==0)
    {
        cout<<"No move can be done as no disk is present";
        return;
    }
    else if(n==1)
    {
        cout<<"Move disk 1 from "<<from_pole<<" to "<<to_pole<<endl;
        return;
    }
    else
    {
        //Recursively move n-1 disk from A to B using C as auxx
        hanoi(n-1,from_pole,auxx_pole,to_pole);
        //atomic move of a single disk;
        cout<<"Move disks "<<n<<" from "<<from_pole<<" to "<<to_pole<<endl;
        //Recursively move n-1 disk from B to C using A as auxx
        hanoi(n-1,to_pole,auxx_pole,from_pole);
    }
    
    
}
int main()
{
    int n;
    char A,B,C;
    cout<<"enter the value of n";
    cin>>n;
    cout<<"enter the name of all the 3 pole:";
    cin>>A>>B>>C;
    cout<<"Apply Tower Of Hanoi\n:";
    hanoi(n, A,C, B);
    return 0;
}