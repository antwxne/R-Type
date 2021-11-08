/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** Message
*/

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <vector>
#include <cstring>
#include <iostream>

#define MAX_MESSAGE_BODY_SIZE 1000

template <typename T>
struct messageHeader
{
    T messageType;
    short responseCode = 0;
	int bodySize = 0;
};

template <typename T>
class Message {
    public:
        Message()
        {

        }

        ~Message()
        {

        }

        size_t getHeaderSize() const
        {
            return sizeof(_header);
        }
        
        int getBodySize() const
        {
            return _header.bodySize;
        }

        void setResponseCode(short code)
        {
            _header.responseCode = code;
        }

        int getResponseCode() const
        {
            return _header.responseCode;
        }

        void setBodySize(int size)
        {
            _header.bodySize = size;
        }

        T getMessageType() const
        {
            return _header.messageType;
        }

        char *getBodyDataPtr()
        {
            return _body.data();
        }

        void *getHeaderPtr()
        {
            return &_header;
        }

        void resizeBody(std::size_t size)
        {
            _body.resize(size);
        }

        friend Message<T> &operator <<(Message<T> &message, T messagetype)
        {
            message._header.messageType = messagetype;
            return message;
        }

        template<typename Data>
        friend Message<T> &operator <<(Message<T> &message, const Data &data)
        {
            size_t size = message._body.size();
            message._body.resize(size + sizeof(Data));
            std::memcpy(message._body.data() + size, &data, sizeof(Data));
            message._header.bodySize = message._body.size();
            return message;
        }
        template<typename Data>
        friend Message<T> &operator >>(Message<T> &message, Data &data)
        {
            int newSize = message._body.size() - sizeof(Data);
            if (newSize < 0)
                throw std::runtime_error("Unable to unpack data");
            std::memcpy(&data, message._body.data() + newSize, sizeof(Data));
            message._body.resize(newSize);
            message._header.bodySize = message.getBodySize();
            return message;
        }
        
        void setMessageType(T type)
        {
            _header.messageType = type;
        }

    public:
        messageHeader<T> _header;
        std::vector<char> _body;

};

#endif /* !MESSAGE_HPP_ */
