Pasting sticker into .pdf energetic certificates
-

**Install requirements:**
```
sudo apt update
sudo apt install g++ cmake
cp PDF/libPDFNetC.so /usr/lib/x86_64-linux-gnu/
```

**Build project**:
```
mkdir build
cmake -S . -B build/
cmake --build build -t StickerMaker
```
**Run**:  `./build/firmware/StickerMaker`

StickerMaker will only work if you **copy PDFNet library into lib directory**.
Also **Sticker.jpg needs to be in current dir**.

StickerMaker should be run in dir when PDF folder exists - **not inside PDF dir**!
