#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <winuser.h>
using namespace std;


int task_ind = 0, subtask_ind = 0;
int max_subtask[4] = {0, 10, 20, 40};
string tasks[3] = {
    "Дано натуральное n.\nВычисли значение\nвыбранной суммы...",
    "Дано натуральное n\nи действительное x.\nВычислить значение выбранной суммы...",
    "Вычислить значения\nвыбранной функции f(x)\nна отрезке [a;b] с шагом h..." };
string subtasks[40] = {
    "1   1         1\n- + - + ... + -\n1   2         n",
    " \n2^n\n ",
    "(       1 )(       1 )   (       1 )\n(1  +  ---)(1  +  ---)...(1  +  ---)\n(      1^2)(      2^2)   (      n^2)",
    "  1       1           -1^(n+1)\n----- - ----- + ... + --------\n1 * 2   2 * 3         n(n + 1)",
    " 1     1           1 \n--- + --- + ... + ---\n1^5   2^5         n^5",
    " 1     1               1    \n--- + --- + ... + ----------\n3^2   5^2         (2n + 1)^2",
    "  1   1         (-1)^n\n- - + - + ... + ------\n  3   5         2n + 1",
    "1!      2!                    n!        \n-- + ------- + ... + -------------------\n1    1 + 1/2         1 + 1/2 + ... + 1/n",
    " \nsqrt(2 + sqrt(2 + ... sqrt(2)))\n(n корней)",
    " 1          1                        1           \n---- + ----------- + ... + ----------------------\nsin1   sin1 + sin2         sin1 + sin2 +...+ sinn",
    "    x    x^2         x^n\n1 + -- + --- + ... + ---\n    1!    2!          n!",
    "(1             )         (1             )\n(-- + sqrt(|x|)) + ... + (-- + sqrt(|x|))\n(1!            )         (n!            )",
    "(    sin(x))(    sin(2x))   (    sin(nx))\n(1 + ------)(1 + -------)...(1 + -------)\n(      1!  )(      2!   )   (      n!   )",
    "    x^3   x^5                      x^(2m-1)\nx - --- + --- - ... + (-1)^(m-1) * --------\n    3!    5!                       (2m-1)! ",
    "    x^2   x^4                  x^2m \n1 - --- + --- - ... + (-1)^m * -----\n    2!    4!                   (2m)!",
    "    x^3   x^5         x^(2m-1)\nx + --- + --- + ... + --------\n    3!    5!          (2m-1)! ",
    "    x^2   x^4         x^2m \n1 + --- + --- + ... + -----\n    2!    4!          (2m)!",
    "    x^2   x^3                      x^n\nx - --- + --- + ... + (-1)^(n-1) * ---\n     2     3                        n ",
    "    x^3   x^5                      x^(2m-1)\nx - --- + --- + ... + (-1)^(m-1) * --------\n     3     5                        2m - 1 ",
    "      x^2   x^3         x^n\n- x - --- - --- - ... - ---\n       2     3           n ",
    "ln(x)\nНа отрезке [1; 1.5]\nС шагом 0.1",
    "1 + ln^2(x)\nНа отрезке [0.4; 1]\nС шагом 0.1", 
    "1 + e^x\nНа отрезке [0.5; 0.6]\nС шагом 0.01", 
    "e^x^2 / 2\nНа отрезке [2; 3]\nС шагом 0.2", 
    "cos(x)e^(-x)\nНа отрезке [1; 2]\nС шагом 0.2", 
    "1 / (1 + e^(-x))\nНа отрезке [3; 4]\nС шагом 0.2", 
    "sin(x)sh(x)\nНа отрезке [1; 5]\nС шагом 1", 
    "0.5 + sh^2(x)\nНа отрезке [2; 3]\nС шагом 0.2", 
    "sqrt(x)ch(x)\nНа отрезке [3; 4]\nС шагом 0.2", 
    "1 / (1 + ch^2(x))\nНа отрезке [2; 4]\nС шагом 0.5", 
    "sqrt(x)sh(x)\nНа отрезке [1; 5]\nС шагом 1", 
    "e^(-x)ch(x)\nНа отрезке [1; 4]\nС шагом 1", 
    "ln(x^2)\nНа отрезке [1; 1.4]\nС шагом 0.1", 
    "x + ln(x)\nНа отрезке [1; 5]\nС шагом 1", 
    "1 / (1 + sin(x))\nНа отрезке [п/3; п/6]\nС шагом п/10", 
    "sin(x) + sqrt(x)\nНа отрезке [п/6; п/4]\nС шагом п/10", 
    "x(1 - cos(x))\nНа отрезке [0.4; 0.8]\nС шагом 0.1", 
    "e^(x+3)sin(x)\nНа отрезке [0; 2]\nС шагом 0.5", 
    "cos(x)ch(x)\nНа отрезке [1; 5]\nС шагом 1", 
    "e^(x+1)sh(x)\nНа отрезке [1; 4]\nС шагом 1" };


