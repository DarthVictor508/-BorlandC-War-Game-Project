/*---------------------------------------------------------------------*/
/*                                                                     */
/*   Turbo Vision 1.0                                                  */
/*   Turbo Vision Forms Demo main source file.                         */
/*   Copyright (c) 1991 by Borland International                       */
/*                                                                     */
/*---------------------------------------------------------------------*/
/*                                                                     */
/* This Turbo Vision application uses forms to enter and edit data     */
/* in a collection. Two data files, PHONENUM.TVF and PARTS.TVF, are    */
/* provided and can be loaded using this application's File|Open menu. */
/* The .TVF files were created by GENFORMS.MAK, which compiles and     */
/* and runs GENFORM.CPP. You can create additional data files by       */
/* copying and modifying GENPARTS.H or GENPHONE.H and then             */
/* incorporating your new header into GENFORM.CPP.                     */
/*                                                                     */
/*---------------------------------------------------------------------*/

#define Uses_TKeys
#define Uses_TApplication
#define Uses_TEvent
#define Uses_TRect
#define Uses_TDialog
#define Uses_TStaticText
#define Uses_TButton
#define Uses_TMenuBar
#define Uses_TSubMenu
#define Uses_TMenuItem
#define Uses_TStatusLine
#define Uses_TStatusItem
#define Uses_TStatusDef
#define Uses_TDeskTop
#define Uses_TChDirDialog
#define Uses_TFileDialog
#define Uses_MsgBox
#define Uses_TDisplay
#define Uses_TScreen
#define Uses_TEditor
#define Uses_TMemo
#include <tv.h>
__link( RResourceCollection )
__link( RButton )
__link( RCheckBoxes )
__link( RInputLine )
__link( RLabel )
__link( RMenuBar )
__link( RRadioButtons )
__link( RFrame )
__link( REditor )
__link( RMemo )

#if !defined( __STRING_H )
#include  <string.h>
#endif // __STRING_H

#if !defined( __STDLIB_H )
#include <stdlib.h>
#endif // __STDLIB_H

#if !defined( __FORMCMDS_H )
#include "formcmds.h"
#endif // __FORMCMDS_H

#if !defined( __LISTDLG_H )
#include "listdlg.h"
#endif // __LISTDLG_H

extern TPoint shadowSize;
const MAXSIZE = 150;


class TFormApp : public TApplication
{
public:

    TFormApp();

    void handleEvent( TEvent& Event);
    static TMenuBar *initMenuBar( TRect r);
    static TStatusLine *initStatusLine( TRect r);
    void changeDir();
    void dosShell();
    void openListDialog();
};

// TFormApp
TFormApp::TFormApp() :
    TApplication(),
    TProgInit(&TFormApp::initStatusLine,
              &TFormApp::initMenuBar,
              &TFormApp::initDeskTop)
{
    TEvent event;

    // Display about box
    event.what = evCommand;
    event.message.command = cmAboutBox;
    putEvent(event);
}

void TFormApp::changeDir()
{
    TView *d = validView( new TChDirDialog( 0, hlChangeDir ) );

    if( d != 0 ) {
        deskTop->execView( d );
        destroy(d);
    }
}

void TFormApp::dosShell()
{
    suspend();
    system("cls");
    cout << "Type EXIT to return...";
    system( getenv( "COMSPEC"));
    resume();
    redraw();
}

