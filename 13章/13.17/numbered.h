#pragma once
#include<iostream>
class numbered
{
public:
	numbered() {
		mysn = unique++;
	}
	numbered(const numbered&n):mysn(unique++){};
	int mysn;
	static int unique;
};

int numbered::unique = 10;