void print_box(stringstream &ss) {
    string line;
    size_t j;
    while (getline(ss, line, '\n')) {
        j = line.length();
        for (int i = 0; i < 50; ++i) {
            if (50 - j > 0) {
                line = " " + line;
                ++j;
            }
            else {
                break;
            }
            if (50 - j >= 1) {
                line += " ";
                ++j;
            }
        }
        cout << "|" << line << "|" << endl;
    }
}

int task_choice() {
    string line;
    stringstream ss;
    subtask_ind = 0;
    for (;;) {
        cout << "Выберите из списка задание, которые вы хотите решить,\nпереключаясь с помощью клавиш.\n" << endl;
        cout << "                 - = Задание " << task_ind + 1 << " = -" << endl;
        ss.clear();
        ss << tasks[task_ind];
        cout << "#--------------------------------------------------#" << endl;
        print_box(ss);
        cout << "#--------------------------------------------------#" << endl;
        cout << "  <-- (A)  |  ENTER  |  (D) -->  |  (W) - TO MENU\n\n";
        for (;;) {
            _getch();
            if (GetKeyState(0x41) & 0x8000) {
                if (task_ind == 0) {
                    task_ind = 2;
                }
                else {
                    task_ind -= 1;
                }
                break;
            }
            if (GetKeyState(0x0D) & 0x8000) {
                system("cls");
                return 0;
            }
            if (GetKeyState(0x44) & 0x8000) {
                if (task_ind == 2) {
                    task_ind = 0;
                }
                else {
                    task_ind += 1;
                }
                break;
            }
            if (GetKeyState(0x57) & 0x8000) {
                system("cls");
                return 1;
            }
        }
        system("cls");
    }
}

int subtask_choice() {
    string line;
    stringstream ss;
    for (;;) {
        ss.clear();
        ss << tasks[task_ind];
        cout << "#--------------------------------------------------#" << endl;
        print_box(ss);
        cout << "#--------------------------------------------------#" << endl;
        cout << "\n                - = Подзадание " << subtask_ind + 1 << " = -" << endl;
        ss.clear();
        ss << subtasks[subtask_ind + max_subtask[task_ind]];
        cout << "#--------------------------------------------------#" << endl;
        print_box(ss);
        cout << "#--------------------------------------------------#" << endl;
        cout << "    <-- (A)  |  ENTER  |  (D) -->  |  (W) - BACK\n\n";
        for (;;) {
            _getch();
            if (GetKeyState(0x41) & 0x8000) {
                if (subtask_ind == 0) {
                    subtask_ind = max_subtask[task_ind + 1] - max_subtask[task_ind] - 1;
                }
                else {
                    subtask_ind -= 1;
                }
                break;
            }
            if (GetKeyState(0x0D) & 0x8000) {
                return 0;
            }
            if (GetKeyState(0x44) & 0x8000) {
                if (subtask_ind == max_subtask[task_ind + 1] - max_subtask[task_ind] - 1) {
                    subtask_ind = 0;
                }
                else {
                    subtask_ind += 1;
                }
                break;
            }
            if (GetKeyState(0x57) & 0x8000) {
                system("cls");
                return 1;
            }
        }
        system("cls");
    }
}

