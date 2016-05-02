CXX = g++ -std=c++14 -Ilib/
OBJS = common control decode image realtime

all: runtime parrot_app_test

runtime: $(OBJS)

$(OBJS):
	$(CXX) -c lib/$@.cpp -obuild/$@.o

parrot_app_test:
	$(CXX) -c test/test.cpp -obuild/test.o
	$(CXX) build/*.o -obuild/parrot_app_test 
clean:
	rm -rf build/*

