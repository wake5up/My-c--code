LDFLAGS=-L /home/ht/ThirdPartLibForCpp/el7.x86_64/third_part/lib
DEBUGFLAGS=-g
BIN=oj_server
CC=g++

.PHONY:$(BIN)
$(BIN):oj_server.cpp
	$(CC) $^ -o $@  $(DEBUGFLAGS) $(LDFLAGS) -lctemplate -ljsoncpp -lpthread -std=c++11

.PHONY:clean
clean:
	rm -f $(BIN)
