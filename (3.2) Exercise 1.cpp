#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Player
{
    public:
    int maxHp = 100;
    string name = "player";
    int hp = maxHp;

    void health()
    {
        hp;
    }
    void playerHealth(){

        cout << name << "Health left " << hp << endl;

    }
    void attack(int attack){

        hp -= attack;

    }
    void showHp(){
        

        int hpPercent = round(((hp/(double)maxHp)*10));
        for(int i =0; i < hpPercent; i++){

            cout << "▮";

        }
        for(int i = hpPercent; i < 10; i++)
        {

            cout << "-";

        }

    }
    void syringe(int heal){

        hp += heal;

    }

};
class healthBar
{
    public:
        int hp = 10; 
        string name = "health"; 
        vector<string> bar = {"▮ ","▮ ","▮ ","▮ ","▮ ","▮ ","▮ ","▮ ","▮ ","▮"};


};
class Enemy
{
    public:
    int hp = 10;
    string name = "enemy";

    void health()
    {
        hp;
    }
    void enemyHealth(){

        cout << name << "Health left " << hp << endl;

    }
    void showHp(){
        
        int hpPercent = round(hp);
        for(int i =0; i < hpPercent; i++){

            cout << "▮";

        }
        for(int i = hpPercent; i < 10; i++)
        {

            cout << "-";

        }

    }
   void attack(int attack){

        hp -= attack;

    }
    void syringe(int heal){

        hp += heal;

    }

};


int main()
{
    srand(time(0));
    Player player;
    Enemy enemy;
    healthBar healthBar;
    

    while(enemy.hp>0 && player.hp > 0){
        
        player.playerHealth();
        enemy.enemyHealth();
        
        int eDamage = rand()%10 ;
        int pDamage = rand()%10;

        
        
        enemy.attack(eDamage);
        player.attack(pDamage);
        player.showHp();
        cout << "\n\n";  
        enemy.showHp();
    
    }

    player.playerHealth();
    cout << "\n\n";
    
    enemy.enemyHealth();
    cout << "\n\n";
    
    
    
   

}