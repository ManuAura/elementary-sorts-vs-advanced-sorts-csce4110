
# Makefile - ElemVsAdv

# Usage:
#   make         Build the project
#   make debug   Build with AddressSanitizer and UndefinedBehaviorSanitizer
#   make clean   Remove build artifacts

# --- Toolchain ---
CXX = g++

# --- Compiler flags ---
CXXFLAGS = -std=c++17

# --- Linker flags ---
LDFLAGS =

# --- Target binary ---
TARGET = ElemVsAdv

# --- Directories ---
SRCDIR = Final_Project
OBJDIR = bin

# --- Source files ---
SRCS = $(SRCDIR)/ElemVsAdv.cpp \
       $(SRCDIR)/utils.cpp \
       $(SRCDIR)/sorts.cpp \
       $(SRCDIR)/benchmark.cpp

# --- Object and dependency files ---
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

# --- Default target ---
.PHONY: all
.DEFAULT_GOAL := all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
	@echo "Build successful: ./$(TARGET)"

# --- Compile .cpp files into object files ---
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# --- Create object directory ---
$(OBJDIR):
	mkdir -p $(OBJDIR)

# --- Include automatically generated dependencies ---
-include $(DEPS)

# --- Debug build ---
.PHONY: debug
debug:
	$(MAKE) clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer" LDFLAGS="$(LDFLAGS) -fsanitize=address,undefined" all

# --- Clean ---
.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "Cleaned."
