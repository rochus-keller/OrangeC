#ifdef __cplusplus
extern "C"
{
#endif

#define Button_Enable(hwndCtl, fEnable) EnableWindow((hwndCtl), (fEnable))
#define Button_GetCheck(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), BM_GETCHECK, 0L, 0L))
#define Button_GetState(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), BM_GETSTATE, 0L, 0L))
#define Button_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))
#define Button_GetTextLength(hwndCtl) GetWindowTextLength(hwndCtl)
#define Button_SetCheck(hwndCtl, check) ((void)SendMessage((hwndCtl), BM_SETCHECK, (WPARAM)(int)(check), 0L))
#define Button_SetState(hwndCtl, state) ((UINT)(DWORD)SendMessage((hwndCtl), BM_SETSTATE, (WPARAM)(int)(state), 0L))
#define Button_SetStyle(hwndCtl, style, fRedraw) \
    ((void)SendMessage((hwndCtl), BM_SETSTYLE, (WPARAM)LOWORD(style), MAKELPARAM(((fRedraw) ? TRUE : FALSE), 0)))
#define Button_SetText(hwndCtl, lpsz) SetWindowText((hwndCtl), (lpsz))

#define CheckDefDlgRecursion(pfRecursion) \
    if (*(pfRecursion))                   \
    {                                     \
        *(pfRecursion) = FALSE;           \
        return FALSE;                     \
    }

#define ComboBox_AddItemData(hwndCtl, data) ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0L, (LPARAM)(data)))
#define ComboBox_AddString(hwndCtl, lpsz) ((int)(DWORD)SendMessage((hwndCtl), CB_ADDSTRING, 0L, (LPARAM)(LPCTSTR)(lpsz)))
#define ComboBox_DeleteString(hwndCtl, index) ((int)(DWORD)SendMessage((hwndCtl), CB_DELETESTRING, (WPARAM)(int)(index), 0L))
#define ComboBox_Dir(hwndCtl, attrs, lpszFileSpec) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCTSTR)(lpszFileSpec)))
#define ComboBox_Enable(hwndCtl, fEnable) EnableWindow((hwndCtl), (fEnable))
#define ComboBox_FindItemData(hwndCtl, indexStart, data) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_FindString(hwndCtl, indexStart, lpszFind) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ComboBox_FindStringExact(hwndCtl, indexStart, lpszFind) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ComboBox_GetCount(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), CB_GETCOUNT, 0L, 0L))
#define ComboBox_GetCurSel(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), CB_GETCURSEL, 0L, 0L))
#define ComboBox_GetDroppedControlRect(hwndCtl, lprc) \
    ((void)SendMessage((hwndCtl), CB_GETDROPPEDCONTROLRECT, 0L, (LPARAM)(RECT*)(lprc)))
#define ComboBox_GetDroppedState(hwndCtl) ((BOOL)(DWORD)SendMessage((hwndCtl), CB_GETDROPPEDSTATE, 0L, 0L))
#define ComboBox_GetEditSel(hwndCtl) ((DWORD)SendMessage((hwndCtl), CB_GETEDITSEL, 0L, 0L))
#define ComboBox_GetExtendedUI(hwndCtl) ((UINT)(DWORD)SendMessage((hwndCtl), CB_GETEXTENDEDUI, 0L, 0L))
#define ComboBox_GetItemData(hwndCtl, index) ((LRESULT)(DWORD)SendMessage((hwndCtl), CB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ComboBox_GetItemHeight(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), CB_GETITEMHEIGHT, 0L, 0L))
#define ComboBox_GetLBText(hwndCtl, index, lpszBuffer) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXT, (WPARAM)(int)(index), (LPARAM)(LPCTSTR)(lpszBuffer)))
#define ComboBox_GetLBTextLen(hwndCtl, index) ((int)(DWORD)SendMessage((hwndCtl), CB_GETLBTEXTLEN, (WPARAM)(int)(index), 0L))
#define ComboBox_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))
#define ComboBox_GetTextLength(hwndCtl) GetWindowTextLength(hwndCtl)
#define ComboBox_InsertItemData(hwndCtl, index, data) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_InsertString(hwndCtl, index, lpsz) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCTSTR)(lpsz)))
#define ComboBox_LimitText(hwndCtl, cchLimit) ((int)(DWORD)SendMessage((hwndCtl), CB_LIMITTEXT, (WPARAM)(int)(cchLimit), 0L))
#define ComboBox_ResetContent(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), CB_RESETCONTENT, 0L, 0L))
#define ComboBox_SelectItemData(hwndCtl, indexStart, data) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ComboBox_SelectString(hwndCtl, indexStart, lpszSelect) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszSelect)))
#define ComboBox_SetCurSel(hwndCtl, index) ((int)(DWORD)SendMessage((hwndCtl), CB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ComboBox_SetEditSel(hwndCtl, ichStart, ichEnd) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_SETEDITSEL, 0L, MAKELPARAM((ichStart), (ichEnd))))
#define ComboBox_SetExtendedUI(hwndCtl, flags) ((int)(DWORD)SendMessage((hwndCtl), CB_SETEXTENDEDUI, (WPARAM)(UINT)(flags), 0L))
#define ComboBox_SetItemData(hwndCtl, index, data) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ComboBox_SetItemHeight(hwndCtl, index, cyItem) \
    ((int)(DWORD)SendMessage((hwndCtl), CB_SETITEMHEIGHT, (WPARAM)(int)(index), (LPARAM)(int)cyItem))
#define ComboBox_SetText(hwndCtl, lpsz) SetWindowText((hwndCtl), (lpsz))
#define ComboBox_ShowDropdown(hwndCtl, fShow) ((BOOL)(DWORD)SendMessage((hwndCtl), CB_SHOWDROPDOWN, (WPARAM)(BOOL)(fShow), 0L))

#define CopyRgn(hrgnDst, hrgnSrc) CombineRgn(hrgnDst, hrgnSrc, 0, RGN_COPY)

#define DefDlgProcEx(hwnd, msg, wParam, lParam, pfRecursion) (*(pfRecursion) = TRUE, DefDlgProc(hwnd, msg, wParam, lParam))

#define DeleteBitmap(hbm) DeleteObject((HGDIOBJ)(HBITMAP)(hbm))

#define DeleteBrush(hbr) DeleteObject((HGDIOBJ)(HBRUSH)(hbr))

#define DeleteFont(hfont) DeleteObject((HGDIOBJ)(HFONT)(hfont))

#define DeletePalette(hpal) DeleteObject((HGDIOBJ)(HPALETTE)(hpal))

#define DeletePen(hpen) DeleteObject((HGDIOBJ)(HPEN)(hpen))

#define DeleteRgn(hrgn) DeleteObject((HGDIOBJ)(HRGN)(hrgn))

#define Edit_CanUndo(hwndCtl) ((BOOL)(DWORD)SendMessage((hwndCtl), EM_CANUNDO, 0L, 0L))
#define Edit_EmptyUndoBuffer(hwndCtl) ((void)SendMessage((hwndCtl), EM_EMPTYUNDOBUFFER, 0L, 0L))
#define Edit_Enable(hwndCtl, fEnable) EnableWindow((hwndCtl), (fEnable))
#define Edit_FmtLines(hwndCtl, fAddEOL) ((BOOL)(DWORD)SendMessage((hwndCtl), EM_FMTLINES, (WPARAM)(BOOL)(fAddEOL), 0L))
#define Edit_GetFirstVisibleLine(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), EM_GETFIRSTVISIBLELINE, 0L, 0L))
#define Edit_GetHandle(hwndCtl) ((HLOCAL)(UINT)(DWORD)SendMessage((hwndCtl), EM_GETHANDLE, 0L, 0L))
#define Edit_GetLine(hwndCtl, line, lpch, cchMax) \
    ((*((int*)(lpch)) = (cchMax)), ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINE, (WPARAM)(int)(line), (LPARAM)(LPTSTR)(lpch))))
