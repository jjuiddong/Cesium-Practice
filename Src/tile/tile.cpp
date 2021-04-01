
#include <iostream>
#include <fstream>
#include <string>
#include "./lerc/include/Lerc_c_api.h"
#include "./lerc/include/Lerc_types.h"
#pragma comment(lib, "./lerc/bin/windows/Lerc.lib")

using namespace std;

typedef unsigned char BYTE;

std::pair<int, int> ReadCntZImage(const string &fileName);
__int64 FileSize(const string &fileName);


int main()
{
	// not work
	//esri::cCntZImage img;
	//img.Read("0.bil");

	const string fileName = "arc-9-435-205.bil";
	const std::pair<int,int> res = ReadCntZImage(fileName);
	if (res.first < 0)
		return 0;
	const int fileSize = (int)FileSize(fileName);
	if (fileSize < 0)
		return 0;

	BYTE *lercBlob = new BYTE[(unsigned int)fileSize];
	ifstream ifs(fileName, ios::binary);
	if (!ifs.is_open())
		return 0;
	ifs.read((char*)lercBlob, fileSize);
	const int w = res.first;
	const int h = res.second;
	float *zImg3 = new float[w * h];
	memset(zImg3, 0, w * h * sizeof(float));
	lerc_status hr(0);
	hr = lerc_decode(lercBlob, fileSize, nullptr, 1, w, h, 1
		, (unsigned int)LercNS::DataType::dt_float, (void*)zImg3);

	delete[] lercBlob;
	delete[] zImg3;
	return 1;
}


// return cntz image width, height
// return {-1, -1} error
std::pair<int, int> ReadCntZImage(const string &fileName)
{
	using namespace std;
	ifstream ifs(fileName, ios::binary);
	if (!ifs.is_open())
		return { -1, -1 };

	char format[11] = { 0, };
	ifs.read(format, 10);

	if (string("CntZImage ") != format)
		return { -1, -1 };

	int version, type, width, height;
	double maxZErrorInFile = 0;

	ifs.read((char*)&version, sizeof(version));
	ifs.read((char*)&type, sizeof(type));
	ifs.read((char*)&width, sizeof(width));
	ifs.read((char*)&height, sizeof(height));
	ifs.read((char*)&maxZErrorInFile, sizeof(maxZErrorInFile));
	if ((version != 11) || (type != 8))
		return { -1, -1 };
	return {width, height};
}

__int64 FileSize(const string &fileName)
{
	struct __stat64 buf;
	if (_stat64(fileName.c_str(), &buf) != 0)
		return -1; // error, could use errno to find out more
	return buf.st_size;
}
