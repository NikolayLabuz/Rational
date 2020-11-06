// Rational_Throw.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
#include <set>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return GCD(b, a % b);
    }
}
class Rational {
public:
    Rational() {
        numerators = 0;
        denominators = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument ("Invalid argument");
        }
        const int NOD = GCD(numerator, denominator);
        denominator /= NOD;
        numerator /= NOD;
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        denominators = denominator;
        numerators = numerator;
    }

    int Numerator() const {
        return numerators;
    }

    int Denominator() const {
        return denominators;
    }
private:
    int numerators;
    int denominators;
};
Rational operator + (const Rational& lhs, const Rational& rhs) {
    return{
        lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}
Rational operator - (const Rational& lhs, const Rational& rhs) {
    return{
        lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}
bool operator == (const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
        return true;
    }
    else {
        return false;
    }

}
ostream& operator << (ostream& stream, const Rational& Rationals) {
    return stream << Rationals.Numerator() << "/" << Rationals.Denominator();
}
istream& operator >> (istream& stream, Rational& Rationals) {
    int n, d;
    char c;
    stream >> n >> c >> d;
    if (stream && c == '/') {
        Rationals = Rational(n, d);
    }
    return stream;
}
Rational operator * (const Rational& lhs, const Rational& rhs) {
    return{
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    };
}
Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator()==0) {
        throw domain_error("Division by zero");
    }
    return{
        lhs.Numerator() * rhs.Denominator(),
        rhs.Numerator() * lhs.Denominator()
    };
}
bool operator < (const Rational& lhs, const Rational& rhs) {
    if ((lhs - rhs).Numerator() < 0) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    Rational a, b;
    string k;
    try {
        cin >> a >> k >> b;
    }
    catch(invalid_argument& e) {
        cout << e.what();
        return 0;
    }
    if (k == "+") {
        cout << a + b;
    }
    else if (k == "-") {
        cout << a - b;
    }
    else if (k == "*") {
        cout << a * b;
    }
    else if (k == "/") {
        try {
            cout << a / b;
        }
        catch (domain_error& e) {
            cout << e.what();
        }
    }

    return 0;
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
