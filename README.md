# Client_Side_App
- ClientConnection.cpp is using the winsock2 library for windows socket applications.
- The client app is assuming the server is configured based on an xml file called client_message.xml which should be written in the same format as provided in the example.
- The xml configuration file is allowing modularity in adding more items in the list for a certain client.
- The app is using the xml parser library pugixml(pugixml.hpp, pugixml.cpp, pugiconfig.hpp) which is a C++ XML processing library, which consists of a DOM-like interface
- The client is supposed to be running all time and sending message after the interval time configured (in milliseconds).
- The client is connecting to the local host socket, with the protocol TCP. It is better to use the SCTP protocol for more reliablity and the multihoming ability but I used TCP as an example.
- The server is sending messages with random values of the information items provided.
