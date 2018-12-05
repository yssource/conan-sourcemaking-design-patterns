#include "before.h"
#include <iostream>
#define LINUX

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
 * Here's a client, which uses concrete products directly.
 * It's code filled up with nasty switch statements
 * which check the product type before its use.
 */
string Client::draw() {
#ifdef LINUX
  Widget *w = new LinuxButton;
#else // WINDOWS
  Widget *w = new WindowsButton;
#endif
  string s = w->draw();
  string ss = display_window_one();
  string sss = display_window_two();
  return boost::str(boost::format("%s%s%s") % s % ss %sss);
}

string Client::display_window_one() {
#ifdef LINUX
  Widget *w[] = {new LinuxButton, new LinuxMenu};
#else // WINDOWS
  Widget *w[] = {new WindowsButton, new WindowsMenu};
#endif
  string s = w[0]->draw();
  string ss = w[1]->draw();
  return boost::str(boost::format("%s%s") % s % ss);
}

string Client::display_window_two() {
#ifdef LINUX
  Widget *w[] = {new LinuxMenu, new LinuxButton};
#else // WINDOWS
  Widget *w[] = {new WindowsMenu, new WindowsButton};
#endif
  string s = w[0]->draw();
  string ss = w[1]->draw();
  return boost::str(boost::format("%s%s") % s % ss);
}
