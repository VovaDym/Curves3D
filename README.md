# Curves3D
mkdir cmake-build-gcc && cd cmake-build-gcc \
 && /sbin/cmake -DCMAKE_CXX_COMPILER=/sbin/g++ -G "CodeBlocks - Unix Makefiles" .. \
 && /sbin/cmake --build . --target mcl_test \
 && ./mcl_test
