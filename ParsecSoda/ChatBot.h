#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include "parsec.h"
#include "Stringer.h"
#include "GamepadClient.h"

#include "Commands/ACommand.h"	
#include "Commands/CommandBan.h"
#include "Commands/CommandBonk.h"
#include "Commands/CommandFF.h"
#include "Commands/CommandGameId.h"
#include "Commands/CommandGuests.h"
#include "Commands/CommandDefaultMessage.h"
#include "Commands/CommandIpFilter.h"
#include "Commands/CommandKick.h"
#include "Commands/CommandListCommands.h"
#include "Commands/CommandMic.h"
#include "Commands/CommandMirror.h"
#include "Commands/CommandName.h"
#include "Commands/CommandOwners.h"
#include "Commands/CommandPads.h"
#include "Commands/CommandPrivate.h"
#include "Commands/CommandPublic.h"
#include "Commands/CommandQuit.h"
#include "Commands/CommandSetConfig.h"
#include "Commands/CommandSpeakers.h"
#include "Commands/CommandUnban.h"
#include "Commands/CommandVideoFix.h"

#define BONK_CHANCE 50
#define BOT_GUESTID 0

class ChatBot
{
public:
	//ChatBot();

	ACommand * identifyUserDataMessage(const char * msg);

	const uint32_t getLastUserId() const;
	void setLastUserId(const uint32_t lastId);

	//bool isTrollMessage(const char* msg, ParsecGuest guest, std::string* replyMsg);
	//bool isSetConfigMessage(const char* msg, std::string* replyMsg);
	//bool isPadsLimitMessage(const char* msg, ParsecGuest* guests, int guestCount, GamepadClient * padClient, std::string* replyMsg);
	//bool isMicVolumeMessage(const char* msg, std::string* replyMsg, float *volume);
	//bool isSpeakersVolumeMessage(const char* msg, std::string* replyMsg, float *volume);
	//bool isQuitMessage(const char* msg, std::string* replyMsg);
	//bool isDX11RefreshMessage(const char* msg, std::string* replyMsg);
	//void processCommandsListMessage(const char* msg, bool isAdmin, std::string *replyMsg);
	//bool tryBonkMessage(const char *msg, ParsecGuest sender, ParsecGuest * guests, int guestCount, std::string* replyMsg);
	//bool tryKickMessage(const char* msg, ParsecGuest sender, ParsecGuest* guests, int guestCount, std::string* replyMsg, ParsecGuest * target);
	//bool tryBanMessage(const char* msg, ParsecGuest sender, ParsecGuest* guests, int guestCount, std::string* replyMsg, ParsecGuest* target);
	//bool tryUnbanMessage(const char* msg, ParsecGuest sender, ParsecGuest* guests, int guestCount, std::string* replyMsg, ParsecGuest* target);

	/**
	* Handles a possible config chat message.
	*
	* @param msg Raw input message.
	* @param config Results of chat bot operation will be stored at this config, invalid messages will leave it unchanged.
	* @param replyMsg A reply message from the chat bot to be displayed in chat.
	* @return true if success (configs were changed or applied). false if some error ocurred (no changes).
	*/
	//bool processHostConfigMessage(const char * msg, ParsecHostConfig * config, std::string * replyMsg);

	/**
	* Gets the message ready to be broadcasted in chat: adds a header with username and proper formatting.
	* @param guest The guest who sent this message.
	* @param msg Raw input message.
	* @return Formatted message to display in chat.
	*/
	const std::string formatGuestMessage(ParsecGuest guest, const char* msg, bool isAdmin = false);

	const std::string formatGuestConnection(ParsecGuest guest, bool isAdmin = false);

	const std::string formatBannedGuestMessage(ParsecGuest guest);

private:
	//bool isVolumeMessage(const char* msg, std::string* replyMsg, float *volume, const char* command, const char* alias);

	static bool msgStartsWith(const char* msg, const char* pattern);
	static bool msgIsEqual(const char* msg, const char* pattern);

	//bool findUser(uint32_t targetUserID, ParsecGuest* guests, int guestCount, ParsecGuest *targetUser);
	//bool findUser(std::string targetUserName, ParsecGuest* guests, int guestCount, ParsecGuest *targetUser);

	uint32_t _lastUserId = 0;

	//Dice _dice;
};

