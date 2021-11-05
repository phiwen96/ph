CXX := clang++
CXX_FLAGS := -std=c++2a -stdlib=libc++ -fmodules-ts -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=.
AR := ar
AR_FLAGS := rv

DATE := $(shell date +%F)

APP := main
PROJ := ph
PROJ_DIR := $(CURDIR)
DOCS_DIR := $(PROJ_DIR)/docs
LIB_DIR := $(PROJ_DIR)/libs/$(PROJ)
SUBMODULES_DIR := $(LIB_DIR)/submodules
# SRC_DIR := $(PROJ_DIR)/src
BUILD_DIR := $(PROJ_DIR)/build
OBJ_DIR := $(BUILD_DIR)/obj






EXE := $(BUILD_DIR)/$(APP)
LIB := $(BUILD_DIR)/libs/$(PROJ).pcm
SUBMODULES := $(wildcard $(SUBMODULES_DIR)/*.cpp)
# SRC := $(wildcard $(SUBMODULES_DIR)/*.cpp) $(LIB_DIR)/$(PROJ).cpp
# OBJ := $(SRC:$(LIB_DIR)/%.cpp=$(OBJ_DIR)/%.pcm)
__OBJ := $(subst .cpp,.pcm,$(SUBMODULES))
_OBJ := $(foreach F,$(__OBJ),$(word $(words $(subst /, ,$F)),$(subst /, ,$F)))
OBJ := $(foreach name, $(_OBJ), $(addprefix $(OBJ_DIR)/, $(name)))

PDF := $(BUILD_DIR)/docs/$(PROJ).pdf

GRAPH := $(DOCS_DIR)/*.dot

DOCS := $(PDF) $(GRAPH)
# LIB := $(OBJ_DIR)/$(APP).o 




# Create the list of directories

# DIRS = docs libs
# SRC_DIRS := $(foreach dir, $(DIRS), $(addprefix $(SRC_DIR)/, $(dir)))
_BUILD_DIRS := libs obj docs
BUILD_DIRS := $(foreach dir, $(_BUILD_DIRS), $(addprefix $(BUILD_DIR)/, $(dir)))

# $(info $$DIRS is [${DIRS}])
# $(info $$PROJ_DIR is [${PROJ_DIR}])
# $(info $$LIB_DIR is [${LIB_DIR}])
# $(info $$SRC is [${SRC}])
# $(info $$OBJ is [${OBJ}])
# $(info $$LIB is [${LIB}])
# $(info $$SUBMODULES is [${SUBMODULES}])


	

all: $(EXE) $(DOCS)



$(PDF): $(DOCS_DIR)/README.yml $(PROJ_DIR)/README.md 
	(cd $(BUILD_DIR)/docs && pandoc --filter pandoc-plot --filter pandoc-plantuml -o $@ $^)


$(EXE): $(OBJ_DIR)/$(APP).o $(SUBMODULES) $(LIB_DIR)/$(PROJ).cpp
	$(CXX) $(CXX_FLAGS) $(OBJ_DIR)/$(APP).o -o $@

$(OBJ_DIR)/$(APP).o: $(LIB)
	$(CXX) $(CXX_FLAGS) -fmodule-file=$(LIB) -c $(PROJ_DIR)/src/$(APP).cpp -o $@

$(LIB): $(OBJ) $(SUBMODULES)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(OBJ)) -c $(LIB_DIR)/$(PROJ).cpp -Xclang -emit-module-interface -o $@
 











$(OBJ_DIR)/Number.pcm: $(SUBMODULES_DIR)/Number.cpp $(OBJ_DIR)/Signed.pcm $(OBJ_DIR)/Unsigned.pcm $(OBJ_DIR)/Integer.pcm $(OBJ_DIR)/Float.pcm
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Signed.pcm: $(SUBMODULES_DIR)/Signed.cpp $(OBJ_DIR)/Convertible_to.pcm 
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Unsigned.pcm: $(SUBMODULES_DIR)/Unsigned.cpp $(OBJ_DIR)/Convertible_to.pcm 
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Float.pcm: $(SUBMODULES_DIR)/Float.cpp $(OBJ_DIR)/Convertible_to.pcm 
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Integer.pcm: $(SUBMODULES_DIR)/Integer.cpp $(OBJ_DIR)/Convertible_to.pcm 
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Convertible_to.pcm: $(SUBMODULES_DIR)/Convertible_to.cpp
	$(CXX) $(CXX_FLAGS) -c $< -Xclang -emit-module-interface -o $@











directories := $(foreach dir, $(BUILD_DIRS), $(shell [ -d $(dir) ] || mkdir -p $(dir)))


clean:
	rm -rf $(BUILD_DIR)/*
	
# rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.pcm $(BUILD_DIR)/*.pdf $(BUILD_DIR)/$(APP) $(BUILD_DIR)/*.png $(BUILD_DIR)/*.html