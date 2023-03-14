/*---------------------------------------------------------*/
/*                                                         */
/*   Turbo Vision 1.0                                      */
/*   Copyright (c) 1991 by Borland International           */
/*                                                         */
/*   Puzzle.h : Header file for puzzle.cpp                 */
/*---------------------------------------------------------*/

#if !defined( __PUZZLE_H )
#define __PUZZLE_H

class TPuzzleView : public TView
{

public:

    TPuzzleView(TRect& r);
    TPuzzleView( StreamableInit ) : TView(streamableInit) { };
    virtual TPalette& getPalette() const;
    virtual void handleEvent(TEvent& event);
    virtual void draw();
    void moveKey(int key);
    void moveTile(TPoint point);
    void scramble();
    void winCheck();

private:

    char board[6][6];
    int moves;
    char solved;

    virtual const char *streamableName() const
        { return name; }

protected:

    virtual void write( opstream& );
    virtual void *read( ipstream& );

public:

    static const char * const name;
    static TStreamable *build();

};

inline ipstream& operator >> ( ipstream& is, TPuzzleView& cl )
    { return is >> (TStreamable&) cl; }
inline ipstream& operator >> ( ipstream& is, TPuzzleView*& cl )
    { return is >> (void *&) cl; }

inline opstream& operator << ( opstream& os, TPuzzleView& cl )
    { return os << (TStreamable&) cl; }
inline opstream& operator << ( opstream& os, TPuzzleView* cl )
    { return os << (TStreamable *) cl; }


class TPuzzleWindow : public TWindow
{

public:

    TPuzzleWindow();
    TPuzzleWindow( StreamableInit ) :
        TWindow(streamableInit), TWindowInit(&TPuzzleWindow::initFrame) { };

private:

    virtual const char *streamableName() const
        { return name; }

protected:

    virtual void write( opstream& );
    virtual void *read( ipstream& );

public:

    static const char * const name;
    static TStreamable *build();

};

inline ipstream& operator >> ( ipstream& is, TPuzzleWindow& cl )
    { return is >> (TStreamable&) cl; }
inline ipstream& operator >> ( ipstream& is, TPuzzleWindow*& cl )
    { return is >> (void *&) cl; }

inline opstream& operator << ( opstream& os, TPuzzleWindow& cl )
    { return os << (TStreamable&) cl; }
inline opstream& operator << ( opstream& os, TPuzzleWindow* cl )
    { return os << (TStreamable *) cl; }


#endif      // __PUZZLE_H