#define Edit_GetLineCount(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), EM_GETLINECOUNT, 0L, 0L))
#define Edit_GetModify(hwndCtl) ((BOOL)(DWORD)SendMessage((hwndCtl), EM_GETMODIFY, 0L, 0L))
#define Edit_GetPasswordChar(hwndCtl) ((TCHAR)(DWORD)SendMessage((hwndCtl), EM_GETPASSWORDCHAR, 0L, 0L))
#define Edit_GetRect(hwndCtl, lprc) ((void)SendMessage((hwndCtl), EM_GETRECT, 0L, (LPARAM)(RECT*)(lprc)))
#define Edit_GetSel(hwndCtl) ((DWORD)SendMessage((hwndCtl), EM_GETSEL, 0L, 0L))
#define Edit_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))
#define Edit_GetTextLength(hwndCtl) GetWindowTextLength(hwndCtl)
#define Edit_GetWordBreakProc(hwndCtl) ((EDITWORDBREAKPROC)SendMessage((hwndCtl), EM_GETWORDBREAKPROC, 0L, 0L))
#define Edit_LimitText(hwndCtl, cchMax) ((void)SendMessage((hwndCtl), EM_LIMITTEXT, (WPARAM)(cchMax), 0L))
#define Edit_LineFromChar(hwndCtl, ich) ((int)(DWORD)SendMessage((hwndCtl), EM_LINEFROMCHAR, (WPARAM)(int)(ich), 0L))
#define Edit_LineIndex(hwndCtl, line) ((int)(DWORD)SendMessage((hwndCtl), EM_LINEINDEX, (WPARAM)(int)(line), 0L))
#define Edit_LineLength(hwndCtl, line) ((int)(DWORD)SendMessage((hwndCtl), EM_LINELENGTH, (WPARAM)(int)(line), 0L))
#define Edit_ReplaceSel(hwndCtl, lpszReplace) ((void)SendMessage((hwndCtl), EM_REPLACESEL, 0L, (LPARAM)(LPCTSTR)(lpszReplace)))
#define Edit_Scroll(hwndCtl, dv, dh) ((void)SendMessage((hwndCtl), EM_LINESCROLL, (WPARAM)(dh), (LPARAM)(dv)))
#define Edit_ScrollCaret(hwndCtl) ((BOOL)(DWORD)SendMessage((hwndCtl), EM_SCROLLCARET, 0, 0L))
#define Edit_SetHandle(hwndCtl, h) ((void)SendMessage((hwndCtl), EM_SETHANDLE, (WPARAM)(UINT)(HLOCAL)(h), 0L))
#define Edit_SetModify(hwndCtl, fModified) ((void)SendMessage((hwndCtl), EM_SETMODIFY, (WPARAM)(UINT)(fModified), 0L))
#define Edit_SetPasswordChar(hwndCtl, ch) ((void)SendMessage((hwndCtl), EM_SETPASSWORDCHAR, (WPARAM)(UINT)(ch), 0L))
#define Edit_SetReadOnly(hwndCtl, fReadOnly) ((BOOL)(DWORD)SendMessage((hwndCtl), EM_SETREADONLY, (WPARAM)(BOOL)(fReadOnly), 0L))
#define Edit_SetRect(hwndCtl, lprc) ((void)SendMessage((hwndCtl), EM_SETRECT, 0L, (LPARAM)(const RECT*)(lprc)))
#define Edit_SetRectNoPaint(hwndCtl, lprc) ((void)SendMessage((hwndCtl), EM_SETRECTNP, 0L, (LPARAM)(const RECT*)(lprc)))
#define Edit_SetSel(hwndCtl, ichStart, ichEnd) ((void)SendMessage((hwndCtl), EM_SETSEL, (ichStart), (ichEnd)))
#define Edit_SetTabStops(hwndCtl, cTabs, lpTabs) \
    ((void)SendMessage((hwndCtl), EM_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(const int*)(lpTabs)))
#define Edit_SetText(hwndCtl, lpsz) SetWindowText((hwndCtl), (lpsz))
#define Edit_SetWordBreakProc(hwndCtl, lpfnWordBreak) \
    ((void)SendMessage((hwndCtl), EM_SETWORDBREAKPROC, 0L, (LPARAM)(EDITWORDBREAKPROC)(lpfnWordBreak)))
#define Edit_Undo(hwndCtl) ((BOOL)(DWORD)SendMessage((hwndCtl), EM_UNDO, 0L, 0L))

#define FORWARD_WM_ACTIVATE(hwnd, state, hwndActDeact, fMinimized, fn) \
    (void)(fn)((hwnd), WM_ACTIVATE, MAKEWPARAM((state), (fMinimized)), (LPARAM)(HWND)(hwndActDeact))
#define FORWARD_WM_ACTIVATEAPP(hwnd, fActivate, dwThreadId, fn) \
    (void)(fn)((hwnd), WM_ACTIVATEAPP, (WPARAM)(BOOL)(fActivate), (LPARAM)(dwThreadId))
#define FORWARD_WM_ASKCBFORMATNAME(hwnd, cchMax, rgchName, fn) \
    (void)(fn)((hwnd), WM_ASKCBFORMATNAME, (WPARAM)(int)(cchMax), (LPARAM)(rgchName))
#define FORWARD_WM_CANCELMODE(hwnd, fn) (void)(fn)((hwnd), WM_CANCELMODE, 0L, 0L)
#define FORWARD_WM_CHANGECBCHAIN(hwnd, hwndRemove, hwndNext, fn) \
    (void)(fn)((hwnd), WM_CHANGECBCHAIN, (WPARAM)(HWND)(hwndRemove), (LPARAM)(HWND)(hwndNext))
#define FORWARD_WM_CHAR(hwnd, ch, cRepeat, fn) (void)(fn)((hwnd), WM_CHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat), 0))
#define FORWARD_WM_CHARTOITEM(hwnd, ch, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_CHARTOITEM, MAKEWPARAM((UINT)(iCaret), (UINT)(ch)), (LPARAM)(hwndListBox))
#define FORWARD_WM_CHILDACTIVATE(hwnd, fn) (void)(fn)((hwnd), WM_CHILDACTIVATE, 0L, 0L)
#define FORWARD_WM_CLEAR(hwnd, fn) (void)(fn)((hwnd), WM_CLEAR, 0L, 0L)
#define FORWARD_WM_CLOSE(hwnd, fn) (void)(fn)((hwnd), WM_CLOSE, 0L, 0L)
#define FORWARD_WM_COMMAND(hwnd, id, hwndCtl, codeNotify, fn) \
    (void)(fn)((hwnd), WM_COMMAND, MAKEWPARAM((UINT)(id), (UINT)(codeNotify)), (LPARAM)(HWND)(hwndCtl))
#define FORWARD_WM_COMMNOTIFY(hwnd, cid, flags, fn) (void)(fn)((hwnd), WM_COMMNOTIFY, (WPARAM)(cid), MAKELPARAM((flags), 0))
#define FORWARD_WM_COMPACTING(hwnd, compactRatio, fn) (void)(fn)((hwnd), WM_COMPACTING, (WPARAM)(UINT)(compactRatio), 0L)
#define FORWARD_WM_COMPAREITEM(hwnd, lpCompareItem, fn)                                                    \
    (int)(DWORD)(fn)((hwnd), WM_COMPAREITEM, (WPARAM)(((const COMPAREITEMSTRUCT*)(lpCompareItem))->CtlID), \
                     (LPARAM)(const COMPAREITEMSTRUCT*)(lpCompareItem))
#define FORWARD_WM_COPY(hwnd, fn) (void)(fn)((hwnd), WM_COPY, 0L, 0L)
#define FORWARD_WM_CREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_CREATE, 0L, (LPARAM)(LPCREATESTRUCT)(lpCreateStruct))
#define FORWARD_WM_CTLCOLORBTN(hwnd, hdc, hwndChild, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLORBTN, (WPARAM)(HDC)(hdc), (LPARAM)(HWND)(hwndChild))
#define FORWARD_WM_CTLCOLORDLG(hwnd, hdc, hwndChild, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLORDLG, (WPARAM)(HDC)(hdc), (LPARAM)(HWND)(hwndChild))
#define FORWARD_WM_CTLCOLOREDIT(hwnd, hdc, hwndChild, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLOREDIT, (WPARAM)(HDC)(hdc), (LPARAM)(HWND)(hwndChild))
#define FORWARD_WM_CTLCOLORLISTBOX(hwnd, hdc, hwndChild, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLORLISTBOX, (WPARAM)(HDC)(hdc), (LPARAM)(HWND)(hwndChild))
#define FORWARD_WM_CTLCOLORMSGBOX(hwnd, hdc, hwndChild, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLORMSGBOX, (WPARAM)(HDC)(hdc), (LPARAM)(HWND)(hwndChild))
#define FORWARD_WM_CTLCOLORSCROLLBAR(hwnd, hdc, hwndChild, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLORSCROLLBAR, (WPARAM)(HDC)(hdc), (LPARAM)(HWND)(hwndChild))
#define FORWARD_WM_CTLCOLORSTATIC(hwnd, hdc, hwndChild, fn) \
    (HBRUSH)(UINT)(DWORD)(fn)((hwnd), WM_CTLCOLORSTATIC, (WPARAM)(HDC)(hdc), (LPARAM)(HWND)(hwndChild))
