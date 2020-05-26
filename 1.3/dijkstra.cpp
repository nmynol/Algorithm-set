/*
    Dijkstra双栈中缀表达式求值算法（支持+ - * /）
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int toNum(char num_ch)
{
    switch (num_ch) {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    }
}

double returnnum(string c, int n) //返回字符对应的数,n位数
{
    int l = n;
    double num = 0;
    double m = 1;
    for (int i = l - 1; i >= 0; i--) {
        num += toNum(c[i]) * m;
        m *= 10;
    }
    return num;
}

double calculator(string a)
{
    stack<double> num;
    stack<char> ope;
    for(string::iterator i = a.begin(); i != a.end(); i++)
    {
        if(*i == '+' || *i == '-' || *i == '*' || *i == '/')
            ope.push(*i);
        else if(*i >= '0' && *i <= '9')
        {
            string x = "";
            do
            {
                x = x + *i;
                i++;
            }
            while(*i >= '0' && *i <= '9');
            i--;
            num.push(returnnum(x, x.size()));
        }
        else if(*i == '(');
        else if(*i == ')')
        {
            double a = num.top();
            num.pop();
            double b = num.top();
            num.pop();
            char op = ope.top();
            ope.pop();
            if(op == '+')
                num.push(b + a);
            if(op == '-')
                num.push(b - a);
            if(op == '*')
                num.push(b * a);
            if(op == '/')
                num.push(b / a);                
        }
    }
    return num.top();
}



int main()
{
    string x;
    while(cin >> x && x != "0")
    {
        cout << calculator(x) << endl;
    }
    // double a = 13, b = 14;
    // cout << a/b;
    return 0;
}