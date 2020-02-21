CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/sm
MAINSRC := state_machine.cpp
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
TESTSOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT) ! -name $(MAINSRC))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -std=c++11 # -Wall
LIB := -L lib -ldl
INC := -I include -I include/fpga_lib/myRIO

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR)/* $(TARGET)"; $(RM) -r $(BUILDDIR)/* $(TARGET)

cleanall:
	@echo " Cleaning all..."; 
	@echo " $(RM) -r $(BUILDDIR)/* $(TARGET)"; $(RM) -r $(BUILDDIR)/* $(TARGET)
	@echo " $(RM) -r $(BUILDDIR)/* bin/logging"; $(RM) -r $(BUILDDIR)/* bin/logging
	@echo " $(RM) -r $(BUILDDIR)/* bin/network"; $(RM) -r $(BUILDDIR)/* bin/network
	@echo " $(RM) -r $(BUILDDIR)/* bin/sensor"; $(RM) -r $(BUILDDIR)/* bin/sensor

# Tests
logging:
	$(CC) $(CFLAGS) test/logging_test.cpp $(INC) $(TESTSOURCES) $(LIB) -o bin/logging

network:
	$(CC) $(CFLAGS) test/pod_network_test.cpp $(INC) $(TESTSOURCES) $(LIB) -o bin/network

sensor:
	$(CC) $(CFLAGS) test/sensor_test.cpp $(INC) $(TESTSOURCES) $(LIB) -o bin/sensor

# Spikes
example:
	$(CC) $(CFLAGS) spikes/example.cpp $(INC) $(LIB) -o bin/example

.PHONY: clean
.PHONY: cleanall
