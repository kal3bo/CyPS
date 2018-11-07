#include <string>
#include "gtest/gtest.h"

using namespace std;

TEST(TestCase, TestName){
	int a = 5;
	int b = 5;
	ASSERT_TRUE(a == b);
}
