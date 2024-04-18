#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
#include <algorithm>
using namespace std;
//��������� ���. ��������� ��� ���������� ��������� � ������, ���������� � �������, �������� ��������� ��������� � ������� � �������� ���������� ������ �� ������������.

vector<char> a = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
//�������� ����������� ������� ���� ��������� ��������� ������ ���������� ��� ����������� ����������� �����.

vector<double> to_ten(vector<string> num, int sys) { //������� ���� ��������� ����� � ���������� ������� ����������.
    vector<double> result;
    int size, minus = 0;
    double temp = 0, realnum;
    for (int i = 0; i < num.size(); ++i) {
        size = num[i].find('.')-1;
        if (size == -2) { //������� ����� ����� ����� �����.
            size = num[i].length()-1;
        }
        for (int j = 0; j < num[i].length(); ++j) {
            if (num[i][j] != '.' and num[i][j] != '-') {
                realnum = distance(a.begin(), find(a.begin(), a.end(), num[i][j]));
                temp += realnum * pow(sys, size); //������� ����� �� �������.
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
        result.push_back(temp); //����� ������� ����� � ������.
        temp = 0;
        minus = 0;
    }
    return result;
}

string to_other(vector<double> num, int sys) { //������� ���� ����� � ��������� ������� ����������.
    string result, temp;
    int part1;
    double part2;
    for (int i = 0; i < num.size(); ++i) {
        part1 = floor(abs(num[i]));
        part2 = abs(num[i]) - part1;
        if (part1 == 0) {
            temp = "0" + temp;
        }
        while (part1 > 0) { //������� ����� ����� ����� � ������ �������.
            temp = a[part1 % sys] + temp;
            part1 = part1 / sys;
        }
        if (part2 > 0) { //������� ������� ����� ����� � ������ �������.
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
        result = result + temp + " "; //����� ����� � ������, ��� �������� ���������. ������ ��� ���� ���������� ������� ���������� �����.
        temp = "";
    }
    return result;
}

string expand(vector<double> num, int i, int sys) { //���������� ����� � ����������� ����.
    string result = "", temp = "";
    int size, part1;
    double part2;
    part1 = floor(abs(num[i]));
    part2 = abs(num[i]) - part1;
    if (part1 == 0) {
        temp = "0" + temp;
    }
    while (part1 > 0) { //������� ����� ����� ����� �� ���������� ������� � ��������� �����������.
        temp = a[part1 % sys] + temp;
        part1 = part1 / sys;
    }
    if (part2 > 0) { //������� ������� ����� �����.
        temp += ".";
        for (int j = 0; j < 4; ++j) {
            part2 = part2 * sys;
            temp += a[floor(part2)];
            part2 -= floor(part2);
        }
    }
    size = temp.find('.') - 1;
    if (size == -2) { //���������� ����� ����� ����� ������������� �����.
        size = temp.length() - 1;
    }
    for (int j = 0; j < temp.length(); ++j) { //����������� �������� � ������� ������� ��� ���������� ����������� �����.
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

void sum(vector<double>& num, int i1, int i2) { //�������� ���� ����� � ���������� �������.
    num[i1] = num[i1] + num[i2];
    num.erase(next(num.begin(), i2));
}

void min(vector<double>& num, int i1, int i2) { //��������� ���� �����.
    num[i1] = num[i1] - num[i2];
    num.erase(next(num.begin(), i2));
}

void dif(vector<double>& num, int i1, int i2) { //������� ���� �����.
    if (num[i2] != 0) {
        num[i1] = num[i1] / num[i2];
        num.erase(next(num.begin(), i2));
    }
    else {
        cout<< "�� ����� �������� ������� ��������� ������: ������������ ������� �� 0." << endl;
    }
}

void mul(vector<double>& num, int i1, int i2) { //��������� ���� �����.
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
    cout << "��� ������������ ������� ��������� v1.1! ������� ��������� � ����:" << endl;
    cout << "������� ���� ��� ��������� �����, � ����������� �� ����� ������� �����������, ����� ������." << endl;
    cout << "> ";
    getline(cin, line);
    stringstream ss1(line);
    while (getline(ss1, line, ' ')) {
        numbers.push_back(line); //������ ���� ����� � ������ ��� ����������� ������.
    }
    cout << "������� ������� ����������, � ������� ��������� ��� ���� �����." << endl;
    cout << "> ";
    cin >> sys;
    cin.ignore(1);
    cout << "������� ����, ��� ��������� ��������, ������� �� ������ ��������� ��� ������� ����� ������:" << endl;
    cout << "- convert <system> - ��������� ������� ����� ����� � ������ ������� ����������;" << endl;
    cout << "- spread <index> - ����������� ���� ����� �� ������ � ���������� �����;" << endl;
    cout << "- plus <index1> <index2> - ������� 2 �����;\n- minus <������1> <������2> - ����� ������� 2-� �����;" << endl;
    cout << "- divine <index1> <index2> - ��������� 2 �����;\n- multiply <������1> <������2> - ����������� 2 �����." << endl;
    cout << "������ �����, ��� ��������� ������ ����� �������� ����� ������ ��� ������ ������-������������!" << endl;
    cout << "\n> ";
    getline(cin, line);
    stringstream ss2(line);
    while (getline(ss2, line, ' ')) {
        commands.push_back(line); //������ ���� ������ � ������.
    }
    nums10 = to_ten(numbers, sys);
    cout << endl;
    for (int i = 0; i < commands.size(); ++i) { //���� ��� ���� ��������� ������� �� �������.
        if (commands[i] == "convert") { //���������: ��������� ��� ��������� ����� � ������������ ������� ����������. ���� ����� ������� - �� 4-� ���� ����� �����.
            sys = stoi(commands[i + 1]);
            result = to_other(nums10, sys);
            cout << "����� � " << sys << "-����� ������� ����������: " << result << endl;
            check = 1;
        }
        if (commands[i] == "spread") { //���������: ������ ����� � ����������� ���� �� ���������� �������. �� ������ �� ���������� ����������.
            result = expand(nums10, stoi(commands[i + 1]), sys);
            cout << "��������� ����� � ���������� �����: " << result << endl;
        }
        if (commands[i] == "plus") { //�������: ��������� 2 ����� �� ���������� �������, ������� � 0. ����� ������������ �� ����� ������� �����. ������ ����� ���������.
            sum(nums10, stoi(commands[i + 1]), stoi(commands[i + 2]));
        }
        if (commands[i] == "minus") { //������: �������� ����� 2 �� ����� 1 �� ���������� �������, ������� � 0. �������� ������������ �� ����� ������� �����. ������ ����� ���������.
            min(nums10, stoi(commands[i + 1]), stoi(commands[i + 2]));
        }
        if (commands[i] == "divine") { //�������: ����� ����� 1 �� ����� 2 �� ���������� �������, ������� � 0. ��������� ������������ �� ����� ������� �����. ������ ����� ���������.
            dif(nums10, stoi(commands[i + 1]), stoi(commands[i + 2]));
        }
        if (commands[i] == "multiply") { //�������: �������� 2 ����� �� ���������� �������, ������� � 0. ��������� ������������ �� ����� ������� �����. ������ ����� ���������.
            mul(nums10, stoi(commands[i + 1]), stoi(commands[i + 2]));
        }
    }
    if (check == 0) { //���� ������� �������� �� ���� - ������� �������� ��������� � ��������� ������� ����������.
        result = to_other(nums10, sys);
        cout << "�������� ��������� � " << sys << "-����� ������� ����������: " << result << endl;
    }
    system("pause");
    return 0;
}