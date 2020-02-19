#include "Message.h"
class ChatRoom;
class User {
   public:
      User(int user_id, char* username, ChatRoom* room);
      ~User();

      int uid;
      char* uname;

      void sendMessage(Message msg);
      void recvMsg(Message msg);
      void updateMsgRecord(Message msg);
      void printMsgRecord();
   private:
      ChatRoom* userRoom;
      vector<Message> msgList;
};