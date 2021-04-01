
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
	// 0/0/0 -> lv/y/x
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

	//string url10 = "https://services.arcgisonline.com/arcgis/rest/services/Elevation/World_Hillshade/MapServer/tile/0/0/0";
	//string url11 = "https://services.arcgisonline.com/arcgis/rest/services/WorldElevation3D/Terrain3D/ImageServer/0/0/0";
	//hr = URLDownloadToFileA(NULL, url10.c_str(), "tile10.bil", 0, NULL);

	// google map
	//string url10 = "https://khms1.googleapis.com/kh?v=899&hl=ko-KR&x=27&y=12&z=5";
	//hr = URLDownloadToFileA(NULL, url10.c_str(), "tile.jpg", 0, NULL);

	// ngii
	//string url10 = "http://210.117.198.120:8081/o2map/services?service=WMTS&request=GetTile&version=1.0.0&layer=AIRPHOTO&style=_null&format=image/jpg&tilematrixset=NGIS_AIR&tilematrix=18&tilerow=33245&tilecol=20056";
	//hr = URLDownloadToFileA(NULL, url10.c_str(), "tile_ngii.jpg", 0, NULL);

	// cesium  terrain quantized mesh
	//string url = "https://api.maptiler.com/tiles/terrain-quantized-mesh/1/1/1.terrain?key=2C5ETahQR5FyKmhlf8Z9";
	//string url = "https://api.maptiler.com/tiles/terrain-quantized-mesh/12/1606/3517.terrain?key=2C5ETahQR5FyKmhlf8Z9";
	//hr = URLDownloadToFileA(NULL, url.c_str(), "12-1606-3517.terrain", 0, NULL);

	// mapbox, fail
	//string url = "https://api.mapbox.com/v4/mapbox.satellite/14/13966/6576.png?access_token=pk.eyJ1Ijoia3lsZWJhcnJvbiIsImEiOiJja2c0bDg4ZGEwbHI4MnNvMzd2bHM2ZDJ5In0.1KD5cEoyiyW3fb3MXQkAvA";
	//hr = URLDownloadToFileA(NULL, url.c_str(), "14-13966-6576.png", 0, NULL);

	// kylebarron
	// lv/x/y
	//string url = "https://khms1.googleapis.com/kh?v=899&hl=ko-KR&x=1743&y=822&z=11";
	//string url = "https://us-east-1-lambda.kylebarron.dev/dem/mesh/11/1743/822.terrain?url=terrarium&mesh_max_error=150.52&mesh_algorithm=pydelatin&flip_y=true";
	//hr = URLDownloadToFileA(NULL, url.c_str(), "11-1743-822.terrain", 0, NULL);

	// maptiler
	// z/x/y
	//string url = "https://api.maptiler.com/tiles/terrain-quantized-mesh/9/205/435.terrain?key=2C5ETahQR5FyKmhlf8Z9";
	//hr = URLDownloadToFileA(NULL, url.c_str(), "9-435-205.terrain", 0, NULL);

	// ArcGis elevation
	string url = "https://services.arcgisonline.com/arcgis/rest/services/WorldElevation3D/Terrain3D/ImageServer/tile/9/435/205";
	hr = URLDownloadToFileA(NULL, url.c_str(), "arc-9-435-205.bil", 0, NULL);

}
