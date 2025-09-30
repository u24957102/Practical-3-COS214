# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
COVERAGE_FLAGS = --coverage -fprofile-arcs -ftest-arcs

# Source files (ChatRoom.cpp removed - methods are inline in ChatRoom.h)
SOURCES = Users.cpp CtrlCat.cpp Dogorithm.cpp \
          SendMessageCommand.cpp LogMessageCommand.cpp \
          Command.cpp

# Main files
TESTING_MAIN = TestingMain.cpp
DEMO_MAIN = DemoMain.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)
TESTING_OBJECTS = $(TESTING_MAIN:.cpp=.o)
DEMO_OBJECTS = $(DEMO_MAIN:.cpp=.o)

# Coverage files
COVERAGE_OBJECTS = $(SOURCES:.cpp=.gcov.o)
TESTING_COVERAGE_OBJECTS = $(TESTING_MAIN:.cpp=.gcov.o)

# Executable names
TESTING_EXEC = testing_main
DEMO_EXEC = demo_main
COVERAGE_EXEC = coverage_main

# Default target
all: $(TESTING_EXEC)

# Build testing executable
$(TESTING_EXEC): $(OBJECTS) $(TESTING_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build demo executable (if exists)
demo: $(OBJECTS) $(DEMO_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(DEMO_EXEC) $^

# Build coverage executable
$(COVERAGE_EXEC): $(COVERAGE_OBJECTS) $(TESTING_COVERAGE_OBJECTS)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) -o $@ $^

# Pattern rule for regular object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pattern rule for coverage object files
%.gcov.o: %.cpp
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) -c $< -o $@

# Run the testing executable
run: $(TESTING_EXEC)
	./$(TESTING_EXEC)

# Run demo (if exists)
run_demo: demo
	./$(DEMO_EXEC)

# Generate coverage report
coverage: $(COVERAGE_EXEC)
	./$(COVERAGE_EXEC)
	gcov $(SOURCES) $(TESTING_MAIN)
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '/usr/*' --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
	@echo "Coverage report generated in coverage_report/index.html"

# Clean build files
clean:
	rm -f $(OBJECTS) $(TESTING_OBJECTS) $(DEMO_OBJECTS)
	rm -f $(COVERAGE_OBJECTS) $(TESTING_COVERAGE_OBJECTS)
	rm -f $(TESTING_EXEC) $(DEMO_EXEC) $(COVERAGE_EXEC)
	rm -f *.gcda *.gcno *.gcov coverage.info
	rm -rf coverage_report

# Valgrind memory check
valgrind: $(TESTING_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TESTING_EXEC)

# Phony targets
.PHONY: all demo run run_demo coverage clean valgrind

# Help target
help:
	@echo "Available targets:"
	@echo "  make          - Build testing executable"
	@echo "  make run      - Build and run testing executable"
	@echo "  make demo     - Build demo executable"
	@echo "  make run_demo - Build and run demo executable"
	@echo "  make coverage - Generate coverage report"
	@echo "  make valgrind - Run valgrind memory check"
	@echo "  make clean    - Remove all build files"
	@echo "  make help     - Show this help message"