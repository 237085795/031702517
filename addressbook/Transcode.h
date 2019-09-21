#pragma once
class Transcode
{
public:
	Transcode();
	~Transcode();
	char* G2U(const char* gb2312);
	char* U2G(const char* utf8);
};

