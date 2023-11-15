#include <stdio.h>

int main(){
    #if __APPLE__
	#elif _WIN32
	#elif __linux__
        printf("entrei");
	#elif BSD
	#else
	#endif
    return 0;
}