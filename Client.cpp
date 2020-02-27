#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string>

#include<unistd.h>
#include<iostream>
#ifdef _WIN32
#include <WinSock.h>
#endif

#ifndef _WIN32
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#endif



using namespace std;

int main(int argc, char** argv)
{
   // Create a socket
   // Actually it apply a socket from our system
   int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
   if(socket_fd == -1)
   {
      cout<<"SOCKET CREATE FAIL! EXIT -1"<<endl;
      exit(-1);
   }

   // Get the server ip address and port from input
   char* serverAddr = argv[1];
   int port = atoi(argv[2]);
   cout<<"Connect IP Address: "<<serverAddr<<endl;
   cout<<"Port: "<<port<<endl; 

   // connect
   struct sockaddr_in addr;
   addr.sin_family = AF_INET;
   addr.sin_addr.s_addr = inet_addr(serverAddr);
   addr.sin_port = htons(port);
   int res = connect(socket_fd,(struct sockaddr*)&addr,sizeof(addr));
   
   if(res == -1)
   {
      cout<<"CONNECT FAILED! EXIT -1："<<endl;
      exit(-1);
   } else {
      cout<<"Connect Success!"<<endl;
   }

   char buff[100] = {};
   char msg[100] = {};
   const char* recv_msg = "Recieved";
   int msg_len=100;
   while(1) {
      if(read(socket_fd, buff, sizeof(buff)) > 0) {
         if(strcmp(buff, recv_msg) == 0) {
            cout<<"从服务器接收到消息: "<< buff <<endl;
         }
      }

      cout<<"请发送你的消息：";
      cin.getline(msg, msg_len);
      write(socket_fd, msg, sizeof(msg));
      cout<<"成功发送内容："<< msg <<endl;
      memset(msg,'\0',sizeof(msg));
   }

   close(socket_fd);

   return 0;
}