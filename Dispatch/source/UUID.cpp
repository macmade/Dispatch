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
 * @file        UUID.cpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#include <Dispatch/UUID.hpp>
#include <iostream>
#include <regex>

#ifdef __APPLE__
#include <uuid/uuid.h>
#endif

#ifdef _WIN32
#include <Windows.h>
#endif

namespace Dispatch
{
    class UUID::IMPL
    {
        public:
            
            IMPL();
            IMPL( const std::string & s ) noexcept( false );
            IMPL( const IMPL & o );
            ~IMPL();
            
            std::string _uuid;
    };
    
    UUID::UUID():
        impl( std::make_unique< IMPL >() )
    {}
    
    UUID::UUID( const std::string & s ) noexcept( false ):
        impl( std::make_unique< IMPL >( s ) )
    {}
    
    UUID::UUID( const UUID & o ):
        impl( std::make_unique< IMPL >( *( o.impl.get() ) ) )
    {}
    
    UUID::UUID( UUID && o ) noexcept:
        impl( std::move( o.impl ) )
    {}
    
    UUID::~UUID()
    {}
    
    UUID & UUID::operator =( UUID o )
    {
        swap( *( this ), o );
        
        return *( this );
    }
    
    bool UUID::operator ==( const UUID & o ) const
    {
        return this->impl->_uuid == o.impl->_uuid;
    }
    
    bool UUID::operator !=( const UUID & o ) const
    {
        return !operator ==( o );
    }
    
    UUID::operator std::string () const
    {
        return this->string();
    }
    
    std::string UUID::string() const
    {
        return this->impl->_uuid;
    }
    
    void swap( UUID & o1, UUID & o2 )
    {
        using std::swap;
        
        swap( o1.impl, o2.impl );
    }
    
    std::ostream & operator << ( std::ostream & os, const UUID & o )
    {
        os << o.string();
        
        return os;
    }
    
    #ifdef __APPLE__
    
    UUID::IMPL::IMPL()
    {
        uuid_t uuid;
        char   s[ 37 ];
        
        uuid_generate_random( uuid );
        memset( s, 0, sizeof( s ) );
        uuid_unparse( uuid, s );
        
        this->_uuid = s;
        
        std::transform
        (
            this->_uuid.begin(),
            this->_uuid.end(),
            this->_uuid.begin(),
            ::tolower
        );
    }
    
    #endif

    #ifdef _WIN32

    UUID::IMPL::IMPL()
    {
        ::UUID          uuid;
        unsigned char * s;

        UuidCreate( &uuid );
        UuidToStringA( &uuid, &s );

        this->_uuid = reinterpret_cast< char * >( s );

        RpcStringFreeA( &s );

        std::transform
        (
            this->_uuid.begin(),
            this->_uuid.end(),
            this->_uuid.begin(),
            ::tolower
        );
    }

    #endif
    
    UUID::IMPL::IMPL( const std::string & s ) noexcept( false )
    {
        std::regex e( "[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}", std::regex_constants::icase );
        
        if( std::regex_search( s, e ) == false )
        {
            throw std::runtime_error( "Invalid UUID string" );
        }
        
        this->_uuid = s;
        
        std::transform
        (
            this->_uuid.begin(),
            this->_uuid.end(),
            this->_uuid.begin(),
            ::tolower
        );
    }
    
    UUID::IMPL::IMPL( const IMPL & o ):
        _uuid( o._uuid )
    {}
    
    UUID::IMPL::~IMPL()
    {}
}
