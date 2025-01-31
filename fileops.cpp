#include "fileops.h"

FileOps::FileOps(bool new_ds_value, std::string new_mask, SaveOption s_option, std::string new_spath) {

    this->mask = new_mask;
    this->save_option = s_option;
    this->savePath = new_spath;
    this->deleteSources = new_ds_value;


}

void FileOps::set_new_values(bool new_ds_value, std::string new_mask, SaveOption s_option, std::string new_spath) {

    this->mask = new_mask;
    this->save_option = s_option;
    this->savePath = new_spath;
    this->deleteSources = new_ds_value;

}

std::string FileOps::get_mask(){

    return this->mask;

}


void FileOps::save_bytes(unsigned char* readyBytes) const{
    std::string filePath = savePath + "//" + extracted_file_name;

    if(std::filesystem::exists(filePath + "." + mask)){

        if(save_option == SaveOption::Modification){
            //time_t currentTime = time(nullptr);
            auto now = std::chrono::system_clock::now();
            auto duration = now.time_since_epoch();
            auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
            filePath += std::to_string(milliseconds);
        }

        else{
            if(std::remove(filePath.c_str()) == 0)
                std::cout << "Файл успешно удален" << std::endl;
            else
                std::cout << "Ошибка удаления" << std::endl;

        }
    }
    filePath += ("." + mask);
    std::ofstream outputFile(filePath, std::ios::binary);
    outputFile.write(reinterpret_cast<char*>(readyBytes), file_size);


}

void FileOps::extract_filename(std::string file_path){

    std::filesystem::path p(file_path);
    extracted_file_name = p.stem().u8string();

    if(this->mask.empty()){
        this->mask = std::string{p.extension().u8string()};
        this->mask.erase(0, 1);
    }


}

unsigned FileOps::get_bytes_quantity(){

    return file_size;

}

unsigned char* FileOps::read_bytes(std::string readPath){

    std::ifstream file(readPath, std::ios::binary);
    file.seekg(0, std::ios::end);
    file_size = file.tellg(); // Берем размер файла
    file.seekg(0, std::ios::beg);
    unsigned char* buff = new unsigned char[file_size]; // Читаем байты
    extract_filename(readPath);
    file.read((char*)buff, file_size);
    file.close();
    if(deleteSources == true){
        if(std::remove(readPath.c_str()) == 0)
            std::cout << "Файл успешно удален" << std::endl;
        else
            std::cout << "Ошибка удаления" << std::endl;
    }
        return buff; // Возврат указателя на каноничный байтовый тип

}

