//
// 2021-03-28, jjuiddong
// ArcGIS, esri world imagery, terrain
// CntZImage read, parsing class
// reference:
//	- https://github.com/Esri/lerc
//
// not work
//
#pragma once

#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>
using std::string;
using std::vector;
#ifndef uint
	typedef unsigned int uint;
#endif


namespace esri
{
	// pixel data format
	enum class eType
	{
		BYTE,
		RGB,
		SHORT,
		LONG,
		FLOAT,
		DOUBLE,
		COMPLEX,
		POINT3F,
		CNT_Z,
		CNT_ZXY,
		Last_Type_
	};

	// CntZ pixel format
	struct sCntZ
	{
		float cnt, z;
		bool operator == (const sCntZ& cz) const { return cnt == cz.cnt && z == cz.z; }
		bool operator != (const sCntZ& cz) const { return cnt != cz.cnt || z != cz.z; }
		void operator += (const sCntZ& cz) { cnt += cz.cnt;  z += cz.z; }
	};


	// cntzimage class
	class cCntZImage
	{
	public:

	public:
		cCntZImage();
		virtual ~cCntZImage();

		bool Read(const string &fileName);
		bool ReadTiles(bool zPart, double maxZErrorInFile, int numTilesVert, int numTilesHori,
			float maxValInImg, std::ifstream &ifs);
		bool ReadCntTile(std::ifstream &ifs, int i0, int i1, int j0, int j1);
		bool ReadZTile(std::ifstream &ifs, int i0, int i1, int j0, int j1, double maxZErrorInFile, float maxZInImg);

		bool Resize(uint width, uint height);


	public:
		uint m_width;
		uint m_height;
		vector<sCntZ> m_src; // source cntz data
		vector<float> m_buffer;
	};

}

