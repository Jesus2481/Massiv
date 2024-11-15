#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    int choice;

    do {
        cout << "�������� �������:\n";
        cout << "1. ����� ����������� � ������������ �������� � �������\n";
        cout << "2. ����� ����� ��������� �������, ������� ��������� �����\n";
        cout << "3. ����� ����� � ����������� � ������������ ��������\n";
        cout << "0. �����\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            // ������� 1
            const int size = 10; // ������ �������
            int arr[size];

            // ���������� ������� ���������� �������
            srand(time(0));
            for (int i = 0; i < size; ++i) {
                arr[i] = rand() % 100; // ����� �� 0 �� 99
            }

            // ����� ������������ � ������������� ���������
            int min = arr[0], max = arr[0];
            for (int i = 1; i < size; ++i) {
                if (arr[i] < min) {
                    min = arr[i];
                }
                if (arr[i] > max) {
                    max = arr[i];
                }
            }

            cout << "����������� �������: " << min << endl;
            cout << "������������ �������: " << max << endl;
            break;
        }
        case 2: {
            // ������� 2
            const int size = 10;
            int arr[size];
            int sum = 0, limit;

            // ���������� ������� ���������� ������� (��������, �� 1 �� 100)
            for (int i = 0; i < size; ++i) {
                arr[i] = rand() % 100 + 1;
            }

            cout << "������� ���������� ��������: ";
            cin >> limit;

            for (int i = 0; i < size; ++i) {
                if (arr[i] < limit) {
                    sum += arr[i];
                }
            }

            cout << "����� ���������, ������� " << limit << ": " << sum << endl;
            break;
        }
        case 3: {
            // ������� 3
            const int months = 12;
            int profit[months];
            int start, end, min_month, max_month;

            // ���� ������� �� ������ �����
            for (int i = 0; i < months; ++i) {
                cout << "������� ������� �� " << i + 1 << " �����: ";
                cin >> profit[i];
            }

            cout << "������� ������ ��������� (�����): ";
            cin >> start;
            cout << "������� ����� ��������� (�����): ";
            cin >> end;

            // ����� ������������ � ������������� �������� � ���������
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

            cout << "����������� ������� ���� � " << min_month + 1 << " ������." << endl;
            cout << "������������ ������� ���� � " << max_month + 1 << " ������." << endl;
            break;
        }
        case 0:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "������������ �����." << endl;
        }
    } while (choice != 0);

    return 0;
}