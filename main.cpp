/**
 * @file main.cpp
 * @brief Implement Pupil tracking on images
 * @author Ari Nguyen
 */
#include <iostream>
#include <string>

#include <boost/program_options.hpp>
// #include "helper/helper.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
namespace po = boost::program_options;

// Main function: acts as a pipeline
int main(int argc, const char **argv) {
    std::string img_path;

    // Parse arguments
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("-f", po::value<std::string>(&img_path));
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
        cerr << img_path << endl;
    } catch (exception& e) {
        cerr << "error: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Exception of unknown type!\n";
        return 1;
    }

    //  
    
    return 0;
}



