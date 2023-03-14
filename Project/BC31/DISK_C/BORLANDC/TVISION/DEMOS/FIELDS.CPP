/*-------------------------------------------------------*/
/*                                                       */
/*   Turbo Vision 1.0                                    */
/*   Turbo Vision Forms Demo                             */
/*   Copyright (c) 1991 by Borland International         */
/*                                                       */
/*   Fields.cpp: Support source file for TVFORMS demo    */
/*-------------------------------------------------------*/

#define Uses_TStreamableClass
#define Uses_TInputLine
#define Uses_TStreamable
#define Uses_MsgBox
#include <tv.h>
__link( RInputLine )

#if !defined( __FIELDS_H )
#include "fields.h"
#endif  // __FIELDS_H

#if !defined( __STRING_H )
#include <string.h>
#endif  // __STRING_H

#if !defined( __STDLIB_H )
#include <stdlib.h>
#endif  // __STDLIB_H

#if !defined( __STRSTREAM_H )
#include <strstream.h>
#endif  // __STRSTREAM_H


// TKeyInputLine

const char *const TKeyInputLine::name = "TKeyInputLine";

TStreamable *TKeyInputLine::build()
{
    return new TKeyInputLine( streamableInit );
}

TKeyInputLine::TKeyInputLine( const TRect& bounds, int aMaxLen ) :
    TInputLine( bounds, aMaxLen )
{
}

TStreamableClass RKeyInputLine( TKeyInputLine::name,
                                  TKeyInputLine::build,
                                  __DELTA(TKeyInputLine)
                                );


Boolean TKeyInputLine::valid( ushort command )
{

    Boolean ok;

    ok = True;
    if ( ( command != cmCancel) && ( command != cmValid ) )
	if ( strlen( data ) == 0 )
            {
            select();
            messageBox("This field cannot be empty.", mfError | mfOKButton);
            ok = False;
            }
    if ( ok )
        return TInputLine::valid(command);
    else
        return False;
}

// TNumInputLine

const char * const TNumInputLine::name = "TNumInputLine";

void TNumInputLine::write( opstream& os )
{
    TInputLine::write( os );
    os << min;
    os << max;
    
}

void *TNumInputLine::read( ipstream& is )
{
    TInputLine::read( is );
    is >> min;
    is >> max;
    return this;
}

TStreamable *TNumInputLine::build()
{
    return new TNumInputLine( streamableInit );
}


TStreamableClass RNumInputLine( TNumInputLine::name,
                                  TNumInputLine::build,
                                  __DELTA(TNumInputLine)
                                );

TNumInputLine::TNumInputLine( const TRect& bounds,
			      int aMaxLen,
			      long aMin,
			      long aMax ) :
    TInputLine(bounds, aMaxLen)
{
    min = aMin;
    max = aMax;
}


ushort TNumInputLine::dataSize()
{
    return sizeof(long);
}

void TNumInputLine::getData( void *rec )
{
    *(long *)rec = atol(data);
}

void TNumInputLine::setData( void *rec )
{
    ltoa(*(long *)rec, data, 10);
    selectAll(True);
}

Boolean TNumInputLine::valid( ushort command )
{
    long value;
    Boolean ok;
    char msg[80];
    ostrstream os(msg, 80);

    ok = True;
    if ( (command != cmCancel) && (command != cmValid) )
        {
        if (strlen(data) == 0)
            strcpy(data,"0");
        value = atol(data);
        if ( (value == 0) || (value < min) || (value > max) )
            {
            select();
            os << "Number must be from " << min << " to " << max << "." << ends;
            messageBox(os.str(), mfError + mfOKButton);
            selectAll(True);
            ok = False;
            }
        }
    if (ok)
        return TInputLine::valid(command);
    else
        return False;
}
