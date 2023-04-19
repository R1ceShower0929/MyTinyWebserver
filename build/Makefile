CXX = g++
CFLAGS = -std=c++14 -O2 -Wall -g

TARGET = server
OBJS = ../code/pool/*.cpp ../code/http/*.cpp ../code/server/*.cpp ../code/buffer/*.cpp ../code/main.cpp ../code/log/*.cpp ../code/timer/*.cpp
all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o ../bin/$(TARGET) -pthread -lmysqlclient

clean:
	rm -rf ../bin/$(OBJS) $(TARGET)