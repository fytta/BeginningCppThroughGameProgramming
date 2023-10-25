// CritterFarm


#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Critter
{

public:
    static int s_Critters;
    Critter(const string& name = "");
    friend ostream& operator<<(ostream& os, const Critter& critter);
    string getName() const;

private:
    string m_Name;

};

int Critter::s_Critters = 0;
Critter::Critter(const string& name) : m_Name(name)
{
	m_Name = name == "" ? ("Critter"+to_string(s_Critters)) : name;
    s_Critters++;
    cout << m_Name << endl;
}

inline string Critter::getName() const
{
    return m_Name;
}

/* END Critter Class
/********************/

class Farm
{

public:
    Farm(int spaces = 1);
    ~Farm();
    void add(const Critter* critter);
    void rollCall() const;
    void kickCritter(int index);
    void clear();

private:
	vector<const Critter*> m_Critters;
};

Farm::Farm(int spaces)
{
    m_Critters.reserve(spaces);
}

void Farm::add(const Critter* critter)
{
	m_Critters.push_back(critter);
}

void Farm::kickCritter(int index)
{
    const Critter* ptrCritter = m_Critters[index];
    m_Critters.erase(m_Critters.begin() + index);
    delete ptrCritter;
}

Farm::~Farm()
{
    for (const Critter* ptrCritter : m_Critters)
    {
        delete ptrCritter;
    }
    m_Critters.clear();
}

void Farm::rollCall() const
{
  //  for (vector<Critter>::const_iterator iter = m_Critters.begin(); iter != m_Critters.end(); ++iter)
  //  {
		//cout << "Hi! " << iter->getName() << endl;
  //  }
    for (const Critter* critter : m_Critters)
    {
		//cout << "Hi! Critter " << critter->getName() << endl;
        cout << *critter;
    }
}
/* END Farm Class
/********************/



int main()
{
    Critter crit("Poochie");
    cout << "My critter's name is " << crit.getName() << endl;

    cout << "\nCreating critter farm.\n";
    Farm myFarm(3);

    cout << "\nAdding three critters to the farm.\n";
    myFarm.add(new Critter("Jack"));
    myFarm.add(new Critter("Zero"));
    myFarm.add(new Critter());

    cout << "\nCalling Roll. . .\n";
    myFarm.rollCall();

    //cout << "\nCalling Roll after kick one critter. . .\n";
    //myFarm.kickCritter(1);
    //myFarm.rollCall();

    return 0;
}

//global friend function which can access all of Critter object’s members
//overloads the << operator so you can send a Critter object to cout
ostream& operator<<(ostream& os, const Critter& critter)
{
    os << "Critter Object - ";
    os << "m_Name: " << critter.m_Name << endl;
    return os;
}