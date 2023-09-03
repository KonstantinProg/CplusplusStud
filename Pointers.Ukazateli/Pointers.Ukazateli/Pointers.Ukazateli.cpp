// Pointers.Ukazateli.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//указатель - та же ссылка, только обладает большими возможностями
#include <iostream>

int main()
{
    int* pointer; //nullpointer - указатель, не имеющий никакого адреса
    int a = 25;
    pointer = &a;

    std::cout << "pointer = " << pointer << "\n"; //ссылка на конкретную ячейку памяти
    std::cout << "pointer = " << *pointer << "\n";

    *pointer = 19;
    std::cout << "a = " << a << "\n";

    //с указателями в отличие от ссылок можно производить арифметические операции
    
    int mult2 = *pointer * 2;
    std::cout << "mult2 = " << mult2 << "\n"; 

    float f = 15.3;
    float* pointerf = &f;
    std::cout << "pointerf = " << pointerf << "\n";
    std::cout << "pointerf = " << *pointerf << "\n";

    std::cout << "-------- Pointers and Arrays ---------\n";

    int array[] = { 20,5,3,65,3,7 };
    std::cout << *array << "\n" << "\n"; //имя массива - указатель на первый его элемент

    for (int i = 0; i < 5; i++) {
        std::cout << *(array + i) << "\n";
    }
    std::cout << "\n";

    for (int* p = array; p <= &array[5]; p++) {
        std::cout << *p << " ";
    }
    std::cout << "\n";

    int mArray[3][2] = { {1,2}, {3, 4}, {5, 6} };
    int rows = sizeof(mArray) / sizeof(mArray[0]);
    int columns = sizeof(mArray[0]) / sizeof(mArray[0][0]);
    int* end = mArray[0] + rows * columns - 1;

    for (int* p = mArray[0], i = 0; p <= end; p++, i++) {
        std::cout << *p << " ";
        if ((i + 1) % 2 == 0) std::cout << "\n";
    }
    std::cout << "\n";

    char chars[] = "my string";
    std::cout << chars[3] << "\n";
    std::cout << chars << "\n"; //интерпритируется как строка

    char* pchars = chars;
    std::cout << pchars << "\n";
    std::cout << (void*)pchars << "\n"; //если надо узнать адрес массива

    std::cout << "\n";
    std::cout << "----------Pointers and Constants---------------\n";
    std::cout << "\n";
    
    const float PI = 3.14;
    const float G = 9.8;
    const float* pointer1 = &PI;
    std::cout << pointer1 << " = " << *pointer1 <<"\n";
    //*pointer1 = 4; - ошибка на уровне компилятора - попытка изменить константу
    pointer1 = &G;
    std::cout << pointer1 << " = " << *pointer1 <<"\n";
    std::cout << "\n";
    
    int x = 5;
    int y = 10;
    const int* px = &x;
    //*px = 15; - ошибка
    std::cout << px << " = " << *px <<"\n";

    px = &y;    //----------можно менять адрес, но нельзя менять значение
    std::cout << px << " = " << *px <<"\n";
    
    int z = 15;
    int* const pz = &z; //константный указатель
    std::cout << pz << " = " << *pz <<"\n";
    
    *pz = 25;   //----------а тут наоборот
    //pz = &x; Ошибка, поменять указатель в константном указателе нельзя
    std::cout << pz << " = " << *pz <<"\n";
    std::cout << "z = " << z << "\n";


    //блокирует изменение и адреса, и значения:
    int m = 30;
    const int* const pm = &m;
    //*pm = 35;
    //pm = &z;
    std::cout << "pm = " << pm << " = " << *pm << "\n";

    std::cout << "-----------\n";

    m = 40;
    std::cout << "m = " << m << "\n";
    std::cout << "pm = " << *pm << "\n";

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
