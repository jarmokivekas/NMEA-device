#ifndef NMEA_parse_h
#define NMEA_parse_h

//some defines to make access easier to NMEA words
#define SENTENCE_ID 0
#define	GGA_TIME 1
#define	GGA_LAT 2
#define GGA_LAT_NS 3
#define GGA_LON 4
#define	GGA_LON_EW 5
#define GGA_QUALITY 6
#define GGA_NUMSATELLITES 7
#define GGA_H_DILUTION 8
#define GGA_ANTENNA_ALT 9
#define GGA_ANTENNA_M 10
#define GGA_GEODIAL 11
#define GGA_GEODIAL_M 12
#define GGA_AGE 13
#define GGA_STATION_ID 14
#define GGA_CHECKSUM 15

void NMEA_sentence_destroy(char** n);
char** NMEA_sentence_new();
int NMEA_validate(char* NMEA_string);
void NMEA_split_words(char* NMEA_string, char** sentence);
#endif /*NMRA_parse_h*/
