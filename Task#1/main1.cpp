#include <iostream>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
enum color
{
    none = 0,
    red = 1,
    blue = 2,
    green = 3
};

class Figure
{
    // public:
    int coord[2] = {0, 0};
    char color = 0;
    friend class Circle; //: public Figure
    friend class Square;
    friend class Triangle;
    friend class Rectangle;
};
class Circle : public Figure
{
    double radius = 1;
    double squCircle()
    {
        return atan(1) * 4 * radius;
    }

public:
    void infoCircle()
    {
        std::cout << "Circle:\nСoordinates: (" << coord[0] << "," << coord[1]
                  << ");\n Color:";
        if (color == color ::none)
            std::cout << "None;" << std::endl;
        else if (color == color ::blue)
            std::cout << "Blue;" << std::endl;
        else if (color == color ::red)
            std::cout << "Red;" << std::endl;
        else if (color == color ::green)
            std::cout << "Green;" << std::endl;
        std::cout
            << "\nArea of the circle: " << squCircle()
            << ";\nArea of the circumscribing rectangle: " << pow((radius * 2), 2)
            << std::endl;
    }
    Circle(int inCoord[2], char inColor, double inRadius) : radius(inRadius)
    {
        assert(inRadius > 0);
        coord[0] = inCoord[0];
        coord[1] = inCoord[1];
        color = inColor;
    }
};
class Square : public Figure
{
    double length = 10;
    double areaSquare()
    {
        return pow(length, 2);
    }

public:
    void infoSquare()
    {
        std::cout << "Square:\nСoordinates: (" << coord[0] << "," << coord[1]
                  << ");\n Color:";
        if (color == color ::none)
            std::cout << "None;" << std::endl;
        else if (color == color ::blue)
            std::cout << "Blue;" << std::endl;
        else if (color == color ::red)
            std::cout << "Red;" << std::endl;
        else if (color == color ::green)
            std::cout << "Green;" << std::endl;
        std::cout
            << "\nArea of the square: " << areaSquare()
            << ";\nArea of the circumscribing rectangle: " << areaSquare()
            << std::endl;
    }
    Square(int inCoord[2], char inColor, double inLength) : length(inLength)
    {
        assert(inLength > 0);
        coord[0] = inCoord[0];
        coord[1] = inCoord[1];
        color = inColor;
    }
};
class Triangle : public Figure
{
    double ribLength = 10;
    double areaTriangle()
    {
        return ribLength * ribLength * std::sqrt(3);
    }

public:
    void infoTriangle()
    {
        std::cout << "Triangle:\nСoordinates: (" << coord[0] << "," << coord[1]
                  << ");\n Color:";
        if (color == color ::none)
            std::cout << "None;" << std::endl;
        else if (color == color ::blue)
            std::cout << "Blue;" << std::endl;
        else if (color == color ::red)
            std::cout << "Red;" << std::endl;
        else if (color == color ::green)
            std::cout << "Green;" << std::endl;
        std::cout
            << "\nArea of the triangle: " << areaTriangle()
            << ";\nArea of the circumscribing rectangle: " << sqrt(pow(ribLength, 2) + pow((ribLength / 2), 2))
            << std::endl;
    }
    Triangle(int inCoord[2], char inColor, double inRibLength) : ribLength(inRibLength)
    {
        assert(ribLength > 0);
        coord[0] = inCoord[0];
        coord[1] = inCoord[1];
        color = inColor;
    }
};
class Rectangle : public Figure
{
    double weight = 20;
    double height = 10;
    double areaRectangle()
    {
        return weight * height;
    }

public:
    void infoRectangle()
    {
        std::cout << "Square:\nСoordinates: (" << coord[0] << "," << coord[1]
                  << ");\n Color:";
        if (color == color ::none)
            std::cout << "None;" << std::endl;
        else if (color == color ::blue)
            std::cout << "Blue;" << std::endl;
        else if (color == color ::red)
            std::cout << "Red;" << std::endl;
        else if (color == color ::green)
            std::cout << "Green;" << std::endl;
        std::cout << "\nArea of the square: " << areaRectangle()
                  << ";\nArea of the circumscribing rectangle: " << areaRectangle()
                  << std::endl;
    }
    Rectangle(int inCoord[2], char inColor, double inWeight, double inHeight) : weight(inWeight), height(inHeight)
    {
        assert(inWeight != inHeight && inWeight > 0 && inHeight > 0);
        coord[0] = inCoord[0];
        coord[1] = inCoord[1];
        color = inColor;
    }
};
int main()
{
    std::string command;
    while (command != "close")
    {
        std::srand(time(0));
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "circle")
        {
            int value[2] = {rand() % 100, rand() % 100};
            Circle circle = Circle(value, rand() % 4, 1.2);
            circle.infoCircle();
        }
        else if (command == "square")
        {
            int value[2] = {rand() % 100, rand() % 100};
            Square square = Square(value, rand() % 4, 1.2);
            square.infoSquare();
        }
        else if (command == "triangle")
        {
            int value[2] = {rand() % 100, rand() % 100};
            Triangle triangle = Triangle(value, rand() % 4, 1.2);
            triangle.infoTriangle();
        }
        else if (command == "rectangle: ")
        {
            int value[2] = {rand() % 100, rand() % 100};
            Rectangle rectangle = Rectangle(value, rand() % 4, 1.2, 2.1);
            rectangle.infoRectangle();
        }
    }
}