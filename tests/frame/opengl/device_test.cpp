#include "frame/opengl/device_test.h"

#include "frame/file/file_system.h"
#include "frame/json/parse_level.h"
#include "frame/plugin_mock.h"

namespace test {

using testing::Return;

TEST_F(DeviceTest, CreateDeviceTest) {
    EXPECT_TRUE(window_);
    EXPECT_TRUE(window_->GetUniqueDevice());
}

TEST_F(DeviceTest, StartupDeviceWithCameraTest) {
    EXPECT_TRUE(window_);
    window_->GetUniqueDevice()->Startup(std::move(level_));
    EXPECT_TRUE(window_->GetUniqueDevice());
}

TEST_F(DeviceTest, AddOnePluginTest) {
    EXPECT_TRUE(window_);
    window_->GetUniqueDevice()->Startup(std::move(level_));
    EXPECT_TRUE(window_->GetUniqueDevice());
    auto plugin = std::make_unique<test::PluginMock>();
    EXPECT_CALL(*plugin, GetName).WillRepeatedly(Return("test"));
    auto* device = window_->GetUniqueDevice();
    EXPECT_TRUE(device);
    device->AddPlugin(std::move(plugin));
    EXPECT_EQ(1, device->GetPluginPtrs().size());
    EXPECT_EQ(std::vector<std::string>{ "test" }, device->GetPluginNames());
    device->RemovePluginByName("test");
    EXPECT_EQ(0, device->GetPluginPtrs().size());
}

TEST_F(DeviceTest, AddManySamePluginTest) {
    EXPECT_TRUE(window_);
    window_->GetUniqueDevice()->Startup(std::move(level_));
    auto* device = window_->GetUniqueDevice();
    EXPECT_TRUE(device);
    for (int i = 0; i < 8; ++i) {
        auto plugin = std::make_unique<test::PluginMock>();
        EXPECT_CALL(*plugin, GetName).WillRepeatedly(Return("test"));
        device->AddPlugin(std::move(plugin));
    }
    EXPECT_EQ(1, device->GetPluginPtrs().size());
    EXPECT_EQ(std::vector<std::string>{ "test" }, device->GetPluginNames());
    device->RemovePluginByName("test");
    EXPECT_EQ(0, device->GetPluginPtrs().size());
}

TEST_F(DeviceTest, AddManyDifferentPluginTest) {
    EXPECT_TRUE(window_);
    window_->GetUniqueDevice()->Startup(std::move(level_));
    auto* device = window_->GetUniqueDevice();
    EXPECT_TRUE(device);
    for (int i = 0; i < 8; ++i) {
        auto plugin = std::make_unique<test::PluginMock>();
        EXPECT_CALL(*plugin, GetName).WillRepeatedly(Return(fmt::format("test{}", i)));
        device->AddPlugin(std::move(plugin));
    }
    EXPECT_EQ(8, device->GetPluginPtrs().size());
    std::vector<std::string> vec;
    for (int i = 0; i < 8; ++i) {
        vec.push_back(fmt::format("test{}", i));
    }
    EXPECT_EQ(vec, device->GetPluginNames());
    for (int i = 0; i < 8; ++i) {
        device->RemovePluginByName(vec[i]);
    }
    EXPECT_EQ(0, device->GetPluginPtrs().size());
}

}  // End namespace test.