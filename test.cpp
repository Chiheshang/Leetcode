#include<iostream>
#include<thread>
#include <stdlib.h>
#include <time.h> 
#include<vector>
#include"json.h"
using namespace std;

int main()
{
    std::string strValue = "{ \"name\":\"json\", \"array\" : [{\"key0\":23456}, {\"key1\":123}] }";

    Json::Reader reader;
    Json::Value value;
    if (reader.parse(strValue, value))
    {
        std::string out = value["name"].asString();
        std::cout << out << std::endl;
        const Json::Value arrayObj = value["array"];
        for (unsigned int i = 0; i < arrayObj.size(); i++)
        {
            if (!arrayObj[i].isMember("key0"))
                continue;
            out = arrayObj[i]["key0"].asString();
            int m_int = arrayObj[i]["key0"].asInt64();
            std::cout << out<<endl;
            cout << m_int << endl;
            if (i != (arrayObj.size() - 1))
                std::cout << std::endl;
        }
    }
}
