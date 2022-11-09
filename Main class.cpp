#include<bits/stdc++.h>
using namespace std;



// Main parent class

class FestManagement
{
    public:
    string name;
    string areaofwork;
    string PositionOfResponsibility;
    static int totalmembers;


    FestManagement()
    {
        cout<<"Welcome to the 25th annuual Tech fest"<<endl;
    }
    
    void Totalpeeps()
    {
        cout<<totalmembers<<endl;
    }

};

    

// Child class-1
class CoreCommittee : public FestManagement {

    public:
    int numofcoremembers;
    CoreCommittee()
    {
        totalmembers++;
        numofcoremembers++;
    }
};

// Child class-2

class Participants : public FestManagement {

    public:
    int numofparticipants;
   Participants()
   {
        numofparticipants++;
        totalmembers++;
   }
};

// Child class-3

class Coordinators : public FestManagement {

    public:
    int numofcoordinators;
    Coordinators()
    {
        numofcoordinators++;
        totalmembers++;
    }

    
};

// Child class-4

class Workforce : public FestManagement {

    public:
    int numofworkforce;
    Workforce()
    {
        numofworkforce++;
        totalmembers++;
    }


};


int main()
{
    return 0;
}
