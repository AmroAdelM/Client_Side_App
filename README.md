# Client_Side_App
## Overview
- ClientConnection.cpp is using the winsock2 library for windows socket applications.
- The app is using the xml parser library pugixml(pugixml.hpp, pugixml.cpp, pugiconfig.hpp) which is a C++ XML processing library, which consists of a DOM-like interface.
## Configuration
- The xml configuration file is allowing modularity in adding more items in the list for a certain client.
- The client app is assuming the server is configured based on an xml file called client_message.xml which should be written in the same format as provided in the example:
```
<client id="1" server_ip="127.0.0.1" interval="2000">
<items>
	<item name ="Free memory"/>
	<item name ="Swapspace Used"/>
	<item name ="CPU load"/>
	<item name ="Disk space free" />
	<item name ="IO Wait"/>
</items>
</client>
```
- The client is supposed to be running all time and sending message after the interval time configured (in milliseconds).
- The client is sending messages with random values in the below format:
```
<client id= "1" server_ip=" 127.0.0.1" interval="2000">
  <item name = "Free memory" value="1"/>
  <item name = "Swapspace Used" value="7"/>
  <item name = "CPU load" value="4"/>
  <item name = "Disk space free" value="0"/>
  <item name = "IO Wait" value="9"/>
</client>
```
- The client is connecting to the local host socket, with the protocol TCP. It is better to use the SCTP protocol for more reliablity and the multihoming ability but I used TCP as an example.
- The server is sending messages with random values of the information items provided.
