#pragma once

#define MSG_WELCOME				"Welcome to the Complex Calculator from Johannes and Maximilian. You have following options:"
#define MSG_HELP				"\x1B[31m0 = Exit\n1 = Calculation\n2 = Generates XML\n3 = Runs all Tests\033[0m\t\t"

#define MSG_ERROR_INPUT			"Error: cannot operate with your inputs! Error in with "
	#define MSG_ERROR_NUMBERS	"reading numbers"
	#define MSG_ERROR_OPERATION "fetching the operation"
	#define MSG_ERROR_OUTPUT	"outputting result"
	#define MSG_ERROR_XML		"writing the XML file"

#define MSG_SEPERATOR			"-------------------------------------------------"

#define MSG_READ_NUMBER			"Please input the number. Either format cartesian(1+7i) or polar (7.1e^(i81.8))!"
#define MSG_READ_FORMAT			"Please input the format. Either cartesian or polar!"
#define MSG_READ_OPERATION		"Please input the operation. Either + - * /!"