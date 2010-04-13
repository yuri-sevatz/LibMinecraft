/*
 * packet.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_CLIENT_PACKET_HPP
#define LIBMINECRAFT_CLASSIC_CLIENT_PACKET_HPP

#include "../packet.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace client
        {
            // Categorization of MinecraftPacket - packets moving from the client.
            class Packet : public classic::Packet
            {
            public:
                enum Type
                {
                    IDENT = 0x00,
                    BLOCK = 0x05,
                    POSDIR = 0x08,
                    MESSAGE = 0x0d
                };

                // Type of packet - for faster runtime type detection.
                const Type type;
            protected:
                Packet(Type t);
            };
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_CLIENT_PACKET_HPP