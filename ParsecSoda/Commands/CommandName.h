#pragma once

#include "parsec.h"
#include "ACommandStringArg.h"

class CommandName : public ACommandStringArg
{
public:
	const COMMAND_TYPE type() const { return COMMAND_TYPE::NAME; }

	void run(const char * msg, ParsecHostConfig* config)
	{
		std::string roomName;
		if ( !ACommandStringArg::run(msg, "/name ", &roomName) )
		{
			_replyMessage = "[ChatBot] | Usage: /name <roomname>\nExample: /name Let's Play Gauntlet!\0";
			return;
		}

		// Replaces \ + n with \n
		size_t index = 0;
		while (true)
		{
			index = roomName.find("\\n", index);
			if (index == std::string::npos) break;

			roomName.replace(index, 2, "\n");
			index++;
		}

		strcpy_s(config->name, roomName.c_str());

		_replyMessage = std::string() + "[ChatBot] | Room name changed:\n" + roomName + "\0";
	}
};
