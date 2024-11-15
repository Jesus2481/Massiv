#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    int choice;

    do {
        cout << "Выберите задание:\n";
        cout << "1. Найти минимальное и максимальное значения в массиве\n";
        cout << "2. Найти сумму элементов массива, меньших заданного числа\n";
        cout << "3. Найти месяц с минимальной и максимальной прибылью\n";
        cout << "0. Выход\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Задание 1
            const int size = 10; // Размер массива
            int arr[size];

            // Заполнение массива случайными числами
            srand(time(0));
            for (int i = 0; i < size; ++i) {
                arr[i] = rand() % 100; // Числа от 0 до 99
            }

            // Поиск минимального и максимального элементов
            int min = arr[0], max = arr[0];
            for (int i = 1; i < size; ++i) {
                if (arr[i] < min) {
                    min = arr[i];
                }
                if (arr[i] > max) {
                    max = arr[i];
                }
            }

            cout << "Минимальный элемент: " << min << endl;
            cout << "Максимальный элемент: " << max << endl;
            break;
        }
        case 2: {
            // Задание 2
            const int size = 10;
            int arr[size];
            int sum = 0, limit;

            // Заполнение массива случайными числами (например, от 1 до 100)
            for (int i = 0; i < size; ++i) {
                arr[i] = rand() % 100 + 1;
            }

            cout << "Введите предельное значение: ";
            cin >> limit;

            for (int i = 0; i < size; ++i) {
                if (arr[i] < limit) {
                    sum += arr[i];
                }
            }

            cout << "Сумма элементов, меньших " << limit << ": " << sum << endl;
            break;
        }
        case 3: {
            // Задание 3
            const int months = 12;
            int profit[months];
            int start, end, min_month, max_month;

            // Ввод прибыли за каждый месяц
            for (int i = 0; i < months; ++i) {
                cout << "Введите прибыль за " << i + 1 << " месяц: ";
                cin >> profit[i];
            }

            cout << "Введите начало диапазона (месяц): ";
            cin >> start;
            cout << "Введите конец диапазона (месяц): ";
            cin >> end;

            // Поиск минимального и максимального значения в диапазоне
            min_month = start - 1;
            max_month = start - 1;
            for (int i = start - 1; i < end; ++i) {
                if (profit[i] < profit[min_month]) {
                    min_month = i;
                }
                if (profit[i] > profit[max_month]) {
                    max_month = i;
                }
            }

            cout << "Минимальная прибыль была в " << min_month + 1 << " месяце." << endl;
            cout << "Максимальная прибыль была в " << max_month + 1 << " месяце." << endl;
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор." << endl;
        }
    } while (choice != 0);

    return 0;
}