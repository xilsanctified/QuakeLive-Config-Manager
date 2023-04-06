#ifndef CONFIG_MERGER_HPP
#define CONFIG_MERGER_HPP

#include <string>
#include <vector>

class ConfigMerger
{
public:
    ConfigMerger();
    void listFiles();
    bool selectFiles(int first_file_index, int second_file_index);
    bool mergeFiles();

private:
    std::vector<std::string> cfg_files;
    std::string first_file_contents;
    std::string second_file_contents;
};

#endif