#define FORWARD_WM_CUT(hwnd, fn) (void)(fn)((hwnd), WM_CUT, 0L, 0L)
#define FORWARD_WM_DEADCHAR(hwnd, ch, cRepeat, fn) (void)(fn)((hwnd), WM_DEADCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat), 0))
#define FORWARD_WM_DELETEITEM(hwnd, lpDeleteItem, fn)                                             \
    (void)(fn)((hwnd), WM_DELETEITEM, (WPARAM)(((const DELETEITEMSTRUCT*)(lpDeleteItem))->CtlID), \
               (LPARAM)(const DELETEITEMSTRUCT*)(lpDeleteItem))
#define FORWARD_WM_DESTROY(hwnd, fn) (void)(fn)((hwnd), WM_DESTROY, 0L, 0L)
#define FORWARD_WM_DESTROYCLIPBOARD(hwnd, fn) (void)(fn)((hwnd), WM_DESTROYCLIPBOARD, 0L, 0L)
#define FORWARD_WM_DEVMODECHANGE(hwnd, lpszDeviceName, fn) \
    (void)(fn)((hwnd), WM_DEVMODECHANGE, 0L, (LPARAM)(LPCTSTR)(lpszDeviceName))
#define FORWARD_WM_DRAWCLIPBOARD(hwnd, fn) (void)(fn)((hwnd), WM_DRAWCLIPBOARD, 0L, 0L)
#define FORWARD_WM_DRAWITEM(hwnd, lpDrawItem, fn)                                         \
    (void)(fn)((hwnd), WM_DRAWITEM, (WPARAM)(((const DRAWITEMSTRUCT*)lpDrawItem)->CtlID), \
               (LPARAM)(const DRAWITEMSTRUCT*)(lpDrawItem))
#define FORWARD_WM_DROPFILES(hwnd, hdrop, fn) (void)(fn)((hwnd), WM_DROPFILES, (WPARAM)(HDROP)(hdrop), 0L)
#define FORWARD_WM_ENABLE(hwnd, fEnable, fn) (void)(fn)((hwnd), WM_ENABLE, (WPARAM)(BOOL)(fEnable), 0L)
#define FORWARD_WM_ENDSESSION(hwnd, fEnding, fn) (void)(fn)((hwnd), WM_ENDSESSION, (WPARAM)(BOOL)(fEnding), 0L)
#define FORWARD_WM_ENTERIDLE(hwnd, source, hwndSource, fn) \
    (void)(fn)((hwnd), WM_ENTERIDLE, (WPARAM)(UINT)(source), (LPARAM)(HWND)(hwndSource))
#define FORWARD_WM_ERASEBKGND(hwnd, hdc, fn) (BOOL)(DWORD)(fn)((hwnd), WM_ERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define FORWARD_WM_FONTCHANGE(hwnd, fn) (void)(fn)((hwnd), WM_FONTCHANGE, 0L, 0L)
#define FORWARD_WM_GETDLGCODE(hwnd, lpmsg, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_GETDLGCODE, (lpmsg ? lpmsg->wParam : 0), (LPARAM)(LPMSG)(lpmsg))
#define FORWARD_WM_GETFONT(hwnd, fn) (HFONT)(UINT)(DWORD)(fn)((hwnd), WM_GETFONT, 0L, 0L)
#define FORWARD_WM_GETMINMAXINFO(hwnd, lpMinMaxInfo, fn) \
    (void)(fn)((hwnd), WM_GETMINMAXINFO, 0L, (LPARAM)(LPMINMAXINFO)(lpMinMaxInfo))
#define FORWARD_WM_GETTEXT(hwnd, cchTextMax, lpszText, fn) \
    (int)(DWORD)(fn)((hwnd), WM_GETTEXT, (WPARAM)(int)(cchTextMax), (LPARAM)(LPTSTR)(lpszText))
#define FORWARD_WM_GETTEXTLENGTH(hwnd, fn) (int)(DWORD)(fn)((hwnd), WM_GETTEXTLENGTH, 0L, 0L)
#define FORWARD_WM_HSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLL, MAKEWPARAM((UINT)(int)(code), (UINT)(int)(pos)), (LPARAM)(UINT)(hwndCtl))
#define FORWARD_WM_HSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_HSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define FORWARD_WM_ICONERASEBKGND(hwnd, hdc, fn) (BOOL)(DWORD)(fn)((hwnd), WM_ICONERASEBKGND, (WPARAM)(HDC)(hdc), 0L)
#define FORWARD_WM_INITDIALOG(hwnd, hwndFocus, lParam, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_INITDIALOG, (WPARAM)(HWND)(hwndFocus), (lParam))
#define FORWARD_WM_INITMENU(hwnd, hMenu, fn) (void)(fn)((hwnd), WM_INITMENU, (WPARAM)(HMENU)(hMenu), 0L)
#define FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, item, fSystemMenu, fn) \
    (void)(fn)((hwnd), WM_INITMENUPOPUP, (WPARAM)(HMENU)(hMenu), MAKELPARAM((item), (fSystemMenu)))
#define FORWARD_WM_KEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((cRepeat), (flags)))
#define FORWARD_WM_KEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_KEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((cRepeat), (flags)))
#define FORWARD_WM_KILLFOCUS(hwnd, hwndNewFocus, fn) (void)(fn)((hwnd), WM_KILLFOCUS, (WPARAM)(HWND)(hwndNewFocus), 0L)
#define FORWARD_WM_LBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_LBUTTONDBLCLK : WM_LBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define FORWARD_WM_LBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_LBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define FORWARD_WM_MBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_MBUTTONDBLCLK : WM_MBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define FORWARD_WM_MBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define FORWARD_WM_MDIACTIVATE(hwnd, fActive, hwndActivate, hwndDeactivate, fn) \
    (void)(fn)(hwnd, WM_MDIACTIVATE, (WPARAM)(hwndDeactivate), (LPARAM)(hwndActivate))
#define FORWARD_WM_MDICASCADE(hwnd, cmd, fn) (BOOL)(DWORD)(fn)((hwnd), WM_MDICASCADE, (WPARAM)(cmd), 0L)
#define FORWARD_WM_MDICREATE(hwnd, lpmcs, fn) (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDICREATE, 0L, (LPARAM)(LPMDICREATESTRUCT)(lpmcs))
#define FORWARD_WM_MDIDESTROY(hwnd, hwndDestroy, fn) (void)(fn)((hwnd), WM_MDIDESTROY, (WPARAM)(hwndDestroy), 0L)
#define FORWARD_WM_MDIGETACTIVE(hwnd, fn) (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDIGETACTIVE, 0L, 0L)
#define FORWARD_WM_MDIICONARRANGE(hwnd, fn) (void)(fn)((hwnd), WM_MDIICONARRANGE, 0L, 0L)
#define FORWARD_WM_MDIMAXIMIZE(hwnd, hwndMaximize, fn) (void)(fn)((hwnd), WM_MDIMAXIMIZE, (WPARAM)(hwndMaximize), 0L)
#define FORWARD_WM_MDINEXT(hwnd, hwndCur, fPrev, fn) (HWND)(UINT)(DWORD)(fn)((hwnd), WM_MDINEXT, (WPARAM)(hwndCur), (LPARAM)(fPrev))
#define FORWARD_WM_MDIRESTORE(hwnd, hwndRestore, fn) (void)(fn)((hwnd), WM_MDIRESTORE, (WPARAM)(hwndRestore), 0L)
#define FORWARD_WM_MDISETMENU(hwnd, fRefresh, hmenuFrame, hmenuWindow, fn) \
    (HMENU)(UINT)(DWORD)(fn)((hwnd), WM_MDISETMENU, (WPARAM)((fRefresh) ? (hmenuFrame) : 0), (LPARAM)(hmenuWindow))
#define FORWARD_WM_MDITILE(hwnd, cmd, fn) (BOOL)(DWORD)(fn)((hwnd), WM_MDITILE, (WPARAM)(cmd), 0L)
#define FORWARD_WM_MEASUREITEM(hwnd, lpMeasureItem, fn)                                      \
    (void)(fn)((hwnd), WM_MEASUREITEM, (WPARAM)(((MEASUREITEMSTRUCT*)lpMeasureItem)->CtlID), \
               (LPARAM)(MEASUREITEMSTRUCT*)(lpMeasureItem))
