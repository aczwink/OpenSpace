/*
 * Copyright (c) 2017 Amir Czwink (amir130@hotmail.de)
 *
 * This file is part of OpenSpace.
 *
 * OpenSpace is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenSpace is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenSpace.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <ACStdLib.hpp>
using namespace ACStdLib;
//Local
#include "CLICommands/Command.hpp"

class CLI
{
private:
	//Members
	bool exit;
	Map<ByteString, Command *> commands;

	//Constructor
	CLI();

	//Methods
	void ParseCommandLine(const ByteString &line, LinkedList<ByteString> &commandLine);

public:
	//Destructor
	~CLI();

	//Methods
	void Run();

	//Inline
	inline void Exit()
	{
		this->exit = true;
	}

	inline const Map<ByteString, Command *> &GetCommands() const
	{
		return this->commands;
	}

	//Functions
	static inline CLI &Instance()
	{
		static CLI cli;

		return cli;
	}
};