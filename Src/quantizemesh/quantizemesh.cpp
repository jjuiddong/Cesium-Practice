//
// load cesium terrain quantize mesh 
// reference
//	- https://github.com/CesiumGS/quantized-mesh
//
//	- Fail
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int32_t zigZagDecode(int32_t value) { return (value >> 1) ^ (-(value & 1)); }

double lerp(double p, double q, double time) noexcept {
	//return glm::mix(p, q, time);
	return (q - p) * std::max(0.0, std::min(1.0, time)) + p;
}


int main()
{

	struct QuantizedMeshHeader {
		// The center of the tile in Earth-centered Fixed coordinates.
		double CenterX;
		double CenterY;
		double CenterZ;

		// The minimum and maximum heights in the area covered by this tile.
		// The minimum may be lower and the maximum may be higher than
		// the height of any vertex in this tile in the case that the min/max vertex
		// was removed during mesh simplification, but these are the appropriate
		// values to use for analysis or visualization.
		float MinimumHeight;
		float MaximumHeight;

		// The tile¡¯s bounding sphere.  The X,Y,Z coordinates are again expressed
		// in Earth-centered Fixed coordinates, and the radius is in meters.
		double BoundingSphereCenterX;
		double BoundingSphereCenterY;
		double BoundingSphereCenterZ;
		double BoundingSphereRadius;

		// The horizon occlusion point, expressed in the ellipsoid-scaled
		// Earth-centered Fixed frame. If this point is below the horizon, the entire
		// tile is below the horizon. See
		// http://cesiumjs.org/2013/04/25/Horizon-culling/ for more information.
		double HorizonOcclusionPointX;
		double HorizonOcclusionPointY;
		double HorizonOcclusionPointZ;

		// The total number of vertices.
		uint32_t vertexCount;
	};

	//ifstream ifs("12-1606-3517.terrain", ios::binary);
	//ifstream ifs("14-14067-6419.terrain", ios::binary);
	//ifstream ifs("11-1743-822.terrain", ios::binary);	
	ifstream ifs("6-54-25.terrain", ios::binary);
	if (!ifs.is_open())
		return 0;

	QuantizedMeshHeader header;
	ifs.read((char*)&header, sizeof(header));

	struct VertexData
	{
		unsigned int vertexCount;
		unsigned short *u;
		unsigned short *v;
		unsigned short *h; // height
	};

	VertexData vtxData;
	vtxData.vertexCount = header.vertexCount;
	unsigned short *buffer = new unsigned short[header.vertexCount * 3];
	ifs.read((char*)buffer, sizeof(unsigned short) * header.vertexCount * 3);
	vtxData.u = buffer;
	vtxData.v = buffer + header.vertexCount;
	vtxData.h = buffer + (header.vertexCount * 2);


	vector<float> hmap(header.vertexCount, 0.f);

	uint32_t u = 0, v = 0, height = 0;
	for (uint32_t i = 0; i < header.vertexCount; ++i) {
		u += zigZagDecode(vtxData.u[i]);
		v += zigZagDecode(vtxData.v[i]);
		height += zigZagDecode(vtxData.h[i]);

		//double uRatio = static_cast<double>(u) / 32767.0;
		//double vRatio = static_cast<double>(v) / 32767.0;
		double heightRatio = static_cast<double>(height) / 32767.0;

		//double longitude = lerp(west, east, uRatio);
		//double latitude = lerp(south, north, vRatio);
		double heightMeters = lerp(header.MinimumHeight, header.MaximumHeight
			, heightRatio);

		//vtxData.u[i] = u;
		//vtxData.v[i] = v;
		//vtxData.h[i] = height;
		hmap[i] = (float)heightMeters;

		cout << vtxData.h[i] << endl;
		//cout << height << endl;
	}

	int triangleCount = 0;
	ifs.read((char*)&triangleCount, sizeof(triangleCount));
	//unsigned short *indices = new unsigned short[triangleCount * 3];
	//ifs.read((char*)indices, sizeof(unsigned short) * triangleCount * 3);



	delete[] buffer;
	//delete[] indices;
}

