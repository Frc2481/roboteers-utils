/*
 * testrotation.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: kyle
 */

#include "gtest/gtest.h"
#include "utils/Translation2D.h"
#include "utils/RigidTransform2D.h"
#include <math.h>

TEST(RigidTransformTest, inverse) {
	RigidTransform2D start = RigidTransform2D::fromTranslation(Translation2D(5,5));
	EXPECT_NEAR(-5, start.inverse().getTranslation().getX(), 1E-3);
	EXPECT_NEAR(-5, start.inverse().getTranslation().getY(), 1E-3);
}

TEST(RigidTransformTest, Yaxis) {

	RigidTransform2D robotPos = RigidTransform2D::fromTranslation(Translation2D(5,5));
	RigidTransform2D fieldPos = RigidTransform2D::fromTranslation(Translation2D(0,5));
	RigidTransform2D actual = fieldPos.transformBy(robotPos.inverse());
	EXPECT_NEAR(-5.0, actual.getTranslation().getX(), 1E-3);
	EXPECT_NEAR(0.0, actual.getTranslation().getY(), 1E-3);
}

TEST(RigidTransformTest, transformWithRotation) {

	RigidTransform2D robotPos = RigidTransform2D(Translation2D(5,5), Rotation2D::fromDegrees(90));
	RigidTransform2D fieldPos = RigidTransform2D(Translation2D(0,5), Rotation2D::fromDegrees(90));
	RigidTransform2D actual = fieldPos.transformBy(robotPos.inverse());
	EXPECT_NEAR(-5.0, actual.getTranslation().getX(), 1E-3);
	EXPECT_NEAR(0.0, actual.getTranslation().getY(), 1E-3);
	EXPECT_NEAR(0, actual.getRotation().getDegrees(), 1E-3);
}

TEST(RigidTransformTest, transformWithDifferentRotations) {

	RigidTransform2D robotPos = RigidTransform2D(Translation2D(5,5), Rotation2D::fromDegrees(90));
	RigidTransform2D fieldPos = RigidTransform2D(Translation2D(0,5), Rotation2D::fromDegrees(180));
	RigidTransform2D actual = fieldPos.transformBy(robotPos.inverse());
	EXPECT_NEAR(5.0, actual.getTranslation().getX(), 1E-3);
	EXPECT_NEAR(0.0, actual.getTranslation().getY(), 1E-3);
	EXPECT_NEAR(90, actual.getRotation().getDegrees(), 1E-3);
}
