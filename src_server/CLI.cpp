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
//Class header
#include "CLI.hpp"
//Commands
#include "CLICommands/ExitCommand.hpp"
#include "CLICommands/HelpCommand.hpp"
//Definitions
#define ADD_CMD(cmdClass) {cmdClass *c = new cmdClass; this->commands.Insert(c->GetName(), c);}

//Constructor
CLI::CLI()
{
	this->exit = false;

	ADD_CMD(ExitCommand);
	ADD_CMD(HelpCommand);
}

//Destructor
CLI::~CLI()
{
	for(const auto kv : this->commands)
	{
		delete kv.value;
	}
}

//Private methods
void CLI::ParseCommandLine(const ByteString &line, LinkedList<ByteString> &commandLine)
{
	commandLine = line.Split(' ');
}

//Public methods
void CLI::Run()
{
	ByteString line;
	LinkedList<ByteString> commandLine;

	TextReader inputReader(stdIn, TextCodecType::ASCII);

	stdOut << "OpenSpace server successfully launched." << endl << "Welcome, Admin..." << endl;

	while(!this->exit)
	{
		line = inputReader.ReadASCII_Line();
		this->ParseCommandLine(line, commandLine);
		if(commandLine.IsEmpty())
			continue;
		auto it = this->commands.Find(commandLine[0]);
		if(it == this->commands.end())
		{
			stdOut << "Illegal command. Type 'help' to get help." << endl;
			continue;
		}

		commandLine.Remove(0u);

		(*it).value->Execute(commandLine);
	}
}