void task_1_resolve() {
    double result = 0;
    int n, cycle = 1;
    cout << "\nВведите n: ";
    cin >> n;
    if (subtask_ind == 0) {
        while (cycle <= n) {
            result += 1.0 / cycle;
            cycle++;
        }
    }
    if (subtask_ind == 1) {
        result = pow(2, n);
    }
    if (subtask_ind == 2) {
        result = 1;
        while (cycle <= n) {
            result *= 1 + 1 / pow(cycle, 2);
            cycle++;
        }
    }
    if (subtask_ind == 3) {
        while (cycle <= n) {
            result += pow(-1, cycle + 1) / (cycle * (cycle + 1));
            cycle++;
        }
    }
    if (subtask_ind == 4) {
        while (cycle <= n) {
            result += 1 / pow(cycle, 5);
            cycle++;
        }
    }
    if (subtask_ind == 5) {
        while (cycle <= n) {
            result += 1 / pow(2 * cycle + 1, 2);
            cycle++;
        }
    }
    if (subtask_ind == 6) {
        while (cycle <= n) {
            result += pow(-1, cycle) / (2 * cycle + 1);
            cycle++;
        }
    }
    if (subtask_ind == 7) {
        int fact = 1;
        double temp = 0;
        while (cycle <= n) {
            for (int i = 1; i <= cycle; i++) {
                fact *= i;
            }
            for (int j = 1; j <= cycle; j++) {
                temp += 1.0 / j;
            }
            result += fact / temp;
            temp = 0, fact = 1;
            cycle++;
        }
    }
    if (subtask_ind == 8) {
        while (cycle <= n) {
            result = sqrt(2 + result);
            cycle++;
        }
    }
    if (subtask_ind == 9) {
        double temp = 0;
        while (cycle <= n) {
            for (int i = 1; i <= cycle; i++) {
                temp += sin(i);
            }
            result = 1 / temp;
            temp = 0;
            cycle++;
        }
    }
    cout << "\nРезультат суммы: " << result << endl;
}

void task_2_resolve() {
    double x, result = 0;
    int n, cycle = 1, fact = 1;
    cout << "\nВведите n: ";
    cin >> n;
    cout << "\nВведите x: ";
    cin >> x;
    if (subtask_ind == 0) {
        cycle--;
        while (cycle <= n) {
            for (int i = 1; i <= cycle; i++) {
                fact *= i;
            }
            result += pow(x, cycle) / fact;
            fact = 1;
            cycle++;
        }
    }
    if (subtask_ind == 1) {
        while (cycle <= n) {
            for (int i = 1; i <= cycle; i++) {
                fact *= i;
            }
            result += 1.0 / fact + sqrt(fabs(x));
            fact = 1;
            cycle++;
        }
    }
    if (subtask_ind == 2) {
        result = 1;
        while (cycle <= n) {
            for (int i = 1; i <= cycle; i++) {
                fact *= i;
            }
            result *= 1 + sin(cycle * x) / fact;
            fact = 1;
            cycle++;
        }
    }
    if (subtask_ind == 3) {
        while (cycle <= n) {
            for (int i = 1; i <= 2 * cycle - 1; i++) {
                fact *= i;
            }
            result += pow(-1, cycle - 1) * pow(x, 2 * cycle - 1) / fact;
            fact = 1;
            cycle++;
        }
    }
    if (subtask_ind == 4) {
        cycle--;
        while (cycle <= n) {
            for (int i = 1; i <= 2 * cycle; i++) {
                fact *= i;
            }
            result += pow(-1, cycle) * pow(x, 2 * cycle) / fact;
            fact = 1;
            cycle++;
        }
    }
    if (subtask_ind == 5) {
        while (cycle <= n) {
            for (int i = 1; i <= 2 * cycle - 1; i++) {
                fact *= i;
            }
            result += pow(x, 2 * cycle - 1) / fact;
            fact = 1;
            cycle++;
        }
    }
    if (subtask_ind == 6) {
        cycle--;
        while (cycle <= n) {
            for (int i = 1; i <= 2 * cycle; i++) {
                fact *= i;
            }
            result += pow(x, 2 * cycle) / fact;
            fact = 1;
            cycle++;
        }
    }
    if (subtask_ind == 7) {
        while (cycle <= n) {
            result += pow(-1, cycle - 1) * pow(x, cycle) / cycle;
            cycle++;
        }
    }
    if (subtask_ind == 8) {
        while (cycle <= n) {
            result += pow(-1, cycle - 1) * pow(x, 2 * cycle - 1) / (2 * cycle - 1);
            cycle++;
        }
    }
    if (subtask_ind == 9) {
        while (cycle <= n) {
            result -= pow(x, cycle) / cycle;
            cycle++;
        }
    }
    cout << "\nРезультат суммы: " << result << endl;
}

