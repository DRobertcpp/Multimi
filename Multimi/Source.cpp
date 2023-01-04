#include "Header.h"


Multime::Multime() { //constructor
	dim = 10;
	date = new int[dim];
	n = 0;
}

Multime::Multime(int d) {
	dim = d;
	date = new int[dim];
	n = 0;
}Multime::~Multime() { //destructorul
	if (date)delete[] date;
}void Multime::adauga(int v) {
	if (n == dim) {
		cout << "Multimea este plina!" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
		if (date[i] == v)
			return;
	date[n++] = v;
}
void Multime::extrage(int v) {
	for (int i = 0; i < n; i++)
		if (date[i] == v) {
			for (int j = i; j < n - 1; j++)
				date[j] = date[j + 1];
			n--;
		}
}ostream& operator<<(ostream& out, const Multime& M) {
	cout << "{";
	for (int i = 0; i < M.n; i++)
		cout << " " << M.date[i];
	cout << " }" << endl;
	return out;
}

Multime& Multime::operator+=(int n) {
	adauga(n);
	return *this;
}

Multime& Multime::operator-=(int n) {
	extrage(n);
	return *this;
}

Multime Multime::operator+(const Multime& M) {
	Multime R(dim + M.dim);
	for (int i = 0; i < n; i++)
		R += date[i];
	for (int i = 0; i < M.n; i++)
		R += M.date[i];
	return R;
}

Multime::Multime(const Multime& M) {
	n = M.n;
	dim = M.dim;
	date = new int[dim];
	for (int i = 0; i < n; i++)
		date[i] = M.date[i];
}

Multime& Multime::operator=(const Multime& M) {

	if (this != &M) {
		if (date)
			delete[]date;
		n = M.n;
		dim = M.dim;
		date = new int[dim];
		for (int i = 0; i < n; i++)
			date[i] = M.date[i];
	}
	return *this;
}

int main()
{
	Multime A, M, B, C;
	A.adauga(4); A.adauga(5); A.adauga(5);
	cout << A;
	M += 12; A -= 5;
	A.extrage(4); cout << A;
	cout << M;
	B += 5; B.adauga(10); B.adauga(10);
	cout << B;
	cout << M + B;
	C = M + B;
	cout << C;
	system("pause");
	return 0;
}