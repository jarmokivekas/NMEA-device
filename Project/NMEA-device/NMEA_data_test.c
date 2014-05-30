#include "NMEA_parse.h"
#include <stdio.h>
#define MAX_STRLEN 120
void do_a_print(char* NMEA_string);
NMEA_sentence words;
FILE* raw_data;
int main(){
	raw_data = fopen("/home/juha/Documents/Ell-i_hackathon/data", "r");
	if (raw_data==NULL) perror ("Error opening file");
	words = NMEA_sentence_new();
	char received_string[MAX_STRLEN];
	int char_count = 0;
	char t;
	while(1){
		t = fgetc(raw_data);
		if(t != '\n' && char_count < MAX_STRLEN){
			received_string[char_count] = t;
			char_count++;
		}else{
			received_string[char_count] = 0x00;
			char_count = 0;
			do_a_print(received_string);
		}
	}
}

void do_a_print(char* NMEA_string){
	if(NMEA_validate(NMEA_string)){
		//printf("NMEA data is valid\n");
	}else{
		//printf("NMEA data is bad\n");
		return;
	}
	NMEA_sentence_empty(words);
	NMEA_split_words(NMEA_string, words);
	//printf("%s\n", words[0]);
	if(!strcmp(words[0], "GPGGA")){

		/*
		int i;
		for(i=0; i<MAX_SENTENCE_LEN; i++){
			printf("%s", words[i]);
		}
		*/

		char serialized[100];
		NMEA_serialize(words, serialized);
		puts(serialized);
	}
}

