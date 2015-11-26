CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wshadow -Werror -fopenmp -O3 -DNDEBUG

#INCLUDES =
#LDFLAGS =
#LIBS =

# blas
#INCLUDES += -I/usr/lib64/atlas/include/
#LDFLAGS += -L/usr/lib64/atlas/
#LIBS += -lcblas -latlas

# likwid
#CXXFLAGS += -DUSE_LIKWID -pthread
#INCLUDES += -I/usr/local/likwid-3.1.2/include/
#LDFLAGS += -L/usr/local/likwid-3.1.2/lib/
#LIBS += -llikwid

TARGET = EllipticSolver_V4.0
OBJS = $(TARGET).o

all: $(TARGET)

$(TARGET): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(TARGET).o: $(TARGET).cpp Makefile
	$(CXX) -c $(CXXFLAGS) $(TARGET).cpp

clean:
	@$(RM) -rf *.o $(TARGET)
