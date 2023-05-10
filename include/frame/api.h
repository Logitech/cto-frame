#pragma once

namespace frame {

/**
 * @class RenderingAPIEnum
 * @brief List of Device API.
 */
enum class RenderingAPIEnum {
    OPENGL,
    VULKAN,
// From: https://sourceforge.net/p/predef/wiki/OperatingSystems/
#if defined(_WIN32) || defined(_WIN64)
    DIRECTX11,
    DIRECTX12,
#endif
};

/**
 * @class DrawingTargetEnum
 * @brief Where do you want to draw?
 */
enum class DrawingTargetEnum { NONE, WINDOW };

/**
 * @class FullScreenEnum
 * @brief List of full screen mode.
 */
enum class FullScreenEnum {
    WINDOW,
    FULLSCREEN,
    FULLSCREEN_DESKTOP,
};

/**
 * @class WindowFlagEnum
 * @brief List of window flags.
 */
enum class WindowFlagEnum {
    MAXIMIZE,
    MINIMIZE,
    RESTORE,
    CENTER,
    ENABLE_BORDER,
    DISABLE_BORDER,
};

/**
 * @class ResizePolicyEnum
 * @brief List of resize policy / behaviour.
 */
enum class ResizePolicyEnum {
    //! The top left corner will not move (default in SDL).
    FROM_TOP_LEFT,
    //! The window will be expanded or shrunk in all directions (the center won't move).
    FROM_CENTER
};

/**
 * @class StereoEnum
 * @brief List of stereo implementation API.
 */
enum class StereoEnum {
    //! No stereo.
    NONE,
    //! Anaglyph used by colored glasses.
    ANAGLYPH,
    //! Split, single image wrapped to fit in the image size.
    HORIZONTAL_SPLIT,
    //! Side by side keep the image aspect ratio and put one image side-by-side.
    HORIZONTAL_SIDE_BY_SIDE,
};

/**
 * @brief Key definition for use in the input interface.
 * For now there is only the 2 shift key that are defined here, but this could increase.
 */
constexpr char KEY_LSHIFT = static_cast<char>(0xe1);
constexpr char KEY_RSHIFT = static_cast<char>(0xe5);

}  // End namespace frame.
