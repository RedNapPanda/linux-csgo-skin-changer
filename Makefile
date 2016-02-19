CXX = g++
CXXFLAGS = -m32 -std=c++11
LDFLAGS = -shared
RM = rm -f
TARGET_LIB = bin/linux-csgo-skin-changer.so

SRCS = src/main.c
OBJS = $(SRCS:.c=bin/.o)

.PHONY: all bin
all: ${TARGET_LIB}

bin:
	-mkdir bin

$(TARGET_LIB): $(OBJS)
	$(CXX) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CXX) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)