// Critter caretaker
// Virtual pet

#include <iostream>
using namespace std;

// Class definition
class Critter
{
public:
    static int s_Total;

    Critter(int hunger = 0, int boredom = 0);
    static int getTotal();

    void talk();
    void eat(int food = 4);
    void play(int fun = 4);
    void showValues();

private:
    int m_Hunger = 0;
    int m_Boredom = 0;

    void passTime(int time = 1);
    int getMood() const;

};

int Critter::s_Total = 0;

// Class implementation
Critter::Critter(int hunger, int boredom):
	m_Hunger(hunger),
    m_Boredom(boredom)
{
	cout << "Critter initialized: " << m_Hunger << endl;
    s_Total++;
}

int Critter::getTotal() 
{
    return s_Total;
}

inline int Critter::getMood() const
{
    return (m_Hunger + m_Boredom);
}

void Critter::passTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}

void Critter::showValues()
{
    cout << "Hungry: " << m_Hunger;
    cout << "Boredom: " << m_Boredom << endl;
}

void Critter::talk()
{
    cout << "I'm a critter and I feel ";
    int mood = getMood();
    cout << mood;
    if (mood > 15)
    {
        cout << "mad.\n";
    }
    else if (mood > 10)
    {
        cout << "frustrated.\n";
    }
    else if (mood > 5)
    {
        cout << "okay.\n";
    }
    else
    {
        cout << "happy.\n";
    }
    passTime();
}

void Critter::eat(int food)
{
    cout << "Brruppp.\n";
    m_Hunger -= food;

    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    passTime();
}

void Critter::play(int fun)
{
    cout << "Wheee!\n";

    m_Boredom -= fun;
    if (m_Boredom = 0)
    {
        m_Boredom = 0;
    }
    passTime();
}

int main()
{
    Critter crit;
    crit.talk();

    int choice;
    do
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";
        cout << "4 - Show critter values\n\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Good-bye.\n";
            break;
        case 1:
            crit.talk();
            break;
        case 2:
            crit.eat();
            break;
        case 3:
            crit.play();
            break;
        case 4:
            crit.showValues();
            break;
        default:
            cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
    }while (choice != 0);


    return 0;
}

