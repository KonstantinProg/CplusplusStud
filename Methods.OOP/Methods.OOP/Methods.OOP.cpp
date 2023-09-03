// Methods.OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using std::string;

class Monster {

public:
    string name;
    float health;
    float maxHealth;
    float damage;

    Monster(string name, float maxHealth, float damage) : name(name), maxHealth(maxHealth), health(maxHealth), damage(damage) {};
    Monster() : Monster("Monster", 1, 1) {}

    int getLevel() {  //метод
        return maxHealth / 5;  
    }

    void applyDamage(float damage) {
        health -= damage;
    }

    void applyDamage() { //мы можем вызывать методы через другие методы внутри одного класса
        applyDamage(1);
    }

    void recovery() {
        health = maxHealth;
    }

    void attack(Monster& m) { //обязательна работа через указатель или ссылку
        m.applyDamage(damage);
    }

    void attack(Monster* m) {     //альтернатива 
        m->applyDamage(damage);
    }
    
};

int main()
{
    Monster g("Goblin", 10, 1);
    Monster v("Varvar", 20, 5);

    std::cout << g.getLevel() << "\n";
    std::cout << v.getLevel() << "\n";

    g.applyDamage(3);
    std::cout << g.name << " " << g.health << " " << g.damage << "\n";

    v.applyDamage();
    v.applyDamage();
    std::cout << v.name << " is health = " << v.health << "\n";

    v.attack(g);
    std::cout << "g.health = " << g.health << "\n";

    Monster* pg = &g; //работает только благодаря строке 38
    v.attack(pg);
    std::cout << "g.health = " << g.health << "\n";


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