#define FORWARD_WM_MENUCHAR(hwnd, ch, flags, hmenu, fn) \
    (DWORD)(fn)((hwnd), WM_MENUCHAR, MAKEWPARAM(flags, (WORD)(ch)), (LPARAM)(HMENU)(hmenu))
#define FORWARD_WM_MENUSELECT(hwnd, hmenu, item, hmenuPopup, flags, fn) \
    (void)(fn)((hwnd), WM_MENUSELECT, MAKEWPARAM((item), (flags)), (LPARAM)(HMENU)((hmenu) ? (hmenu) : (hmenuPopup)))
#define FORWARD_WM_MOUSEACTIVATE(hwnd, hwndTopLevel, codeHitTest, msg, fn) \
    (int)(DWORD)(fn)((hwnd), WM_MOUSEACTIVATE, (WPARAM)(HWND)(hwndTopLevel), MAKELPARAM((codeHitTest), (msg)))
#define FORWARD_WM_MOUSEMOVE(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_MOUSEMOVE, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define FORWARD_WM_MOVE(hwnd, x, y, fn) (void)(fn)((hwnd), WM_MOVE, 0L, MAKELPARAM((x), (y)))
#define FORWARD_WM_NCACTIVATE(hwnd, fActive, hwndActDeact, fMinimized, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCACTIVATE, (WPARAM)(BOOL)(fActive), 0L)
#define FORWARD_WM_NCCALCSIZE(hwnd, fCalcValidRects, lpcsp, fn) \
    (UINT)(DWORD)(fn)((hwnd), WM_NCCALCSIZE, 0L, (LPARAM)(NCCALCSIZE_PARAMS*)(lpcsp))
#define FORWARD_WM_NCCREATE(hwnd, lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_NCCREATE, 0L, (LPARAM)(LPCREATESTRUCT)(lpCreateStruct))
#define FORWARD_WM_NCDESTROY(hwnd, fn) (void)(fn)((hwnd), WM_NCDESTROY, 0L, 0L)
#define FORWARD_WM_NCHITTEST(hwnd, x, y, fn) (UINT)(DWORD)(fn)((hwnd), WM_NCHITTEST, 0L, MAKELPARAM((x), (y)))
#define FORWARD_WM_NCLBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCLBUTTONDBLCLK : WM_NCLBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define FORWARD_WM_NCLBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCLBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define FORWARD_WM_NCMBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCMBUTTONDBLCLK : WM_NCMBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define FORWARD_WM_NCMBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define FORWARD_WM_NCMOUSEMOVE(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCMOUSEMOVE, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define FORWARD_WM_NCPAINT(hwnd, hrgn, fn) (void)(fn)((hwnd), WM_NCPAINT, (WPARAM)(HRGN)(hrgn), 0L)
#define FORWARD_WM_NCRBUTTONDOWN(hwnd, fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_NCRBUTTONDBLCLK : WM_NCRBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define FORWARD_WM_NCRBUTTONUP(hwnd, x, y, codeHitTest, fn) \
    (void)(fn)((hwnd), WM_NCRBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))
#define FORWARD_WM_NEXTDLGCTL(hwnd, hwndSetFocus, fNext, fn) \
    (HWND)(UINT)(DWORD)(fn)((hwnd), WM_NEXTDLGCTL, (WPARAM)(HWND)(hwndSetFocus), (LPARAM)(fNext))
#define FORWARD_WM_PAINT(hwnd, fn) (void)(fn)((hwnd), WM_PAINT, 0L, 0L)
#define FORWARD_WM_PAINTCLIPBOARD(hwnd, hwndCBViewer, lpPaintStruct, fn) \
    (void)(fn)((hwnd), WM_PAINTCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(LPPAINTSTRUCT)(lpPaintStruct))
#define FORWARD_WM_PALETTECHANGED(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTECHANGED, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define FORWARD_WM_PALETTEISCHANGING(hwnd, hwndPaletteChange, fn) \
    (void)(fn)((hwnd), WM_PALETTEISCHANGING, (WPARAM)(HWND)(hwndPaletteChange), 0L)
#define FORWARD_WM_PARENTNOTIFY(hwnd, msg, hwndChild, idChild, fn) \
    (void)(fn)((hwnd), WM_PARENTNOTIFY, MAKEWPARAM(msg, idChild), (LPARAM)(hwndChild))
#define FORWARD_WM_PASTE(hwnd, fn) (void)(fn)((hwnd), WM_PASTE, 0L, 0L)
#define FORWARD_WM_POWER(hwnd, code, fn) (void)(fn)((hwnd), WM_POWER, (WPARAM)(int)(code), 0L)
#define FORWARD_WM_QUERYDRAGICON(hwnd, fn) (HICON)(UINT)(DWORD)(fn)((hwnd), WM_QUERYDRAGICON, 0L, 0L)
#define FORWARD_WM_QUERYENDSESSION(hwnd, fn) (BOOL)(DWORD)(fn)((hwnd), WM_QUERYENDSESSION, 0L, 0L)
#define FORWARD_WM_QUERYNEWPALETTE(hwnd, fn) (BOOL)(DWORD)(fn)((hwnd), WM_QUERYNEWPALETTE, 0L, 0L)
#define FORWARD_WM_QUERYOPEN(hwnd, fn) (BOOL)(DWORD)(fn)((hwnd), WM_QUERYOPEN, 0L, 0L)
#define FORWARD_WM_QUEUESYNC(hwnd, fn) (void)(fn)((hwnd), WM_QUEUESYNC, 0L, 0L)
#define FORWARD_WM_QUIT(hwnd, exitCode, fn) (void)(fn)((hwnd), WM_QUIT, (WPARAM)(exitCode), 0L)
#define FORWARD_WM_RBUTTONDOWN(hwnd, fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), (fDoubleClick) ? WM_RBUTTONDBLCLK : WM_RBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define FORWARD_WM_RBUTTONUP(hwnd, x, y, keyFlags, fn) \
    (void)(fn)((hwnd), WM_RBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))
#define FORWARD_WM_RENDERALLFORMATS(hwnd, fn) (void)(fn)((hwnd), WM_RENDERALLFORMATS, 0L, 0L)
#define FORWARD_WM_RENDERFORMAT(hwnd, fmt, fn) (HANDLE)(UINT)(DWORD)(fn)((hwnd), WM_RENDERFORMAT, (WPARAM)(UINT)(fmt), 0L)
#define FORWARD_WM_SETCURSOR(hwnd, hwndCursor, codeHitTest, msg, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_SETCURSOR, (WPARAM)(HWND)(hwndCursor), MAKELPARAM((codeHitTest), (msg)))
#define FORWARD_WM_SETFOCUS(hwnd, hwndOldFocus, fn) (void)(fn)((hwnd), WM_SETFOCUS, (WPARAM)(HWND)(hwndOldFocus), 0L)
#define FORWARD_WM_SETFONT(hwnd, hfont, fRedraw, fn) (void)(fn)((hwnd), WM_SETFONT, (WPARAM)(HFONT)(hfont), (LPARAM)(BOOL)(fRedraw))
#define FORWARD_WM_SETREDRAW(hwnd, fRedraw, fn) (void)(fn)((hwnd), WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L)
#define FORWARD_WM_SETTEXT(hwnd, lpszText, fn) (void)(fn)((hwnd), WM_SETTEXT, 0L, (LPARAM)(LPCTSTR)(lpszText))
#define FORWARD_WM_SHOWWINDOW(hwnd, fShow, status, fn) \
    (void)(fn)((hwnd), WM_SHOWWINDOW, (WPARAM)(BOOL)(fShow), (LPARAM)(UINT)(status))
#define FORWARD_WM_SIZE(hwnd, state, cx, cy, fn) (void)(fn)((hwnd), WM_SIZE, (WPARAM)(UINT)(state), MAKELPARAM((cx), (cy)))
#define FORWARD_WM_SIZECLIPBOARD(hwnd, hwndCBViewer, lprc, fn) \
    (void)(fn)((hwnd), WM_SIZECLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), (LPARAM)(LPRECT)(lprc))
#define FORWARD_WM_SPOOLERSTATUS(hwnd, status, cJobInQueue, fn) \
    (void)(fn)((hwnd), WM_SPOOLERSTATUS, (WPARAM)(status), MAKELPARAM((cJobInQueue), 0))
