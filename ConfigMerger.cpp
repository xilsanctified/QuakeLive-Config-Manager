#include "ConfigMerger.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

ConfigMerger::ConfigMerger() {}

void ConfigMerger::listFiles()
{
    for (const auto &entry : fs::directory_iterator("."))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".cfg")
        {
            cfg_files.push_back(entry.path().string());
        }
    }

    std::cout << "List of .cfg files in the current directory:\n";
    for (int i = 0; i < cfg_files.size(); i++)
    {
        std::cout << i + 1 << ". " << cfg_files[i] << "\n";
    }
}

bool ConfigMerger::selectFiles(int first_file_index, int second_file_index)
{
    if (first_file_index < 1 || first_file_index > cfg_files.size() ||
        second_file_index < 1 || second_file_index > cfg_files.size())
    {
        return false;
    }

    // Open the first file and read its contents
    std::ifstream first_file(cfg_files[first_file_index - 1]);
    if (!first_file.is_open())
    {
        return false;
    }
    first_file_contents = std::string((std::istreambuf_iterator<char>(first_file)), std::istreambuf_iterator<char>());
    first_file.close();

    // Open the second file and read its contents
    std::ifstream second_file(cfg_files[second_file_index - 1]);
    if (!second_file.is_open())
    {
        return false;
    }
    second_file_contents = std::string((std::istreambuf_iterator<char>(second_file)), std::istreambuf_iterator<char>());
    second_file.close();

    return true;
}

bool ConfigMerger::mergeFiles()
{
    // Merge the contents of the two files
    std::string merged_contents = first_file_contents + second_file_contents;

    // Write the merged contents to a new file called merged.cfg
    std::ofstream merged_file("merged.cfg");
    if (!merged_file.is_open())
    {
        return false;
    }
    merged_file << merged_contents;
    merged_file.close();

    return true;
}