/*
 * testrotation.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: kyle
 */

#include "gtest/gtest.h"
#include "utils/Translation2D.h"

#include <math.h>

TEST(RotationTest, FromRadadians) {

	Rotation2D actual = Rotation2D::fromRadians(M_PI/3);

	EXPECT_NEAR(0.866, actual.getSin(), 1E-3);
	EXPECT_NEAR(0.5, actual.getCos(), 1E-3);
}

TEST(RotationTest, FromDegrees) {

	Rotation2D actual = Rotation2D::fromDegrees(60);

	EXPECT_NEAR(0.866, actual.getSin(), 1E-3);
	EXPECT_NEAR(0.5, actual.getCos(), 1E-3);
}

TEST(RotationTest, RotateBy) {

	Rotation2D rotation = Rotation2D::fromDegrees(60);
	Rotation2D actual = rotation.rotateBy(Rotation2D::fromDegrees(90));

	EXPECT_NEAR(0.5, actual.getSin(), 1E-3);
	EXPECT_NEAR(-0.866, actual.getCos(), 1E-3);
}

TEST(RotationTest, Inverse) {

	Rotation2D rotation = Rotation2D::fromDegrees(-60);
	Rotation2D actual = rotation.inverse();

	EXPECT_NEAR(0.866, actual.getSin(), 1E-3);
	EXPECT_NEAR(.5, actual.getCos(), 1E-3);
}

TEST(RotationTest, Norm) {
	//TODO Figure this out.
}

TEST(RotationTest, Interpolate) {

	Rotation2D rotation1 = Rotation2D::fromDegrees(75);
	Rotation2D rotation2 = Rotation2D::fromDegrees(-40);
	Rotation2D interpolated = rotation1.interpolate(rotation2, 0.5);

	EXPECT_NEAR(sin(17.5 * M_PI / 180), interpolated.getSin(), 1E-3);
	EXPECT_NEAR(cos(17.5 * M_PI / 180), interpolated.getCos(), 1E-3);
}
