#include "Message.h"

class User;

class ChatRoom {
   vector<class User*> users;
   Message newMsg;
   public:
   ChatRoom();
   ~ChatRoom();
   void Notify();
   void registerUser(User* user);
   void setMessage(Message msg);
};