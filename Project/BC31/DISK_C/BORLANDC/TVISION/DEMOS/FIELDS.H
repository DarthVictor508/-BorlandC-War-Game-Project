/*-------------------------------------------------------*/
/*                                                       */
/*   Turbo Vision 1.0                                    */
/*   Turbo Vision Forms Demo                             */
/*   Copyright (c) 1991 by Borland International         */
/*                                                       */
/*   Fields.h: Header file for Fields.cpp                */
/*             (Support header file for TVFORMS Demo)    */
/*-------------------------------------------------------*/

#if !defined( __FIELDS_H )
#define __FIELDS_H

#define Uses_TInputLine
#define Uses_TStreamable
#include <tv.h>

// Same as TInputLine, except invalid if empty 

class TKeyInputLine : public TInputLine
{

public:

    TKeyInputLine( const TRect&, int );
    virtual Boolean valid( ushort );

protected:

    TKeyInputLine( StreamableInit ) : TInputLine( streamableInit ) {};

private:

    virtual const char *streamableName() const
        { return name; }

public:

    static const char * const name;
    static TStreamable *build();
     
};


inline ipstream& operator >> ( ipstream& is, TKeyInputLine& cl )
    { return is >> (TStreamable&)cl; }
inline ipstream& operator >> ( ipstream& is, TKeyInputLine*& cl )
    { return is >> (void *&)cl; }
inline opstream& operator << ( opstream& os, TKeyInputLine& cl )
    { return os << (TStreamable&)cl; }
inline opstream& operator << ( opstream& os, TKeyInputLine* cl )
    { return os << (TStreamable *)cl; }


// Accepts only valid numeric input between Min and Max

class TNumInputLine : public TInputLine
{

public:

    TNumInputLine( const TRect&, int, long, long );
    virtual ushort dataSize();
    virtual void getData( void *);
    virtual void setData( void *);
    virtual Boolean valid( ushort );
    long min;
    long max;

protected:

    TNumInputLine( StreamableInit ) : TInputLine( streamableInit ) {};
    virtual void write( opstream& );
    virtual void *read( ipstream& );

private:

    virtual const char *streamableName() const
        { return name; }

public:

    static const char * const name;
    static TStreamable *build();

};

inline ipstream& operator >> ( ipstream& is, TNumInputLine& cl )
    { return is >> (TStreamable&)cl; }
inline ipstream& operator >> ( ipstream& is, TNumInputLine*& cl )
    { return is >> (void *&)cl; }
inline opstream& operator << ( opstream& os, TNumInputLine& cl )
    { return os << (TStreamable&)cl; }
inline opstream& operator << ( opstream& os, TNumInputLine* cl )
    { return os << (TStreamable *)cl; }

#endif  // __FIELDS_H
