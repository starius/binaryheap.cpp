test: test.exe
	./test.exe

test.exe: test.cpp
	$(CXX) -o $@ $<
