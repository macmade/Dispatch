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
 * @header      UUID.hpp
 * @copyright   (c) 2020, Jean-David Gadina - www.xs-labs.com
 */

#ifndef DISPATCH_UUID_HPP
#define DISPATCH_UUID_HPP

#include <memory>
#include <algorithm>
#include <string>

namespace Dispatch
{
    class UUID
    {
        public:
            
            UUID();
            UUID( const UUID & o );
            UUID( UUID && o ) noexcept;
            ~UUID();
            
            UUID & operator =( UUID o );
            
            operator std::string() const;
            
            bool operator ==( const UUID & o ) const;
            bool operator !=( const UUID & o ) const;
            
            std::string string() const;
            
            friend void swap( UUID & o1, UUID & o2 );
            
            friend std::ostream & operator << ( std::ostream & os, const UUID & o );
            
        private:
            
            class IMPL;
            
            std::unique_ptr< IMPL > impl;
    };
}

#endif /* DISPATCH_UUID_HPP */
