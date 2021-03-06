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
//Local
#include "Command.hpp"
#include "../CLI.hpp"

class HelpCommand : public Command
{
public:
	void Execute(const LinkedList<ByteString> &args) const override
	{
		auto &cmds = CLI::Instance().GetCommands();
		for(const auto &kv : cmds)
		{
			stdOut << kv.value->GetName() << "\t" << kv.value->GetDescription() << '.' << endl;
		}
	}

	ByteString GetDescription() const override
	{
		return "Helps you controlling the server";
	}

	ByteString GetName() const override
	{
		return "help";
	}
};