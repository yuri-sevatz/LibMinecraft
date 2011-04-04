/*
 * serverlevelchunkpkt.cpp
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

#include "serverlevelchunkpkt.hpp"

#include "../minecraftstream.hpp"

#include <ios>

namespace libminecraft
{
    const MinecraftTypes::Byte ServerLevelChunkPkt::id = ServerPkt::LEVELCHUNK;

    ServerLevelChunkPkt::ServerLevelChunkPkt() :
            ServerPkt(ServerPkt::LEVELCHUNK)
    {

    }

    void ServerLevelChunkPkt::read(std::istream &stream)
    {
        MinecraftStream::getSignedShort(stream, length);

        if (length < 0 || length > 1024)
            throw ProtocolException("Invalid chunk size detected while receiving map");

        // Make room for length bytes.
        data.resize(length);

        // Save the data.
        stream.read((char *) &(data.front()), length);

        // Ignore the trailing characters in the byte array.
        if (length < 1024)
            stream.ignore(1024 - length);

        // Read the percentage complete...
        MinecraftStream::getByte(stream, percent);
    }

    void ServerLevelChunkPkt::write(std::ostream &os) const
    {
        throw ProtocolException("XXX: Not Implemented");
    }

    void ServerLevelChunkPkt::toReadable(std::ostream &os) const
    {
        os << "Length: " << length << "\n";
/*
        os << "Data: " << std::ios::hex;
        os.write((const char *) &data.front(), data.size());
        os << std::ios::dec << "\n";
*/
        os << "Percent: " << (unsigned int) percent << std::endl;
    }
}
