#include "pch.h"
#include "ButtonManager.h"
#include "Utility.h"
#define WM_TRAYNOTIFY (WM_USER + 100)
namespace Mp
{

    int idList[8]{
    0x2001, 0x2002,
    0x2003, 0x2004,
    0x2005, 0x2006,
    0x2007, 0x2008
    };
    enum
    {
        IDC_BUTTON_1 = 0x2001,
        IDC_BUTTON_2 = 0x2002,
        IDC_BUTTON_3 = 0x2003,
        IDC_BUTTON_4 = 0x2004,
        IDC_BUTTON_5 = 0x2005,
        IDC_BUTTON_6 = 0x2006,
        IDC_BUTTON_7 = 0x2007,
        IDC_BUTTON_8 = 0x2008,
    };

};

HINSTANCE g_hInst;
HWND g_Hwnd, g_hDlg;
static ButtonManager bm;

const int FILENAME_MAX_SIZE = 1024;
const std::wstring clsName = L"MakeProject";

void StartUpRoutine();
BOOL fnBrowseFolder(HWND hWnd, const TCHAR* pTitle, TCHAR* pFolder, UINT nFlags);
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void OnCreate(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void OnCommand(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void OnTrayNotify(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

char* p = getenv("UserProfile");
fs::path result = p;

fs::path userProfile = result;
fs::path configParentPath = userProfile / L"AppData\\Local\\MakeProject";
fs::path configFileName = L"config.txt";

const TCHAR RegisterPath[] = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");


enum
{
    IDC_CONFIG_BUTTON = 0x9001
};



int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
    g_hInst = hInstance;
    std::locale::global(std::locale("korean"));
    WNDCLASSEX wcex{ 0 };
    wcex.cbSize = sizeof(wcex);
    wcex.lpszClassName = clsName.c_str();
    wcex.lpfnWndProc = WndProc;
    wcex.hbrBackground = CreateSolidBrush(RGB(255, 1, 7));
    wcex.hCursor = LoadCursor(hInstance, IDC_ARROW);
    
    ATOM atom = RegisterClassEx(&wcex);

    SetProcessDPIAware();
    int iScreenCx = GetSystemMetrics(SM_CXSCREEN);
    int iScreenCy = GetSystemMetrics(SM_CYSCREEN);

    HWND hwnd = CreateWindowEx(
        WS_EX_LAYERED, clsName.c_str(), clsName.c_str(), WS_POPUP | WS_SYSMENU, iScreenCx - 250, iScreenCy - 350, 240, 300, 0, 0, 0, 0
    );
    SetLayeredWindowAttributes(hwnd, RGB(255, 1, 7), 0, LWA_COLORKEY);

    ShowWindow(hwnd, SW_SHOW);

    MSG msg;

    while (GetMessage(&msg, 0, 0, 0))
    {
        DispatchMessage(&msg);
        TranslateMessage(&msg);
    }


    return (int)msg.wParam;
}

BOOL CALLBACK ConfigDialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static std::vector<std::pair<std::wstring, std::wstring>> buttonStatus;
    static wofstream wofs;

    static TCHAR lpstrFile[FILENAME_MAX_SIZE]{ 0 };
    static TCHAR lpstrFileTitle[FILENAME_MAX_SIZE]{ 0 };
    static TCHAR lpstrButtonName[FILENAME_MAX_SIZE]{ 0 };


    switch (uMsg)
    {
    case WM_INITDIALOG:
    {
        g_hDlg = hDlg;
        Utility::getInstance().Load(bm);
        Utility::getInstance().ConfigInit(hDlg, bm);
        
        
    }
    break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
            case IDOK:
            {
                if (!fs::exists(configParentPath))
                    fs::create_directories(configParentPath);

                wofs.open(configParentPath / configFileName, std::ios::out);

                GetDlgItemText(hDlg, IDC_EDIT_NAME1, lpstrButtonName, FILENAME_MAX_SIZE);
                GetDlgItemText(hDlg, IDC_EDIT1, lpstrFile, FILENAME_MAX_SIZE);

                if ((_tcslen(lpstrButtonName)) && (_tcslen(lpstrFile)))
                    wofs << lpstrButtonName << '|' << lpstrFile << endl;

                GetDlgItemText(hDlg, IDC_EDIT_NAME2, lpstrButtonName, FILENAME_MAX_SIZE);
                GetDlgItemText(hDlg, IDC_EDIT2, lpstrFile, FILENAME_MAX_SIZE);

                if ((_tcslen(lpstrButtonName)) && (_tcslen(lpstrFile)))
                    wofs << lpstrButtonName << '|' << lpstrFile << endl;

                GetDlgItemText(hDlg, IDC_EDIT_NAME3, lpstrButtonName, FILENAME_MAX_SIZE);
                GetDlgItemText(hDlg, IDC_EDIT3, lpstrFile, FILENAME_MAX_SIZE);

                if ((_tcslen(lpstrButtonName)) && (_tcslen(lpstrFile)))
                    wofs << lpstrButtonName << '|' << lpstrFile << endl;

                GetDlgItemText(hDlg, IDC_EDIT_NAME4, lpstrButtonName, FILENAME_MAX_SIZE);
                GetDlgItemText(hDlg, IDC_EDIT4, lpstrFile, FILENAME_MAX_SIZE);

                if ((_tcslen(lpstrButtonName)) && (_tcslen(lpstrFile)))
                    wofs << lpstrButtonName << '|' << lpstrFile << endl;

                GetDlgItemText(hDlg, IDC_EDIT_NAME5, lpstrButtonName, FILENAME_MAX_SIZE);
                GetDlgItemText(hDlg, IDC_EDIT5, lpstrFile, FILENAME_MAX_SIZE);

                if ((_tcslen(lpstrButtonName)) && (_tcslen(lpstrFile)))
                    wofs << lpstrButtonName << '|' << lpstrFile << endl;

                GetDlgItemText(hDlg, IDC_EDIT_NAME6, lpstrButtonName, FILENAME_MAX_SIZE);
                GetDlgItemText(hDlg, IDC_EDIT6, lpstrFile, FILENAME_MAX_SIZE);

                if ((_tcslen(lpstrButtonName)) && (_tcslen(lpstrFile)))
                    wofs << lpstrButtonName << '|' << lpstrFile << endl;

                GetDlgItemText(hDlg, IDC_EDIT_NAME7, lpstrButtonName, FILENAME_MAX_SIZE);
                GetDlgItemText(hDlg, IDC_EDIT7, lpstrFile, FILENAME_MAX_SIZE);

                if ((_tcslen(lpstrButtonName)) && (_tcslen(lpstrFile)))
                    wofs << lpstrButtonName << '|' << lpstrFile << endl;

                GetDlgItemText(hDlg, IDC_EDIT_NAME8, lpstrButtonName, FILENAME_MAX_SIZE);
                GetDlgItemText(hDlg, IDC_EDIT8, lpstrFile, FILENAME_MAX_SIZE);

                if ((_tcslen(lpstrButtonName)) && (_tcslen(lpstrFile)))
                    wofs << lpstrButtonName << '|' << lpstrFile << endl;

                wofs.close();
                Utility::getInstance().Load(bm);
                Utility::getInstance().Init(g_hInst, g_Hwnd, bm);

                EndDialog(hDlg, wParam);
                return TRUE;
            }

                break;

            case IDC_BUTTON1:
                if (fnBrowseFolder(hDlg, lpstrFileTitle, lpstrFile, BIF_RETURNONLYFSDIRS))
                {
                    SetDlgItemText(hDlg, IDC_EDIT1, lpstrFile);
                    
               
                }
                break;

            case IDC_BUTTON2:
                if (fnBrowseFolder(hDlg, lpstrFileTitle, lpstrFile, BIF_RETURNONLYFSDIRS))
                {
                    SetDlgItemText(hDlg, IDC_EDIT2, lpstrFile);
                }
                break;

            case IDC_BUTTON3:
                if (fnBrowseFolder(hDlg, lpstrFileTitle, lpstrFile, BIF_RETURNONLYFSDIRS))
                {
                    SetDlgItemText(hDlg, IDC_EDIT3, lpstrFile);
                }
                break;

            case IDC_BUTTON4:
                if (fnBrowseFolder(hDlg, lpstrFileTitle, lpstrFile, BIF_RETURNONLYFSDIRS))
                {
                    SetDlgItemText(hDlg, IDC_EDIT4, lpstrFile);
                }
                break;

            case IDC_BUTTON5:
                if (fnBrowseFolder(hDlg, lpstrFileTitle, lpstrFile, BIF_RETURNONLYFSDIRS))
                {
                    SetDlgItemText(hDlg, IDC_EDIT5, lpstrFile);
                }
                break;

            case IDC_BUTTON6:
                if (fnBrowseFolder(hDlg, lpstrFileTitle, lpstrFile, BIF_RETURNONLYFSDIRS))
                {
                    SetDlgItemText(hDlg, IDC_EDIT6, lpstrFile);
                }
                break;

            case IDC_BUTTON7:
                if (fnBrowseFolder(hDlg, lpstrFileTitle, lpstrFile, BIF_RETURNONLYFSDIRS))
                {
                    SetDlgItemText(hDlg, IDC_EDIT7, lpstrFile);
                }
                break;

            case IDC_BUTTON8:
                if (fnBrowseFolder(hDlg, lpstrFileTitle, lpstrFile, BIF_RETURNONLYFSDIRS))
                {
                    SetDlgItemText(hDlg, IDC_EDIT8, lpstrFile);
                }
                break;

            case IDCANCEL:

                Utility::getInstance().Init(g_hInst, g_Hwnd, bm);
                EndDialog(hDlg, wParam);
                return TRUE;
        }
    }



    return FALSE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HDC hdc;
    static PAINTSTRUCT ps;
    static RECT rect;

    static HBRUSH hRectBrush, oldRectBrush;
    static HWND hConfigButton;

    static HFONT hFont;
    static long style;
    switch (uMsg)
    {

    case WM_CREATE:
        StartUpRoutine();
        style = GetWindowLong(hwnd, GWL_EXSTYLE);
        style &= ~(WS_VISIBLE);
        style |= WS_EX_TOOLWINDOW;
        style &= ~(WS_EX_APPWINDOW);

        ShowWindow(hwnd, SW_HIDE);
        SetWindowLong(hwnd, GWL_EXSTYLE, style);
        ShowWindow(hwnd, SW_SHOW);

        OnCreate(hwnd, uMsg, wParam, lParam);
        GetClientRect(hwnd, &rect);
        g_Hwnd = hwnd;
        //hConfigButton = CreateWindowEx(
        //    0, L"button", L"◎", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, rect.right - 30, rect.bottom - 30, 30, 30, hwnd, (HMENU)IDC_CONFIG_BUTTON, g_hInst, 0
        //);

        hFont = CreateFont(30, 0, 0, 0, FW_SEMIBOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Consolas"));
        SendMessage(hConfigButton, WM_SETFONT, (WPARAM)hFont, 0);

        Utility::getInstance().Load(bm);
        Utility::getInstance().Init(g_hInst, hwnd, bm);

        break;

    case WM_COMMAND:
    {

        OnCommand(hwnd, uMsg, wParam, lParam);
        switch (LOWORD(wParam))
        {
        case IDC_CONFIG_BUTTON:
            DialogBox(g_hInst, MAKEINTRESOURCE(IDD_CONFIG_DIALOG), hwnd, (DLGPROC)ConfigDialogProc);
            break;

        case Mp::IDC_BUTTON_1:
            if (bm.GetButtonList().size() > 0 && fs::exists(bm.GetButtonList()[0].get()->GetAddr()))
                ShellExecute(NULL, _T("open"), bm.GetButtonList()[0].get()->GetAddr().c_str(), NULL, NULL, SW_SHOW);
            break;

        case Mp::IDC_BUTTON_2:
            if (bm.GetButtonList().size() > 1 && fs::exists(bm.GetButtonList()[1].get()->GetAddr()))
                ShellExecute(NULL, _T("open"), bm.GetButtonList()[1].get()->GetAddr().c_str(), NULL, NULL, SW_SHOW);
            break;

        case Mp::IDC_BUTTON_3:
            if (bm.GetButtonList().size() > 2 && fs::exists(bm.GetButtonList()[2].get()->GetAddr()))
                ShellExecute(NULL, _T("open"), bm.GetButtonList()[2].get()->GetAddr().c_str(), NULL, NULL, SW_SHOW);
            break;

        case Mp::IDC_BUTTON_4:
            if (bm.GetButtonList().size() > 3 && fs::exists(bm.GetButtonList()[3].get()->GetAddr()))
                ShellExecute(NULL, _T("open"), bm.GetButtonList()[3].get()->GetAddr().c_str(), NULL, NULL, SW_SHOW);
            break;

        case Mp::IDC_BUTTON_5:
            if (bm.GetButtonList().size() > 4 && fs::exists(bm.GetButtonList()[4].get()->GetAddr()))
                ShellExecute(NULL, _T("open"), bm.GetButtonList()[4].get()->GetAddr().c_str(), NULL, NULL, SW_SHOW);
            break;

        case Mp::IDC_BUTTON_6:
            if (bm.GetButtonList().size() > 5 && fs::exists(bm.GetButtonList()[5].get()->GetAddr()))
                ShellExecute(NULL, _T("open"), bm.GetButtonList()[5].get()->GetAddr().c_str(), NULL, NULL, SW_SHOW);
            break;

        case Mp::IDC_BUTTON_7:
            if (bm.GetButtonList().size() > 6 && fs::exists(bm.GetButtonList()[6].get()->GetAddr()))
                ShellExecute(NULL, _T("open"), bm.GetButtonList()[6].get()->GetAddr().c_str(), NULL, NULL, SW_SHOW);
            break;

        case Mp::IDC_BUTTON_8:
            if (bm.GetButtonList().size() > 7 && fs::exists(bm.GetButtonList()[7].get()->GetAddr()))
                ShellExecute(NULL, _T("open"), bm.GetButtonList()[7].get()->GetAddr().c_str(), NULL, NULL, SW_SHOW);
            break;

        }

    }
    break;

    case WM_TRAYNOTIFY:
        OnTrayNotify(hwnd, uMsg, wParam, lParam);
        break;

    case WM_PAINT: 
    {
        hdc = BeginPaint(hwnd, &ps);

        EndPaint(hwnd, &ps);
    }
        break;


    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


BOOL fnBrowseFolder(HWND hWnd, const TCHAR* pTitle, TCHAR* pFolder, UINT nFlags)
{
    LPMALLOC pMalloc;
    LPITEMIDLIST pidl;
    BROWSEINFO bi;
    memset(&bi, 0, sizeof(BROWSEINFO));

    bi.hwndOwner = hWnd;
    bi.pidlRoot = NULL;
    bi.pszDisplayName = NULL;
    bi.lpszTitle = (TCHAR*)pTitle;
    bi.ulFlags = nFlags;
    bi.lpfn = NULL;
    bi.lParam = 0;
    pidl = SHBrowseForFolder(&bi);

    if (pidl == NULL)
        return FALSE;

    SHGetPathFromIDList(pidl, pFolder);

    if (SHGetMalloc(&pMalloc) != NOERROR)
        return FALSE;


    pMalloc->Free(pidl);
    pMalloc->Release();

    return TRUE;
}


void OnCreate(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    NOTIFYICONDATA nid{ 0 };
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
    nid.uCallbackMessage = WM_TRAYNOTIFY;
    nid.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_TRAYICON));
    lstrcpy(nid.szTip, _T("MakeProject"));
    Shell_NotifyIcon(NIM_ADD, &nid);
}

void OnCommand(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (LOWORD(wParam))
    {
    case ID_TRAYMENU_CONFIG:
        DialogBox(g_hInst, MAKEINTRESOURCE(IDD_CONFIG_DIALOG), hwnd, (DLGPROC)ConfigDialogProc);
        break;
    case ID_TRAYMENU_EXIT:
        DestroyWindow(hwnd);
        break;
    }
}

void OnTrayNotify(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HMENU hMenu, hPopupMenu;
    POINT pt;

    switch (lParam)
    {
    case WM_LBUTTONDOWN:
        hMenu = LoadMenu(g_hInst, MAKEINTRESOURCE(IDR_TRAYMENU));
        hPopupMenu = GetSubMenu(hMenu, 0);
        GetCursorPos(&pt);
        SetForegroundWindow(hwnd);
        TrackPopupMenu(hPopupMenu, TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, pt.x, pt.y, 0, hwnd, NULL);
        SetForegroundWindow(hwnd);
        DestroyMenu(hPopupMenu);
        DestroyMenu(hMenu);
        break;

    case WM_RBUTTONDOWN:
        hMenu = LoadMenu(g_hInst, MAKEINTRESOURCE(IDR_TRAYMENU));
        hPopupMenu = GetSubMenu(hMenu, 0);
        GetCursorPos(&pt);
        SetForegroundWindow(hwnd);
        TrackPopupMenu(hPopupMenu, TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, pt.x, pt.y, 0, hwnd, NULL);
        SetForegroundWindow(hwnd);
        DestroyMenu(hPopupMenu);
        DestroyMenu(hMenu);
        break;
    }
}

void StartUpRoutine()
{
    LONG lResult;
    HKEY hKey;
    DWORD dwDesc;
    TCHAR buff[256];
    TCHAR current[256];

    GetModuleFileName(NULL, current, 256);

    RegOpenKeyEx(
        HKEY_CURRENT_USER,
        RegisterPath,
        0,
        KEY_ALL_ACCESS,
        &hKey);

    lResult = RegCreateKeyEx(
        HKEY_CURRENT_USER,
        RegisterPath,
        0,
        buff,
        REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS,
        NULL,
        &hKey,
        &dwDesc);

    if (lResult == ERROR_SUCCESS)
        RegSetValueEx(
            hKey,
            _T("MakeProject"),
            0,
            REG_SZ,
            (BYTE*)current,
            _tcslen(current) * sizeof(TCHAR)
        );

    RegCloseKey(hKey);
}