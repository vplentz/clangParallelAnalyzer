# clangParallelAnalyzer
To use this plugin you have to follow this steps:

Step 0: Obtaining Clang
mkdir ~/clang-llvm && cd ~/clang-llvm
git clone http://llvm.org/git/llvm.git
cd llvm/tools
git clone http://llvm.org/git/clang.git
cd clang/tools
git clone http://llvm.org/git/clang-tools-extra.git extra

Step 1: Obtain CMake
cd ~/clang-llvm
git clone https://github.com/martine/ninja.git
cd ninja
git checkout release
./bootstrap.py
sudo cp ninja /usr/bin/

cd ~/clang-llvm
git clone https://github.com/Kitware/CMake
cd CMake
git checkout next
./bootstrap
make
sudo make install

Step 3: Build Clang
cd ~/clang-llvm
mkdir build && cd build
cmake -G Ninja ../llvm -DLLVM_BUILD_TESTS=ON  # Enable tests; default is off.
ninja
ninja check       # Test LLVM only.
ninja clang-test  # Test Clang only.
ninja install

Step 4: Set Clang as your compiler
cd ~/clang-llvm/build
ccmake ../llvm

The second command will bring up a GUI for configuring Clang. You need to set the entry for CMAKE_CXX_COMPILER. Press 't' to turn on advanced mode. Scroll down to CMAKE_CXX_COMPILER, and set it to /usr/bin/clang++, or wherever you installed it. Press 'c' to configure, then 'g' to generate CMake’s files.

Step 5: Add our plugin to Clang
cd ~/clang-llvm/llvm/tools/clang
mkdir tools/extra/loop-convert
echo 'add_subdirectory(reduction)' >> tools/extra/CMakeLists.txt
vim tools/extra/reduction/CMakeLists.txt

CMakeLists.txt should have the following contents:
set(LLVM_LINK_COMPONENTS support)

add_clang_executable(loop-convert
  Reduction.cpp
  )
target_link_libraries(loop-convert
  clangTooling
  clangBasic
  clangASTMatchers
  )

Step 6: Run our plugin
cd ~/clang-llvm/build
ninja
./bin/reduction your-test-file.cpp --

And this is it, this should work!!

more at:
https://clang.llvm.org/docs/LibASTMatchersTutorial.html
