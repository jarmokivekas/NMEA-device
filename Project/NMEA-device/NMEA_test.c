#include "NMEA_parse.h"
#include <stdio.h>
int main(){
	char tmp[100];

	char* teststring = "$GPGGA,103656,6011.4253,N,02154.0686,E,1,12,1.5,21.9,M,16.2,M,,*71";
	puts(teststring);
	NMEA_sentence words = NMEA_sentence_new();

	if(NMEA_validate(teststring)){
		sprintf(tmp, "NMEA data is valid");
		puts(tmp);
	}else{
		sprintf(tmp, "NMEA data is bad");
		puts(tmp);
	}
	NMEA_split_words(teststring, words);

	int i;
	for(i=0; i<MAX_SENTENCE_LEN; i++){
		sprintf(tmp, "%s", words[i]);
		puts(tmp);
	}
	char serialized[100];
	NMEA_serialize_GGA(words, serialized);
	puts(serialized);
}
