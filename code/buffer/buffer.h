#ifndef BUFFER_H
#define BUFFER_H

#include <assert.h>
#include <vector>
#include<atomic>
#include<string>
#include <cstring>
#include <unistd.h>  // write
#include <sys/uio.h> //readv
#include<iostream>

class Buffer{
public:
    Buffer(int initBuffSize = 1024);
    ~Buffer() = default;

    size_t ReadableBytes()const;    //读指针到写指针的大小
    size_t WritableBytes()const;    //写指针到buffer.size的大小
    size_t PrependBytes()const;

    const char* Peek()const;    //当前读的位置
    void EnsureWritable(size_t len);  //确保可写
    void HasWritten(size_t len); //写指针偏移

    void Retrieve(size_t len);  //读指针偏移
    void RetrieveUntil(const char* end);    //读，直到end位置
    void RetrieveAll(); //清空buffer，读写归零

    std::string RetrieveAllToStr(); //后面数据转str并清空

    const char* BeginWriteConst() const;    //当前可写位置
    char* BeginWrite(); //同上

    void Append(const std::string& str);
    void Append(const char* str, size_t len);
    void Append(const void* data, size_t len);
    void Append(const Buffer& buff);

    ssize_t ReadFd(int fd, int* Errno); //读数据
    ssize_t WriteFd(int fd, int* Errno);    //写数据

private:
    char* BeginPtr_();
    const char* BeginPtr_()const;
    void MakeSpace_(size_t len);

    std::vector<char> buffer_;  //具体装数据的
    //为何已经有互斥量了，还要引入std::atomic呢，这是因为互斥量保护的数据范围比较大，我们期望更小范围的保护。并且当共享数据为一个变量时，原子操作std::atomic效率更高。
    std::atomic<size_t> readPos_;   //读的位置
    std::atomic<size_t> writePos_;  //写的位置
};

#endif