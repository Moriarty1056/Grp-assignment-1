#include<bits/stdc++.h>
using namespace std;



// Main parent class

class FestManagement
{
    public:
    string name;
    string department;
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
    string POR;
    int numofcoremembers;


    CoreCommittee(string name, string department, string POR)
    {
        this->name = name;
        this->department = department;
        this->POR = POR;
        totalmembers++;
        numofcoremembers++;
    }


    void CoreCpeeps()
    {
        cout<<numofcoremembers<<endl;
    }


    void InfoCore(Coordinators *p)
    {
        cout<<p->name<<endl;
        cout<<p->POR<<", ";
        cout<<"in the department :: "<<" "<<p->department<<endl;
    }

};

// Child class-2

class Participants : public FestManagement {

    public:
    int age;
    int numofparticipants;
    string event;


   Participants(string name, string event1,int age )
   {
        this->age = age;
        this->name= name;
        this->event= event1;
        numofparticipants++;
        totalmembers++;
   }


   void numofplayers()
   {
    cout<<numofparticipants<<endl;
   }
   

   void InfoParticipants(Participants *p)
    {
        cout<<p->name<<", "<<p->age<<"years old."<<endl;
        cout<<"Participating in ::"<<" "<<p->event<<". ";
    }


};

// Child class-3

class Coordinators : public FestManagement {

    public:
    string activity;
    int numofcoordinators;


    Coordinators(string name, string department,string activity )
    {
        this->name = name;
        this->department = department;
        this->activity = activity;
        numofcoordinators++;
        totalmembers++;
    }


    void numofcoords()
   {
    cout<<numofcoordinators<<endl;
   }

   void InfoCoordinator(Coordinators *p)
    {
        cout<<p->name<<endl;
        cout<<"Handling activity ::"<<" "<<p->activity<<" ";
        cout<<"in the department :: "<<" "<<p->department<<endl;
    }
    

};

// Child class-4

class Workforce : public FestManagement {

    public:
    string workalloted;
    int numofworkforce;


    Workforce(string name, string work , string department)
    {
        this->name = name;
        this->workalloted= work;
        this->department = department;
        numofworkforce++;
        totalmembers++;
    }


    void numofworkpeeps()
    {
        cout<<numofworkforce<<endl;
    }

    void InfoWorkforce(Workforce *p)
    {
        cout<<p->name<<endl;
        cout<<"Works as ::"<<" "<<p->work<<" ";
        cout<<"in the department :: "<<" "<<p->department<<endl;
    }

};


int main()
{
    return 0;
}
