#include<cstdlib> for rand and system
#include<time.h> for time
#include<cstdint> and #include<limits> for std::numeric_limits<std::int32_t>::max() instead of INT_MAX
Do not use nullptr
Do not use to_string
compile using "make main"
clean using "make clean"
add "filename.o" as we add classes that contain .cpp AND .h files only to the OBJS variable in the makefile.