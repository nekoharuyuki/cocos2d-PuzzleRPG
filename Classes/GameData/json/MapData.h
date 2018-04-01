#ifndef __MAP_DATA__
#define __MAP_DATA__

#include "cocos2d.h"

class MapData
{
private:
    MapData();   //コンストラクタ
    static MapData* m_instance;
    
    // マップ情報の設定リスト
    struct MapDataParams {
        int mapId;
        std::string mapName;
        int mapStamina;
        int mapStage;
        int mapDropCoin;
        bool mapBoss;
    };
    static std::map<int, MapDataParams> m_mapDataList;
    
    // マップ管理ファイルのファイルパス
    CC_SYNTHESIZE(std::string, m_mapListFile, MapListFile);
    
public:
    ~MapData();
    static MapData* getInstance();
    static void deleteInstance();
    
    bool mapDataJsonOpen(const std::string& filename);
    
    static int getMapId(int mapId);
    static std::string getMapName(int mapId);
    static int getMapStamina(int mapId);
    static int getMapStage(int mapId);
    static int getMapDropCoin(int mapId);
    static bool getMapBoss(int mapId);
};

#endif /* defined(__MAP_DATA__) */