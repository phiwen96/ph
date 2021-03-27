# Testing library
ph_fetch (catch2)
set (self "libtest")
add_executable (${self} testlib.cpp)
target_link_libraries (${self} PRIVATE ${PROJECT_NAME} Catch2::Catch2)
ph_precompile (TARGET ${self} PRIVATE PCH ${std_pch})
add_test (NAME testlibtest COMMAND ${self}) 
ph_run ()






