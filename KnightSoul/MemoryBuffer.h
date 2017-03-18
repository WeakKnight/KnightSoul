
#ifndef __EGRET_DATA_H__
#define __EGRET_DATA_H__

#include <stdio.h>

class MemoryBuffer
{
public:

	static const MemoryBuffer Null;

public:

	MemoryBuffer();
	MemoryBuffer(const MemoryBuffer& other);
	MemoryBuffer(MemoryBuffer&& other);

	~MemoryBuffer();

	MemoryBuffer& operator= (const MemoryBuffer& other);
	MemoryBuffer& operator= (MemoryBuffer&& other);

	unsigned char* getBytes() const;

	size_t getSize() const;

	void copy(const unsigned char* bytes, size_t size);

	void fastSet(unsigned char* bytes, size_t size);

	void clear();

	bool isNull() const;
    
    unsigned read(void* dest, unsigned size);
    
    char* readFileID(); 
    
    char* readString(unsigned size);
    
    unsigned readUInt();
    
    int seek(int position);
    
    int getPosition() const
    {
        return _position;
    }
    
private:

	void move(MemoryBuffer& other);

private:
    
	unsigned char* _bytes;
	size_t _size;
    int _position;
};

#endif // __EGRET_DATA_H__








