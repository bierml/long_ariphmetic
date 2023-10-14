// lab1_MARCH.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#define N 512
class BigNum
{
    //friend BigNum operator + (const BigNum& object1, const BigNum& object2);
    public:
        BigNum()
        {
            for (int i = 0; i < N; i++)
                number[i] = '0';
            return;
        }
        BigNum(const char str[])
        {
            int i = 0;
            int l = strlen(str);
            for (int j = 0; j < N - l; j++)
                number[j] = '0';
            while (str[i] != '\0')
            {
                number[N - l + i] = str[i];
                i++;
            }
            return;
        }
        void output()
        {
            int i = 0;
            int l = 0;
            while (number[i] == '0')
                i++;
            if (i == N)
            {
                cout << "0";
                return;
            }
            for (int j = i; j < N; j++)
            {
                l = number[j] - '0';
                cout << l;
            }
        }
        BigNum operator = (char str[])
        {
            int i = 0;
            int l = strlen(str);
            for (int j = 0; j < N - l; j++)
                number[j] = '0';
            while (str[i] != '\0')
            {
                number[N - l + i] = str[i];
                i++;
            }
            return *this;
        }
    //private:
        char number[N];
};
void shift(BigNum& obj, int count)
{
    for (int j = 0; j < count; j++)
    {
        for (int i = 1; i < N; i++)
            obj.number[i - 1] = obj.number[i];
    }
    for (int j = 0; j < count; j++)
            obj.number[N - 1 - j] = '0';
    return;
}
BigNum operator + (const BigNum& object1, const BigNum& object2)
{
    BigNum a;
    int carry = 0;
    for (int j = N - 1; j >= 0; j--)
    {
        a.number[j] = '0'+(((object1.number[j]-'0') + (object2.number[j]-'0') + carry) % 10);
        carry = (((object1.number[j]-'0') + (object2.number[j]-'0') + carry)) >= 10 ? 1 : 0;
    }
    return a;
}
BigNum operator - (const BigNum& object1, const BigNum& object2)
{
    BigNum a;
    int negcarry = 0;
    int res;
    for (int j = N - 1; j >= 0; j--)
    {
        if (((object1.number[j] - '0') - (object2.number[j] - '0') - negcarry) < 0)
        {
            res = 10 + ((object1.number[j] - '0') - (object2.number[j] - '0') - negcarry);
            negcarry = 1;
        }
        else
        {
            res = (object1.number[j] - '0') - (object2.number[j] - '0') - negcarry;
            negcarry = 0;
        }
        a.number[j] = '0' + res;
    }
    return a;
}
BigNum operator * (const BigNum& object1, const BigNum& object2)
{
    BigNum a,b;
    char* arr;
    string s;
    int i = 0;
    int k = 0;
    int z = 0;
    while (object1.number[i] == '0')
        i++;
    while (object2.number[k] == '0')
        k++;
    bool var = (i >= k);            //true - строка object2 длиннее, false - строка object1 длиннее
    if (var)
    {
        for (int l = k; l < N; l++)
        {
            for (int m = i; m < N; m++)
            {
                z = (object1.number[l] - '0') * (object2.number[m] - '0');
                //z *= ((int)pow(10, N - 1 - l + N - 1 - m));
                s = to_string(z);
                b = s.c_str();
                shift(b, N - 1 - l + N - 1 - m);
                a = a + b;
            }
        }
    }
    else
    {
        for (int l = i; l < N; l++)
        {
            for (int m = k; m < N; m++)
            {
                //s = to_string((object1.number[l] - '0' * object2.number[m] - '0') * ((int)pow(10, l - N - 1 + m - N - 1)));
                //b = s.c_str();
                //a = a + b;
                //z = (object1.number[l] - '0') * (object2.number[m] - '0');
                //z *= ((int)pow(10, N - 1 - l + N - 1 - m));
                //s = to_string(z);
                //b = s.c_str();
                //a = a + b;
                z = (object1.number[l] - '0') * (object2.number[m] - '0');
                s = to_string(z);
                b = s.c_str();
                shift(b, N - 1 - l + N - 1 - m);
                a = a + b;
            }
        }
    }
    return a;
}
int main()
{
    //BigNum a;
    BigNum a{"586"};
    BigNum b{"34"};
    BigNum c = a * b;
    c.output();
    /*cout << endl;
    c = "5";
    cout << endl;
    c.output();*/
    //int d = -7 % 3;
    //std::cout << d;
    //std::cout << "Hello World!\n";
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
