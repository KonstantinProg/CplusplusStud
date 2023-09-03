// OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// ООП - методика построения программ, в основе которых лежит совокупность объектов


#include <iostream>

void sep() {
    std::cout << "-------------------" << "\n";
}

using std::string;

class Monster {

public:
    string name;
    float health;
    float damage;
/*
    Monster() { //конструктор, внутри которого можно обращаться к полям класса и задавать их по умолчанию при создании объекта
        name = "Monster";
        health = 1;
        damage = 1;
    }

    Monster(string name, float health, float damage) {
        this->name = name;
        this->health = health;
        this->damage = damage;
    }
    альтернативная запись ниже:
    */

    Monster(string name, float health, float damage) : name(name), health(health), damage(damage) {};
    Monster() : Monster("Monster", 1, 1){}

};


int main()
{
    Monster m;
    std::cout << m.name << " " << m.health << " " << m.damage << "\n"; //по умолчанию данные конструктора

    m.name = "Goblin1";
    m.health = 10;
    m.damage = 2;

    std::cout << m.name << " " << m.health << " " << m.damage << "\n";

    Monster goblin("Goblin2", 10, 2); //эквивалент записи: Monster goblin = Monster("Goblin", 10, 2);
    //Monster goblin1 = Monster("Goblin", 10, 2);
    std::cout << goblin.name << " " << goblin.health << " " << goblin.damage << "\n";

    sep();
    std::cout << "pointers" << "\n" << "\n";

    Monster* pgoblin = &goblin; //указатели на объекты
    pgoblin->name = "New name";
    std::cout << pgoblin->name << " " << pgoblin->health << " " << pgoblin->damage << "\n";
    std::cout << goblin.name << " " << goblin.health << " " << goblin.damage << "\n"; //при замене через указатель - объект тоже меняется

    Monster* spider = new Monster("Spider", 25, 5); //создание нового указателя на объект
    std::cout << spider->name << " " << spider->health << " " << spider->damage << "\n"; 
    delete spider; //важно после new удалять новый указатель чтобы не было утечки памяти

    sep();

    Monster test = goblin; //копирование объекта 
    goblin.name = "Goblin 3"; //при замене имени в goblin - имя в test не меняется
    std::cout << test.name << " " << test.health << " " << test.damage << "\n";
    std::cout << goblin.name << " " << goblin.health << " " << goblin.damage << "\n";



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
