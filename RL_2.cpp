#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <math.h>
using namespace std;

int task_ind = 0;
int subtask_ind = 0;

void choose() {
    string tasks[11] = {
        "               |x|-|y|                 \n      Получить -------- вводя x,y      \n               1 + |xy|                ",
        "      Найти среднее арифметическое     \n            кубов двух чисел           \n  и среднее геометрическое их модулей  ",
        "          Вычислить расстояние         \n          между двумя точками          \n         с данными координатами        ",
        "      Найти площадь треугольника       \n со сторонами a,b,c по формуле Герона: \n      S = sqrt(p(p-a)(p-b)(p-c))       ",
        "              Даны x,y,z.              \n                Найти w                \n        по выбранной формуле...        ",
        " Даны два числа. Вывести первое число, \n       если оно больше второго,        \n     и оба числа, если это не так      ",
        "                                       \n Найти наименьшее из трех данных чисел \n                                       ",
        "            Даны три числа,            \nявляющиеся длинами сторон треугольника.\n      Определить тип треугольника      ",
        "              Даны x,y,z.              \n              Найти ответ              \n        по выбранной формуле...        ",
        "                 Дано x.               \n              Вычислить y              \n     по выбранной системе условий...   ",
        "       Определить, попадает ли         \n        заданная точка внутрь          \n         выбранной области...          " };
    string ans, line, lite, chosen = "NO";
    stringstream ss;
    while (chosen != "YES") {
        while (chosen == "NO") {
            cout << "\n                  Задание " << task_ind + 1 << endl;
            if (lite != "YES") {
                ss.clear();
                ss << tasks[task_ind];
                cout << "-----------------------------------------------" << endl;
                while (getline(ss, line, '\n')) {
                    cout << "|   " << line << "   |" << endl;
                }
                cout << "-----------------------------------------------" << endl;
            }
            cout << " 1 - назад  2 - выбрать  3 - вперед  4 - лайт\n\n> ";
            cin >> ans;
            if (ans == "1") {
                if (task_ind == 0) {
                    task_ind = 10;
                }
                else {
                    task_ind -= 1;
                }
            }
            if (ans == "2") {
                chosen = "YES";
            }
            if (ans == "3") {
                if (task_ind == 10) {
                    task_ind = 0;
                }
                else {
                    task_ind += 1;
                }
            }
            if (ans == "4") {
                if (lite == "YES") {
                    lite = "NO";
                }
                else {
                    lite = "YES";
                }
            }
        }
        if (task_ind == 4 or task_ind == 8 or task_ind == 9 or task_ind == 10) {
            chosen = "NO2";
            string task5[4] = {
                "       (|            (          y       )|)\nw = sin(|(y-sqrt(|x|)(x - --------------)|)\n       (|            (    z^2 + (x^2)/4 )|)",
                "                       x^2                 \n       w = x - --------------------        \n               1 + sin^2(x + y + z)        ",
                "                 (      x^2    )           \n          w = cos(z^2 + --- + y)           \n                 (       4     )           ",
                "                        cos^2(x)           \n       w = y + x - -----------------       \n                   1 + sqrt(|y + z|)       " };
            string task9[2] = {
                "                                           \n          max{x + y + z, xyz} + 3          \n                                           ",
                "                                           \n       min{x^2 + y^2, y^2 + z^2} - 4       \n                                           " };
            string task10[4] = {
                "            {x^2, при -2 <= x <= 2,        \n        y = {                              \n            {4, при x < -2 и x > 2         ",
                "              {x^4, при x > 1              \n          y = {x, при 0 < x <= 1,          \n              {0, при x <= 0               ",
                "         {x^2 + 4x + 5, при x<= 2,         \n     y = {                                 \n         {1/(x^2 + 4x + 5), при x > 2      ",
                "        {0, при x<= 0                      \n    y = {x^2 - x, при 0 < x <= 1,          \n        {x^2 - sin(пx^2) - 1, при x > 1    " };
            string task11[6] = {
                "     ~               |                     \n       ~             |                     \n         ~           |                     \n           ~    #####1#####                \n             ~###############              \n               ~###############            \n                 ~##############           \n                   ~############           \n-----------1---------~#########1-----------\n                     | ~########           \n                     |   ~######           \n                     |     ~###            \n                     |       ~             \n                     1         ~           \n                     |           ~         \n                     |             ~       \n                     |               ~     ",
                "                     2                     \n                     |                  ~  \n                     |               ~     \n                     |            ~        \n                     1         ~####       \n                     |      ~##########    \n                     |   ~###############  \n                     | ~################## \n-2---------1---------####################2-\n                  ~####################### \n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n             ~       |                     \n          ~          1                     \n       ~             |                     \n    ~                |                     \n  ~                  |                     \n                     2                     ",
                "                     |                     \n                     |                     \n                     |                     \n                     1#####                \n                     ########              \n                     ##########            \n                     ###########           \n                     ###########           \n-----------1###################1-----------\n           ###########                     \n           ###########                     \n           ###########                     \n           ###########                     \n           ##########1                     \n                     |                     \n                     |                     \n                     |                     ",
                "                     |                     \n                     |                     \n                     |                     \n           ##########1#####                \n           ##################              \n           ####################            \n           #####################           \n           #####################           \n-----------1###################1-----------\n           #####################           \n           #####################           \n           ####################            \n           ##################              \n           ##########1#####                \n                     |                     \n                     |                     \n                     |                     ",
                "                     |                     \n                     |                     \n                     |                     \n ~                   1#####                \n   ~               ~#########              \n     ~           ~#############            \n       ~       ~################           \n         ~   ~##################           \n-----------1###################1-----------\n         ~   ~##################           \n       ~       ~################           \n     ~           ~#############            \n   ~               ~#########              \n ~                   1#####                \n                     |                     \n                     |                     \n                     |                     ",
                "                     |               ~     \n                     |             ~       \n                     |           ~         \n                     1         ~           \n                     |       ~##           \n                     |     ~####           \n                     |   ~######           \n                     | ~########           \n-----------1---------~#########1-----------\n                    ~###########           \n                  ~#############           \n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n              ~      |                     \n            ~        1                     \n          ~          |                     \n        ~            |                     \n      ~              |                     " };
            while (chosen == "NO2") {
                cout << "\n                 Подзадание " << subtask_ind + 1 << endl;
                if (lite != "YES") {
                    ss.clear();
                    if (task_ind == 4) {
                        ss << task5[subtask_ind];
                    }
                    if (task_ind == 8) {
                        ss << task9[subtask_ind];
                    }
                    if (task_ind == 9) {
                        ss << task10[subtask_ind];
                    }
                    if (task_ind == 10) {
                        ss << task11[subtask_ind];
                    }
                    cout << "-----------------------------------------------" << endl;
                    while (getline(ss, line, '\n')) {
                        cout << "| " << line << " |" << endl;
                    }
                    cout << "-----------------------------------------------" << endl;
                }
                cout << "1 - назад   2 - выбрать   3 - вперед   4 - меню\n\n> ";
                cin >> ans;
                if (ans == "1") {
                    if (subtask_ind == 0) {
                        if (task_ind == 8) {
                            subtask_ind = 1;
                        }
                        else {
                            if (task_ind == 10) {
                                subtask_ind = 5;
                            }
                            else {
                                subtask_ind = 3;
                            }
                        }
                    }
                    else {
                        subtask_ind -= 1;
                    }
                }
                if (ans == "2") {
                    chosen = "YES";
                }
                if (ans == "3") {
                    if (task_ind == 8) {
                        if (subtask_ind == 1) {
                            subtask_ind = 0;
                        }
                        else {
                            subtask_ind += 1;
                        }
                    }
                    else {
                        if (task_ind == 10) {
                            if (subtask_ind == 5) {
                                subtask_ind = 0;
                            }
                            else {
                                subtask_ind += 1;
                            }
                        }
                        else {
                            if (subtask_ind == 3) {
                                subtask_ind = 0;
                            }
                            else {
                                subtask_ind += 1;
                            }
                        }
                    }
                }
                if (ans == "4") {
                    subtask_ind = 0;
                    chosen = "NO";
                }
            }
        }
    }
}

