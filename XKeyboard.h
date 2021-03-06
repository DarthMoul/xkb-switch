// xkeyboard.h
// Interface for a class to get keyboard layout information and change layouts
// Copyright (C) 2008 by Jay Bromley <jbromley@gmail.com>
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option)
// any later version.

#ifndef XKEYBOARD_H
#define XKEYBOARD_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>

namespace kb {

typedef std::vector<std::string> string_vector;

class XKeyboard
{
public:
	Display* _display;
	int _deviceId;
	XkbDescRec* _kbdDescPtr;

	XKeyboard();
	~XKeyboard();

	// Gets the current layout
	int get_group() const;

	// Sets the layout
	void set_group(int num);

	// Returns keyboard layout string
	std::string get_kb_string();

	// Waits for kb event
	void wait_event();
};

// Parses keyboard string returned by get_kb_stirng. ns are symbols to ignore,
// normally the result of nonsyms()
string_vector parse1(const std::string& symbols, const string_vector& ns);
string_vector parse2(const std::string& symbols, const string_vector& ns);

// Symbols to be ignored by the parser
inline string_vector nonsyms()
{
	string_vector nonsyms;
	nonsyms.push_back("group");
	nonsyms.push_back("inet");
	nonsyms.push_back("ctr");
	nonsyms.push_back("pc");
	nonsyms.push_back("ctrl");
	nonsyms.push_back("capslock");
	nonsyms.push_back("compose");
	nonsyms.push_back("terminate");
	nonsyms.push_back("eurosign");
	return nonsyms;
}

}

#endif

