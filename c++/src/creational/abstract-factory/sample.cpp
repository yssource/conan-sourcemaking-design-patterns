#include "sample.h"
#include <iostream>

stringstream ss;
int Shape::total_ = 0;
Shape::Shape() { id_ = total_++; }
string Circle::draw() {
  ss.clear();
  ss.str("");
  ss << "circle " << id_ << ": draw";
  return ss.str();
}
string Square::draw() {
  ss.clear();
  ss.str("");
  ss << "square " << id_ << ": draw";
  return ss.str();
}
string Ellipse::draw() {
  ss.clear();
  ss.str("");
  ss << "ellipse " << id_ << ": draw";
  return ss.str();
}
string Rectangle::draw() {
  ss.clear();
  ss.str("");
  ss << "rectangle " << id_ << ": draw";
  return ss.str();
}
Shape *SimpleShapeFactory::createCurvedInstance() { return new Circle; }
Shape *SimpleShapeFactory::createStraightInstance() { return new Square; }
Shape *RobustShapeFactory::createCurvedInstance() { return new Ellipse; }
Shape *RobustShapeFactory::createStraightInstance() { return new Rectangle; }
