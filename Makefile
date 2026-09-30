CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2

alterdune: $(wildcard src/*.cpp) $(wildcard src/*.h)
	$(CXX) $(CXXFLAGS) src/*.cpp -o $@

clean:
	rm -f alterdune alterdune.exe
