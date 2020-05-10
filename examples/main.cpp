#include <iostream>
#include <vector>
using namespace std;

class Shape {
    public:
    virtual string get_name() const = 0;
    virtual float get_area() const = 0;
};

class Triangle : public Shape {
    public:
    float m_base;
    float m_height;

    Triangle(float base, float height) : m_base{base}, m_height{height} {}
    virtual string get_name() const override {
        return {"Triangle"};
    }
    virtual float get_area() const override {
        return 0.5*m_base*m_height;
    }
};

class Rectangle : public Shape {
    public:
    float m_length;
    float m_width;

    Rectangle(float length, float width) : m_length{length}, m_width{width} {}
    virtual string get_name() const override {
        return {"Rectangle"};
    }
    virtual float get_area() const override {
        return m_length*m_width;
    }
};

class Circle : public Shape {
    public:
    float m_radius;

    Circle(float radius) : m_radius{radius} {}
    virtual string get_name() const override {
        return {"Circle"};
    }
    virtual float get_area() const override {
        return 3.14159*m_radius*m_radius;
    }
    float get_circumference() const {
        return 2*3.14159*m_radius;
    }
    float get_diameter() const {
        return 2*m_radius;
    }
};

int main()
{
    Triangle triangle{3,3};
    Rectangle rectangle{3,3};
    Circle circle{3};

    vector<Shape *> shapes;
    shapes.push_back(&triangle);
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);

    for(auto shape : shapes) {
        cout << shape->get_name() << " Area : " << shape->get_area() << endl;
    }   
    return 0;
}