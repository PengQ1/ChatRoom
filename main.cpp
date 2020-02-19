#include "User.h"
#include "ChatRoom.h"

int main() {
   ChatRoom* room = new ChatRoom();
   User* user1 = new User(1, "yinpengqi", room);
   User* user2 = new User(2, "youjingwen", room);
   Message msg1 = {user1->uid, user1->uname, "2020-02-12", "Today is a nice day!"};
   Message msg2 = {user2->uid, user2->uname, "2020-02-13", "Tomorrow is also a nice day!"};
   user1 -> sendMessage(msg1);
   user2 -> sendMessage(msg2);
   delete room;
   delete user1;
   delete user2;
}
