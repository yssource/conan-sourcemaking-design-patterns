#include "before.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::HasSubstr;
namespace {
// Tests the default c'tor.
TEST(Before, BeforeFactory) {
  Client *c = new Client();
  string s = c->draw();
  EXPECT_THAT(s, HasSubstr("LinuxButton"));

  // string expect("LinuxButton\n");
  // Widget *w = new LinuxButton;
  // auto s = w->draw();
  // EXPECT_EQ(0, s.compare(expect));
  // EXPECT_EQ(0, 0);
}
} // namespace
