#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "MaxBinPlugin.h"

void MaxBinPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void MaxBinPlugin::run() {}

void MaxBinPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "run_MaxBin.pl -contig ";
myCommand += parameters["contigs"];
myCommand += " ";
myCommand += "-out";
myCommand += " ";
myCommand += outputfile + " ";
myCommand += "-reads_list " + parameters["reads_list"];
 system(myCommand.c_str());
}

PluginProxy<MaxBinPlugin> MaxBinPluginProxy = PluginProxy<MaxBinPlugin>("MaxBin", PluginManager::getInstance());
