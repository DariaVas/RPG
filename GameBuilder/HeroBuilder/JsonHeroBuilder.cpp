#include "JsonHeroBuilder.h"
#include "json.hpp"
using nlohmann::json;

JsonHeroBuilder::JsonHeroBuilder(const std::string &file_path)
    :m_file_path(file_path),
     m_config(read_json_file(json::parse(file_path)))
{
}

MagicDefense JsonHeroBuilder::build_magic_amulet(const std::string &hero)
{
    m_config[hero][]
}

std::string JsonHeroBuilder::read_json_file()
{
    std::ifstream file;
    file.exceptions(std::ios::failbit | std::ios::badbit);
    file.open(m_file_path);
    std::string content;
    content.assign(std::istreambuf_iterator<char>(file),
                   std::istreambuf_iterator<char>());
    return content;
}
