#ifndef FileReader_h
#define FileReader_h

#include<fstream>
#include<iostream>
class FileReader
{
private:
    std::string input_file;
    std::string output_file;
public:
    virtual bool inputFile(std::ifstream& fin)=0;
    virtual bool outputFile(std::ofstream& fout)=0;
    std::string getInputFileName();
    std::string getOutputFileName();
    void setInputFileName(std::string s);
    void setOutputFileName(std::string s);
    virtual ~FileReader();
};

#endif