double task1() {
    double x, y, result;
    cout << "\nВведите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    result = (abs(x) - abs(y)) / (1 + abs(x * y));
    return result;
}

pair<double, double> task2() {
    double x, y, res1, res2;
    cout << "\nВведите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    res1 = (pow(x, 3) + pow(y, 3)) / 2;
    res2 = sqrt(abs(x) * abs(y));
    return make_pair(res1, res2);
}

double task3() {
    double xa, ya, xb, yb, result;
    cout << "\nВведите через пробел координаты X и Y первой точки: ";
    cin >> xa >> ya;
    cout << "Введите через пробел координаты X и Y второй точки: ";
    cin >> xb >> yb;
    result = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
    return result;
}

double task4() {
    double a = 0, b = 0, c = 0, p = -1, result;
    while (a + b <= c or a + c <= b or b + c <= a) {
        if (p == 0) {
            cout << "\nУпс! Такой треугольник мы не можем создать. Попробуйте еще раз." << endl;
        }
        cout << "\nВведите через пробел длины трех сторон треугольника: ";
        cin >> a >> b >> c;
        p = 0;
    }
    p = (a + b + c) / 2;
    result = sqrt(p * (p - a) * (p - b) * (p - c));
    return result;
}

double task5() {
    double x, y, z, w;
    cout << "\nВведите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    cout << "Введите z: ";
    cin >> z;
    if (subtask_ind == 0) {
        w = sin(abs((y - sqrt(abs(x))) * (x - y / (pow(z, 2) + pow(x, 2) / 4))));
    }
    if (subtask_ind == 1) {
        w = x - pow(x, 2) / (1 + pow(sin(x + y + z), 2));
    }
    if (subtask_ind == 2) {
        w = cos(pow(z, 2) + pow(x, 2) / 4 + y);
    }
    if (subtask_ind == 3) {
        w = y + x - pow(cos(x), 2) / (1 + sqrt(abs(y + z)));
    }
    return w;
}

