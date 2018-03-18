#include "MapData.h"
#include "json/rapidjson.h"
#include "json/document.h"

USING_NS_CC;

MapData* MapData::m_instance = nullptr;
std::map<int, MapData::MapDataParams> MapData::m_mapDataList;

MapData::MapData()
: m_mapListFile("")
{
}

// デストラクタ
MapData::~MapData() {
    
}

// 初期化
MapData* MapData::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new MapData();
    }
    return m_instance;
}

// 削除する際に使用
void MapData::deleteInstance() {
    if (m_instance != nullptr) {
        delete m_instance;
    }
    m_instance = nullptr;
}

bool MapData::mapDataJsonOpen(const std::string& filename)
{
    // ファイル読み込み
    std::string strData = FileUtils::getInstance()->getStringFromFile(filename);
    
    rapidjson::Document doc;
    doc.Parse<rapidjson::kParseDefaultFlags>(strData.c_str());
    
    if (doc.HasParseError()) {
        // 解析エラー
        CCLOG("JSON parse error.");
        return false;
    }
    
    if(!doc.IsObject()) {
        // パースエラーした状態でハンドリングせずにIsObject判定するとfalseになる
        CCLOG("invalid!");
        return false;
    }
    
    CCLOG("%s", strData.c_str());
    
    // 初期化
    m_mapDataList.clear();
    
    // キーと値を変数に登録する
    const rapidjson::Value& mapList = doc["map"];
    // キーと値をリストに登録する
    for(rapidjson::SizeType i = 0; i < mapList.Size(); i++){
        m_mapDataList[i].mapId       = mapList[i]["id"].GetInt();
        m_mapDataList[i].mapName     = mapList[i]["name"].GetString();
        m_mapDataList[i].mapStamina  = mapList[i]["stamina"].GetInt();
        m_mapDataList[i].mapStage    = mapList[i]["stage"].GetInt();
        m_mapDataList[i].mapDropCoin = mapList[i]["dropCoin"].GetInt();
        m_mapDataList[i].mapBoss     = mapList[i]["boss"].GetBool();
    }
    
    // 現在のファイルをセット
    m_mapListFile = filename;
    
    return true;
}

int MapData::getMapId(int mapId){
    return m_mapDataList[mapId].mapId;
}

std::string MapData::getMapName(int mapId){
    return m_mapDataList[mapId].mapName;
}

int MapData::getMapStamina(int mapId){
    return m_mapDataList[mapId].mapStamina;
}

int MapData::getMapStage(int mapId){
    return m_mapDataList[mapId].mapStage;
}

int MapData::getMapDropCoin(int mapId){
    return m_mapDataList[mapId].mapDropCoin;
}

bool MapData::getMapBoss(int mapId){
    return m_mapDataList[mapId].mapBoss;
}