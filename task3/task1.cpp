#include <iostream>
// <summary>
// Вычисляет периметр квадрата.
// </summary>
// <param name="side">Длина стороны квадрата.</param>
// <returns>
// Периметр квадрата, если длина стороны положительна.
// Возвращает -1, если длина стороны некорректна (меньше либо равна нулю).
// </returns>
double calculateSquarePerimetr(double side)
{
	if (side <= 0.0)
	{
		return -1.0;
	}
	return 4. * side;
}
int main()
{
	setlocale(LC_ALL, "");
	double side = 5.0;
	double perimetr = calculateSquarePerimetr(side);
	std::cout << "Длина стороны квадрата: " << side << std::endl;
	std::cout << "Периметр квадрата: " << perimetr << std::endl;
	return 0;
}
