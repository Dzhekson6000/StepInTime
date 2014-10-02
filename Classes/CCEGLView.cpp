#include "CCEGLView.h"

int CCEGLView::getFullscreenWidth()
{
    return GetDeviceCaps(m_hDC, HORZRES);
}

int CCEGLView::getFullscreenHeight()
{
    return GetDeviceCaps(m_hDC, VERTRES);
}

bool CCEGLView::enterFullscreen(int fullscreenWidth, int fullscreenHeight)
{
    DEVMODE fullscreenSettings;
    bool isChangeSuccessful;

    if(fullscreenWidth == 0 || fullscreenHeight == 0)
    {
        fullscreenWidth  = GetDeviceCaps(m_hDC, HORZRES);
        fullscreenHeight = GetDeviceCaps(m_hDC, VERTRES);
    }

    int colourBits       = GetDeviceCaps(m_hDC, BITSPIXEL);
    int refreshRate      = GetDeviceCaps(m_hDC, VREFRESH);

    EnumDisplaySettings(NULL, 0, &fullscreenSettings);
    fullscreenSettings.dmPelsWidth        = fullscreenWidth;
    fullscreenSettings.dmPelsHeight       = fullscreenHeight;
    fullscreenSettings.dmBitsPerPel       = colourBits;
    fullscreenSettings.dmDisplayFrequency = refreshRate;
    fullscreenSettings.dmFields           = DM_PELSWIDTH |
                                            DM_PELSHEIGHT |
                                            DM_BITSPERPEL |
                                            DM_DISPLAYFREQUENCY;

    SetWindowLongPtr(m_hWnd, GWL_EXSTYLE, WS_EX_APPWINDOW | WS_EX_TOPMOST);
    SetWindowLongPtr(m_hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
    SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, fullscreenWidth, fullscreenHeight, SWP_SHOWWINDOW);
    isChangeSuccessful = ChangeDisplaySettings(&fullscreenSettings, CDS_FULLSCREEN) == DISP_CHANGE_SUCCESSFUL;
    ShowWindow(m_hWnd, SW_MAXIMIZE);

    resize(fullscreenWidth, fullscreenHeight);

    return isChangeSuccessful;
}

bool CCEGLView::exitFullscreen(int windowX, int windowY, int windowedWidth, int windowedHeight, int windowedPaddingX, int windowedPaddingY)
{
    bool isChangeSuccessful;

    SetWindowLongPtr(m_hWnd, GWL_EXSTYLE, WS_EX_LEFT);
    SetWindowLongPtr(m_hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
    isChangeSuccessful = ChangeDisplaySettings(NULL, CDS_RESET) == DISP_CHANGE_SUCCESSFUL;
    SetWindowPos(m_hWnd, HWND_NOTOPMOST, windowX, windowY, windowedWidth + windowedPaddingX, windowedHeight + windowedPaddingY, SWP_SHOWWINDOW);
    ShowWindow(m_hWnd, SW_RESTORE);

    return isChangeSuccessful;
}