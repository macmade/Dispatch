/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2020 Jean-David Gadina - www.xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        Dispatch-Interval.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <XSTest/XSTest.hpp>
#include <Dispatch.hpp>

XSTest( Interval, FromMilliseconds )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromMilliseconds(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromMilliseconds( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Milliseconds );
}

XSTest( Interval, FromSeconds )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromSeconds(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromSeconds( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
}

XSTest( Interval, FromMinutes )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromMinutes(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromMinutes( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Minutes );
}

XSTest( Interval, FromHours )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromHours(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromHours( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Hours );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Hours );
}

XSTest( Interval, FromDays )
{
    Dispatch::Interval i1 = Dispatch::Interval::FromDays(  0 );
    Dispatch::Interval i2 = Dispatch::Interval::FromDays( 42 );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Days );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Days );
}

XSTest( Interval, CTOR_Duration )
{}

XSTest( Interval, CTOR )
{
    Dispatch::Interval i1( 1, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i2( 2, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i3( 3, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i4( 4, Dispatch::Interval::Kind::Hours );
    Dispatch::Interval i5( 5, Dispatch::Interval::Kind::Days );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( i4.kind(), Dispatch::Interval::Kind::Hours );
    XSTestAssertEqual( i5.kind(), Dispatch::Interval::Kind::Days );
    
    XSTestAssertEqual( i1.value(), 1ULL );
    XSTestAssertEqual( i2.value(), 2ULL );
    XSTestAssertEqual( i3.value(), 3ULL );
    XSTestAssertEqual( i4.value(), 4ULL );
    XSTestAssertEqual( i5.value(), 5ULL );
}

XSTest( Interval, CCTOR )
{
    Dispatch::Interval i1( 1, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i2( 2, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval c1( i1 );
    Dispatch::Interval c2( i2 );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( c1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( c2.kind(), Dispatch::Interval::Kind::Seconds );
    
    XSTestAssertEqual( i1.value(), 1ULL );
    XSTestAssertEqual( c1.value(), 1ULL );
    XSTestAssertEqual( i2.value(), 2ULL );
    XSTestAssertEqual( c2.value(), 2ULL );
}

XSTest( Interval, MCTOR )
{
    Dispatch::Interval i1( 1, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i2( 2, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval m1( std::move( i1 ) );
    Dispatch::Interval m2( std::move( i2 ) );
    
    XSTestAssertEqual( m1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( m2.kind(), Dispatch::Interval::Kind::Seconds );
    
    XSTestAssertEqual( m1.value(), 1ULL );
    XSTestAssertEqual( m2.value(), 2ULL );
}

XSTest( Interval, OperatorAssign )
{
    Dispatch::Interval i1( 1, Dispatch::Interval::Kind::Milliseconds );
    Dispatch::Interval i2( 2, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i3( 3, Dispatch::Interval::Kind::Minutes );
    Dispatch::Interval i4( 4, Dispatch::Interval::Kind::Hours );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( i4.kind(), Dispatch::Interval::Kind::Hours );
    
    XSTestAssertEqual( i1.value(), 1ULL );
    XSTestAssertEqual( i2.value(), 2ULL );
    XSTestAssertEqual( i3.value(), 3ULL );
    XSTestAssertEqual( i4.value(), 4ULL );
    
    i3 = i1;
    i4 = i2;
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i3.kind(), Dispatch::Interval::Kind::Milliseconds );
    XSTestAssertEqual( i4.kind(), Dispatch::Interval::Kind::Seconds );
    
    XSTestAssertEqual( i1.value(), 1ULL );
    XSTestAssertEqual( i2.value(), 2ULL );
    XSTestAssertEqual( i3.value(), 1ULL );
    XSTestAssertEqual( i4.value(), 2ULL );
}

XSTest( Interval, Value )
{
    Dispatch::Interval i1(  0, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Seconds );

    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
}

XSTest( Interval, Kind )
{
    Dispatch::Interval i1(  0, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Minutes );

    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Minutes );
}

XSTest( Interval, Swap )
{
    Dispatch::Interval i1(  0, Dispatch::Interval::Kind::Seconds );
    Dispatch::Interval i2( 42, Dispatch::Interval::Kind::Minutes );
    
    XSTestAssertEqual( i1.value(),  0ULL );
    XSTestAssertEqual( i2.value(), 42ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Seconds );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Minutes );
    
    swap( i1, i2 );
    
    XSTestAssertEqual( i1.value(), 42ULL );
    XSTestAssertEqual( i2.value(),  0ULL );
    
    XSTestAssertEqual( i1.kind(), Dispatch::Interval::Kind::Minutes );
    XSTestAssertEqual( i2.kind(), Dispatch::Interval::Kind::Seconds );
}