#define FORWARD_WM_SYSCHAR(hwnd, ch, cRepeat, fn) (void)(fn)((hwnd), WM_SYSCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat), 0))
#define FORWARD_WM_SYSCOLORCHANGE(hwnd, fn) (void)(fn)((hwnd), WM_SYSCOLORCHANGE, 0L, 0L)
#define FORWARD_WM_SYSCOMMAND(hwnd, cmd, x, y, fn) (void)(fn)((hwnd), WM_SYSCOMMAND, (WPARAM)(UINT)(cmd), MAKELPARAM((x), (y)))
#define FORWARD_WM_SYSDEADCHAR(hwnd, ch, cRepeat, fn) \
    (void)(fn)((hwnd), WM_SYSDEADCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat), 0))
#define FORWARD_WM_SYSKEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((cRepeat), (flags)))
#define FORWARD_WM_SYSKEYUP(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)((hwnd), WM_SYSKEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((cRepeat), (flags)))
#define FORWARD_WM_SYSTEMERROR(hwnd, errCode, fn) 0L
#define FORWARD_WM_TIMECHANGE(hwnd, fn) (void)(fn)((hwnd), WM_TIMECHANGE, 0L, 0L)
#define FORWARD_WM_TIMER(hwnd, id, fn) (void)(fn)((hwnd), WM_TIMER, (WPARAM)(UINT)(id), 0L)
#define FORWARD_WM_UNDO(hwnd, fn) (void)(fn)((hwnd), WM_UNDO, 0L, 0L)
#define FORWARD_WM_VKEYTOITEM(hwnd, vk, hwndListBox, iCaret, fn) \
    (int)(DWORD)(fn)((hwnd), WM_VKEYTOITEM, MAKEWPARAM((vk), (iCaret)), (LPARAM)(hwndListBox))
#define FORWARD_WM_VSCROLL(hwnd, hwndCtl, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLL, MAKEWPARAM((UINT)(int)(code), (UINT)(int)(pos)), (LPARAM)(HWND)(hwndCtl))
#define FORWARD_WM_VSCROLLCLIPBOARD(hwnd, hwndCBViewer, code, pos, fn) \
    (void)(fn)((hwnd), WM_VSCROLLCLIPBOARD, (WPARAM)(HWND)(hwndCBViewer), MAKELPARAM((code), (pos)))
#define FORWARD_WM_WINDOWPOSCHANGED(hwnd, lpwpos, fn) \
    (void)(fn)((hwnd), WM_WINDOWPOSCHANGED, 0L, (LPARAM)(const LPWINDOWPOS)(lpwpos))
#define FORWARD_WM_WINDOWPOSCHANGING(hwnd, lpwpos, fn) \
    (BOOL)(DWORD)(fn)((hwnd), WM_WINDOWPOSCHANGING, 0L, (LPARAM)(LPWINDOWPOS)(lpwpos))
#define FORWARD_WM_WININICHANGE(hwnd, lpszSectionName, fn) \
    (void)(fn)((hwnd), WM_WININICHANGE, 0L, (LPARAM)(LPCTSTR)(lpszSectionName))

#define GET_EM_LINESCROLL_MPS(vert, horz) (WPARAM) horz, (LONG)vert
#define GET_EM_SETSEL_END(wp, lp) (lp)
#define GET_EM_SETSEL_MPS(iStart, iEnd) (WPARAM)(iStart), (LONG)(iEnd)
#define GET_EM_SETSEL_START(wp, lp) (INT)(wp)
#define GET_LPARAM(wp, lp) (lp)
#define GET_WM_ACTIVATE_FMINIMIZED(wp, lp) (BOOL) HIWORD(wp)
#define GET_WM_ACTIVATE_HWND(wp, lp) (HWND)(lp)
#define GET_WM_ACTIVATE_MPS(s, fmin, hwnd) (WPARAM) MAKELONG((s), (fmin)), (LONG)(hwnd)
#define GET_WM_ACTIVATE_STATE(wp, lp) LOWORD(wp)
#define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp) (HWND)(lp)
#define GET_WM_CHARTOITEM_CHAR(wp, lp) (TCHAR) LOWORD(wp)
#define GET_WM_CHARTOITEM_HWND(wp, lp) (HWND)(lp)
#define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd) (WPARAM) MAKELONG((pos), (ch)), (LONG)(hwnd)
#define GET_WM_CHARTOITEM_POS(wp, lp) HIWORD(wp)
#define GET_WM_COMMAND_CMD(wp, lp) HIWORD(wp)
#define GET_WM_COMMAND_HWND(wp, lp) (HWND)(lp)
#define GET_WM_COMMAND_ID(wp, lp) LOWORD(wp)
#define GET_WM_COMMAND_MPS(id, hwnd, cmd) (WPARAM) MAKELONG(id, cmd), (LONG)(hwnd)
#define GET_WM_CTLCOLOR_HDC(wp, lp, msg) (HDC)(wp)
#define GET_WM_CTLCOLOR_HWND(wp, lp, msg) (HWND)(lp)
#define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type) (WPARAM)(hdc), (LONG)(hwnd)
#define GET_WM_CTLCOLOR_MSG(type) (WORD)(WM_CTLCOLORMSGBOX + (type))
#define GET_WM_CTLCOLOR_TYPE(wp, lp, msg) (WORD)(msg - WM_CTLCOLORMSGBOX)
#define GET_WM_HSCROLL_CODE(wp, lp) LOWORD(wp)
#define GET_WM_HSCROLL_HWND(wp, lp) (HWND)(lp)
#define GET_WM_HSCROLL_MPS(code, pos, hwnd) (WPARAM) MAKELONG(code, pos), (LONG)(hwnd)
#define GET_WM_HSCROLL_POS(wp, lp) HIWORD(wp)
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp) (lp == (LONG)hwnd)
#define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp) (HWND)(lp)
#define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp) (HWND)(wp)
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA) (WPARAM)(hwndA), 0
#define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW) (WPARAM) hmenuF, (LONG)hmenuW
#define GET_WM_MENUCHAR_CHAR(wp, lp) (TCHAR) LOWORD(wp)
#define GET_WM_MENUCHAR_FMENU(wp, lp) (BOOL) HIWORD(wp)
#define GET_WM_MENUCHAR_HMENU(wp, lp) (HMENU)(lp)
#define GET_WM_MENUCHAR_MPS(ch, hmenu, f) (WPARAM) MAKELONG(ch, f), (LONG)(hmenu)
#define GET_WM_MENUSELECT_CMD(wp, lp) LOWORD(wp)
#define GET_WM_MENUSELECT_FLAGS(wp, lp) (UINT)(int)(short)HIWORD(wp)
#define GET_WM_MENUSELECT_HMENU(wp, lp) (HMENU)(lp)
#define GET_WM_MENUSELECT_MPS(cmd, f, hmenu) (WPARAM) MAKELONG(cmd, f), (LONG)(hmenu)
#define GET_WM_PARENTNOTIFY2_MPS(msg, x, y) (WPARAM) MAKELONG(0, msg), MAKELONG(x, y)
#define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp) (HWND)(lp)
#define GET_WM_PARENTNOTIFY_ID(wp, lp) HIWORD(wp)
#define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd) (WPARAM) MAKELONG(id, msg), (LONG)(hwnd)
#define GET_WM_PARENTNOTIFY_MSG(wp, lp) LOWORD(wp)
#define GET_WM_PARENTNOTIFY_X(wp, lp) (int)(short) LOWORD(lp)
#define GET_WM_PARENTNOTIFY_Y(wp, lp) (int)(short) HIWORD(lp)
#define GET_WM_VKEYTOITEM_CODE(wp, lp) (int)(short) LOWORD(wp)
#define GET_WM_VKEYTOITEM_HWND(wp, lp) (HWND)(lp)
#define GET_WM_VKEYTOITEM_ITEM(wp, lp) HIWORD(wp)
#define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) (WPARAM) MAKELONG(item, code), (LONG)(hwnd)
#define GET_WM_VSCROLL_CODE(wp, lp) LOWORD(wp)
#define GET_WM_VSCROLL_HWND(wp, lp) (HWND)(lp)
#define GET_WM_VSCROLL_MPS(code, pos, hwnd) (WPARAM) MAKELONG(code, pos), (LONG)(hwnd)
#define GET_WM_VSCROLL_POS(wp, lp) HIWORD(wp)
#define GET_WPARAM(wp, lp) (wp)

