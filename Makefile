test: test-sort.exe
	./test-sort.exe

test-sort.exe: test-sort.cpp binaryheap.hpp
	$(CXX) -g -o $@ $<
