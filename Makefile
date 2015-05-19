test: test-sort.exe test-string-payload.exe test-update.exe
	./test-sort.exe
	./test-string-payload.exe
	./test-update.exe

test-sort.exe: test-sort.cpp binaryheap.hpp
	$(CXX) -g -o $@ $<

test-string-payload.exe: test-string-payload.cpp binaryheap.hpp
	$(CXX) -g -o $@ $<

test-update.exe: test-update.cpp binaryheap.hpp
	$(CXX) -g -o $@ $<
