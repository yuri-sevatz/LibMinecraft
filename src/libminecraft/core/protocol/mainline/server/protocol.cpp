/*
 * protocol.cpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 04/2011.
 * Copyright (c) 2011 Yuri Sevatz. All rights reserved
 *
 * LibMinecraft is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LibMinecraft is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LibMinecraft.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "protocol.hpp"

#include <typeinfo>

#include <boost/assign/list_of.hpp>

#include "packet.hpp"
#include "packet/ping.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace server
        {
            const std::map<const std::type_info *, Protocol::TransType> Protocol::transmap =
                    boost::assign::map_list_of
                        (&typeid(packet::Ping), Protocol::PING);

            Protocol::Protocol(std::iostream & stream)
                : mainline::Protocol(stream)
            {
            }

            MCTypes::Byte Protocol::next()
            {
                return (MCTypes::Byte) stream.peek();
            }
        }
    }
}
