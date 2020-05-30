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
     * - ios::ate (at end) -> ~ ios::app, but if repositionning, write will not always happen at EOF, contrary to "ios::app"
     * Either "ios::trunc" or "ios::ate", not both. The file must exist !
     */
    string path1 = "../examples/write.txt", path2 = "../examples/read.txt", path3 = "../examples/read_write.txt";
    ofstream fw(path1);
    ifstream fr(path2.c_str());
    fstream frw(path3, ios::in | ios::out | ios :: trunc);


    /*
     * Writing to files
     */
    int integer = 1;
    char chr = 'A';
    string str = "String";

    fw << integer << " ";
    fw << chr << " " << str << endl;
    frw << integer << " " << chr << " " << str << endl;
//    frw.put(integer);


    /*
     * Reading ifstream files
     */
    // Read a character
    chr = 0;
    fr >> chr;
    cout << "Read character from ifstream: " << chr << endl;

    // Read words by words
    fr >> str; // Read until a delimiter (space, or '\n') is found
    cout << "Read word from ifstream: " << str << endl;
    fr >> str;
    cout << "Read word from ifstream: " << str << endl;
    fr >> str;
    cout << "Read word from ifstream: " << str << endl;

    // Read a line
    getline(fr, str);
    cout << "Read remaining line from ifstream: " << str << endl;
    getline(fr, str);
    cout << "Read line from ifstream: " << str << endl;

    // Read line until character
    getline(fr, str, 'Z'); // Notice that this character will never be read: excluded. See remaining line
    cout << "Read line from ifstream until character: " << str << endl;

    // Read remaining line
    getline(fr, str);
    cout << "Read remaining line from ifstream: " << str << endl;

    // Read when EOF
    str = "";
    getline(fr, str);
    cout << "Read line from ifstream when EOF: " << str << endl; // Value of str is unchanged


    /*
     * Reading from fstream files
     */
//    chr = 0;
//    frw >> chr;
//    frw.get(chr); // Read a character
//    cout << "Read character from fstream: " << chr << endl;

    // Read a line
//    getline(fr, str, 'w'); // Read a string into "str" until the character 'w' is found. Default character: '\n'


    /*
     * Positioning
     *
     * Possible flags:
     * - ios::beg -> Beginning of file
     * - ios::cur -> Current position
     * - ios::end -> Enf of file
     */
    int position;
    position = fw.tellp(); // For ofstream
    position = fr.tellg(); // For ifstream

    // Go back the beginning
    fw.seekp(0, ios::beg);
    fr.clear(); // Clear the 'EOF' flag, necessary before C++11
    fr.seekg(0, ios::beg);
    cout << "Went back to beginning of ofstream and ifstream files" << endl;

    // Go back to a certain position
    fw.seekp(position, ios::beg);
    fr.seekg(position, ios::beg);


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