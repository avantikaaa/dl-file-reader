#include "../headers/FileReader.h"

std::string FileReader::getInputFileName()
{
    return this->input_file;
}
std::string FileReader::getOutputFileName()
{
    return this->output_file;
}
void FileReader::setInputFileName(std::string s)
{
    this->input_file=s;
}
void FileReader::setOutputFileName(std::string s)
{
    this->output_file = s;
}

FileReader::~FileReader()
{
    
}