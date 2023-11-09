all: client

client: client.cpp window.cpp window.h
	g++ window.cpp client.cpp -o Client

clean: 
	del Client.exe