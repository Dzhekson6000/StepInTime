#include "cocos2d.h"
class CCEGLView
{
	bool enterFullscreen(int fullscreenWidth=0, int fullscreenHeight=0);
    bool exitFullscreen(int windowX, int windowY, int windowedWidth, int windowedHeight, int windowedPaddingX, int windowedPaddingY);
    int getFullscreenWidth();
    int getFullscreenHeight();
};