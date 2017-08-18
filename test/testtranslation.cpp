/*
 * testtranslation.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: kyle
 */

#include "gtest/gtest.h"
#include "utils/Translation2D.h"

TEST(TranslationTest, TranslateBy) {

	Translation2D translation(1, 2);
	Translation2D actual = translation.translateBy(Translation2D(2, 3));

	EXPECT_EQ(3.0, actual.getX());
	EXPECT_EQ(5.0, actual.getY());
}

TEST(TranslationTest, TranslateByNeg) {

	Translation2D translation(1, 2);
	Translation2D actual = translation.translateBy(Translation2D(-2, -3));

	EXPECT_EQ( -1.0, actual.getX());
	EXPECT_EQ(-1.0, actual.getY());
}

TEST(TranslationTest, Norm) {

	Translation2D translation(1, 2);
	double actual = translation.norm();

	EXPECT_NEAR( 2.23607, actual, 1E-3);
}

TEST(TranslationTest, Inverse) {

	Translation2D translation(1, 2);
	Translation2D  actual = translation.inverse();

	EXPECT_EQ(-1.0, actual.getX());
	EXPECT_EQ(-2.0, actual.getY());
}

TEST(TranslationTest, RotateBy) {

	Translation2D translation(1, 2);
	Translation2D actual = translation.rotateBy(Rotation2D::fromDegrees(90));

	EXPECT_NEAR(-2.0, actual.getX(), 1E-3);
	EXPECT_NEAR(1.0, actual.getY(), 1E-3);
}

TEST(TranslationTest, Interpolate) {

	Translation2D translation1(1.5, 2);
	Translation2D translation2(-4, -3);
	Translation2D interpolated = translation1.interpolate(translation2, 0.5);

	EXPECT_NEAR(-1.25, interpolated.getX(), 1E-3);
	EXPECT_NEAR(-0.5, interpolated.getY(), 1E-3);
}
