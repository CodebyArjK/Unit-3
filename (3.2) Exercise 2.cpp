#include <iostream>
#include <vector>

using namespace std;

class healthBar
{
    public:
        int hp = 10; 
        string name = "health"; 

    void showHp(){
        
        int hpPercent = round(hp/10);
        for(int i =0; i < hpPercent; i++){

            cout << "▮";

        }
        for(int i = hpPercent; i < 10; i++)
        {

            cout << "-";

        }

    }

};

int main()
{

    healthBar health;

    health.display();
    health.reduce(4);
    cout << endl;
    cout << endl;

    health.display();
    
}