#define GetFirstChild(hwnd) GetTopWindow(hwnd)

#define GetFirstSibling(hwnd) GetWindow(hwnd, GW_HWNDFIRST)

#define GetInstanceModule(hInstance) (HMODULE)(hInstance)

#define GetLastSibling(hwnd) GetWindow(hwnd, GW_HWNDLAST)

#define GetNextSibling(hwnd) GetWindow(hwnd, GW_HWNDNEXT)

#define GetPrevSibling(hwnd) GetWindow(hwnd, GW_HWNDPREV)

#define GetStockBrush(i) ((HBRUSH)GetStockObject(i))

#define GetStockFont(i) ((HFONT)GetStockObject(i))

#define GetStockPen(i) ((HPEN)GetStockObject(i))

#define GetWindowExStyle(hwnd) ((DWORD)GetWindowLong(hwnd, GWL_EXSTYLE))

#define GetWindowFont(hwnd) FORWARD_WM_GETFONT((hwnd), SendMessage)

#define GetWindowID(hwnd) GetDlgCtrlID(hwnd)

#define GetWindowInstance(hwnd) ((HMODULE)GetWindowLong(hwnd, GWL_HINSTANCE))

#define GetWindowOwner(hwnd) GetWindow(hwnd, GW_OWNER)

#define GetWindowStyle(hwnd) ((DWORD)GetWindowLong(hwnd, GWL_STYLE))

#define GlobalAllocPtr(flags, cb) (GlobalLock(GlobalAlloc((flags), (cb))))

#define GlobalFreePtr(lp) (GlobalUnlockPtr(lp), (BOOL)GlobalFree(GlobalPtrHandle(lp)))

#define GlobalLockPtr(lp) ((BOOL)GlobalLock(GlobalPtrHandle(lp)))

#define GlobalPtrHandle(lp) ((HGLOBAL)GlobalHandle(lp))

#define GlobalReAllocPtr(lp, cbNew, flags) (GlobalUnlockPtr(lp), GlobalLock(GlobalReAlloc(GlobalPtrHandle(lp), (cbNew), (flags))))

#define GlobalUnlockPtr(lp) GlobalUnlock(GlobalPtrHandle(lp))

#define HANDLE_MSG(hwnd, message, fn) \
    case (message):                   \
        return HANDLE_##message((hwnd), (wParam), (lParam), (fn))
#define HANDLE_WM_ACTIVATE(hwnd, wParam, lParam, fn) ((fn)((hwnd), (UINT)LOWORD(wParam), (HWND)(lParam), (BOOL)HIWORD(wParam)), 0L)
#define HANDLE_WM_ACTIVATEAPP(hwnd, wParam, lParam, fn) ((fn)((hwnd), (BOOL)(wParam), (DWORD)(lParam)), 0L)
#define HANDLE_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn) ((fn)((hwnd), (int)(wParam), (LPTSTR)(lParam)), 0L)
#define HANDLE_WM_CANCELMODE(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HWND)(wParam), (HWND)(lParam)), 0L)
#define HANDLE_WM_CHAR(hwnd, wParam, lParam, fn) ((fn)((hwnd), (TCHAR)(wParam), (int)(short)LOWORD(lParam)), 0L)
#define HANDLE_WM_CHARTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)LOWORD(wParam), (HWND)(lParam), (int)(short)HIWORD(wParam))
#define HANDLE_WM_CHILDACTIVATE(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_CLEAR(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_CLOSE(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_COMMAND(hwnd, wParam, lParam, fn) ((fn)((hwnd), (int)(LOWORD(wParam)), (HWND)(lParam), (UINT)HIWORD(wParam)), 0L)
#define HANDLE_WM_COMMNOTIFY(hwnd, wParam, lParam, fn) ((fn)((hwnd), (int)(wParam), (UINT)LOWORD(lParam)), 0L)
#define HANDLE_WM_COMPACTING(hwnd, wParam, lParam, fn) ((fn)((hwnd), (UINT)(wParam)), 0L)
#define HANDLE_WM_COMPAREITEM(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(int)(fn)((hwnd), (const COMPAREITEMSTRUCT*)(lParam))
#define HANDLE_WM_COPY(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_CREATE(hwnd, wParam, lParam, fn) ((fn)((hwnd), (LPCREATESTRUCT)(lParam)) ? 0L : (LRESULT)-1L)
#define HANDLE_WM_CTLCOLORBTN(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_BTN)
#define HANDLE_WM_CTLCOLORDLG(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_DLG)
#define HANDLE_WM_CTLCOLOREDIT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_EDIT)
#define HANDLE_WM_CTLCOLORLISTBOX(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_LISTBOX)
#define HANDLE_WM_CTLCOLORMSGBOX(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_MSGBOX)
#define HANDLE_WM_CTLCOLORSCROLLBAR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_SCROLLBAR)
#define HANDLE_WM_CTLCOLORSTATIC(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_STATIC)
#define HANDLE_WM_CUT(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_DEADCHAR(hwnd, wParam, lParam, fn) ((fn)((hwnd), (TCHAR)(wParam), (int)(short)LOWORD(lParam)), 0L)
#define HANDLE_WM_DELETEITEM(hwnd, wParam, lParam, fn) ((fn)((hwnd), (const DELETEITEMSTRUCT*)(lParam)), 0L)
#define HANDLE_WM_DESTROY(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn) ((fn)((hwnd), (LPCTSTR)(lParam)), 0L)
#define HANDLE_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_DRAWITEM(hwnd, wParam, lParam, fn) ((fn)((hwnd), (const DRAWITEMSTRUCT*)(lParam)), 0L)
#define HANDLE_WM_DROPFILES(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HDROP)(wParam)), 0L)
#define HANDLE_WM_ENABLE(hwnd, wParam, lParam, fn) ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define HANDLE_WM_ENDSESSION(hwnd, wParam, lParam, fn) ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define HANDLE_WM_ENTERIDLE(hwnd, wParam, lParam, fn) ((fn)((hwnd), (UINT)(wParam), (HWND)(lParam)), 0L)
#define HANDLE_WM_ERASEBKGND(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define HANDLE_WM_FONTCHANGE(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_GETDLGCODE(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(UINT)(fn)(hwnd, (LPMSG)(lParam))
#define HANDLE_WM_GETFONT(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(UINT)(HFONT)(fn)(hwnd)
#define HANDLE_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn) ((fn)((hwnd), (LPMINMAXINFO)(lParam)), 0L)
#define HANDLE_WM_GETTEXT(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(int)(fn)((hwnd), (int)(wParam), (LPTSTR)(lParam))
#define HANDLE_WM_GETTEXTLENGTH(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(int)(fn)(hwnd)
#define HANDLE_WM_HSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(lParam), (UINT)(LOWORD(wParam)), (int)(short)HIWORD(wParam)), 0L)
#define HANDLE_WM_HSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define HANDLE_WM_ICONERASEBKGND(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))
#define HANDLE_WM_INITDIALOG(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(UINT)(BOOL)(fn)((hwnd), (HWND)(wParam), lParam)
#define HANDLE_WM_INITMENU(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HMENU)(wParam)), 0L)
#define HANDLE_WM_INITMENUPOPUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam), (UINT)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define HANDLE_WM_KEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define HANDLE_WM_KEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define HANDLE_WM_KILLFOCUS(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HWND)(wParam)), 0L)
#define HANDLE_WM_LBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_LBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_LBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_MBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_MBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_MBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_MDIACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(lParam == (LPARAM)hwnd), (HWND)(lParam), (HWND)(wParam)), 0L)
#define HANDLE_WM_MDICASCADE(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define HANDLE_WM_MDICREATE(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(UINT)(fn)((hwnd), (LPMDICREATESTRUCT)(lParam))
#define HANDLE_WM_MDIDESTROY(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HWND)(wParam)), 0L)
#define HANDLE_WM_MDIGETACTIVE(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define HANDLE_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HWND)(wParam)), 0L)
#define HANDLE_WM_MDINEXT(hwnd, wParam, lParam, fn) (LRESULT)(HWND)(fn)((hwnd), (HWND)(wParam), (BOOL)lParam)
#define HANDLE_WM_MDIRESTORE(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HWND)(wParam)), 0L)
#define HANDLE_WM_MDISETMENU(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (HMENU)(wParam), (HMENU)(lParam))
#define HANDLE_WM_MDITILE(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))
#define HANDLE_WM_MEASUREITEM(hwnd, wParam, lParam, fn) ((fn)((hwnd), (MEASUREITEMSTRUCT*)(lParam)), 0L)
#define HANDLE_WM_MENUCHAR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(LOWORD(wParam)), (UINT)HIWORD(wParam), (HMENU)(lParam))
#define HANDLE_WM_MENUSELECT(hwnd, wParam, lParam, fn)                                  \
    ((fn)((hwnd), (HMENU)(lParam), (int)(LOWORD(wParam)),                               \
          (HIWORD(wParam) & MF_POPUP) ? GetSubMenu((HMENU)lParam, LOWORD(wParam)) : 0L, \
          (UINT)(((short)HIWORD(wParam) == -1) ? 0xFFFFFFFF : HIWORD(wParam))),         \
     0L)
