/*-------------------------------------------------------*/
/*                                                       */
/*   Turbo Vision 1.0                                    */
/*   Copyright (c) 1991 by Borland International         */
/*                                                       */
/*   Calendar.h: Header file for Calendar.cpp            */
/*-------------------------------------------------------*/

#if !defined( __CALENDAR_H )
#define __CALENDAR_H

class TCalendarView : public TView
{

public:

    TCalendarView(TRect & r);
    TCalendarView( StreamableInit ) : TView(streamableInit) { };
    virtual void handleEvent(TEvent& event);
    virtual void draw();

private:

    unsigned days, month, year;
    unsigned curDay, curMonth, curYear;

    virtual const char *streamableName() const
        { return name; }

protected:

    virtual void write( opstream& );
    virtual void *read( ipstream& );

public:

    static const char * const name;
    static TStreamable *build();
};

inline ipstream& operator >> ( ipstream& is, TCalendarView& cl )
    { return is >> (TStreamable&) cl; }
inline ipstream& operator >> ( ipstream& is, TCalendarView*& cl )
    { return is >> (void *&) cl; }

inline opstream& operator << ( opstream& os, TCalendarView& cl )
    { return os << (TStreamable&) cl; }
inline opstream& operator << ( opstream& os, TCalendarView* cl )
    { return os << (TStreamable *) cl; }


class TCalendarWindow : public TWindow
{

public:

    TCalendarWindow();
    TCalendarWindow( StreamableInit ) :
        TWindow(streamableInit), TWindowInit(&TCalendarWindow::initFrame) { };

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

inline ipstream& operator >> ( ipstream& is, TCalendarWindow& cl )
    { return is >> (TStreamable&) cl; }
inline ipstream& operator >> ( ipstream& is, TCalendarWindow*& cl )
    { return is >> (void *&) cl; }

inline opstream& operator << ( opstream& os, TCalendarWindow& cl )
    { return os << (TStreamable&) cl; }
inline opstream& operator << ( opstream& os, TCalendarWindow* cl )
    { return os << (TStreamable *) cl; }


#endif      // __CALENDAR_H
