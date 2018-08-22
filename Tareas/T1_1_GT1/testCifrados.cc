#include "gtest/gtest.h"
#include "cifrados.h"

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

class Comb : public ::testing::TestWithParam< ::testing::tuple<int, int> >{
    public:
    int num1 = ::testing::get<0>(GetParam());
    int num2 = ::testing::get<1>(GetParam());
};