void task_3_resolve() {
    double x, b, h, result;
    if (subtask_ind == 0) {
        x = 1.0, b = 1.5, h = 0.1;
    }
    if (subtask_ind == 1) {
        x = 0.4, b = 1, h = 0.1;
    }
    if (subtask_ind == 2) {
        x = 0.5, b = 0.6, h = 0.01;
    }
    if (subtask_ind == 3) {
        x = 2, b = 3, h = 0.2;
    }
    if (subtask_ind == 4) {
        x = 1, b = 2, h = 0.2;
    }
    if (subtask_ind == 5) {
        x = 3, b = 4, h = 0.2;
    }
    if (subtask_ind == 6) {
        x = 1, b = 5, h = 1;
    }
    if (subtask_ind == 7) {
        x = 2, b = 3, h = 0.2;
    }
    if (subtask_ind == 8) {
        x = 3, b = 4, h = 0.2;
    }
    if (subtask_ind == 9) {
        x = 2, b = 4, h = 0.5;
    }
    if (subtask_ind == 10) {
        x = 1, b = 5, h = 1;
    }
    if (subtask_ind == 11) {
        x = 1, b = 4, h = 1;
    }
    if (subtask_ind == 12) {
        x = 1, b = 1.4, h = 0.1;
    }
    if (subtask_ind == 13) {
        x = 1, b = 5, h = 1;
    }
    if (subtask_ind == 14) {
        double pi = acos(-1.0);
        x = pi/3, b = M_PI/6, h = M_PI/10;
    }
    if (subtask_ind == 15) {
        double pi = acos(-1.0);
        x = pi/6, b = pi/4, h = pi/10;
    }
    if (subtask_ind == 16) {
        x = 0.4, b = 0.8, h = 0.1;
    }
    if (subtask_ind == 17) {
        x = 0, b = 2, h = 0.5;
    }
    if (subtask_ind == 18) {
        x = 1, b = 5, h = 1;
    }
    if (subtask_ind == 19) {
        x = 1, b = 4, h = 1;
    }
    for (; x-h < b; x += h) {
        if (subtask_ind == 0) {
            result = log(x);
        }
        if (subtask_ind == 1) {
            result = 1 + pow(log(x), 2);
        }
        if (subtask_ind == 2) {
            result = 1 + exp(x);
        }
        if (subtask_ind == 3) {
            result = exp(pow(x, 2)) / 2;
        }
        if (subtask_ind == 4) {
            result = cos(x) * exp(-x);
        }
        if (subtask_ind == 5) {
            result = 1 / (1 + exp(-x));
        }
        if (subtask_ind == 6) {
            result = sin(x) * sinh(x);
        }
        if (subtask_ind == 7) {
            result = 0.5 + pow(sinh(x), 2);
        }
        if (subtask_ind == 8) {
            result = sqrt(x) * cosh(x);
        }
        if (subtask_ind == 9) {
            result = 1 / (1 + pow(cosh(x), 2));
        }
        if (subtask_ind == 10) {
            result = sqrt(x) * sinh(x);
        }
        if (subtask_ind == 11) {
            result = exp(-x) * cosh(x);
        }
        if (subtask_ind == 12) {
            result = log(pow(x, 2));
        }
        if (subtask_ind == 13) {
            result = x + log(x);
        }
        if (subtask_ind == 14) {
            result = 1 / (1 + sin(x));
        }
        if (subtask_ind == 15) {
            result = sin(x) + sqrt(x);
        }
        if (subtask_ind == 16) {
            result = x * (1 - cos(x));
        }
        if (subtask_ind == 17) {
            result = exp(x + 3) * sin(x);
        }
        if (subtask_ind == 18) {
            result = cos(x) * cosh(x);
        }
        if (subtask_ind == 19) {
            result = exp(1 + x) * sinh(x);
        }
        cout << "Значение функции f(x) на шаге " << x << ": " << result << endl;
    }
}

