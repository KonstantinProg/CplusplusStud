﻿// UslovniyOperator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    bool b = true;
    if (b) std::cout << "b is true \n";
    else std::cout << "b is false \n";
    
    int a = 5;
    if (a > 5) std::cout << "a > 5 \n";
    else if (a == 5) std::cout << "a == 5 \n";
    else std::cout << "a < 5 \n";

    int x = 10;
    if (x < 20) {
        x *= 3;
        std::cout << x << "\n";
    }
    else {
        x -= 10;
        std::cout << x << "\n";
    }

    std::cout << "x: ";
    std::cin >> x;
    if (x < 0) x *= -1;

    std::cout << "abs(x) = " << x << "\n"; // abs - модуль числа

    int y = (x < 10) ? 10 : x * 2;
    // эквивалент записи: if (x < 10) y = 10; else y = x * 2;
    std::cout << "y = " << y << "\n";
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
