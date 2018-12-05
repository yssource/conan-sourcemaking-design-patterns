#pragma once
#include <sstream>
#include <string>
using namespace std;

class Shape {
public:
  Shape();
  virtual string draw() = 0;

protected:
  int id_;
  static int total_;
};

class Circle : public Shape {
public:
  string draw();
};

class Square : public Shape {
public:
  string draw();
};

class Ellipse : public Shape {
public:
  string draw();
};

class Rectangle : public Shape {
public:
  string draw();
};

class Factory {
public:
  virtual Shape *createCurvedInstance() = 0;
  virtual Shape *createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory {
public:
  Shape *createCurvedInstance();
  Shape *createStraightInstance();
};

class RobustShapeFactory : public Factory {
public:
  Shape *createCurvedInstance();
  Shape *createStraightInstance();
};