void TFormApp::openListDialog()
{
    TFileDialog *d;
    char *fileName;
    TDialog *listEditor;
    char errorMsg[MAXSIZE];
    extern Boolean fileExists( char *);
    char name[MAXFILE];
    char drive[MAXDRIVE];
    char dir[MAXDIR];
    char ext[MAXEXT];

    d = new TFileDialog("*.TVF", "Open File",
           "~N~ame", fdOpenButton, hlOpenListDlg);
    if (validView(d) != NULL)
        {
        if (deskTop->execView(d) != cmCancel)
            {
            fileName = new char[MAXPATH];
            d->getFileName(fileName);
            if (!fileExists(fileName))
                {
                strcpy(errorMsg, "Cannot find file ");
                strcat(errorMsg, fileName);
                messageBox(errorMsg, mfError | mfOKButton);
                }
            else
                {
                // If listEditor exists, select it; otherwise, open new one
                fnsplit(fileName, drive, dir, name, ext);
                listEditor = (TDialog *)message(deskTop, evBroadcast, cmEditingFile, fileName);
                if (listEditor == NULL)
                    deskTop->insert(validView(new TListDialog(fileName, name)));
                else listEditor->select();
                }
            delete fileName;
            }
        destroy(d);
        }
}

void TFormApp::handleEvent(TEvent& event)
{
    ushort newMode;
    char aboutMsg[80]; 

    TApplication::handleEvent(event);
    if (event.what == evCommand)
        {
        switch (event.message.command)
            {
            case cmListOpen:
                openListDialog();
                break;
            case cmChgDir:
                changeDir();
                break;
            case cmDosShell:
                dosShell();
                break;
            case cmAboutBox:
                strcpy(aboutMsg, "\x3Turbo Vision C++ 1.0\n\n\x3Turbo Vision Forms Demo");
                messageBox(aboutMsg, mfInformation | mfOKButton);
                break;
            case cmVideoMode:
                newMode = TScreen::screenMode ^ TDisplay::smFont8x8;
                if ((newMode & TDisplay::smFont8x8) != 0)
                    shadowSize.x = 1;
                else
                    shadowSize.x = 2;
                setScreenMode(newMode);
                break;

            default:
                return; 
            }
        clearEvent(event);
        }
}

TMenuBar *TFormApp::initMenuBar( TRect r)
{

    r.b.y = r.a.y + 1;
    return new TMenuBar(r,
      *new TSubMenu( "~\xF0~", hcNoContext ) +
        *new TMenuItem( "~V~ideo mode", cmVideoMode, kbNoKey, hcNoContext, "" ) +
             newLine() +
        *new TMenuItem( "~A~bout...", cmAboutBox, kbNoKey, hcNoContext ) +
      *new TSubMenu( "~F~ile", hcNoContext) +
        *new TMenuItem( "~O~pen...", cmListOpen, kbF3, hcNoContext, "F3" ) +
        *new TMenuItem( "~S~ave", cmListSave, kbF2, hcNoContext, "F2" ) +
             newLine() +
        *new TMenuItem( "~C~hange directory...", cmChgDir, kbNoKey, hcNoContext ) +
        *new TMenuItem( "~D~OS shell", cmDosShell, kbNoKey, hcNoContext ) +
        *new TMenuItem( "E~x~it", cmQuit, kbAltX, hcNoContext, "Alt-X" ) +
      *new TSubMenu( "~W~indow", hcNoContext ) +
        *new TMenuItem( "~M~ove", cmResize, kbCtrlF5, hcNoContext, "Cntl-F5") +
        *new TMenuItem( "~N~ext", cmNext, kbF6, hcNoContext, "F6") +
        *new TMenuItem( "~P~rev", cmPrev, kbShiftF6, hcNoContext, "Shift-F6") +
        *new TMenuItem( "~C~lose", cmClose, kbAltF3, hcNoContext, "Alt-F3")
      );
}

TStatusLine *TFormApp::initStatusLine( TRect r )
{
    r.a.y = r.b.y - 1;
    return new TStatusLine( r,
    *new TStatusDef( 0, 0xFFFF ) +
      *new TStatusItem( "~F2~ Save", kbF2, cmListSave ) +
      *new TStatusItem( "~F3~ Open", kbF3, cmListOpen ) +
      *new TStatusItem( "~F10~ Menu", kbF10, cmMenu) +
      *new TStatusItem( "", kbCtrlF5, cmResize )
      );
}

int main()
{
    TFormApp formApp;

    formApp.run();
    return 0;
}
