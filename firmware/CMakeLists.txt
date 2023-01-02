set(DEPENDENCIES_LIST FilesManagment StringManagment Entertainment PDF)

add_executable(StickerMaker StickerMaker.cpp)

target_include_directories(StickerMaker PUBLIC .)
add_dependencies(StickerMaker ${DEPENDENCIES_LIST})
target_link_libraries(StickerMaker PUBLIC ${DEPENDENCIES_LIST})

# libPDFNetC.so file needs to be in /usr/lib/x86_64-linux-gnu/
target_link_libraries(StickerMaker PUBLIC PDFNetC)
