#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
#include <algorithm>
using namespace std;
//Включение доп. библиотек для нахождения элементов в строке, возведения в степень, хранения отдельных элементов в массиве и быстрого разделения строки на составляющие.

vector<char> a = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
//Хранение глобального массива всех возможных элементов систем исчисления для последующей конвертации чисел.

vector<double> to_ten(vector<string> num, int sys) { //Перевод всех введенных чисел в десятичную систему исчисления.
    vector<double> result;
    int size, minus = 0;
    double temp = 0, realnum;
    for (int i = 0; i < num.size(); ++i) {
        size = num[i].find('.')-1;
        if (size == -2) { //Подсчет длины целой части числа.
            size = num[i].length()-1;
        }
        for (int j = 0; j < num[i].length(); ++j) {
            if (num[i][j] != '.' and num[i][j] != '-') {
                realnum = distance(a.begin(), find(a.begin(), a.end(), num[i][j]));
                temp += realnum * pow(sys, size); //Перевод числа по формуле.
                --size;
            }
            if (num[i][j] == '-') {
                minus = 1;
                --size;
            }
        }
        if (minus == 1) {
            temp = temp * -1;
        }
        result.push_back(temp); //Вывод готовых чисел в вектор.
        temp = 0;
        minus = 0;
    }
    return result;
}

string to_other(vector<double> num, int sys) { //Перевод всех чисел в выбранную систему исчисления.
    string result, temp;
    int part1;
    double part2;
    for (int i = 0; i < num.size(); ++i) {
        part1 = floor(abs(num[i]));
        part2 = abs(num[i]) - part1;
        if (part1 == 0) {
            temp = "0" + temp;
        }
        while (part1 > 0) { //Перевод целой части числа в другую систему.
            temp = a[part1 % sys] + temp;
            part1 = part1 / sys;
        }
        if (part2 > 0) { //Перевод дробной части числа в другую систему.
            temp += ".";
            for (int j = 0; j < 4; ++j) {
                part2 = part2 * sys;
                temp += a[floor(part2)];
                part2 -= floor(part2);
            }
        }
        if (num[i] < 0) {
            temp = "-" + temp;
        }
        result = result + temp + " "; //Вывод чисел в строку, как конечный результат. Вектор при этом продолжает хранить десятичные числа.
        temp = "";
    }
    return result;
}

string expand(vector<double> num, int i, int sys) { //Приведение числа в развернутом виде.
    string result = "", temp = "";
    int size, part1;
    double part2;
    part1 = floor(abs(num[i]));
    part2 = abs(num[i]) - part1;
    if (part1 == 0) {
        temp = "0" + temp;
    }
    while (part1 > 0) { //Перевод целой части числа из десятичной системы в последнюю сохраненную.
        temp = a[part1 % sys] + temp;
        part1 = part1 / sys;
    }
    if (part2 > 0) { //Перевод дробной части числа.
        temp += ".";
        for (int j = 0; j < 4; ++j) {
            part2 = part2 * sys;
            temp += a[floor(part2)];
            part2 -= floor(part2);
        }
    }
    size = temp.find('.') - 1;
    if (size == -2) { //Вычисление длины целой части получившегося числа.
        size = temp.length() - 1;
    }
    for (int j = 0; j < temp.length(); ++j) { //Подстановка значений в готовую формулу для построения развернутой формы.
        if (temp[j] != '.') {
            if (num[i] >= 0) {
                if (j == 0) {
                    result = result + to_string(distance(a.begin(), find(a.begin(), a.end(), temp[j]))) + " * " + to_string(sys) + "^" + to_string(size) + " ";
                }
                else {
                    result = result + "+ " + to_string(distance(a.begin(), find(a.begin(), a.end(), temp[j]))) + " * " + to_string(sys) + "^" + to_string(size) + " ";
                }            
            }
            else {
                    result = result + "- " + to_string(distance(a.begin(), find(a.begin(), a.end(), temp[j]))) + " * " + to_string(sys) + "^" + to_string(size) + " ";
            }
            --size;
        }
    }
    if (result == "") {
        result = "0 + " + to_string(sys) + "^" + "0";
    }
    return result;
}

void sum(vector<double>& num, int i1, int i2) { //Сложение двух чисел в десятичной системе.
    num[i1] = num[i1] + num[i2];
    num.erase(next(num.begin(), i2));
}

void min(vector<double>& num, int i1, int i2) { //Вычитание двух чисел.
    num[i1] = num[i1] - num[i2];
    num.erase(next(num.begin(), i2));
}

