#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include<csignal>

using namespace std;

int socket_fd;

void signalHandler(int signalNum) {
   cout << "Server is closing" << endl;
   sleep(1);
   close(socket_fd);
   exit(signalNum);
}

int main()
{
   //signal(SIGINT, signalHandler);

   int socket_fd = socket(AF_INET,SOCK_STREAM,0);
   if(socket_fd == -1)
   {
      cout<<"SOCKET CREATE FAIL! EXIT -1"<<endl;
      exit(-1);
   }

   char* ip_addr = "127.0.0.1";
   int port = 8888;

   struct sockaddr_in addr;
   addr.sin_family = AF_INET;
   addr.sin_port = htons(port);
   addr.sin_addr.s_addr = inet_addr(ip_addr);

   int reuseaddr = 1;//解决地址已被占用问题
   setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr));

   int res = bind(socket_fd,(struct sockaddr*)&addr,sizeof(addr));
   if(res == -1)
   {
      cout<<"BIND FAIL! EXIT -1"<<endl;
      exit(-1);        
   }
   cout<<"BIND "<< ip_addr << " Port: " << port << " SUCCESS"<<endl;

   listen(socket_fd, 30);

   while(1) {

   struct sockaddr_in client;
   socklen_t len = sizeof(client);
   int fd = accept(socket_fd,(struct sockaddr*)&client, &len);
   if(fd == -1) {
      cout<<"ACCEPT FAIL! EXIT -1"<<endl;
      exit(-1);
   } else {
      pid_t pid = fork();
      if(pid==0) {
         write(fd, "Welcome to chatroom!", 20);
         char *ip = inet_ntoa(client.sin_addr);
         char *recv_msg_server = "Recieved";
         cout<<"IP: "<<ip<<" CONNECT SUCCESS"<<endl;
         char buffer[255] = {};
         while(1) {
            if(read(fd, buffer, sizeof(buffer)) > 0) {
               cout<<buffer<<endl;
               write(fd, recv_msg_server, 20);
               memset(buffer, 0, sizeof(buffer));
            }
         }
         close(fd);
         exit(0);
      }
   }
   close(fd);
 }
}