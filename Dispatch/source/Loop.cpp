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
 * @file        Loop.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <Dispatch/Loop.hpp>

namespace Dispatch
{
    class Loop::IMPL
    {
        public:
            
            IMPL();
            IMPL( const IMPL & o );
            ~IMPL();
    };
    
    Loop::Loop():
        impl( std::make_unique< IMPL >() )
    {}
    
    Loop::Loop( const Loop & o ):
        impl( std::make_unique< IMPL >( *( o.impl ) ) )
    {}
    
    Loop::Loop( Loop && o ) noexcept:
        impl( std::move( o.impl ) )
    {}
    
    Loop::~Loop()
    {}
    
    Loop & Loop::operator =( Loop o )
    {
        swap( *( this ), o );
        
        return *( this );
    }
    
    void swap( Loop & o1, Loop & o2 )
    {
        using std::swap;
        
        swap( o1.impl, o2.impl );
    }
    
    Loop::IMPL::IMPL()
    {}
    
    Loop::IMPL::IMPL( const IMPL & o )
    {
        ( void )o;
    }
    
    Loop::IMPL::~IMPL()
    {}
}
