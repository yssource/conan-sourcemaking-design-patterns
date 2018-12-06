#include "after.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::HasSubstr;
namespace {
TEST(AFTER, AfterFactory) {
  Factory *factory;
#ifdef LINUX
  factory = new LinuxFactory;
#else // WINDOWS
  factory = new WindowsFactory;
#endif

  Client *c = new Client(factory);
  string s = c->draw();
  EXPECT_THAT(s, HasSubstr("LinuxButton"));
}
} // namespace
