file(GLOB_RECURSE HEADER_LIST "*.h")

add_library(PDF STATIC ${HEADER_LIST})
set_target_properties(PDF PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(PDF PUBLIC .)
