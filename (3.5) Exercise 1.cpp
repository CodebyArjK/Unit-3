#include <iostream>
#include <vector>
#include <cstdlib> // Include <cstdlib> for the rand() function

using namespace std;

class Enemy
{
protected:
    int hp = 10;
    int attack = 2;
    string name = "Bart";

public:
    int getAttack()
    {
        return attack;
    }
    void getDamage(int damage)
    {
        hp -= damage;
    }
    int showHp()
    {
        return hp;
    }
    string getName()
    {
        return name;
    }
};

class Player
{
protected:
    int hp = 100;
    int attack = rand() % 15;
    string name = "Beethoven";

public:
    int getAttack()
    {
        return attack;
    }
    void getDamage(int damage)
    {
        hp -= damage;
    }
    int showHp()
    {
        return hp;
    }
    string getName()
    {
        return name;
    }
};

bool isAlive(vector<Enemy> villain)
{
    for (int i = villain.size() - 1; i >= 0; i--)
    {
        if (villain[i].showHp() > 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Enemy Bart;
    Player Beethoven;
    vector<Enemy> villain;

    for (int i = 0; i < 5; i++)
    {
        villain.push_back(Bart);
        cout << "Adding Enemy Bart!" << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << i << ". " << villain[i].getName() << " with " << villain[i].showHp() << " HP\n";
    }

    for (int i = villain.size() - 1; i >= 0; i--)
    {
        if (villain[i].showHp() > 0)
        {
            cout << Beethoven.getName() << " " << Beethoven.showHp() << endl;
            villain[i].getDamage(Beethoven.getAttack());
            cout << villain[i].getName() << " " << villain[i].showHp() << endl;
            Beethoven.getDamage(villain[i].getAttack());
            cout << villain[i].showHp() << endl;
        }

        if (Beethoven.showHp() == 0)
        {
            cout << "Beethoven lost!\n";
            break;
        }

        if (isAlive(villain))
        {
            cout << "Beethoven Won\n";
            break;
        }
    }

    cout << "Game Over!!!\n";
}
