#include <iostream>
#include <iomanip>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

void menu();
short input_and_check(int, int);
double func_1(double, int, double&);
double func_2(double, int, double, int&);

int main() {

	bool tag = 1;
	do {
		menu();
		short choice = input_and_check(1, 3);

		double sum, arg;
		int num;

		switch (choice) {

		case 1: {
			cout << "Введите значение аргумента: ";
			cin >> arg;
			cout << "Введите количество слагаемых ряда: ";
			cin >> num;
			double eps, last_n;
			sum = func_1(arg, num, last_n);
			eps = fabs(cos(arg) - sum);
			cout << "\nЧастичная сумма ряда равна: " << sum << endl;
			cout << "Абсолютная погрешность равна: " << eps << endl << "Последнее слагаемое ряда равно: " << last_n << endl;
			cout << "Разность абс. погр. и послед. слаг.: " << eps - fabs(last_n) << endl << endl;
			break;
		}

		case 2: {
			int n;
			double E, sum;
			cout << "Введите значение аргумента: ";
			cin >> arg;
			cout << "Введите количество слагаемых ряда: ";
			cin >> num;
			cout << "Введите знач. с которым будут сравниваться слагаемые: ";
			cin >> E;
			sum = func_2(arg, num, E, n);
			cout << "\nСумма слаг., которые больше Е1 по абс. величине: " << sum << endl;
			cout << "Количество таких слагаемых: " << n << endl << endl;
			E *= 10;
			sum = func_2(arg, num, E, n);
			cout << "Сумма слаг., которые больше Е1 в 10 раз по абс. величине: " << sum << endl;
			cout << "Количество таких слагаемых: " << n << endl << endl;
			break;
		}

		case 3: {
			tag = false;
			break;
		}

		}
	} while (tag == true);

}

void menu() {

	cout << "1. Решение задачи 1\n";
	cout << "2. Решение задачи 2\n";
	cout << "3. Завершение\n";

}

short input_and_check(int A, int B) {

	bool isError = true;
	short local_choice;
	do {
		cout << "-> ";
		cin >> local_choice;
		cout << endl;
		if (!cin.good() || local_choice < A || local_choice > B) {

			cout << "Ошибка ввода! Значение должно быть в диапазоне " << A << ".." << B << endl;
			cin.clear();
			cin.ignore(255, '\n');
		}
		else
			isError = false;

	} while (isError);

	return local_choice;
}

double func_1(double x, int n, double& r)
{
	double S = x;
	r = x;
	for (int i = 1; i < n; i++)
	{
		r *= -x * x / (2 * i + 1) / (2 * i + 2);
		S += r;
	}
	return S;
}

double func_2(double x, int n, double E, int& N)
{
	double r = x, S = x;
	N = 0;
	if (r > E)
		N = 1;
	for (int i = 1; i < n; i++)
	{
		r *= -x * x / (2 * i + 1) / (2 * i + 2);
		if (fabs(r) > E) {
			S += r;
			N++;
		}
	}
	return S;
}