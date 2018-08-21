#include "gtest/gtest.h"
#include "sort.h"

template <class T>
class SortFixure : public ::testing::TestWithParam<T>{
    public:
    void SetUp(){
        arr = new T;
    }
    void TearDown(){
        delete arr;
    }

    protected:
    T* arr;
};

typedef ::testing::Types<QuickSort> implementations;
TYPED_TEST_CASE(SortFixure, implementations);
TYPED_TEST(TypedFixure, implementations){
    this -> arr -> ordenar();
}

int arr[] = {10, 7, 8, 9, 1, 5};
