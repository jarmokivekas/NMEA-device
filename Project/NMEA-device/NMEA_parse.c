#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NMEA_parse.h"

//validates the NMEA string, 0=not valid, 1=valid
int NMEA_validate(char* NMEA_string){
	int checksum = 0;
	int i=0;
	NMEA_string++;//skip dollar
	//do checksum until the end of the data (*) or until the buffer is all gone
	while(*NMEA_string != '*' && i++ < NMEA_BUFFER_LEN){
		checksum ^= *NMEA_string;
		NMEA_string++;
	}
	if(i == NMEA_BUFFER_LEN) return 0;

	//skip the asterix
	NMEA_string++;
	if(checksum == strtol(NMEA_string, NULL, 16))
		return 1;
	else 
		return 0;
}

//splits a string of NMEA data into a NMEA_sentence
void NMEA_split_words(char* NMEA_string, NMEA_sentence words){
	int i=0;
	int j=0;
	do{
		//skip the comma/dollar
		NMEA_string++;
		i=0;
		while(*NMEA_string != ',' && *NMEA_string != '*'){
			words[j][i++] = *NMEA_string++;
		}
		//terminate the string
		words[j][i] = 0x00;
		j++;
	} while(*NMEA_string != '*' && j<MAX_SENTENCE_LEN);
}

//constructor for NMEA_sentence
NMEA_sentence NMEA_sentence_new(){
	NMEA_sentence words = malloc(MAX_SENTENCE_LEN * sizeof(char*));
	int i;
	for(i=0; i<MAX_SENTENCE_LEN; i++){
		words[i] = malloc(MAX_WORD_LEN * sizeof(char));
	}
	return words;
}

//overwrites all the strings with zeroes
void NMEA_sentence_empty(NMEA_sentence words){
	int i;
	for(i=0; i<MAX_SENTENCE_LEN; i++){
		memset(words[i], 0x00, MAX_WORD_LEN * sizeof(char));
	}
}

//destroys an NMEA_sentence
void NMEA_sentence_destroy(NMEA_sentence words){
	int i;
	for(i=0; i<MAX_SENTENCE_LEN; i++){
		free(words[i]);
	}
	free(words);
}

//serialize the NMEA_sentence into a string (GPGSV), make sure the string has enough space
void NMEA_serialize_GSV(NMEA_sentence words, char* serialized){
	sprintf(serialized,
		"(%s/%s)\n%s %s %s %s\n%s %s %s %s\n%s %s %s %s\n%s %s %s %s\n",
		words[2],
		words[1],

		words[4],
		words[5],
		words[6],
		words[7],

		words[8],
		words[9],
		words[10],
		words[11],

		words[12],
		words[13],
		words[14],
		words[15],

		words[16],
		words[17],
		words[18],
		words[19]
	);
}


//serialize the NMEA_sentence into a string (GPGAA), make sure the string has enough space
void NMEA_serialize_GGA(NMEA_sentence words, char* serialized){
	sprintf(serialized,
		"%s %s\n%s %s",
		words[GGA_LAT],
		words[GGA_LAT_NS],
		words[GGA_LON],
		words[GGA_LON_EW]
	);
}
