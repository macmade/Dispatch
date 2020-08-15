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

XSTest( Action, CTOR_LAMBDA )
{
    int              i( 0 );
    Dispatch::Action a( [ & ] { i++; } );
    
    XSTestAssertEqual( i, 0 );
    a.execute();
    XSTestAssertEqual( i, 1 );
    a.execute();
    XSTestAssertEqual( i, 2 );
}

XSTest( Action, CTOR_FUNC )
{
    int                     i( 0 );
    std::function< void() > f1( [ & ] { i++; } );
    std::function< void() > f2( nullptr );
    Dispatch::Action        a1( f1 );
    Dispatch::Action        a2( f2 );
    
    XSTestAssertEqual( i, 0 );
    a1.execute();
    XSTestAssertEqual( i, 1 );
    a1.execute();
    XSTestAssertEqual( i, 2 );
    
    XSTestAssertNoThrow( a2.execute() );
}

XSTest( Action, CCTOR )
{}

XSTest( Action, MCTOR )
{}

XSTest( Action, OperatorAssign )
{}

XSTest( Action, OperatorEqualNull )
{}

XSTest( Action, OperatorNotEqualNull )
{}

XSTest( Action, OperatorCall )
{}

XSTest( Action, Execute )
{}

XSTest( Action, Swap )
{}
