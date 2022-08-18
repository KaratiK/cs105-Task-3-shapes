// CS105_Task3_Assessment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class print {
public:
	void square() {
		for (int i = 0; i < 10; i++)
		{
			cout << "\n\t\t* * * * * * * * * *";
		}
	}

	void rectangle() {
		cout << "\n";
		for (int i = 0; i < 5; i++)
		{
			cout << "\n\t\t* * * * * * * * * *";
		}
	}

	void triangle() {
		cout << "\n";
		cout << "\n\t\t     *";
		cout << "\n\t\t   * * *";
		cout << "\n\t\t  * * * *";
		cout << "\n\t\t * * * * *";
		cout << "\n\t\t* * * * * *";
	}

	void circle() {
		cout << "\n";
		cout << "\n\t\t     * * *";
		cout << "\n\t\t   * * * * *";
		cout << "\n\t\t  * * * * * *";
		cout << "\n\t\t  * * * * * *";
		cout << "\n\t\t   * * * * *";
		cout << "\n\t\t     * * *";
	}
};

class shapes {
public:
	double H; double W; double res;

	void getData() {
		cout << "\nHeight: ";
		cin >> H;
		cout << "\nWidth: ";
		cin >> W;
	}
	void calculateArea(int h, int w) {
		int H = h; int W = w;
		res = h * w;
	}
	void giveResult() {
		cout << res << "cm";
	}
};

class square : public shapes {
public:
	void calculateP(int h, int w) {
		res = H * 4;
	}
};

class rectangle : public shapes {
public:
	void calculateP(int h, int w) {
		res = (H * 2) + (W * 2);
	}
};

class triangle : public shapes {
public:
	void calculateP(int h, int w) {
		res = (H * W) / 2;
	}
};

class circle : public shapes {
public:
	void calculateP(int h, int w) {
		res = (2 * 3.141) * (H / 2);
	}
};

int main()
{
	print p;
	rectangle rec; square sq; triangle tri; circle cir;
	cout << "Chose your shape!\n\n1: Rectangle\n2: Square\n3: Triangle\n4: Circle\n";
	int i;
	cin >> i;
	cout << "Chose your operation!\n\n1: Calculate Area\n2: Calculate Perimeter/Circumference\n";
	int z;
	cin >> z;


	if (i == 1) {
		cout << "Rectangle";
		p.rectangle();
		rec.getData();
		if (z == 1) {
			rec.calculateArea(rec.H, rec.W);
			cout << "area = ";
		}
		else if (z == 2) {
			rec.calculateP(rec.H, rec.W);
			cout << "perimiter = ";
		}
		rec.giveResult();

	}
	else if (i == 2) {
		cout << "Square";
		p.square();
		sq.getData();
		if (z == 1) {
			sq.calculateArea(sq.H, 1);
			cout << "area = ";
		}
		else if (z == 2) {
			sq.calculateP(sq.H, sq.W);
			cout << "perimiter = ";
		}
		sq.giveResult();
	}
	else if (i == 3) {
		cout << "Triangle";
		p.triangle();
		tri.getData();
		if (z == 1) {
			tri.calculateArea(tri.H / 2, tri.W);
			cout << "area = ";
		}
		else if (z == 2) {
			tri.calculateP(tri.H, tri.W);
			cout << "perimiter = ";
		}
		tri.giveResult();
	}
	else if (i == 4) {
		cout << "Circle";
		p.circle();
		cir.getData();
		if (z == 1) {
			cir.calculateArea(3.141 * (cir.H / 2) * (cir.H / 2), 1);
			cout << "area = ";
		}
		else if (z == 2) {
			cir.calculateP(cir.H, 1);
			cout << "circumference = ";
		}
		cir.giveResult();
	}
}