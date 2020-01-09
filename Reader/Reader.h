#ifndef __READER_H__
#define __READER_H__


#include "resource.h"
#include "Cache.h"
#include "Utils.h"
#include "Upgrade.h"
#include "Book.h"
#include <map>

#define ID_HOTKEY_SHOW_HIDE_WINDOW  100
#define ID_HOTKEY_TOP_WINDOW        101
#define IDT_TIMER_PAGE              102
#define IDT_TIMER_UPGRADE           103
#define WM_NEW_VERSION              (WM_USER + 100)
#define WM_UPDATE_CHAPTERS          (WM_USER + 101)


Cache               _Cache(CACHE_FILE_NAME);
header_t*           _header                 = NULL;
item_t*             _item                   = NULL;
HWND                _hWndStatus             = NULL;
HWND                _hFindDlg               = NULL;
UINT                _uFindReplaceMsg        = 0;
TCHAR               _szSrcTitle[MAX_PATH]   = {0};
window_info_t       _WndInfo                = {0};
BOOL                _IsAutoPage             = FALSE;
Upgrade             _Upgrade;
Book *              _Book                   = NULL;


LRESULT             OnCreate(HWND);
LRESULT             OnUpdateMenu(HWND);
LRESULT             OnOpenItem(HWND, int);
LRESULT             OnOpenFile(HWND, TCHAR*);
LRESULT             OnOpenFile(HWND, UINT, WPARAM, LPARAM);
LRESULT             OnSetFont(HWND, UINT, WPARAM, LPARAM);
LRESULT             OnSetBkColor(HWND, UINT, WPARAM, LPARAM);
LRESULT             OnRestoreDefault(HWND, UINT, WPARAM, LPARAM);
LRESULT             OnPaint(HWND, HDC);
LRESULT             OnSize(HWND, UINT, WPARAM, LPARAM);
LRESULT             OnMove(HWND);
LRESULT             OnPageUp(HWND);
LRESULT             OnPageDown(HWND);
LRESULT             OnLineUp(HWND);
LRESULT             OnLineDown(HWND);
LRESULT             OnFindText(HWND, UINT, WPARAM, LPARAM);
LRESULT             OnGotoPrevChapter(HWND, UINT, WPARAM, LPARAM);
LRESULT             OnGotoNextChapter(HWND, UINT, WPARAM, LPARAM);
LRESULT             OnDropFiles(HWND, UINT, WPARAM, LPARAM);
LRESULT             OnHideBorder(HWND);
LRESULT             OnFullScreen(HWND);
LRESULT             OnUpdateChapters(HWND);
BOOL                OnOpenBook(HWND, TCHAR *, item_t**);
UINT                GetCacheVersion(void);
BOOL                Init(void);
void                Exit(void);
void                UpdateProgess(void);
BOOL                GetClientRectExceptStatusBar(HWND, RECT*);
void                WheelSpeedInit(HWND);
void                HotkeyInit(HWND);
BOOL                HotkeySave(HWND);
int                 HotKeyMap_IndexToKey(int, int);
int                 HotKeyMap_KeyToIndex(int, int);
TCHAR*              HotKeyMap_KeyToString(int, int);
Bitmap*             LoadBGImage(int, int);
BOOL                FileExists(TCHAR *);
void                StartAutoPage(HWND);
void                StopAutoPage(HWND);
void                PauseAutoPage(HWND);
void                ResumeAutoPage(HWND);
void                CheckUpgrade(HWND);
bool                UpgradeCallback(void *, json_item_data_t *);


#endif
