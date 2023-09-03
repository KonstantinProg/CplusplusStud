// Pointers2.TZ.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
typedef float (*Calc)(float, float);

void massiv(int* begin, int* end)
{
    int sum = 0;
    for (int* p = begin; p < end; p++)
        sum += *p;
    std::cout << "sum = " << sum << "\n";
}

float sub(float x, float y)
{
    return x - y;
}

float add(float x, float y)
{
    return x + y;
}

float nothing(float x, float y)
{
    return 0;
}

Calc ch(char a)
{
    if (a == '+')
        return &add;
    else if (a == '-')
        return &sub;
    return &nothing;
}

int main()
{
    int array[]{ 1, 2, 4, 5, 6, 7, 10, 14 };
    massiv(std::begin(array), std::end(array));

    //std::cout << add(5, 10) << endl;
    //std::cout << sub(11, 7) << endl;

    std::cout << "-------------" << endl;

    // Calc sum = ch("+");
    // int resSum = (*sum)(5, 10);
    // cout << resSum << endl;

    // Calc sub = ch("-");
    // int resSub = (*sub)(11, 7);
    // cout << resSub << endl;

    char a;
    
    float x;
    float y;
    cin >> a;
    
    cin >> x;
    cin >> y;
    Calc randOp = ch(a);
    int result = (*randOp)(x, y);
    cout << result << endl;


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
