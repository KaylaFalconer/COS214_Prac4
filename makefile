# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
TARGET = taskforge

# Explicitly list only the .cpp files needed for the State pattern test
SRCS = main.cpp \
       Patient.cpp \
       State.cpp \
       Admitted.cpp \
       UnderExamination.cpp \
       InTreatment.cpp \
       Discharged.cpp \
       Vet.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run