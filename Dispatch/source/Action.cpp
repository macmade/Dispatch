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
 * @file        Action.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <Dispatch/Action.hpp>

namespace Dispatch
{
    class Action::IMPL
    {
        public:
            
            IMPL( const std::function< void( void ) > & f );
            IMPL( const IMPL & o );
            ~IMPL();
            
            std::function< void() > _f;
    };
    
    Action::Action( const std::function< void() > & f ):
        impl( std::make_unique< IMPL >( f ) )
    {}
    
    Action::Action( const Action & o ):
        impl( std::make_unique< IMPL >( *( o.impl ) ) )
    {}
    
    Action::Action( Action && o ) noexcept:
        impl( std::move( o.impl ) )
    {}
    
    Action::~Action()
    {}
    
    Action & Action::operator =( Action o )
    {
        swap( *( this ), o );
        
        return *( this );
    }
    
    bool Action::operator ==( std::nullptr_t ) const
    {
        return this->impl->_f == nullptr;
    }
    
    bool Action::operator !=( std::nullptr_t ) const
    {
        return this->impl->_f != nullptr;
    }
    
    void Action::operator ()() const
    {
        this->execute();
    }
    
    void Action::execute() const
    {
        if( this->impl->_f != nullptr )
        {
            this->impl->_f();
        }
    }
    
    void swap( Action & o1, Action & o2 )
    {
        using std::swap;
        
        swap( o1.impl, o2.impl );
    }
    
    Action::IMPL::IMPL( const std::function< void() > & f ):
        _f( f )
    {}
    
    Action::IMPL::IMPL( const IMPL & o ):
        _f( o._f )
    {}
    
    Action::IMPL::~IMPL()
    {}
}
