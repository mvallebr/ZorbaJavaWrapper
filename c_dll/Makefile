CXX=colorgcc

CXXFLAGS=-Wall -O2 -I/usr/include/ -fPIC -I.
OBJS=ZorbaWrapperTest.o
LIBOBJS=ZorbaWrapper.o
PROGNAME=zorbawrapper

default: clean all

all: $(LIBOBJS) $(OBJS)
	$(CXX) -shared -Wl,-soname,lib$(PROGNAME).so -o lib$(PROGNAME).so $(LIBOBJS) -L/usr/lib -L. -lzorba_simplestore 
	$(CXX) $(OBJS) -o $(PROGNAME) -L. -l$(PROGNAME)  
	ldd $(PROGNAME)

clean: 
	rm -f $(OBJS) $(LIBOBJS) $(PROGNAME) lib$(PROGNAME).so
