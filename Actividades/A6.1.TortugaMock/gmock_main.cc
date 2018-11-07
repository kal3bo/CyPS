#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::InSequence;

class Tortuga {
public:
  virtual ~Tortuga() {}
  virtual void PenUp() {}
  virtual void PenDown() {}
  virtual int GetX() {}
  virtual int GetY() {}
  virtual void Forward(int distancia) {}
  virtual void Turn(int grados) {}
  virtual void GoTo(int x, int y) {}
};

class MockTortuga : public Tortuga {
 public:
  MOCK_METHOD0(PenUp, void());
  MOCK_METHOD0(PenDown, void());
  MOCK_METHOD0(GetX, int());
  MOCK_METHOD0(GetY, int());
  MOCK_METHOD1(Forward, void(int distancia));
  MOCK_METHOD1(Turn, void(int grados));
  MOCK_METHOD2(GoTo, void(int x, int y));
};

class Pintor {
	Tortuga & t;
public:
  Pintor(Tortuga & _t) : t(_t) { /*t.PenDown();*/ }
  //
  //
  void Pinta(){
    t.PenDown();
    t.PenUp();
    t.GetX();
    t.GetY();
    t.Forward(1);
    t.Turn(180);
    t.GoTo(0, 0);
    //t->PenDown();
  }
};

TEST(PruebaDibujo, DibujaAlgo) {
  // Arrange
  MockTortuga turtle;
  Pintor t(turtle);
  {
    InSequence algo;
    EXPECT_CALL(turtle, PenDown()).Times(1);
    EXPECT_CALL(turtle, PenUp()).Times(1);
    EXPECT_CALL(turtle, GetX()).Times(1);
    EXPECT_CALL(turtle, GetY()).Times(1);
    EXPECT_CALL(turtle, Forward(1)).Times(1);
    EXPECT_CALL(turtle, Turn(180)).Times(1);
    EXPECT_CALL(turtle, GoTo(0, 0)).Times(1);


  }
  //EXPECT_CALL(turtle, PenDown()).Times(1);
	// Act
  t.Pinta();
	// Assert
	//
} 


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
