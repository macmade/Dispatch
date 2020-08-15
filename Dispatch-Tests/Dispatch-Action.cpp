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
{
    int              i( 0 );
    Dispatch::Action a1( nullptr );
    Dispatch::Action a2( [ & ]() { i++; } );
    Dispatch::Action c1( a1 );
    Dispatch::Action c2( a2 );
    
    XSTestAssertTrue( a1 == nullptr );
    XSTestAssertTrue( c1 == nullptr );
    XSTestAssertTrue( a2 != nullptr );
    XSTestAssertTrue( c2 != nullptr );
    
    XSTestAssertNoThrow( a1.execute() );
    XSTestAssertNoThrow( c1.execute() );
    
    XSTestAssertEqual( i, 0 );
    a2.execute();
    XSTestAssertEqual( i, 1 );
    c2.execute();
    XSTestAssertEqual( i, 2 );
    a2.execute();
    XSTestAssertEqual( i, 3 );
    c2.execute();
    XSTestAssertEqual( i, 4 );
}

XSTest( Action, MCTOR )
{
    int              i( 0 );
    Dispatch::Action a1( nullptr );
    Dispatch::Action a2( [ & ]() { i++; } );
    Dispatch::Action c1( std::move( a1 ) );
    Dispatch::Action c2( std::move( a2 ) );
    
    XSTestAssertTrue( c1 == nullptr );
    XSTestAssertTrue( c2 != nullptr );
    
    XSTestAssertNoThrow( c1.execute() );
    
    XSTestAssertEqual( i, 0 );
    c2.execute();
    XSTestAssertEqual( i, 1 );
    c2.execute();
    XSTestAssertEqual( i, 2 );
}

XSTest( Action, OperatorAssign )
{
    int              i( 0 );
    Dispatch::Action a1( nullptr );
    Dispatch::Action a2( [ & ]() { i++; } );
    
    XSTestAssertTrue(  a1 == nullptr );
    XSTestAssertFalse( a2 == nullptr );
    
    a1 = a2;
    
    XSTestAssertFalse( a1 == nullptr );
    XSTestAssertFalse( a1 == nullptr );
    
    XSTestAssertEqual( i, 0 );
    a1.execute();
    XSTestAssertEqual( i, 1 );
    a2.execute();
    XSTestAssertEqual( i, 2 );
    a1.execute();
    XSTestAssertEqual( i, 3 );
    a2.execute();
    XSTestAssertEqual( i, 4 );
    
    a1 = nullptr;
    
    XSTestAssertTrue(  a1 == nullptr );
    XSTestAssertFalse( a2 == nullptr );
    
    a1.execute();
    XSTestAssertEqual( i, 4 );
    a2.execute();
    XSTestAssertEqual( i, 5 );
}

XSTest( Action, OperatorEqualNull )
{
    Dispatch::Action a1( nullptr );
    Dispatch::Action a2( []() {} );
    
    XSTestAssertTrue(  a1 == nullptr );
    XSTestAssertFalse( a2 == nullptr );
}

XSTest( Action, OperatorNotEqualNull )
{
    Dispatch::Action a1( nullptr );
    Dispatch::Action a2( []() {} );
    
    XSTestAssertFalse( a1 != nullptr );
    XSTestAssertTrue(  a2 != nullptr );
}

XSTest( Action, OperatorCall )
{
    int              i( 0 );
    Dispatch::Action a1( nullptr );
    Dispatch::Action a2( [ & ]() { i++; } );
    
    XSTestAssertNoThrow( a1() );
    
    XSTestAssertEqual( i, 0 );
    a2();
    XSTestAssertEqual( i, 1 );
    a2();
    XSTestAssertEqual( i, 2 );
}

XSTest( Action, Execute )
{
    int              i( 0 );
    Dispatch::Action a1( nullptr );
    Dispatch::Action a2( [ & ]() { i++; } );
    
    XSTestAssertNoThrow( a1() );
    
    XSTestAssertEqual( i, 0 );
    a2.execute();
    XSTestAssertEqual( i, 1 );
    a2.execute();
    XSTestAssertEqual( i, 2 );
}

XSTest( Action, Swap )
{
    int              i( 0 );
    Dispatch::Action a1( nullptr );
    Dispatch::Action a2( [ & ]() { i++; } );
    Dispatch::Action a3( [ & ]() { i += 2; } );
    
    XSTestAssertEqual( i, 0 );
    a2.execute();
    XSTestAssertEqual( i, 1 );
    a3.execute();
    XSTestAssertEqual( i, 3 );
    
    swap( a2, a3 );
    
    a2.execute();
    XSTestAssertEqual( i, 5 );
    a3.execute();
    XSTestAssertEqual( i, 6 );
    
    XSTestAssertTrue(  a1 == nullptr );
    XSTestAssertFalse( a2 == nullptr );
    
    swap( a1, a2 );
    
    XSTestAssertFalse( a1 == nullptr );
    XSTestAssertTrue(  a2 == nullptr );
}
