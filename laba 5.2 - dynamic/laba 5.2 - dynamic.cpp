#include <iostream>
#include <locale>

using namespace std;

/*
*Лабораторная работа 5. Задание 2. Индивидуальный вариант 24. Динамический массив.
*Удалить повторяющиеся элементы массива.
* return 0 - все ок. return 1 - ошибка.
*/

int main() {
    setlocale(LC_ALL, "ru");

    int N;
    cout << "Введите количество элементов: ";
    cin >> N;

    if (N <= 0) {
        cerr << "Введите натуральное количество элементов!";
        return 1;
    }

    int* A = new int[N];

    cout << "Введите элементы массива: " << endl;

    for (int i = 0; i < N; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> A[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (A[i] == A[j]) {
                for (int k = j; k < N - 1; k++) {
                    A[k] = A[k + 1];
                }
                N--;
                break;
            }
        }
    }

    cout << "Массив без дубликатов: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }

    return 0;
    delete[] A;
}
