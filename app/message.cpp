#include <iostream>
using namespace std; 

// solo entre amigos. 
class Message {
    private: 
        string _message; 
        bool _read; 
        string _shippingDate; 

    public: 
        Message(string message, bool read): _message(message), _read(read) {}

        ~Message(); 
}; 

class Inbox {
    private: 
        string _messagesSent; 
        string _messagesReceived; 
}; 