
#include <iostream>
#include <string>
#include <Windows.h>
#include <direct.h> //mkdir
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

using std::string;

int main()
{
	//string url = "http://ecn.t0.tiles.virtualearth.net/tiles/a132112101030310.jpeg?n=z&g=10242";
	// 10/393/874
	//string url = "https://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/10/393/874";
	//// 19/202474/448180
	//string url2 = "https://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/19/202474/448180";
	//// 6/24/54
	//string url3 = "https://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/6/24/54";
	//// 0/0/0
	//string url4 = "https://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/0/0/0";

	HRESULT hr;
	//string dstFileName = "test.jpeg";
	//hr = URLDownloadToFileA(NULL, url4.c_str(), dstFileName.c_str(), 0, NULL);

	// ArcGIS, ESRI world imagery
	// 0/0/0
	//string url10 = "https://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/1/0/0";
	//string url11 = "https://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/1/0/1";
	//string url12 = "https://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/1/1/0";
	//string url13 = "https://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/1/1/1";
	//hr = URLDownloadToFileA(NULL, url10.c_str(), "tile0.jpg", 0, NULL);
	//hr = URLDownloadToFileA(NULL, url11.c_str(), "tile1.jpg", 0, NULL);
	//hr = URLDownloadToFileA(NULL, url12.c_str(), "tile2.jpg", 0, NULL);
	//hr = URLDownloadToFileA(NULL, url13.c_str(), "tile3.jpg", 0, NULL);

	// BingMap
	//// https://docs.microsoft.com/en-us/bingmaps/articles/bing-maps-tile-system
	//string url10 = "http://ecn.t0.tiles.virtualearth.net/tiles/a0.jpeg?n=z&g=10242";
	//string url11 = "http://ecn.t0.tiles.virtualearth.net/tiles/a1.jpeg?n=z&g=10242";
	//string url12 = "http://ecn.t0.tiles.virtualearth.net/tiles/a2.jpeg?n=z&g=10242";
	//string url13 = "http://ecn.t0.tiles.virtualearth.net/tiles/a3.jpeg?n=z&g=10242";
	//hr = URLDownloadToFileA(NULL, url10.c_str(), "tile10.jpg", 0, NULL);
	//hr = URLDownloadToFileA(NULL, url11.c_str(), "tile11.jpg", 0, NULL);
	//hr = URLDownloadToFileA(NULL, url12.c_str(), "tile12.jpg", 0, NULL);
	//hr = URLDownloadToFileA(NULL, url13.c_str(), "tile13.jpg", 0, NULL);

	

	//string url10 = "https://assets.cesium.com/1/13/13973/5807.terrain?extensions=metadata&v=1.2.0";
	//hr = URLDownloadToFileA(NULL, url10.c_str(), "tile10.bil", 0, NULL);

	string url10 = "https://services.arcgisonline.com/arcgis/rest/services/Elevation/World_Hillshade/MapServer/tile/0/0/0";
	string url11 = "https://services.arcgisonline.com/arcgis/rest/services/WorldElevation3D/Terrain3D/ImageServer/0/0/0";
	hr = URLDownloadToFileA(NULL, url10.c_str(), "tile10.bil", 0, NULL);

}
