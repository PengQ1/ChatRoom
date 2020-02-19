
main:main.o User.o ChatRoom.o
	g++ -o main main.o User.o ChatRoom.o

main.o:main.cpp
	g++ -o main.o -c main.cpp

User.o:User.cpp
	g++ -o User.o -c User.cpp

ChatRoom.o:ChatRoom.cpp
	g++ -o ChatRoom.o -c ChatRoom.cpp

server:server.cpp
	g++ -o server server.cpp

client:client.cpp
	g++ -o client client.cpp

clean:
	rm main.o User.o ChatRoom.o server client