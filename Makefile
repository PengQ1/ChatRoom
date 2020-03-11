
main:main.o User.o ChatRoom.o
	g++ -o main main.o User.o ChatRoom.o

main.o:main.cpp
	g++ -o main.o -c main.cpp

User.o:User.cpp
	g++ -o User.o -c User.cpp

ChatRoom.o:ChatRoom.cpp
	g++ -o ChatRoom.o -c ChatRoom.cpp

DataOpsUtils.o:DataOpsUtils.cpp
	export DYLD_LIBRARY_PATH=/usr/lib/mysql/lib64
	g++ -o DataOpsUtils.o -c DataOpsUtils.cpp -I deps/mysql/include/jdbc -I deps/boost

utils.o:utils.cpp
	g++ -o utils.o -c utils.cpp

server:server.cpp Utils.o DataOpsUtils.o
	g++ -o server server.cpp utils.o DataOpsUtils.o -I deps/mysql/include/jdbc -I deps/boost -L deps/mysql/lib64 -lmysqlcppconn

client:client.cpp
	g++ -o client client.cpp

clean:
	rm main.o User.o ChatRoom.o server client