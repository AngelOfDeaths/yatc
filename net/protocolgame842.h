//////////////////////////////////////////////////////////////////////
// Yet Another Tibia Client
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////


#ifndef __PROTOCOLGAME842_H
#define __PROTOCOLGAME842_H

#include "protocolgame84.h"

class Thing;
class Item;

class ProtocolGame842 : public ProtocolGame84
{
	public:
		virtual ~ProtocolGame842();

		virtual const char* getProtocolName() { return "Protocol842";}
		virtual ClientVersion_t getVersion() const { return CLIENT_VERSION_842; }

        virtual void onConnect();
        virtual bool parseTileAddThing(NetworkMessage& msg);
        virtual bool parsePacket(uint8_t cmd, NetworkMessage& msg);

	protected:
		ProtocolGame842(const std::string& accountname, const std::string& password, const std::string& name, bool isGM);

		virtual void checkVersion();
		friend class ProtocolConfig;
};

#endif
