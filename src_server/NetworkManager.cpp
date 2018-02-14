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
#include "NetworkManager.hpp"

//Constructor
NetworkManager::NetworkManager()
{
	this->exit = false;
}

//Public methods
void NetworkManager::Run()
{
	Datagram datagram;
	DatagramSocket datagramSocket(IPv4Address::GetLoopbackAddress(), 65000);

	stdOut << "NetworkManager successfully started." << endl;

	while(!this->exit)
	{
		if(datagramSocket.ReceivePacket(datagram))
		{
			stdOut << "NetworkManager received package with size " << datagram.GetPacketSize() << " from: ";
			if(datagram.GetSender())
			{
				stdOut << datagram.GetSender()->ToString() << ":" << datagram.GetSenderPort();
			}
			else
				stdOut << "Unknown";
			stdOut << endl;



			stdOut << "Message: " << (char *)datagram.GetBuffer() << endl;
		}
	}

	stdOut << "NetworkManager successfully shut down." << endl;
}