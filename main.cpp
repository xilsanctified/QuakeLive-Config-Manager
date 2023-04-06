#include <iostream>
#include "ConfigMerger.hpp"

int main()
{
    int choice = 0;
    while (choice != 3)
    {
        std::cout << "Menu:\n";
        std::cout << "1. Merge two .cfg files\n";
        std::cout << "2. Option 2\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            // Code to handle option 1
            {
                std::cout << "----------------------\n";
                ConfigMerger merger;

                merger.listFiles();

                int first_file_index, second_file_index;
                std::cout << "Enter the number of the first file to merge: ";
                std::cin >> first_file_index;
                std::cout << "Enter the number of the second file to merge: ";
                std::cin >> second_file_index;

                if (!merger.selectFiles(first_file_index, second_file_index))
                {
                    std::cout << "Error selecting files\n";
                    break;
                }

                if (!merger.mergeFiles())
                {
                    std::cout << "Error merging files\n";
                    break;
                }

                std::cout << "Files merged successfully!\n";
                break;
            }
        case 2:
            // Code to handle option 2
            std::cout << "You selected option 2\n";
            break;
        case 3:
            std::cout << "Quitting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    return 0;
}
