// Pointers.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void separator() {
    std::cout << "\n----------\n";
}

void PrintArray(int array[], int lenght) { //эквивалент void PrintArray(int* array, int lenght)
    //std::cout << *array;
    //int lenght = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < lenght; i++) {
        std::cout << array[i] << " ";
    }
    separator();
}

void PrintArray(int* begin, int* end) {
    for (int* p = begin; p < end; p++) std::cout << *p << " ";
    separator();
}

const int cols = 2;

void PrintArray2(int(*array)[cols], int rows) {// Экввивалент void PrintArray2(int array[][cols], int rows)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void TestArray(const int* array) {
    //array[1] = 25; - Функция гарантирует, чтоникаких изменений массива внутри неё не будет
}

//-----------------указатели на функции----------------------------

void function1() {
    std::cout << "function1\n";
}
void function2() {
    std::cout << "function2\n";
}

float add(float x, float y) {
    return x + y;
}

float sub(float x, float y) {
    return x - y;
}
//--нахождение min и max в массиве
int getMax(int arrayy[], int lenght, bool(*compare)(int, int)) {
    int max = arrayy[0];
    for (int i = 1; i < lenght; i++) {
        if (compare(arrayy[i], max)) max = arrayy[i];
    }
    return max;
}

bool compare1(int x, int y) {
    return x > y;
}
bool compare2(int x, int y) {
    return x < y;
}
//--нахождение min и max в массиве

void numberPositive() {
    std::cout << "+\n";
}
void numberNegative() {
    std::cout << "-\n";
}

void (*function(int x))() { //так задаются функции, которые возвращают указатели на другие функции
    if (x > 0) return numberPositive;
    else return numberNegative;
}
//-------------------------динамические объекты ------------------------

int* test() {
    return new int(5);
}


int main()
{
    std::cout << "Functions and Arrays\n"; //Функции и массивы
    int array[] = {2, 9, 4, 6, 11, 54, 1, 5};
    PrintArray(array, sizeof(array) / sizeof(array[0]));
    separator();
    PrintArray(array, sizeof(array) / sizeof(*array));

    PrintArray(std::begin(array), std::end(array)); //альтернативный вариант для вывода массива

    int array2[3][2] = { {2, -5}, {-4, 9}, {1, 0} };
    PrintArray2(array2, 3);
    separator();
    
    TestArray(array);
    PrintArray(std::begin(array), std::end(array));

    std::cout << "---------FunctionPointers------------" << "\n";//--------------указатели на функции
    
    void (*pf)();
    pf = function1;
    pf();

    pf = function2;
    pf();

    separator();

    void(*pfs[])() = { function1,function2 }; //массив указателей на функции
    pfs[0]();
    pfs[1]();

    float (*operation)(float, float);
    operation = add;

    std::cout << operation(5, 7) << "\n";
    
    operation = sub;
    std::cout << operation(5, 7) << "\n";


    separator();
    int arrayy[] = { 2, 5, 7, 4, -2, 51, 11 }; //нахождение min и max в массиве
    std::cout << "MAX = " << getMax(arrayy, 6, compare1) << "\n";
    std::cout << "MIN = " << getMax(arrayy, 6, compare2) << "\n";
    
    separator();
    void(*testf)() = function(-5);
    testf();
    
    testf = function(5);
    testf();

    std::cout << "\n";
    std::cout << "---------Dinamic Objects-------------\n"; //динамические объекты --------------

    int* pc1 = new int(5); // new - всегда возврат указателя
    std::cout << pc1 << " = " << *pc1 << "\n";
    delete pc1; //удаление указателя для очистки оперативной памяти, воизбежание утечки памяти

    int* pc2 = test();//динамическая переменная объявлена внутри функции, необходимо удалить после ее выполнения
    delete pc2;
    //delete pc2; - дважды вызывать удаление того же указателя нельзя, может привести к проблемам и ошибкам

    int* ar = new int[3] {3, 7, 9};
    std::cout << ar[1] << "\n";

    for (int* i = ar; i < ar + 3; i++) {
        std::cout << *i << " ";
    }
    delete[] ar;
    separator();

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
