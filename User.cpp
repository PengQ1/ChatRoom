#include "Message.h"
#include "ChatRoom.h"
#include "User.h"

User::User(int user_id, char* username, ChatRoom* room) {
   uid = user_id;
   uname = username;
   userRoom = room;
   userRoom -> registerUser(this);
}

User::~User() {}

void User::sendMessage(Message msg) {
   userRoom -> setMessage(msg);
}

void User::recvMsg(Message msg) {
   updateMsgRecord(msg);
}

void User::updateMsgRecord(Message msg) {
   msgList.push_back(msg);
   printMsgRecord();
}

void User::printMsgRecord() {
   for(int i=0; i<msgList.size(); i++) {
      cout << "Time: " << msgList[i].time;
      cout << " | User: " << msgList[i].user;
      cout << " | " << msgList[i].content;
      cout << endl;
   }
}