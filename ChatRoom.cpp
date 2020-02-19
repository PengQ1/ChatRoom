#include "Message.h"
#include "User.h"
#include "ChatRoom.h"

ChatRoom::ChatRoom() {}
ChatRoom::~ChatRoom() {}

void ChatRoom::registerUser(User* user) {
   users.push_back(user); 
}

void ChatRoom::setMessage(Message msg) {
   newMsg = msg;
   Notify();
}

void ChatRoom::Notify() {
   for(int i=0; i<users.size(); i++) {
      users[i] -> recvMsg(newMsg);
   }
}