#include "gtest/gtest.h"
#include "hierarchy.h"

template<class T>
class TypedFixure : public ::testing::TestWithParam<T>{
    public:
    void SetUp(){
        parent = new T;
    }
    void TearDown(){
        delete parent;
    }

    protected:
    T* parent;
};

typedef ::testing::Types<Child1, Child2, Child3> implementations;

TYPED_TEST_CASE(TypedFixure, implementations);
TYPED_TEST(TypedFixure, implementations){
    this -> parent -> doSome();
}
