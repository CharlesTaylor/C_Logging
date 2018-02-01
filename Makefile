all:
	gcc log.c -o log_test -DLOG_LEVEL=LOG_LEVEL_VERBOSE -DLOG_FILENAME=\"test_log.txt\"
