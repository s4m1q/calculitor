#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <stack>
#include <vector>
#define SIZE_M 300


#define M_PI 3.141592653589793

using namespace std;


int head = -1;
float mass[SIZE_M] = { 0 };
char str_second[SIZE_M] = { 0 };




void push_it(float c)
{
    head++;
    mass[head] = c;
}

int priority(char what_oper)
{

    if (what_oper == '*' || what_oper == '/')
    {
        return 2;
    }
    else if (what_oper == '+' || what_oper == '-')
    {
        return 1;
    }
    else if (what_oper == '(' || what_oper == ')')
    {
        return -1;
    }
}

float it_pop()
{
    if (head == -1)
    {
        return 0;
    }
    else
    {
        return mass[head--];
    }
}


int _operator_(char op)
{
    return op == '-' || op == '+' || op == '/' || op == '*' || op == 's' || op == 'c' || op == 't' || op == 'a' || op == 'l';
}



float post_counting(const char* str_second)
{
    head = -1;

    int per = 0;
    while (str_second[per] != '\0')
    {
        if (isdigit(str_second[per]))
        {

            float temp = 0;
            while (isdigit(str_second[per]))
            {
                temp *= 10;
                temp += (str_second[per] - '0');
                ++per;
            }
            push_it(temp);
        }
        else if (str_second[per] == ' ')
        {
            ++per;
        }
        else
        {
            float opera_2 = it_pop();
            float opera_1;


            if (str_second[per] == '+')
            {
                opera_1 = it_pop();
                push_it(opera_1 + opera_2);
            }
            else if (str_second[per] == '-')
            {
                opera_1 = it_pop();
                push_it(opera_1 - opera_2);
            }
            else if (str_second[per] == '*')
            {
                opera_1 = it_pop();
                push_it(opera_1 * opera_2);
            }
            else if (str_second[per] == '/')
            {
                opera_1 = it_pop();
                push_it(opera_1 / opera_2);
            }
            else if (str_second[per] == 'a')  // sin
            {
                push_it(sin(opera_2 * M_PI / 180));
            }
            else if (str_second[per] == 'b')  // cos
            {
                push_it(cos(opera_2 * M_PI / 180));
            }
            else if (str_second[per] == 'c')  // tg
            {
                push_it(tan(opera_2 * M_PI / 180));
            }
            else if (str_second[per] == 'd')  // ctg
            {
                push_it(1 / tan(opera_2 * M_PI / 180));
            }
            else if (str_second[per] == 'e')  // arcsin
            {
                push_it(asinf(opera_2) * 180 / M_PI);
            }
            else if (str_second[per] == 'i')  // arccos
            {
                push_it(acosf(opera_2) * 180 / M_PI);
            }
            else if (str_second[per] == 'l')  // arctg
            {
                push_it(atanf(opera_2) * 180 / M_PI);
            }
            else if (str_second[per] == 'm')  // arccot
            {
                push_it((M_PI / 2 - atanf(opera_2)) * 180 / M_PI);
            }
            else if (str_second[per] == '.')  
            {
                
            }


            ++per;
        }
    }
    return it_pop();
}

int is_dot(char str) {
    return str == '.';
}

void post(const char* str_first, char* str_second)
{

    int m = 0;
    int len_float = 0;
    int flag1 = 0;
    for (int per = 0; str_first[per]; per++)
    {

        if (!_operator_(str_first[per]) && str_first[per] != ')' && str_first[per] != '(')
        {
            while (str_first[per] != '(' && !_operator_(str_first[per]) && str_first[per] != ')' && str_first[per])
            {
                if (is_dot(str_first[per])) {
                    if (!flag1)
                      len_float++;
                    flag1 = 1;
                    cout << "LEN " << len_float << per << endl;
                }

                if (len_float && str_first[per] != '.') {
                    cout << "GBCMFH " << per << "  " << len_float << "  " << + pow(0.1, len_float) * ((int)(str_first[per]-48)) << endl;
                    str_second[m] = (char)
                        ( (int) (((int)str_second[m]-48) + pow(0.1, len_float) * ((int)(str_first[per]) - 48)) );
                    len_float++;
                    ++per;
                }
                else {
                        str_second[m] = str_first[per];
                        m += 1;
                        ++per;   
                }
                
                
            }
            str_second[m] = ' ';
            m += 1;
            --per;
        }

        


        else if (_operator_(str_first[per]))
        {
            while (head != -1 && priority(str_first[per]) <= priority(mass[head]))
            {
                str_second[m++] = it_pop();
                str_second[m++] = ' ';
            }
            if (str_first[per] == 's' && str_first[per + 1] == 'i') {
                push_it('a');
                per += 3;
            }
            else if (str_first[per] == 'c' && str_first[per + 1] == 'o') {
                push_it('b');
                per += 3;
            }
            else if (str_first[per] == 't' && str_first[per + 1] == 'g') {
                push_it('c');
                per += 2;
            }
            else if (str_first[per] == 'c' && str_first[per + 1] == 't') {
                push_it('d');
                per += 3;
            }
            else  if (str_first[per + 3] == 's' && str_first[per + 4] == 'i' && str_first[per] == 'a') {     // a  r  c  s  i  n
                push_it('e');
                per += 6;
            }
            else    if (str_first[per + 3] == 'c' && str_first[per + 4] == 'o' && str_first[per] == 'a') {
                push_it('i');
                per += 6;
            }
            else   if (str_first[per + 3] == 't' && str_first[per + 4] == 'g' && str_first[per] == 'a') {
                push_it('l');
                per += 5;
            }
            else  if (str_first[per + 3] == 'c' && str_first[per + 4] == 'g' && str_first[per] == 'a') {
                push_it('m');
                per += 6;
            }
            else
                push_it(str_first[per]);
        }
        else if (str_first[per] == ')')
        {
            while (head != -1 && mass[head] != '(')
            {
                str_second[m++] = it_pop();
                str_second[m++] = ' ';
            }
            if (head != -1)
            {
                it_pop();
            }
        }
        else if (str_first[per] == '(')
        {
            push_it(str_first[per]);
        }

    }
    while (head != -1)
    {
        str_second[m] = it_pop();
        m++;
        str_second[m] = ' ';
        m++;
    }
}

float notation(char* str_first)
{
    for (int k = 0; k < strlen(str_second); k++)
    {
        str_second[k] = 0;
    }

    int len_of_str = strlen(str_first);
    char opea[SIZE_M] = { 0 };

    if (str_first[len_of_str - 1] == '\n')
    {
        str_first[len_of_str - 1] = 0;
        len_of_str--;
    }



    for (int per = 0; per < SIZE_M; per++)
    {
        mass[per] = 0;
    }

    post(str_first, str_second);
    //cout << endl<< post_counting(str_second) << endl;
    /*cout << "Expression:" << endl;
    cout << str_first << endl;
    cout << "Reverse Polish Notation:" << endl;
    cout << str_second << endl << "Result:" << endl << post_counting(str_second);*/

    return post_counting(str_second);   
}

char* convert(std::vector <std::string> words)
{
    static char str[100] = { 0 };
    int count = 0;

    

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].size(); j++)
        {
           
            str[count++] = (words[i][j]);
        }
    }
    cout << " I" << str << "I ";
    return str;
}