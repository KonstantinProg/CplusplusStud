// OOP.TZ2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using std::string;

class Weapon {
public:
    string name;
    float price;
    float maxDamage;
    float damage;
    float weight;

    Weapon(string name, float price, float maxDamage, float damage) : name(name), price(price), maxDamage(maxDamage), damage(maxDamage) {};
    Weapon(): Weapon("p", 1, 1, 1){}

    ~Weapon() {
        std::cout << name << " " << price << " " << damage << " Delited " << "\n";
    }

    bool maxWeight(float weight, float t) {
        
        if (weight <= t)  return true; 
        else  return false;
    }

    float sumWeight(Weapon& w, float weight) { //остановился на заданиях 6-7 (день 12), поплыл мозг
        w.weight + weight;
    }

};//
//
//
// не завершено - поплыл мозг


int main()
{
    Weapon p;
        p.name = "Pistol";
        p.price = 200;
        p.damage = 10;
        p.weight = 5;
    
        std::cout << p.name << " " << p.price << " " << p.damage << "\n";

        Weapon* r = new Weapon("Riffle", 2000, 100, 55);
        std::cout << r->name << " " << r->price << " " << r->damage << "\n"; //динамический объект
        delete r;

        //p.maxWeight(p.weight, 4);
        
        //int i = p.maxWeight(p.price);
        bool i = p.maxWeight(p.weight, 9);
        std::cout << i << "\n";

        Weapon k ("Knife", 10, 5, 1);


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
