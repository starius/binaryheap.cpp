test: test.exe
	./test.exe

test.exe: test.cpp binaryheap.hpp
	$(CXX) -g -o $@ $<
