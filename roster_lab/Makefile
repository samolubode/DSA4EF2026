CXX ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic
CPPFLAGS ?= -Iinclude

TARGET := roster_lab
SOURCES := src/main.cpp src/CourseRoster.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) include/CourseRoster.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) -o $@

clean:
	rm -f $(TARGET) $(TARGET).exe
