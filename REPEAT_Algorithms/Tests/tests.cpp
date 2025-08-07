//
// Created by eljes on 07/08/2025.
//
#include <gtest/gtest.h>
#include "OrderedArray.h"

TEST(OrderedArrayTest, PushAndGet){
OrderedArray<int> arr;
arr.push(3);
arr.push(1);
arr.push(2);

EXPECT_EQ(arr.length(), 3);
EXPECT_EQ(arr.getElement(0), 1);
EXPECT_EQ(arr.getElement(1), 2);
EXPECT_EQ(arr.getElement(2), 3);
}

TEST(OrderedArrayTest, PushAndGet){
OrderedArray<int> arr;
arr.push(5);
arr.push(2);
arr.push(8);

EXPECT_TRUE(arr.remove(1));
EXPECT_EQ(arr.length(), 2);
EXPECT_EQ(arr.getElement(0), 2);
EXPECT_EQ(arr.getElement(1), 8);

}
