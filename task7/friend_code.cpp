#include <iostream>
#include <stdexcept>
using namespace std;

// Вариант 5: движение по окружности
struct CircularMotion
{
    // Угловая скорость ω = v / r
    static double angularVelocity(double v, double r)
    {
        if (r <= 0)
            throw invalid_argument("Радиус должен быть больше 0");
        return v / r;
    }

    // Центростремительное ускорение a = v^2 / r
    static double centripetalAcceleration(double v, double r)
    {
        if (r <= 0)
            throw invalid_argument("Радиус должен быть больше 0");
        return (v * v) / r;
    }

    // Частота f = 1 / T
    static double frequency(double T)
    {
        if (T <= 0)
            throw invalid_argument("Период должен быть больше 0");
        return 1.0 / T;
    }

    // Период T = 1 / f
    static double period(double f)
    {
        if (f <= 0)
            throw invalid_argument("Частота должна быть больше 0");
        return 1.0 / f;
    }
};
int main()
{
    setlocale(0, "");

    try
    {
        double v, r;
        cout << "Введите скорость v (м/с): ";
        cin >> v;
        cout << "Введите радиус r (м): ";
        cin >> r;

        cout << "Угловая скорость ω = " << CircularMotion::angularVelocity(v, r) << " рад/с" << endl;
        cout << "Центростремительное ускорение a = " << CircularMotion::centripetalAcceleration(v, r) << " м/с^2" << endl;

        double T;
        cout << "\nВведите период T (с): ";
        cin >> T;
        cout << "Частота f = " << CircularMotion::frequency(T) << " 1/с" << endl;

        double f;
        cout << "\nВведите частоту f (1/с): ";
        cin >> f;
        cout << "Период T = " << CircularMotion::period(f) << " с" << endl;
    }
    catch (const exception& ex)
    {
        cout << "Ошибка: " << ex.what() << endl;
    }
    system("pause");
    return 0;
}
