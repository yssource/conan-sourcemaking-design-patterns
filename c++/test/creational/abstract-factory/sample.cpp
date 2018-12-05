#include "sample.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::HasSubstr;
namespace {
// Tests the default c'tor.
TEST(MyString, DefaultConstructor) {
#ifdef SIMPLE
  Factory *factory = new SimpleShapeFactory;
#elif ROBUST
  Factory *factory = new RobustShapeFactory;
#endif

  Shape *shapes[3];

  shapes[0] = factory->createCurvedInstance();   // shapes[0] = new Ellipse;
  shapes[1] = factory->createStraightInstance(); // shapes[1] = new Rectangle;
  shapes[2] = factory->createCurvedInstance();   // shapes[2] = new Ellipse;

#ifdef SIMPLE
  EXPECT_THAT(shapes[0]->draw(), HasSubstr("circle 0"));
  EXPECT_THAT(shapes[1]->draw(), HasSubstr("square 1"));
  EXPECT_THAT(shapes[2]->draw(), HasSubstr("circle 2"));
#elif ROBUST
  EXPECT_THAT(shapes[0]->draw(), HasSubstr("ellipse 0"));
  EXPECT_THAT(shapes[1]->draw(), HasSubstr("rectangle 1"));
  EXPECT_THAT(shapes[2]->draw(), HasSubstr("ellipse 2"));
#endif
}
} // namespace