void dif(vector<double>& num, int i1, int i2) { //Деление двух чисел.
    if (num[i2] != 0) {
        num[i1] = num[i1] / num[i2];
        num.erase(next(num.begin(), i2));
    }
    else {
        cout<< "Во время операции деления произошла ошибка: недопустимое деление на 0." << endl;
    }
}

void mul(vector<double>& num, int i1, int i2) { //Умножение двух чисел.
    num[i1] = num[i1] * num[i2];
    num.erase(next(num.begin(), i2));
}

int main()
{
    string line, result;
    vector<string> commands, numbers;
    vector<double> nums10;
    int sys, check = 0;
    setlocale(LC_ALL, "Russian");
    cout << "Вас приветствует Решатор Лаборатор v1.1! Давайте приступим к делу:" << endl;
    cout << "Введите одно или несколько чисел, в зависимости от ваших будущих манипуляций, через пробел." << endl;
    cout << "> ";
    getline(cin, line);
    stringstream ss1(line);
    while (getline(ss1, line, ' ')) {
        numbers.push_back(line); //Запись всех чисел в массив для последующей работы.
    }
    cout << "Введите систему исчисления, в которой находятся все ваши числа." << endl;
    cout << "> ";
    cin >> sys;
    cin.ignore(1);
    cout << "Введите одну, или несколько операций, которые вы хотите совершить над числами через пробел:" << endl;
    cout << "- convert <system> - перевести текущий набор чисел в другую систему исчисления;" << endl;
    cout << "- spread <index> - представить одно число из списка в развёрнутой форме;" << endl;
    cout << "- plus <index1> <index2> - сложить 2 числа;\n- minus <индекс1> <индекс2> - найти разницу 2-х чисел;" << endl;
    cout << "- divine <index1> <index2> - разделить 2 числа;\n- multiply <индекс1> <индекс2> - перемножить 2 числа." << endl;
    cout << "Имейте ввиду, что параметры команд также вводятся через пробел без лишних знаков-разделителей!" << endl;
    cout << "\n> ";
    getline(cin, line);
    stringstream ss2(line);
    while (getline(ss2, line, ' ')) {
        commands.push_back(line); //Запись всех команд в массив.
    }
    nums10 = to_ten(numbers, sys);
    cout << endl;
    for (int i = 0; i < commands.size(); ++i) { //Цикл для всех введенных комманд по очереди.
        if (commands[i] == "convert") { //перевести: переводит все имеющиеся числа в определенную систему исчисления. Если число дробное - до 4-х цифр после точки.
            sys = stoi(commands[i + 1]);
            result = to_other(nums10, sys);
            cout << "Числа в " << sys << "-ичной системе исчисления: " << result << endl;
            check = 1;
        }
        if (commands[i] == "spread") { //разложить: выдает число в развернутом виде по введенному индексу. Не влияет на дальнейшие вычисления.
            result = expand(nums10, stoi(commands[i + 1]), sys);
            cout << "Выбранное число в развёрнутой форме: " << result << endl;
        }
        if (commands[i] == "plus") { //сложить: ссумирует 2 числа по введенному индексу, начиная с 0. Сумма возвращается на место первого числа. Второе число стирается.
            sum(nums10, stoi(commands[i + 1]), stoi(commands[i + 2]));
        }
        if (commands[i] == "minus") { //отнять: отнимает число 2 от числа 1 по введенному индексу, начиная с 0. Разность возвращается на место первого числа. Второе число стирается.
            min(nums10, stoi(commands[i + 1]), stoi(commands[i + 2]));
        }
        if (commands[i] == "divine") { //сложить: делит число 1 на число 2 по введенному индексу, начиная с 0. Результат возвращается на место первого числа. Второе число стирается.
            dif(nums10, stoi(commands[i + 1]), stoi(commands[i + 2]));
        }
        if (commands[i] == "multiply") { //сложить: умножает 2 числа по введенному индексу, начиная с 0. Результат возвращается на место первого числа. Второе число стирается.
            mul(nums10, stoi(commands[i + 1]), stoi(commands[i + 2]));
        }
    }
    if (check == 0) { //Если команды перевода не было - выводит конечный результат в начальной системе исчисления.
        result = to_other(nums10, sys);
        cout << "Конечный результат в " << sys << "-ичной системе исчисления: " << result << endl;
    }
    system("pause");
    return 0;
}