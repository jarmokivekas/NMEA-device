#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LEN 20
#define MAX_WORD_LEN 10
#define NMEA_BUFFER_LEN 1024

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

void NMEA_split_words(char* NMEA_string, char** words){
	int i=0;
	int j=0;
	char* word;
	do{
		word = words[j++];
		//skip the comma/dollar
		NMEA_string++;
		i=0;
		while(*NMEA_string != ',' && *NMEA_string != '*'){
			word[i++] = *NMEA_string++;
		}
		//terminate the string
		word[i] = 0x00;
	} while(*NMEA_string != '*');
}

char** NMEA_sentence_new(){
	char** words = malloc(MAX_SENTENCE_LEN * sizeof(char*));
	int i;
	for(i=0; i<MAX_SENTENCE_LEN; i++){
		words[i] = malloc(MAX_WORD_LEN * sizeof(char));
	}
	return words;
}

void NMEA_sentence_destroy(char** words){
	int i;
	for(i=0; i<MAX_SENTENCE_LEN; i++){
		free(words[i]);
	}
	free(words);
}
