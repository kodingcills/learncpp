#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Shape{
    protected:
        string m_color;
    public:
        Shape(string color): m_color(color){}

        virtual double Area() const = 0;
        virtual double Perimeter() const = 0;
        virtual void Print() const{
            cout << "Color: " << m_color << endl;
            cout << "Area: " << Area() << endl;
            cout << "Perimeter: " << Perimeter() << endl;
        }

        virtual ~Shape(){}
};

class Circle: public Shape{
    private:
        double m_radius;
    public:
        Circle(string color, double radius): Shape(color), m_radius(radius){}

    virtual double Area() const{
        return 3.14159*m_radius*m_radius;
    }
    virtual double Perimeter() const{
        return 2*3.14159*m_radius;
    }
    virtual void Print() const{
        cout << "Circle: " << endl;
        Shape::Print();
    }
};

class Rectangle: public Shape{
    private:
        double m_width, m_height;
    public:
        Rectangle(string color, double width, double height): Shape(color), m_width(width), m_height(height){}

        virtual double Area() const{
            return m_width*m_height;
        }

        virtual double Perimeter() const{
            return 2*(m_width+m_height);
        }

        virtual void Print() const{
            cout << "Recangle:" << endl;
            Shape::Print();
        }
};

int main(){
    vector<Shape*> shapes;
    shapes.push_back(new Circle("blue", 4));
    shapes.push_back(new Rectangle("blue",3,2));
    for(int i = 0; i < (int)shapes.size(); i++){
        shapes.at(i)->Print();
    }

    // Shape s("red")
    //this fails because it's an abstract virtual class, so you can't create an instance of the object of it

    for(int i = 0; i < (int)shapes.size(); i++){
        delete shapes[i];
        shapes[i] = nullptr;
    }
}