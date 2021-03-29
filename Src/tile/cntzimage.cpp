
#include "cntzimage.h"

using namespace esri;


cCntZImage::cCntZImage()
	: m_width(0)
	, m_height(0)
{
}

cCntZImage::~cCntZImage()
{
}


// read cntzimage file
bool cCntZImage::Read(const string &fileName)
{
	using namespace std;
	ifstream ifs(fileName, ios::binary);
	if (!ifs.is_open())
		return 0;

	char format[11] = { 0, };
	ifs.read(format, 10);

	if (string("CntZImage ") != format)
		return false;

	int version, type, width, height;
	double maxZErrorInFile = 0;

	ifs.read((char*)&version, sizeof(version));
	ifs.read((char*)&type, sizeof(type));
	ifs.read((char*)&width, sizeof(width));
	ifs.read((char*)&height, sizeof(height));
	ifs.read((char*)&maxZErrorInFile, sizeof(maxZErrorInFile));

	if ((version != 11) || ((eType)type != eType::CNT_Z))
		return false;

	if (width > 20000 || height > 20000)
		return false;

	if (!Resize((uint)width, (uint)height))
		return false;

	bool isSuccess = true;
	for (int iPart = 0; iPart < 2; ++iPart)
	{
		bool zPart = iPart ? true : false;    // first cnt part, then z part
		int numTilesVert = 0, numTilesHori = 0, numBytes = 0;
		float maxValInImg = 0;

		ifs.read((char*)&numTilesVert, sizeof(numTilesVert));
		ifs.read((char*)&numTilesHori, sizeof(numTilesHori));
		ifs.read((char*)&numBytes, sizeof(numBytes));
		ifs.read((char*)&maxValInImg, sizeof(maxValInImg));

		// no tiling for this cnt partc
		if (!zPart && numTilesVert == 0 && numTilesHori == 0)
		{
			if (numBytes == 0)    // cnt part is const
			{
				sCntZ* dstPtr = &m_src[0];
				for (int i = 0; i < height; i++)
					for (int k = 0; k < width; k++)
					{
						dstPtr->cnt = maxValInImg;
						dstPtr++;
					}
			}

			if (numBytes > 0)    // cnt part is binary mask, use fast RLE class
			{
				// nothing~
			}
		}
		else
		{
			if (!ReadTiles(zPart, maxZErrorInFile, 
				numTilesVert, numTilesHori, maxValInImg, ifs))
			{
				isSuccess = false;
				break;
			}

		}
	}

	return isSuccess;
}


// parse cntz and write original image
bool cCntZImage::ReadTiles(bool zPart, double maxZErrorInFile, 
	int numTilesVert, int numTilesHori, float maxValInImg, std::ifstream &ifs)
{
	for (int iTile = 0; iTile <= numTilesVert; ++iTile)
	{
		int tileH = m_height / numTilesVert;
		int i0 = iTile * tileH;
		if (iTile == numTilesVert)
			tileH = m_height % numTilesVert;
		if (tileH == 0)
			continue;

		for (int jTile = 0; jTile <= numTilesHori; jTile++)
		{
			int tileW = m_width / numTilesHori;
			int j0 = jTile * tileW;
			if (jTile == numTilesHori)
				tileW = m_width % numTilesHori;
			if (tileW == 0)
				continue;

			bool rv = zPart ? 
				ReadZTile(ifs, i0, i0 + tileH, j0, j0 + tileW, 
					maxZErrorInFile, maxValInImg) :
				ReadCntTile(ifs, i0, i0 + tileH, j0, j0 + tileW);
			if (!rv)
				return false;
		}
	}

	return true;
}


// read cnt tile
bool cCntZImage::ReadCntTile(std::ifstream &ifs, int i0, int i1, int j0, int j1)
{

	return true;
}


// read z tile
bool cCntZImage::ReadZTile(std::ifstream &ifs, int i0, int i1, int j0, int j1,
	double maxZErrorInFile, float maxZInImg)
{

	return true;
}


// resize 
bool cCntZImage::Resize(uint width, uint height)
{
	if (width > 10000 || height > 10000)
		return false; // too large
	if (width == m_width && height == m_height)
		return true; // same size

	m_width = width;
	m_height = height;
	m_buffer.resize(width * height);
	m_src.resize(width * height);
	ZeroMemory(&m_src[0], sizeof(sCntZ) * width * height);
	return true;
}
