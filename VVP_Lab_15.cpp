#include <iostream>

using namespace std;

double Power(float A);
int Sign(float X);
double Rings(double R1, double R2);
int Quarter(double x, double y);
double Fact2(int N);

int main()
{
    setlocale(LC_ALL, "ru");
    int number, a, b, N;
    double X, R1, R2, Rad, x, y;
    float A, B;
    bool end = true;
    while (end == true) {
        cout << "Выберите задание:\n" <<
            "1. Описать функцию PowerA3(A, B), вычисляющую третью степень числа A и возвращающую ее в переменной B (A — входной, B — выходной параметр; оба параметра являются вещественными).\nС помощью этой функции найти третьи степени пяти данных чисел.\n" <<
            "2. Описать функцию Sign(X) целого типа, возвращающую для вещественного числа X следующие значения:\n\t−1, если X < 0; 0, если X = 0; 1, если X > 0.\nС помощью этой функции найти значение выражения Sign(A) + Sign(B) для данных вещественных чисел A и B.\n" <<
            "3. Описать функцию RingS(R1, R2) вещественного типа, находящую площадь кольца, заключенного между двумя окружностями с общим центром и радиусами R1 и R2 (R1 и R2 — вещественные, R1 > R2).\nС ее помощью найти площади трех колец, для которых даны внешние и внутренние радиусы.\n" <<
            "4. Описать функцию Quarter(x, y) целого типа, определяющую номер координатной четверти, в которой находится точка с ненулевыми вещественными координатами (x, y).\nС помощью этой функции найти номера координатных четвертей для трех точек с данными ненулевыми координатами.\n" <<
            "5. Описать функцию Fact2(N) вещественного типа, вычисляющую двойной факториал\n\tN!!= 1·3·5·. ..·N, если N — нечетное;\n\tN!!= 2·4·6·. ..·N, если N — четное.\n(N > 0 — параметр целого типа; вещественное возвращаемое значение используется для того, чтобы избежать целочисленного переполнения при больших значениях N).\n";
        cin >> number;
        if (number >= 0 and number <= 5) {
            switch (number)
            {
            case 1:
                system("cls");
                cout << "Вы просматриваете 1 задание!\n\n";
                for (int i = 0; i < 5; i++) {
                    cout << "Введите вещественное число A: ";
                    cin >> A;
                    B = Power(A);
                    cout << i + 1 << " число в третьей степени равно " << B << endl;
                }
                break;
            case 2:
                system("cls");
                cout << "Вы просматриваете 2 задание!\n\n";
                cout << "Введите вещественные числа A и B: ";
                cin >> A >> B;
                a = Sign(A);
                b = Sign(B);
                cout << "Сумма Sign(A) + Sign(B): " << a+b << endl;
                break;
            case 3:
                system("cls");
                cout << "Вы просматриваете 3 задание!\n\n";
                for (int i = 0; i < 3; i++) {
                    cout << "Введите R1 и R2 (R1 > R2) для " << i + 1 << " кольца: ";
                    cin >> R1 >> R2;
                    if (R1 > R2 and R1 > 0 and R2 > 0) {
                        Rad = Rings(R1, R2);
                        cout << "Площадь кольца равна: " << Rad << endl;
                    }
                    else {
                        cout << "Ошибка ввода!!!\n";
                    }
                }
                break;
            case 4:
                system("cls");
                cout << "Вы просматриваете 4 задание!\n\n";
                for (int i = 0; i < 3; i++) {
                    cout << "Введите координаты x и y (x!=0 и y!=0): ";
                    cin >> x >> y;
                    if (x != 0 and y != 0) {
                        a = Quarter(x, y);
                        cout << "Для " << i + 1 << " случая x и y находятся в " << a << " части координат!\n";
                    }
                    else {
                        cout << "Ошибка ввода данных!\n";
                    }
                }
                break;
            case 5:
                system("cls");
                cout << "Вы просматриваете 5 задание!\n\n";
                cout << "Введите целое число N: ";
                cin >> N;
                if (N > 0) {
                    cout << "Для числа " << N << " двойной факториал равен: " << Fact2(N) << endl;
                }
                else {
                    cout << "Ошибка ввода!\n";
                }
                break;
            }
        }
        else {
            system("cls");
            cout << "Спасибо за проверку лабы!! :)\n";
            end = false;
        }
    }
}

double Power(float A) {
    double B;
    B = A * A * A;
    return B;
}

int Sign(float X) {
    if (X < 0) {
        return -1;
    }
    else if (X > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

double Rings(double R1, double R2) {
    const double P = 3.14;
    double SR1, SR2;
    SR1 = P * pow(R1, 2);
    SR2 = P * pow(R2, 2);
    return SR1 - SR2;
}

int Quarter(double x, double y) {
    if (x > 0 and y > 0) {
        return 1;
    }
    else if (x < 0 and y > 0) {
        return 2;
    }
    else if (x < 0 and y < 0) {
        return 3;
    }
    else if (x > 0 and y < 0) {
        return 4;
    }
}

double Fact2(int N) {
    double sum = 1;
    if (N%2==0) {
        for (int i = 2; i <= N; i += 2) {
            sum *= i;
        }
    }
    else {
        for (int i = 1; i <= N; i += 2) {
            sum *= i;
        }
    }
    return sum;
}