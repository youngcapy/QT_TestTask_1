#ifndef FILEOPS_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <filesystem>
#include <locale>
#include <codecvt>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QString>

#define FILEOPS_H

enum class SaveOption { Rewrite, Modification };

class FileOps
{

    public:
        FileOps(bool ds_new_value, std::string new_mask, SaveOption s_option, std::string new_spath);
        void save_bytes(unsigned char* readyBytes) const; // Прототип для сохранения в файл
        void set_new_values(bool ds_new_value, std::string new_mask, SaveOption s_option, std::string new_spath);
        unsigned char* read_bytes(std::string readPath); // Прототип для чтения из файла
        std::string get_mask();

        unsigned get_bytes_quantity();


    private:
        void extract_filename(std::string file_path);
        bool deleteSources; // Содержит информацию о необходимости удаления исходных файлов
        std::string savePath;
        std::string mask;
        SaveOption save_option;
        std::string extracted_file_name;
        unsigned file_size;

};

#endif // FILEOPS_H