string task6() {
    double a, b;
    string result;
    cout << "\nВведите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    if (a > b) {
        result = to_string(a);
    }
    else {
        result = to_string(a) + " " + to_string(b);
    }
    return result;
}

double task7() {
    double a, b, c, min;
    cout << "\nВведите три числа через пробел: ";
    cin >> a >> b >> c;
    if (a < b) {
        if (a < c) {
            min = a;
        }
        else {
            min = c;
        }
    }
    else {
        if (b < c) {
            min = b;
        }
        else {
            min = c;
        }
    }
    return min;
}

string task8() {
    double a = 0, b = 0, c = 0, p = -1;
    string result;
    while (a + b <= c or a + c <= b or b + c <= a) {
        if (p == 0) {
            cout << "\nУпс! Такой треугольник мы не можем создать. Попробуйте еще раз." << endl;
        }
        cout << "\nВведите через пробел длины трех сторон треугольника: ";
        cin >> a >> b >> c;
        p = 0;
    }
    if (a == b or b == c or a == c) {
        if (a == b and b == c and a == c) {
            result = "равносторонний";
        }
        else {
            result = "равнобедренный";
        }
    }
    else {
        result = "разносторонний";
    }
    return result;
}

double task9() {
    double x, y, z, result;
    cout << "\nВведите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    cout << "Введите z: ";
    cin >> z;
    if (subtask_ind == 0) {
        result = max(x + y + z, x * y * z) + 3;
    }
    if (subtask_ind == 1) {
        result = min(pow(x, 2) + pow(y, 2), pow(y, 2) + pow(z, 2)) - 4;
    }
    return result;
}
double task10() {
    double x, y;
    cout << "\nВведите x: ";
    cin >> x;
    if (subtask_ind == 0) {
        if (x >= -2 and x <= 2) {
            y = pow(x, 2);
        }
        else {
            y = 4;
        }
    }
    if (subtask_ind == 1) {
        if (x <= 0) {
            y = 0;
        }
        else {
            if (x > 1) {
                y = pow(x, 4);
            }
            else {
                y = x;
            }
        }
    }
    if (subtask_ind == 2) {
        if (x <= 2) {
            y = pow(x, 2) + 4 * x + 5;
        }
        else {
            y = 1 / (pow(x, 2) + 4 * x + 5);
        }
    }
    if (subtask_ind == 3) {
        if (x <= 0) {
            y = 0;
        }
        else {
            if (x > 1) {
                const double pi = acos(-1.0);
                y = pow(x, 2) - sin(pi * pow(x, 2)) - 1;
            }
            else {
                y = pow(x, 2) - x;
            }
        }
    }
    return y;
}

