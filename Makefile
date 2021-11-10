

CXX := clang++
CXX_FLAGS = -std=c++2a -stdlib=libc++ -fmodules-ts -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=.
CXX_TEST_FLAGS = -std=c++2a -stdlib=libc++ -fmodules-ts -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=.
AR := ar
AR_FLAGS := rv

# $(info $$CXX_FLAGS is [${CXX_FLAGS}])

DATE := $(shell date +%F)

APP := main
PROJ := ph
PROJ_DIR := $(CURDIR)
DOCS_DIR := $(PROJ_DIR)/docs
LIB_DIR := $(PROJ_DIR)/libs/$(PROJ)
SUBMODULES_DIR := $(LIB_DIR)/submodules
BUILD_DIR := $(PROJ_DIR)/build
OBJ_DIR := $(BUILD_DIR)/obj
TESTS_DIR := $(BUILD_DIR)/tests
TESTS_SOURCE_DIR := $(PROJ_DIR)/tests


EXE := $(BUILD_DIR)/$(APP)
LIB := $(BUILD_DIR)/libs/$(PROJ).pcm
SUBMODULES := $(wildcard $(SUBMODULES_DIR)/*.cpp)

__OBJ := $(subst .cpp,.pcm,$(SUBMODULES))
_OBJ := $(foreach F,$(__OBJ),$(word $(words $(subst /, ,$F)),$(subst /, ,$F)))
OBJ := $(foreach name, $(_OBJ), $(addprefix $(OBJ_DIR)/, $(name)))

__TESTS := $(subst .cpp,.pcm,$(SUBMODULES))
_TESTS := $(foreach F,$(__TESTS),$(word $(words $(subst /, ,$F)),$(subst /, ,$F)))
TESTS := $(foreach name, $(_TESTS), $(addprefix $(TESTS_DIR)/, $(name)))

DOCS_PDF := $(BUILD_DIR)/docs/$(PROJ).pdf
DOCS_ARCHITECTURE_PDF := $(BUILD_DIR)/docs/Architecture.pdf
DOCS_ARCHITECTURE_PNG := $(BUILD_DIR)/docs/Architecture.png
DOCS_ARCHITECTURE := $(DOCS_ARCHITECTURE_PDF) $(DOCS_ARCHITECTURE_PNG)
DOCS := $(DOCS_PDF) $(DOCS_ARCHITECTURE)

_BUILD_DIRS := libs obj docs tests
BUILD_DIRS := $(foreach dir, $(_BUILD_DIRS), $(addprefix $(BUILD_DIR)/, $(dir)))

ifeq ($(Testing), true)
CXX_FLAGS += -DTesting
MAYBE_TESTS := $(OBJ_DIR)/Test.pcm
endif

ifeq ($(Testing), false)
CXX_FLAGS += -DRelease
MAYBE_TESTS := 
endif

$(info $$Testing is [${Testing}])
$(info $$MAYBE_TESTS is [${MAYBE_TESTS}])


# $(info $$DIRS is [${DIRS}])
# $(info $$PROJ_DIR is [${PROJ_DIR}])
# $(info $$LIB_DIR is [${LIB_DIR}])
# $(info $$SRC is [${SRC}])
# $(info $$OBJ is [${OBJ}])
# $(info $$LIB is [${LIB}])
# $(info $$SUBMODULES is [${SUBMODULES}])
# $(info $$TESTS is [${TESTS}])


	

all: $(EXE) $(LIB) $(DOCS)



$(DOCS_PDF): $(DOCS_DIR)/Ph.yml $(PROJ_DIR)/README.md
	(cd $(BUILD_DIR)/docs && pandoc --filter pandoc-plot --filter pandoc-plantuml -o $@ $^)

$(DOCS_ARCHITECTURE_PDF): $(DOCS_DIR)/Architecture.dot
	dot -Tpdf $< -o $@

$(DOCS_ARCHITECTURE_PNG): $(DOCS_DIR)/Architecture.dot
	dot -Tpng $< -o $@






$(EXE): $(OBJ_DIR)/$(APP).o $(SUBMODULES) $(LIB_DIR)/$(PROJ).cpp
	$(CXX) $(CXX_FLAGS) $(OBJ_DIR)/$(APP).o -o $@

$(OBJ_DIR)/$(APP).o: $(PROJ_DIR)/src/$(APP).cpp $(LIB)
	$(CXX) $(CXX_FLAGS) -fmodule-file=$(LIB) -c $(PROJ_DIR)/src/$(APP).cpp -o $@

$(LIB): $(LIB_DIR)/$(PROJ).cpp $(OBJ)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(OBJ)) -c $(LIB_DIR)/$(PROJ).cpp -Xclang -emit-module-interface -o $@
 




# $(TESTS): $(PROJ_DIR)/tests/%.cpp
# 	$(CXX) $(CXX_FLAGS) $< -o $@




$(OBJ_DIR)/Range.pcm: $(SUBMODULES_DIR)/Range.cpp $(OBJ_DIR)/Iterator.pcm $(OBJ_DIR)/Pointer.pcm $(OBJ_DIR)/Size.pcm $(OBJ_DIR)/Bool.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Iterator.pcm: $(SUBMODULES_DIR)/Iterator.cpp $(OBJ_DIR)/Input_iterator.pcm  $(OBJ_DIR)/Output_iterator.pcm  $(OBJ_DIR)/Forward_iterator.pcm  $(OBJ_DIR)/Bidirectional_iterator.pcm  $(OBJ_DIR)/Random_access_iterator.pcm $(OBJ_DIR)/Iterator_traits.pcm $(OBJ_DIR)/Incrementable.pcm $(OBJ_DIR)/Decrementable.pcm $(OBJ_DIR)/Pointer.pcm $(OBJ_DIR)/Size.pcm $(OBJ_DIR)/Bool.pcm $(OBJ_DIR)/Reference.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Random_access_iterator.pcm: $(SUBMODULES_DIR)/Random_access_iterator.cpp $(OBJ_DIR)/Bidirectional_iterator.pcm $(OBJ_DIR)/Iterator_traits.pcm $(OBJ_DIR)/Incrementable.pcm $(OBJ_DIR)/Decrementable.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Bidirectional_iterator.pcm: $(SUBMODULES_DIR)/Bidirectional_iterator.cpp $(OBJ_DIR)/Forward_iterator.pcm $(OBJ_DIR)/Iterator_traits.pcm $(OBJ_DIR)/Incrementable.pcm $(OBJ_DIR)/Decrementable.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Forward_iterator.pcm: $(SUBMODULES_DIR)/Forward_iterator.cpp $(OBJ_DIR)/Output_iterator.pcm $(OBJ_DIR)/Iterator_traits.pcm $(OBJ_DIR)/Input_iterator.pcm $(OBJ_DIR)/Incrementable.pcm $(OBJ_DIR)/Decrementable.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Output_iterator.pcm: $(SUBMODULES_DIR)/Output_iterator.cpp $(OBJ_DIR)/Iterator_traits.pcm $(OBJ_DIR)/Reference.pcm $(OBJ_DIR)/Incrementable.pcm $(OBJ_DIR)/Decrementable.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Input_iterator.pcm: $(SUBMODULES_DIR)/Input_iterator.cpp $(OBJ_DIR)/Iterator_traits.pcm $(OBJ_DIR)/Reference.pcm $(OBJ_DIR)/Const.pcm $(OBJ_DIR)/Incrementable.pcm $(OBJ_DIR)/Decrementable.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Iterator_traits.pcm: $(SUBMODULES_DIR)/Iterator_traits.cpp $(OBJ_DIR)/Reference.pcm $(OBJ_DIR)/Const.pcm $(OBJ_DIR)/Pointer.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Number.pcm: $(SUBMODULES_DIR)/Number.cpp $(OBJ_DIR)/Signed.pcm $(OBJ_DIR)/Unsigned.pcm $(OBJ_DIR)/Integer.pcm $(OBJ_DIR)/Float.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Size.pcm: $(SUBMODULES_DIR)/Size.cpp $(OBJ_DIR)/Convertible_to.pcm $(OBJ_DIR)/Test.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Signed.pcm: $(SUBMODULES_DIR)/Signed.cpp $(OBJ_DIR)/Convertible_to.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Unsigned.pcm: $(SUBMODULES_DIR)/Unsigned.cpp $(OBJ_DIR)/Convertible_to.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Float.pcm: $(SUBMODULES_DIR)/Float.cpp $(OBJ_DIR)/Convertible_to.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Integer.pcm: $(SUBMODULES_DIR)/Integer.cpp $(OBJ_DIR)/Convertible_to.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Bool.pcm: $(SUBMODULES_DIR)/Bool.cpp $(OBJ_DIR)/Convertible_to.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Convertible_to.pcm: $(SUBMODULES_DIR)/Convertible_to.cpp $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Pointer.pcm: $(SUBMODULES_DIR)/Pointer.cpp $(OBJ_DIR)/Incrementable.pcm $(OBJ_DIR)/Decrementable.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Const_ref.pcm: $(SUBMODULES_DIR)/Const_ref.cpp $(OBJ_DIR)/Reference.pcm $(OBJ_DIR)/Const.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Reference.pcm: $(SUBMODULES_DIR)/Reference.cpp $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Const.pcm: $(SUBMODULES_DIR)/Const.cpp $(OBJ_DIR)/Test.pcm $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Forward.pcm: $(SUBMODULES_DIR)/Forward.cpp $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Incrementable.pcm: $(SUBMODULES_DIR)/Incrementable.cpp $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Decrementable.pcm: $(SUBMODULES_DIR)/Decrementable.cpp $(MAYBE_TESTS)
	$(CXX) $(CXX_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Test.pcm: $(SUBMODULES_DIR)/Test.cpp $(OBJ_DIR)/Assert.pcm 
	$(CXX) $(CXX_TEST_FLAGS) $(addprefix -fmodule-file=, $(filter-out $<, $^)) -c $< -Xclang -emit-module-interface -o $@

$(OBJ_DIR)/Assert.pcm: $(SUBMODULES_DIR)/Assert.cpp
	$(CXX) $(CXX_TEST_FLAGS) -c $< -Xclang -emit-module-interface -o $@













directories := $(foreach dir, $(BUILD_DIRS), $(shell [ -d $(dir) ] || mkdir -p $(dir)))


clean:
	rm -rf $(BUILD_DIR)/*
	
# rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.pcm $(BUILD_DIR)/*.pdf $(BUILD_DIR)/$(APP) $(BUILD_DIR)/*.png $(BUILD_DIR)/*.html