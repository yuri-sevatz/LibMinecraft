/*
 * protocol.cpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 11/2010.
 * Copyright (c) 2010 Yuri Sevatz. All rights reserved
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

namespace libminecraft
{
    namespace classic
    {
        namespace server
        {
            Protocol::Protocol(std::iostream &stream) :
                    classic::Protocol(stream)
            {

            }

            client::Packet * const Protocol::read()
            {
                throw ProtocolException("Reading from clients not implemented yet");
            }

            void Protocol::write(server::Packet &packet)
            {
                throw ProtocolException("Writing to clients not implemented yet");
            }
        }
    }
}