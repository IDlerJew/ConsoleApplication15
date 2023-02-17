// ConsoleApplication15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class Sort {
public:
    void InsertionSort(int b[], int n) {// Вставка 

        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0 && b[j - 1] > b[j]; j--) {// пока j>0 и элемент j-1 > j, x-массив int
                int k = b[j - 1];
                b[j - 1] = b[j];
                b[j] = k;
            }
        }
    }
    void SelectionSort(int b[], int n) { //Выбор 
        for (int i = 0; i < n; i++) {
            int min=b[i];
            int min_iter=i;
            for (int j = i; j < n; j++) {
                if (b[j] < min) {
                    min = b[j];
                    min_iter=j;
                }
            }
            b[min_iter] = b[i];
            b[i] = min;

            
         }
    }
    void Merge(int b[], int first, int last)
    {
        int middle, start, final, j;
        int* mas = new int[100];
        middle = (first + last) / 2; //вычисление среднего элемента
        start = first; //начало левой части
        final = middle + 1; //начало правой части
        for (j = first; j <= last; j++) //выполнять от начала до конца
            if ((start <= middle) && ((final > last) || (b[start] < b[final])))
            {
                mas[j] = b[start];
                start++;
            }
            else
            {
                mas[j] = b[final];
                final++;
            }
        //возвращение результата в список
        for (j = first; j <= last; j++) b[j] = mas[j];
        delete[]mas;
    }
    //рекурсивная процедура сортировки
    void MergeSort(int b[], int first, int last)
    {
        {
            if (first < last)
            {
                MergeSort(b, first, (first + last) / 2); //сортировка левой части
                MergeSort(b, (first + last) / 2 + 1, last); //сортировка правой части
                Merge(b, first, last); //слияние двух частей
            }
        }
    }
    void print(int b[],int n) {
        for (int i = 0; i < n; i++) {
            cout <<" " << b[i] << " ";
        }
        cout << endl;
    }
    
};
int main()
{ 
    setlocale(0, "rus");
    const int n = 5;
    int first[n] = { 4128,1,6,2,127 };
    int second[n] = { 56,17,45,9,13 };
    int third[n] = { 41,16,62,12,7 };
    Sort b;
    cout << "Массивы перед сортировкой " << endl;
    b.print(first, n);
    b.print(second, n);
    b.print(third, n);
    
    b.InsertionSort(second, n);
    b.SelectionSort(third, n);
    b.MergeSort(first, 0,4);

    cout << "Массивы после сортировки " << endl;
    cout << "Сортировка слиянием";
    b.print(first, n);
    cout << "Сортировка вставкой";
    b.print(second, n);
    cout << "Сортировка выбором";
    b.print(third, n);

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
