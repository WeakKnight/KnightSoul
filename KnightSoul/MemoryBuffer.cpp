
#include "MemoryBuffer.h"
#include <assert.h>
#include <stdlib.h>
#include <memory.h>
//MemoryBuffer

const MemoryBuffer MemoryBuffer::Null;

MemoryBuffer::MemoryBuffer():
_bytes(nullptr),
_size(0),
_position(0)
{
}

MemoryBuffer::MemoryBuffer(MemoryBuffer&& other):
_bytes(nullptr),
_size(0),
_position(0)
{
	move(other);
}

MemoryBuffer::MemoryBuffer(const MemoryBuffer& other):
_bytes(nullptr),
_size(0),
_position(0)
{
	copy(other._bytes, other._size);
}

MemoryBuffer::~MemoryBuffer()
{
	clear();
}

MemoryBuffer& MemoryBuffer::operator= (const MemoryBuffer& other)
{
	copy(other._bytes, other._size);
	return *this;
}

MemoryBuffer& MemoryBuffer::operator= (MemoryBuffer&& other)
{
	move(other);
	return *this;
}

void MemoryBuffer::move(MemoryBuffer& other)
{
	_bytes = other._bytes;
	_size = other._size;
    _position = other._position;
	other._bytes = nullptr;
	other._size = 0;
    other._position = 0;
}

bool MemoryBuffer::isNull() const
{
	return (_bytes == nullptr || _size == 0);
}

unsigned char* MemoryBuffer::getBytes() const
{
	return _bytes;
}

size_t MemoryBuffer::getSize() const
{
	return _size;
}

void MemoryBuffer::copy(const unsigned char* bytes, size_t size)
{
	clear();

	if (size > 0)
	{
		_size = size;
		_bytes = (unsigned char*)(new unsigned char[size]);
		memcpy(_bytes, bytes, _size);
	}
}

void MemoryBuffer::fastSet(unsigned char* bytes, size_t size)
{
	_bytes = bytes;
	_size = size;
}

void MemoryBuffer::clear()
{
	if (_bytes != nullptr)
	{
		delete _bytes;
		_bytes = nullptr;
	}

	_size = 0;
    _position = 0;
}

unsigned MemoryBuffer::read(void* dest, unsigned size)
{
    if (size + _position > _size)
        size = _size - _position;
    if (!size)
        return 0;
    
    unsigned char* srcPtr = &_bytes[_position];
    unsigned char* destPtr = (unsigned char*)dest;
    _position += size;
    
    unsigned copySize = size;
    while (copySize >= sizeof(unsigned))
    {
        *((unsigned*)destPtr) = *((unsigned*)srcPtr);
        srcPtr += sizeof(unsigned);
        destPtr += sizeof(unsigned);
        copySize -= sizeof(unsigned);
    }
    if (copySize & sizeof(unsigned short))
    {
        *((unsigned short*)destPtr) = *((unsigned short*)srcPtr);
        srcPtr += sizeof(unsigned short);
        destPtr += sizeof(unsigned short);
    }
    if (copySize & 1)
        *destPtr = *srcPtr;
    
    return size;
}

char* MemoryBuffer::readFileID()
{
    char* ret = new char[4];
    read(&ret[0], 4);
    return ret;
}

char* MemoryBuffer::readString(unsigned int size)
{
    char* ret = new char[size];
    read(&ret[0], size);
    return ret;
}
    
unsigned MemoryBuffer::readUInt()
{
    unsigned ret;
    read(&ret, sizeof ret);
    return ret;
}

int MemoryBuffer::seek(int position)
{
    if (position > _size)
        position = _size;
    
    _position = position;
    return _position;
}
