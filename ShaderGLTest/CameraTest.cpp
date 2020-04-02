#include "CameraTest.h"

namespace test {

	TEST_F(CameraTest, CreationCameraTest)
	{
		EXPECT_FALSE(camera_);
		camera_ = std::make_shared<sgl::Camera>(glm::vec3(0.f, 0.f, -4.f));
		EXPECT_TRUE(camera_);
	}

	TEST_F(CameraTest, LookAtCameraTest)
	{
		EXPECT_FALSE(camera_);
		camera_ = std::make_shared<sgl::Camera>(
			glm::vec3(12.f, 12.f, 12.f),
			glm::vec3(-1.f, -1.f, -1.f),
			glm::vec3(0.f, -1.f, 0.f));
		EXPECT_TRUE(camera_);
		glm::mat4 look_at = camera_->LookAt();
		EXPECT_FLOAT_EQ(12.f, look_at[3][0]);
		EXPECT_FLOAT_EQ(12.f, look_at[3][1]);
		EXPECT_FLOAT_EQ(12.f, look_at[3][2]);
		EXPECT_FLOAT_EQ(1.f,  look_at[3][3]);
	}

} // End namespace test.
