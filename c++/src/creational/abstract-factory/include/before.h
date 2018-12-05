#pragma once
#include <boost/format.hpp>
#include <iostream>
#define LINUX
using namespace std;

/**
 * Abstract base product.
 */
class Widget {
public:
  virtual string draw() = 0;
};

/**
 * Concrete product family 1.
 */
class LinuxButton : public Widget {
public:
  string draw();
};
class LinuxMenu : public Widget {
public:
  string draw();
};

/**
 * Concrete product family 2.
 */
class WindowsButton : public Widget {
public:
  string draw();
};
class WindowsMenu : public Widget {
public:
  string draw();
};

/**
 * Here's a client, which uses concrete products directly.
 * It's code filled up with nasty switch statements
 * which check the product type before its use.
 */
class Client {
public:
  string draw();
  string display_window_one();
  string display_window_two();
};
