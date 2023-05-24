//task 1
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	string name;
	int age;
	Person() {};
	Person(string n,int a) {
		name = n;
		age = a;
	}
};

void print(Person* person)
{
	cout << person->name << " is " << person->age << " years old" << endl;
}

int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;
	cout << "Meet " << person.name<<endl;
	print(&person);
	Person guest("igor",24);
	print(&guest);
	Person teacher;
	teacher.name = "Svitlana";
	teacher.age = 12;
	print(&teacher);
	return 0;
}

//task 2
#include <iostream>
#include <string>

using namespace std;

class Square
{
public:
	Square(double side);
	double side;
	double area;
	void setSide(double x)
	{
		side = x;
		area = side * side;
	}
};
Square::Square(double side)
{
	this->side = side;
	this->area = side * side;
}

void print(Square* square)
{
	cout << "Square: side=" << square->side << " area=" <<square->area << endl;
}

int main()
{
	Square s(4);
	print(&s);
	s.setSide(2.2);
	print(&s);
	s.setSide(-33);
	print(&s);
		return 0;
}

//task 3

class AdHocSquare {
public:
    AdHocSquare(double side) : side(side) {}

    void set_side(double side) {
        this->side = side;
    }

    double get_area() {
        return side * side;
    }

private:
    double side;
};

class LazySquare {
public:
    LazySquare(double side) : side(side), area(side* side), side_changed(false) {}

    void set_side(double side) {
        this->side = side;
        side_changed = true;
    }

    double get_area() {
        if (side_changed) {
            area = side * side;
            side_changed = false;
        }
        return area;
    }

private:
    double side;
    double area;
    bool side_changed;
};