#define HANDLE_WM_MOUSEACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))
#define HANDLE_WM_MOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_MOVE(hwnd, wParam, lParam, fn) ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define HANDLE_WM_NCACTIVATE(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (BOOL)(wParam), 0L, 0L)
#define HANDLE_WM_NCCALCSIZE(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(0), (NCCALCSIZE_PARAMS*)(lParam))
#define HANDLE_WM_NCCREATE(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (LPCREATESTRUCT)(lParam))
#define HANDLE_WM_NCDESTROY(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_NCHITTEST(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam))
#define HANDLE_WM_NCLBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCLBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCLBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCMBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCMBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCMBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCMOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCPAINT(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HRGN)(wParam)), 0L)
#define HANDLE_WM_NCRBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCRBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NCRBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_NEXTDLGCTL(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(UINT)(HWND)(fn)((hwnd), (HWND)(wParam), (BOOL)(lParam))
#define HANDLE_WM_PAINT(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const LPPAINTSTRUCT)GlobalLock((HGLOBAL)(lParam))), GlobalUnlock((HGLOBAL)(lParam)), 0L)
#define HANDLE_WM_PALETTECHANGED(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HWND)(wParam)), 0L)
#define HANDLE_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HWND)(wParam)), 0L)
#define HANDLE_WM_PARENTNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)LOWORD(wParam), (HWND)(lParam), (UINT)HIWORD(wParam)), 0L)
#define HANDLE_WM_PASTE(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_POWER(hwnd, wParam, lParam, fn) ((fn)((hwnd), (int)(wParam)), 0L)
#define HANDLE_WM_QUERYDRAGICON(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(UINT)(fn)(hwnd)
#define HANDLE_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn) MAKELRESULT((BOOL)(fn)(hwnd), 0L)
#define HANDLE_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn) MAKELRESULT((BOOL)(fn)(hwnd), 0L)
#define HANDLE_WM_QUERYOPEN(hwnd, wParam, lParam, fn) MAKELRESULT((BOOL)(fn)(hwnd), 0L)
#define HANDLE_WM_QUEUESYNC(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_QUIT(hwnd, wParam, lParam, fn) ((fn)((hwnd), (int)(wParam)), 0L)
#define HANDLE_WM_RBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_RBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_RBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define HANDLE_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_RENDERFORMAT(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(UINT)(HANDLE)(fn)((hwnd), (UINT)(wParam))
#define HANDLE_WM_SETCURSOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))
#define HANDLE_WM_SETFOCUS(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HWND)(wParam)), 0L)
#define HANDLE_WM_SETFONT(hwnd, wParam, lParam, fn) ((fn)((hwnd), (HFONT)(wParam), (BOOL)(lParam)), 0L)
#define HANDLE_WM_SETREDRAW(hwnd, wParam, lParam, fn) ((fn)((hwnd), (BOOL)(wParam)), 0L)
#define HANDLE_WM_SETTEXT(hwnd, wParam, lParam, fn) ((fn)((hwnd), (LPCTSTR)(lParam)), 0L)
#define HANDLE_WM_SHOWWINDOW(hwnd, wParam, lParam, fn) ((fn)((hwnd), (BOOL)(wParam), (UINT)(lParam)), 0L)
#define HANDLE_WM_SIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define HANDLE_WM_SIZECLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const LPRECT)GlobalLock((HGLOBAL)(lParam))), GlobalUnlock((HGLOBAL)(lParam)), 0L)
#define HANDLE_WM_SPOOLERSTATUS(hwnd, wParam, lParam, fn) ((fn)((hwnd), (UINT)(wParam), (int)(short)LOWORD(lParam)), 0L)
#define HANDLE_WM_SYSCHAR(hwnd, wParam, lParam, fn) ((fn)((hwnd), (TCHAR)(wParam), (int)(short)LOWORD(lParam)), 0L)
#define HANDLE_WM_SYSCOLORCHANGE(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_SYSCOMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define HANDLE_WM_SYSDEADCHAR(hwnd, wParam, lParam, fn) ((fn)((hwnd), (TCHAR)(wParam), (int)(short)LOWORD(lParam)), 0L)
#define HANDLE_WM_SYSKEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define HANDLE_WM_SYSKEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define HANDLE_WM_SYSTEMERROR(hwnd, wParam, lParam, fn) 0L
#define HANDLE_WM_TIMECHANGE(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_TIMER(hwnd, wParam, lParam, fn) ((fn)((hwnd), (UINT)(wParam)), 0L)
#define HANDLE_WM_UNDO(hwnd, wParam, lParam, fn) ((fn)(hwnd), 0L)
#define HANDLE_WM_VKEYTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)LOWORD(wParam), (HWND)(lParam), (int)(short)HIWORD(wParam))
#define HANDLE_WM_VSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(lParam), (UINT)(LOWORD(wParam)), (int)(short)HIWORD(wParam)), 0L)
#define HANDLE_WM_VSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define HANDLE_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn) ((fn)((hwnd), (const LPWINDOWPOS)(lParam)), 0L)
#define HANDLE_WM_WINDOWPOSCHANGING(hwnd, wParam, lParam, fn) (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (LPWINDOWPOS)(lParam))
#define HANDLE_WM_WININICHANGE(hwnd, wParam, lParam, fn) ((fn)((hwnd), (LPCTSTR)(lParam)), 0L)

#define InsetRect(lprc, dx, dy) InflateRect((lprc), -(dx), -(dy))

#define IntersectRgn(hrgnResult, hrgnA, hrgnB) CombineRgn(hrgnResult, hrgnA, hrgnB, RGN_AND)

#define IsLButtonDown() (GetKeyState(VK_LBUTTON) < 0)

#define IsMButtonDown() (GetKeyState(VK_MBUTTON) < 0)

#define IsMaximized(hwnd) IsZoomed(hwnd)

#define IsMinimized(hwnd) IsIconic(hwnd)

#define IsRButtonDown() (GetKeyState(VK_RBUTTON) < 0)

#define IsRestored(hwnd) ((GetWindowStyle(hwnd) & (WS_MINIMIZE | WS_MAXIMIZE)) == 0L)

