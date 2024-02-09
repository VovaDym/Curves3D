# Curves3D
Design a small program in C++ that would implement the following:

Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified definitions are below). Each curve should be able to return a 3D point and a first derivative (3D vector) per parameter t along the curve.
Populate a container (e.g. vector or list) of objects of these types created in random manner with random parameters. Ensure that the container will contain objects of all supported types.
Print coordinates of points and derivatives of all curves in the container at t=PI/4.
Populate a second container that would contain only circles from the first container. Make sure the second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
Sort the second container in the ascending order of circles’ radii. That is, the first element has the smallest radius, the last - the greatest.
Compute the total sum of radii of all curves in the second container
(Additional) Split implementation into a library of curves and executable which uses API of this library.
Expectations to the implementation:

The implementation must use virtual methods.
Has neither explicit memory deallocation nor memory leaks.
Curves must be physically correct (e.g. radii must be positive).
Containers and sorting must be implemented using STL (C++ Standard Template Library).
The implementation may use constructs of C++11 or higher.
The code must compile with any compiler of your choice (gcc, Visual C++, etc).
The result should be sent via email or posted on github. The delivery must contain source code only (no compiled binaries): *.h and *.cpp files and project files, so that we can compile the result by ourselves
Curve definitions:

All curves are parametrically defined, i.e. a point is calculated using some C(t) formula.
Circle is planar in the plane XoY (i.e. all Z-coordinates are 0) and is defined by its radius.
Ellipse is planar in the plane XoY and is defined by its two radii, along X and Y axes.
Helix is spatial and is defined by its radius and step (see the figure below). It takes 2 * PI in parametric space to make a round, i.e. any point on helix satisfies the condition C(t + 2*PI) = C(t) + {0, 0, step}.


#Supported compiler: gcc, clang
#Supported OS: Linux x64
#Depends on: C++ compiler, CMake
#Build & Run

mkdir cmake-build-gcc && cd cmake-build-gcc \
 && /sbin/cmake -DCMAKE_CXX_COMPILER=/sbin/g++ -G "CodeBlocks - Unix Makefiles" .. \
 && /sbin/cmake --build . --target mcl_test \
 && ./mcl_test
