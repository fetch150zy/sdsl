#! bash
rm -rf build
mkdir build && cd build
cmake ..
cmake --build . -- VERBOSE=1
ctest --parallel 4 --rerun-failed --output-on-failure
# ctest -T memcheck