void setConsoleWindow(int XSize, int YSize)
{
    HWND hWnd = GetForegroundWindow();

    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

    SetWindowPos(hWnd, NULL, 475, 150, XSize, YSize, NULL);
    SMALL_RECT windowSize;
    windowSize.Bottom = YSize;
    windowSize.Left = 0;
    windowSize.Right = XSize;
    windowSize.Top = 0;

    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);

    COORD bufferSize = { XSize , YSize };

    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void main_menu() {
    setConsoleWindow(575, 375);
    string menu[10] = { "", "- = Начать = -", "", "", "- = Настройки = -", "", "", "- = Выйти = -", "", "" };
    string line_menu;
    int choice = 0;
    stringstream ss;
    for (;;) {
        cout << "                Решатор Лаборатор v3.0" << endl;
        line_menu = "";
        for (int i = 0; i < 10; i++) {
            if (choice * 3 + 2 == i) {
                for (int j = 0; j < menu[i - 1].length()-8; j++) {
                    line_menu += "-";
                }
                line_menu += "\n";
            }
            else {
                line_menu += menu[i] + "\n";
            }
        }
        ss.clear();
        ss << line_menu;
        cout << "#--------------------------------------------------#" << endl;
        print_box(ss);
        cout << "#--------------------------------------------------#" << endl;
        cout << "           UP (W)  |  ENTER  |  (S) - DOWN\n\n";
        for (;;) {
            _getch();
            if (GetKeyState(0x57) & 0x8000) {
                if (choice == 0) {
                    choice = 2;
                }
                else {
                    choice--;
                }
                break;
            }
            if (GetKeyState(0x0D) & 0x8000) {
                if (choice == 0) {
                    system("cls");
                    for (;;) {
                        setConsoleWindow(575, 300);
                        if (task_choice() != 1) {
                            setConsoleWindow(575, 360);
                            if (subtask_choice() != 1) {
                                setConsoleWindow(575, 500);
                                system("cls");
                                stringstream ss;
                                ss << tasks[task_ind];
                                cout << "          - = Задание " << task_ind + 1 << " | Подзадание " << subtask_ind + 1 << " = -" << endl;
                                cout << "#--------------------------------------------------#" << endl;
                                print_box(ss);
                                cout << "|                                                  |" << endl;
                                ss.clear();
                                ss << subtasks[subtask_ind + max_subtask[task_ind]];
                                print_box(ss);
                                cout << "#--------------------------------------------------#\n" << endl;
                                if (task_ind == 0) {
                                    task_1_resolve();
                                }
                                if (task_ind == 1) {
                                    task_2_resolve();
                                }
                                if (task_ind == 2) {
                                    task_3_resolve();
                                }
                                system("pause");
                                setConsoleWindow(575, 375);
                                break;
                            }
                        }
                        else {
                            setConsoleWindow(575, 375);
                            break;
                        }
                    }
                }
                if (choice == 1) {

                }
                if (choice == 2) {
                    system("cls");
                    return;
                }
                break;
            }
            if (GetKeyState(0x53) & 0x8000) {
                if (choice == 2) {
                    choice = 0;
                }
                else {
                    choice++;
                }
                break;
            }
        }
        system("cls");
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    main_menu();
}