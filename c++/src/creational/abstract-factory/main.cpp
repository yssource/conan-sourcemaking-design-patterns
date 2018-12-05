#include "before.h"
int main() {
  Client *c = new Client();
  string s = c->draw();
  cout << s << endl;
}
