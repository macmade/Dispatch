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
 * @file        Dispatch-UUID.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <XSTest/XSTest.hpp>
#include <Dispatch.hpp>
#include <sstream>

XSTest( UUID, CTOR )
{
    Dispatch::UUID u1;
    Dispatch::UUID u2;
    
    XSTestAssertTrue( u1.string().length() > 0 );
    XSTestAssertTrue( u2.string().length() > 0 );
    XSTestAssertNotEqual( u1, u2 );
}

XSTest( UUID, CTOR_String )
{
    {
        XSTestAssertThrow(   Dispatch::UUID( "foobar" ), std::runtime_error );
        XSTestAssertNoThrow( Dispatch::UUID( "123e4567-e89b-12d3-a456-426655440000" ) );
        XSTestAssertNoThrow( Dispatch::UUID( "123E4567-E89B-12D3-A456-426655440000" ) );
    }
    
    {
        Dispatch::UUID u1( "123e4567-e89b-12d3-a456-426655440000" );
        Dispatch::UUID u2( "123E4567-E89B-12D3-A456-426655440000" );
        Dispatch::UUID u3( "123E4567-E89B-12D3-A456-426655440001" );
        
        XSTestAssertEqual(    u1, u2 );
        XSTestAssertNotEqual( u1, u3 );
        XSTestAssertNotEqual( u2, u3 );
    }
}

XSTest( UUID, CCTOR )
{
    Dispatch::UUID u1;
    Dispatch::UUID u2( u1 );
    
    XSTestAssertEqual( u1, u2 );
}

XSTest( UUID, MCTOR )
{
    Dispatch::UUID  u1;
    std::string     s1( u1 );
    Dispatch::UUID  u2( std::move( u1 ) );
    
    XSTestAssertEqual( u2.string(), s1 );
}

XSTest( UUID, Operator_Assign )
{
    Dispatch::UUID u1;
    Dispatch::UUID u2;
    
    XSTestAssertNotEqual( u1, u2 );
    
    u2 = u1;
    
    XSTestAssertEqual( u1, u2 );
}

XSTest( UUID, Operator_Equal )
{
    Dispatch::UUID u1;
    Dispatch::UUID u2;
    Dispatch::UUID u3( u1 );
    
    XSTestAssertTrue(  u1 == u3 );
    XSTestAssertFalse( u1 == u2 );
    
    XSTestAssertTrue(  u1.string() == u3.string() );
    XSTestAssertFalse( u1.string() == u2.string() );
}

XSTest( UUID, Operator_NotEqual )
{
    Dispatch::UUID u1;
    Dispatch::UUID u2;
    Dispatch::UUID u3( u1 );
    
    XSTestAssertTrue(  u1 != u2 );
    XSTestAssertFalse( u1 != u3 );
    
    XSTestAssertTrue(  u1.string() != u2.string() );
    XSTestAssertFalse( u1.string() != u3.string() );
}

XSTest( UUID, Operator_String )
{
    XSTestAssertTrue( static_cast< std::string >( Dispatch::UUID() ).length() == 36 );
}

XSTest( UUID, String )
{
    XSTestAssertTrue( Dispatch::UUID().string().length() == 36 );
}

XSTest( UUID, Swap )
{
    Dispatch::UUID  u1;
    Dispatch::UUID  u2;
    std::string     s1( u1 );
    std::string     s2( u2 );
    
    XSTestAssertEqual( u1.string(), s1 );
    XSTestAssertEqual( u2.string(), s2 );
    
    swap( u1, u2 );
    
    XSTestAssertEqual( u1.string(), s2 );
    XSTestAssertEqual( u2.string(), s1 );
}

XSTest( UUID, Print )
{
    std::stringstream ss;
    Dispatch::UUID    u;
    
    ss << u;
    
    XSTestAssertTrue( ss.str().length() == 36 );
}
