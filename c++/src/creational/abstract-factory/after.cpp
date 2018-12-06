#include "after.h"

/**
 * Abstract base product. It should define an interface
 * which will be common to all products. Clients will
 * work with products through this interface, so it
 * should be sufficient to use all products.
 */
/**
 * Concrete product family 1.
 */
string LinuxButton::draw() {
  return boost::str(boost::format("%s") % "LinuxButton\n");
}
string LinuxMenu::draw() {
  return boost::str(boost::format("%s") % "LinuxMenu\n");
}

/**
 * Concrete product family 2.
 */
string WindowsButton::draw() {
  return boost::str(boost::format("%s") % "WindowsButton\n");
}
string WindowsMenu::draw() {
  return boost::str(boost::format("%s") % "WindowsMenu\n");
}

/**
 * Abstract factory defines methods to create all
 * related products.
 */
/**
 * Each concrete factory corresponds to one product
 * family. It creates all possible products of
 * one kind.
 */
Widget *LinuxFactory::create_button() { return new LinuxButton; }
Widget *LinuxFactory::create_menu() { return new LinuxMenu; }

/**
 * Concrete factory creates concrete products, but
 * returns them as abstract.
 */
Widget *WindowsFactory::create_button() { return new WindowsButton; }
Widget *WindowsFactory::create_menu() { return new WindowsMenu; }

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

Client::Client(Factory *f) { factory = f; }

string Client::draw() {
  Widget *w = factory->create_button();
  auto s = w->draw();
  auto ss = display_window_one();
  auto sss = display_window_two();
  return boost::str(boost::format("%s%s%s") % s % ss % sss);
}

string Client::display_window_one() {
  Widget *w[] = {factory->create_button(), factory->create_menu()};
  auto s = w[0]->draw();
  auto ss = w[1]->draw();
  return boost::str(boost::format("%s%s") % s % ss);
}

string Client::display_window_two() {
  Widget *w[] = {factory->create_menu(), factory->create_button()};
  auto s = w[0]->draw();
  auto ss = w[1]->draw();
  return boost::str(boost::format("%s%s") % s % ss);
}
