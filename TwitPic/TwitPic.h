/*
  TwitPic.h - TwitPic Image Uploader for Arduino.
  Copyright (c) arms22 2009-2010. All right reserved.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
*/

#ifndef TwitPic_h
#define TwitPic_h

#include <Ethernet.h>
#include <avr/pgmspace.h>

class TwitPic
{
public:
	TwitPic();
	int upload(const char *message,
			   uint32_t (*imageTransfer)(Client*client));
	int uploadAndPost(const char *message,
					  uint32_t (*imageTransfer)(Client *client),
					  bool post = true);
	int waitResponses(void);
private:
	int read(char *buf,int size);
	int read_until_match_P(const prog_char *str);
	void print_P(const prog_char *str);
	void println_P(const prog_char *str);
	void println(const char *str);
	void println(unsigned long d);
	void println(void);
	Client client;
};

#endif