bool task11() {
    double x, y;
    cout << "\nВведите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    if (subtask_ind == 0) {
        if (sqrt(pow(x, 2) + pow(y, 2)) <= 1 and y >= -x) {
            return true;
        }
        else {
            return false;
        }
    }
    if (subtask_ind == 1) {
        if ((sqrt(pow(x - 1, 2) + pow(y, 2)) <= 1 and y >= -0.5) or (y >= -0.5 and y <= x and x <= 1)) {
            return true;
        }
        else {
            return false;
        }
    }
    if (subtask_ind == 2) {
        if ((sqrt(pow(x, 2) + pow(y, 2)) <= 1 and x > 0 and y > 0) or (x <= 0 and y <= 0 and x >= -1 and y >= -1)) {
            return true;
        }
        else {
            return false;
        }
    }
    if (subtask_ind == 3) {
        if ((sqrt(pow(x, 2) + pow(y, 2)) <= 1) or (x >= -1 and y >= -1 and x <= 0 and y <= 1)) {
            return true;
        }
        else {
            return false;
        }
    }
    if (subtask_ind == 4) {
        if ((sqrt(pow(x, 2) + pow(y, 2)) <= 1 and x >= 0) or (x <= 0 and abs(y) <= 1+x)) {
            return true;
        }
        else {
            return false;
        }
    }
    if (subtask_ind == 5) {
        if (y <= x and y >= -0.5 and x <= 1) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Вас приветствует Решатор Лаборатор v2.0!"<<endl;
    cout << "Выберите из списка задание, которые вы хотите решить, переключаясь с помощью клавиш. " << endl;
    cout << "Нажмите 4 в меню выбора задания для переключения режима производительности." << endl;
    choose();
    if (task_ind == 0) {
        cout << "\nРезультат операции: " << task1() << endl;
    }
    if (task_ind == 1) {
        pair<double, double> ans = task2();
        cout << "\nСреднее арифметичское кубов указанных чисел: " << ans.first << endl;
        cout << "Среднее геометрическое модулей этих чисел: " << ans.second << endl;
    }
    if (task_ind == 2) {
        cout << "\nРасстояние между двумя заданными точками: " << task3() << endl;
    }
    if (task_ind == 3) {
        cout << "\nПлощадь треугольника: " << task4() << endl;
    }
    if (task_ind == 4) {
        cout << "\nw = " << task5() << endl;
    }
    if (task_ind == 5) {
        cout << "\nРезультат операции: " << task6() << endl;
    }
    if (task_ind == 6) {
        cout << "\nМинимальное из трех данных чисел: " << task7() << endl;
    }
    if (task_ind == 7) {
        cout << "\nДанный треугольник - " << task8() << ".\n";
    }
    if (task_ind == 8) {
        cout << "\nРезультат операции: " << task9() << endl;
    }
    if (task_ind == 9) {
        cout << "\ny = " << task10() << endl;
    }
    if (task_ind == 10) {
        if (task11()) {
            cout << "\nТочка принадлежит заданной области." << endl;
        }
        else {
            cout << "\nТочка не принадлежит заданной области." << endl;
        }
    }
    system("pause");
}