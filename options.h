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

#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <string>
#include "gamecontent/enums.h"
#include "net/enum.h"

enum enginelist_t {
	ENGINE_SDL = 0, // software renderer
	ENGINE_OPENGL = 1,
	ENGINE_DIRECTX = 2
};

extern std::string hotkeystrs[36];

struct Hotkey
{
	bool isText;
	bool sendAuto;
	std::string text;
	struct {
		uint16_t itemid;
		uint8_t type;
		bool useOnSelf;
		bool useOnTarget;
		bool useXHairs;
	} item;
};

class Options
{
public:
	Options();
	~Options();

	void Save();
	void Load();

	// [window]
	bool os_cursor;
	std::string skin;

	// [login]
	std::string account, password;
	bool saveAccount;

	// [client]
	enginelist_t engine;
	std::string motdtext;
	int motdnum;
	bool ui_compat;
	std::string lang;

	// [general]
	bool classiccontrol;
	bool autochase;
	bool showhints;
	bool shownames;
	bool showtexteffects;

	// [graphics]
	int w, h, bpp;
	bool fullscreen;
	int maxfps;
	bool stretchGameWindow;
	bool smoothstretch;
	int showlighteffects;

	// [console]
	bool infomsgs;
	bool eventmsgs;
	bool statusmsgs;
	bool timestamps;
	bool levels;
	bool privatemsgs;

	// [network]
	std::string server;
	int port;
    bool otkey;
	ClientVersion_t protocol;

    int overrideversion;

	// [hotkeys]
	Hotkey hotkeys[36];

	// [game]
	int battlemode;
	int chasemode;
	bool safemode;

	// [gui]
	bool inventoryCollapsed;
	int skillsh;	// -1 = closed, 0 = collapsed
	int battleh;	// -1 = closed, 0 = collapsed
	int viph;		// -1 = closed, 0 = collapsed
	int consoleh;	// always 150 + 18 for now.
	bool hideofflineVIP;

	// [not saved]
	SpeakClasses_t speaktype;
};


extern Options options;
#endif

