#include<bits/stdc++.h>
using namespace std;

class FestManagement
{
    public:
    string name;
    string areaofwork;
    string PositionOfResponsibility;
    static int numofparticipants;
    static int numofmembers;

    FestManagement()
    {
        cout<<"Welcome to the 25th annuual Tech fest"<<endl;
    }

};

class CoreCommittee : public FestManagement {};

int main()
{
    CoreCommittee Vidya;

    return 0;
}
