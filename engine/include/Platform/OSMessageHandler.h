#pragma once

class IOSMessageHandler
{
public:
	/*
		ProcessOSMessageLoop
		Purpose: Overridable method to process operating system's message loop
		Returns:
			- Returns true if the message loop was properly handled
			- Returns false if the operating system has instructed our program to cleanup and terminate
	*/
	virtual bool ProcessOSMessageLoop() = 0;
};