#define ListBox_AddItemData(hwndCtl, data) ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0L, (LPARAM)(data)))
#define ListBox_AddString(hwndCtl, lpsz) ((int)(DWORD)SendMessage((hwndCtl), LB_ADDSTRING, 0L, (LPARAM)(LPCTSTR)(lpsz)))
#define ListBox_DeleteString(hwndCtl, index) ((int)(DWORD)SendMessage((hwndCtl), LB_DELETESTRING, (WPARAM)(int)(index), 0L))
#define ListBox_Dir(hwndCtl, attrs, lpszFileSpec) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_DIR, (WPARAM)(UINT)(attrs), (LPARAM)(LPCTSTR)(lpszFileSpec)))
#define ListBox_Enable(hwndCtl, fEnable) EnableWindow((hwndCtl), (fEnable))
#define ListBox_FindItemData(hwndCtl, indexStart, data) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_FindString(hwndCtl, indexStart, lpszFind) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ListBox_FindStringExact(hwndCtl, indexStart, lpszFind) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_FINDSTRINGEXACT, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ListBox_GetCaretIndex(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), LB_GETCARETINDEX, 0L, 0L))
#define ListBox_GetCount(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), LB_GETCOUNT, 0L, 0L))
#define ListBox_GetCurSel(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), LB_GETCURSEL, 0L, 0L))
#define ListBox_GetHorizontalExtent(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), LB_GETHORIZONTALEXTENT, 0L, 0L))
#define ListBox_GetItemData(hwndCtl, index) ((LRESULT)(DWORD)SendMessage((hwndCtl), LB_GETITEMDATA, (WPARAM)(int)(index), 0L))
#define ListBox_GetItemHeight(hwndCtl, index) ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMHEIGHT, (WPARAM)(int)(index), 0L))
#define ListBox_GetItemRect(hwndCtl, index, lprc) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_GETITEMRECT, (WPARAM)(int)(index), (LPARAM)(RECT*)(lprc)))
#define ListBox_GetSel(hwndCtl, index) ((int)(DWORD)SendMessage((hwndCtl), LB_GETSEL, (WPARAM)(int)(index), 0L))
#define ListBox_GetSelCount(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELCOUNT, 0L, 0L))
#define ListBox_GetSelItems(hwndCtl, cItems, lpItems) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_GETSELITEMS, (WPARAM)(int)(cItems), (LPARAM)(int*)(lpItems)))
#define ListBox_GetText(hwndCtl, index, lpszBuffer) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXT, (WPARAM)(int)(index), (LPARAM)(LPCTSTR)(lpszBuffer)))
#define ListBox_GetTextLen(hwndCtl, index) ((int)(DWORD)SendMessage((hwndCtl), LB_GETTEXTLEN, (WPARAM)(int)(index), 0L))
#define ListBox_GetTopIndex(hwndCtl) ((int)(DWORD)SendMessage((hwndCtl), LB_GETTOPINDEX, 0L, 0L))
#define ListBox_InsertItemData(hwndCtl, index, data) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_InsertString(hwndCtl, index, lpsz) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCTSTR)(lpsz)))
#define ListBox_ResetContent(hwndCtl) ((BOOL)(DWORD)SendMessage((hwndCtl), LB_RESETCONTENT, 0L, 0L))
#define ListBox_SelItemRange(hwndCtl, fSelect, first, last) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_SELITEMRANGE, (WPARAM)(BOOL)(fSelect), MAKELPARAM((first), (last))))
#define ListBox_SelectItemData(hwndCtl, indexStart, data) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(data)))
#define ListBox_SelectString(hwndCtl, indexStart, lpszFind) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_SELECTSTRING, (WPARAM)(int)(indexStart), (LPARAM)(LPCTSTR)(lpszFind)))
#define ListBox_SetCaretIndex(hwndCtl, index) ((int)(DWORD)SendMessage((hwndCtl), LB_SETCARETINDEX, (WPARAM)(int)(index), 0L))
#define ListBox_SetColumnWidth(hwndCtl, cxColumn) ((void)SendMessage((hwndCtl), LB_SETCOLUMNWIDTH, (WPARAM)(int)(cxColumn), 0L))
#define ListBox_SetCurSel(hwndCtl, index) ((int)(DWORD)SendMessage((hwndCtl), LB_SETCURSEL, (WPARAM)(int)(index), 0L))
#define ListBox_SetHorizontalExtent(hwndCtl, cxExtent) \
    ((void)SendMessage((hwndCtl), LB_SETHORIZONTALEXTENT, (WPARAM)(int)(cxExtent), 0L))
#define ListBox_SetItemData(hwndCtl, index, data) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMDATA, (WPARAM)(int)(index), (LPARAM)(data)))
#define ListBox_SetItemHeight(hwndCtl, index, cy) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_SETITEMHEIGHT, (WPARAM)(int)(index), MAKELPARAM((cy), 0)))
#define ListBox_SetSel(hwndCtl, fSelect, index) \
    ((int)(DWORD)SendMessage((hwndCtl), LB_SETSEL, (WPARAM)(BOOL)(fSelect), (LPARAM)(index)))
#define ListBox_SetTabStops(hwndCtl, cTabs, lpTabs) \
    ((BOOL)(DWORD)SendMessage((hwndCtl), LB_SETTABSTOPS, (WPARAM)(int)(cTabs), (LPARAM)(int*)(lpTabs)))
#define ListBox_SetTopIndex(hwndCtl, indexTop) ((int)(DWORD)SendMessage((hwndCtl), LB_SETTOPINDEX, (WPARAM)(int)(indexTop), 0L))

#define MapWindowRect(hwndFrom, hwndTo, lprc) MapWindowPoints((hwndFrom), (hwndTo), (POINT*)(lprc), 2)

#define ScrollBar_Enable(hwndCtl, flags) EnableScrollBar((hwndCtl), SB_CTL, (flags))
#define ScrollBar_GetPos(hwndCtl) GetScrollPos((hwndCtl), SB_CTL)
#define ScrollBar_GetRange(hwndCtl, lpposMin, lpposMax) GetScrollRange((hwndCtl), SB_CTL, (lpposMin), (lpposMax))
#define ScrollBar_SetPos(hwndCtl, pos, fRedraw) SetScrollPos((hwndCtl), SB_CTL, (pos), (fRedraw))
#define ScrollBar_SetRange(hwndCtl, posMin, posMax, fRedraw) SetScrollRange((hwndCtl), SB_CTL, (posMin), (posMax), (fRedraw))
#define ScrollBar_Show(hwndCtl, fShow) ShowWindow((hwndCtl), (fShow) ? SW_SHOWNORMAL : SW_HIDE)

#define SelectBitmap(hdc, hbm) ((HBITMAP)SelectObject((hdc), (HGDIOBJ)(HBITMAP)(hbm)))

#define SelectBrush(hdc, hbr) ((HBRUSH)SelectObject((hdc), (HGDIOBJ)(HBRUSH)(hbr)))

#define SelectFont(hdc, hfont) ((HFONT)SelectObject((hdc), (HGDIOBJ)(HFONT)(hfont)))

#define SelectPen(hdc, hpen) ((HPEN)SelectObject((hdc), (HGDIOBJ)(HPEN)(hpen)))

#define SetDlgMsgResult(hwnd, msg, result)                                                                                 \
    (((msg) == WM_CTLCOLORMSGBOX || (msg) == WM_CTLCOLOREDIT || (msg) == WM_CTLCOLORLISTBOX || (msg) == WM_CTLCOLORBTN ||  \
      (msg) == WM_CTLCOLORDLG || (msg) == WM_CTLCOLORSCROLLBAR || (msg) == WM_CTLCOLORSTATIC || (msg) == WM_COMPAREITEM || \
      (msg) == WM_VKEYTOITEM || (msg) == WM_CHARTOITEM || (msg) == WM_QUERYDRAGICON || (msg) == WM_INITDIALOG)             \
         ? (BOOL)(result)                                                                                                  \
         : (SetWindowLong((hwnd), DWL_MSGRESULT, (LPARAM)(LRESULT)(result)), TRUE))

#define SetWindowFont(hwnd, hfont, fRedraw) FORWARD_WM_SETFONT((hwnd), (hfont), (fRedraw), SendMessage)

#define SetWindowRedraw(hwnd, fRedraw) ((void)SendMessage(hwnd, WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L))

#define Static_Enable(hwndCtl, fEnable) EnableWindow((hwndCtl), (fEnable))
#define Static_GetIcon(hwndCtl, hIcon) ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_GETICON, 0L, 0L))
#define Static_GetText(hwndCtl, lpch, cchMax) GetWindowText((hwndCtl), (lpch), (cchMax))
#define Static_GetTextLength(hwndCtl) GetWindowTextLength(hwndCtl)
#define Static_SetIcon(hwndCtl, hIcon) ((HICON)(UINT)(DWORD)SendMessage((hwndCtl), STM_SETICON, (WPARAM)(HICON)(hIcon), 0L))
#define Static_SetText(hwndCtl, lpsz) SetWindowText((hwndCtl), (lpsz))

#define SubclassDialog(hwndDlg, lpfn) ((DLGPROC)SetWindowLong(hwndDlg, DWL_DLGPROC, (LPARAM)(DLGPROC)(lpfn)))

#define SubclassWindow(hwnd, lpfn) ((WNDPROC)SetWindowLong((hwnd), GWL_WNDPROC, (LPARAM)(WNDPROC)(lpfn)))

#define SubtractRgn(hrgnResult, hrgnA, hrgnB) CombineRgn(hrgnResult, hrgnA, hrgnB, RGN_DIFF)

#define UnionRgn(hrgnResult, hrgnA, hrgnB) CombineRgn(hrgnResult, hrgnA, hrgnB, RGN_OR)

#define XorRgn(hrgnResult, hrgnA, hrgnB) CombineRgn(hrgnResult, hrgnA, hrgnB, RGN_XOR)

#ifdef __cplusplus
};
#endif
