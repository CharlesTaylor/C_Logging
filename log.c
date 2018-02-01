
#include "log.h"

int main(){

	LOGGER_INIT();
	LOGGER_LOG(LOG_LEVEL_VERBOSE,"Test %d\n",1);
	LOGGER_FREE();


	LOGGER_INIT_FROM_STREAM(stdout);	

	LOGGER_LOG(LOG_LEVEL_DEBUG,"Test %d\n",2);
	LOGGER_LOG(LOG_LEVEL_VERBOSE,"Test %d\n",3);
	LOGGER_LOG(LOG_LEVEL_NORMAL,"Test %d\n",4);

	LOGGER_FREE_FROM_STREAM();
	return 0;
}
