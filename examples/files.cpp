#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    /*
     * Opening files
     *
     * Stream types:
     * - ofstream: Write (Output File Stream)
     * - ifstream: Read (Input File Stream)
     * - fstream: Read and write
     *
     * Possible flags:
     * - ios::in  -> Read. Optional because it is the default value
     * - ios::out -> Write. Mandatory but default value when using objects "ofstream".
     * - ios::app (append) -> Write with default position at the end of file.
     * - ios::trunc (truncate) -> Write but erases the whole file before
     * - ios::ate (at end) -> Similar to ios::app, but if repositionning, writing will not necesarrily happen at the end of the file, contrary to "ios::app"
     * Either "ios::trunc" or "ios::ate", not both. The file must exist !
     */
    string path1 = "write.txt", path2 = "read.txt", path3 = "read_write.txt";
    ofstream fw(path1);
    ifstream fr(path2.c_str());
    fstream frw(path3, ios::in | ios::out);


    /*
     * Writing to files
     */
    int integer = 1;
    char chr = 'A';
    string str = "A line to a file";

    fw << integer << " ";
    fw << chr << " " << str;
    frw.put(integer);
    frw.put(chr);
    frw << " " << str << endl;


    /*
     * Reading files
     */
    string line, word;
    char letter;
    getline(fr, str, 'w'); // Read a string into "str" until the character 'w' is found. Default character: '\n'
    fr >> word; // Read until a delimiter (space, or '\n') is found
    frw.get(letter); // Read a character


    /*
     * Positioning
     *
     * Possible flags:
     * - ios::beg -> Beginning of file
     * - ios::cur -> Current position
     * - ios::end -> Enf of file
     */
    fw.tellp(); // For ofstream
    fr.tellg(); // For ifstream
//    fw.seekp(nb_cara_deplacement, reference_facultative = ios::beg); // For ofstream
//    fr.seekg(nb_cara_deplacement, reference_facultative = ios::beg); // For ifstream


    /*
     * fstream only methods
     */
    frw.eof(); // true if nothing to read or write

    char end_char = '\r';
    int n = 8;
    frw.ignore(n, end_char); // Ignore n characters until it finds end_char


    /*
     * Closing files
     */
    fw.close();
    fr.close();
    frw.close();

    return EXIT_SUCCESS;
}