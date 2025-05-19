#include "pch.h"
#include "PositionTests.h"

TEST_F(PositionTests, DefaultCreation) {
	Position position;
	EXPECT_EQ(position.x, 0);
	EXPECT_EQ(position.y, 0);
}

TEST_F(PositionTests, ParameterCreation) {
	int x = 3;
	int y = 17;
	Position position(x, y);
	EXPECT_EQ(position.x, x);
	EXPECT_EQ(position.y, y);
}

TEST_F(PositionTests, CopyCreation) {
	Position source(3, 17);
	Position dest(source);
	EXPECT_EQ(source.x, dest.x);
	EXPECT_EQ(source.y, dest.y);
}

TEST_F(PositionTests, CopyCreation_should_create_a_copy) {
	Position source(3, 17);
	Position dest(source);
	source.x = 100;
	source.y = 200;
	EXPECT_NE(source.x, dest.x);
	EXPECT_NE(source.y, dest.y);
}

TEST_F(PositionTests, SumOperator) {
	int x1 = 10, y1 = 12;
	int x2 = 7, y2 = 28;
	Position p1(x1, y1);
	Position p2(x2, y2);
	Position sum = p1 + p2;
	EXPECT_EQ(sum.x, x1 + x2);
	EXPECT_EQ(sum.y, y1 + y2);
}

TEST_F(PositionTests, EqualityTrue) {
	Position p1(10, 12);
	Position p2(10, 12);
	EXPECT_TRUE(p1 == p2);
}

TEST_F(PositionTests, EqualityFalse_x) {
	Position p1(10, 12);
	Position p2(9, 12);
	EXPECT_FALSE(p1 == p2);
} 

TEST_F(PositionTests, EqualityFalse_y) {
	Position p1(10, 12);
	Position p2(10, 13);
	EXPECT_FALSE(p1 == p2);
} 

TEST_F(PositionTests, EqualityFalse_xy) {
	Position p1(10, 12);
	Position p2(9, 13);
	EXPECT_FALSE(p1 == p2);
} 