#pragma once
#include <boost/format.hpp>
#include <iostream>
#define LINUX
using namespace std;

/**
 * Abstract base product. It should define an interface
 * which will be common to all products. Clients will
 * work with products through this interface, so it
 * should be sufficient to use all products.
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
 * Abstract factory defines methods to create all
 * related products.
 */
class Factory {
public:
  virtual Widget *create_button() = 0;
  virtual Widget *create_menu() = 0;
};

/**
 * Each concrete factory corresponds to one product
 * family. It creates all possible products of
 * one kind.
 */
class LinuxFactory : public Factory {
public:
  Widget *create_button();
  Widget *create_menu();
};

/**
 * Concrete factory creates concrete products, but
 * returns them as abstract.
 */
class WindowsFactory : public Factory {
public:
  Widget *create_button();
  Widget *create_menu();
};

/**
 * Client receives a factory object from its creator.
 *
 * All clients work with factories through abstract
 * interface. They don't know concrete classes of
 * factories. Because of this, you can interchange
 * concrete factories without breaking clients.
 *
 * Clients don't know the concrete classes of created
 * products either, since abstract factory methods
 * returns abstract products.
 */
class Client {
private:
  Factory *factory;

public:
  Client(Factory *f);

  string draw();

  string display_window_one();

  string display_window_two();
};
